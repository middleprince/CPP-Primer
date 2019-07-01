#include <functional>
#include <map>
#include <string>
#include <iostream>


// normal function
int add(int i, int j) {
    return i + j;
}

// named lambda
auto mod = [](int i, int j) { return i % j; };

// functor
struct xy_div {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

// boild the map for function table
std::map<std::string, std::function<int(int, int)> > binops = {
    {"+", add},                                //  function pointer
    {"-", std::minus<int>()},                  //  library functor
    //{"/", xy_div()},                           //  user-defined functor
    {"/", std::divides<int>()},                           //  user-defined functor
    {"*", [](int i, int j) { return i * j; }}, //  unnamed lambda
    {"%", mod}                                 //  named lambda object
};

int main()
{
    while (true) {
        std::cout << "\npleasr enter: num operator num :\n";
        int n1, n2;
        std::string s;
        std::cin >> n1 >> s >> n2;

        std::cout << binops[s](n1, n2);
    }

    return 0;
}

