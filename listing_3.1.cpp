#include <list>
#include <mutex>
#include <algorithm>
#include <iostream>

std::list<int> ilist;
std::mutex imutex;
void list_operation(int value)
{
    std::lock_guard<std::mutex> guard(imutex);
    ilist.push_back(value);
}
bool list_contains(int value)
{
    std::lock_guard<std::mutex> guard(imutex);
    return std::find(ilist.begin(),ilist.end(),value)
        != ilist.end();
}



int main()
{
    list_operation(2);
    std::cout<<"contains(2)="<<list_contains(1)<<", contains(3)="<<list_contains(42)<<std::endl;
    system("pause");
}
