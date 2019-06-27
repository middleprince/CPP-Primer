#include "ex14.18.StrVec.hpp"

int main() {
    StrVec vec_1{"hell" , "yeah"};
    StrVec vec_2{"hell" , "yeah", "b"};
    StrVec vec_3{"hell" , "yeah", "a"};
    
    std::cout << "Test vec_1 < vec_2" << std::endl;
    std::cout << (vec_1 < vec_2 ? "True" : "False") << std::endl;

    std::cout << "Test vec_2 < vec_3" << std::endl;
    std::cout << (vec_2 < vec_3 ? "True" : "False") << std::endl;

    
    
    return 0;
}
