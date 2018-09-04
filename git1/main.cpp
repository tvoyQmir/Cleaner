#include <iostream>
#include <string>
#include <algorithm>

int main() {

    std::string str = "Hello";
    std::reverse(str.begin(),str.end());
    std::cout<<str<<std::endl;
    return 0;
}