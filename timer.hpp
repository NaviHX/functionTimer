#ifndef __TIMER_H__
#define __TIMER_H__

#include <functional>
#include <chrono>

using duration_t = std::chrono::duration<double, std::micro>;

template <typename T>
class con_t
{
public:
    T con;
    duration_t d;
    con_t(T _con, duration_t _d) { d = _d, con = _con; };
    operator T() { return this->con; };
};

/* 
get_time_cost:  get both the ret value and the time cost
param: 
    func:       callable. the function which is to be measured
    args ...:   args list. args for func
return type:
    con_t<T>:   can be treated as T which is the ret type of func. use ".d" to access the measure result
                T::operator= must be implemented
 */
template <class F, class... ARGS>
auto get_time_cost(F func, ARGS... args) -> con_t<decltype(func(args...))>
{
    using ret_t = decltype(func(args...));
    auto start = std::chrono::steady_clock::now();
    ret_t ret = func(args...);
    auto end = std::chrono::steady_clock::now();
    return con_t<ret_t>(ret, end - start);
}

#endif