#include <thread>
#include <iostream>
using namespace std;

void do_something(int& i)
{
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }
};

void do_something_in_current_thread()
{
    cout << "choose a:exception or b:no exception:" <<endl;
    char c = getchar();
    if(c == 'a')
        throw 1;
}

void f()
{
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try
    {
        do_something_in_current_thread();
    }
    catch(int e)
    {
        cout << "current_thread throw exception! join in catch..." <<endl;
        t.join();
        cout << "join thread return, exception return!" <<endl;
        system("pause");
        throw;
    }
    cout << "no exception" <<endl;
    t.join();
     cout << "wait for thread return, normal return." <<endl;
}

int main()
{
    f();
    system("pause");
}
