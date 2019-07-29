#include "ex16.22.TextQuery.hpp"
#include <iostream>

void runQueries(std::ifstream& infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main()
{
    std::ifstream file("../Chapter-12-DynamicMem/text_file");
    runQueries(file);
}
