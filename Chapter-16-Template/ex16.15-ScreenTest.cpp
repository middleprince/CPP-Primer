#include "ex16.15.Screen.hpp"

int main() {
    Screen<5, 5> screen('v');
    screen.set(2, 2, 'O');
    
    std::cout << "input some charactor" << std::endl;
    std::cin >> screen;
    std::cout << screen << std::endl; 

    return 0;
}
