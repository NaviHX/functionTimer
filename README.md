# functionTimer

A simple header-only timer for function calling. Return both the time and the return value.

# Usage

Include the `timer.hpp` and wrap the function with `get_time_cost()`. The return value can treated as the return type of original function.

e.g

```c++
int foo(int a)
{
    sleep(3);
    return a*2;
}

int main()
{
    auto con=get_time_cost(foo,1);
    std::cout<<foo(con)<<" "<<con.d.count()<<std::endl;
    return 0;
}
```