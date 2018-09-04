#include <iostream>
#include <vector>
#include <list>

template <typename T>
std::list<T> VectorToList (std::vector<T>& v)
{
    std::list<T> list;

    for (const auto& el:v)
    {
        l.push_back(el);
    }
    return l;
}

template <typename T1>
void PrintList (std::list<T1>& list)
{
    for(auto element:list)
    {
        std::cout<<element<<std::endl;
    }
}
int main() {

    std::vector<int> vector = {1,2,3,4};

    std::list<int> l = VectorToList(vector);

    PrintList(l);

    return 0;
}
