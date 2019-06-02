
#include <iostream>
#include <string>

using std::cout;
using std::string;

class Screen {
public:
    using pos = string::size_type;    
    
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), 
        contents(ht * wd , c) {}
    Screen(pos ht, pos wd) : Screen(ht, wd, ' ') {}

    char get() const{
        return contents[cursor]; 
    }
    inline char get(pos, pos); 
    Screen& move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    // do the const overload 
    Screen &display(std::ostream &os){
        doDisplay(os);
        return *this; 
    }
    const Screen &display(std::ostream &os) const {
        doDisplay(os);
        return *this; 
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    void doDisplay(std::ostream &os) const {
        os << contents << std::endl; 
    }

};

inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) {
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r*width + col] = ch; 
    return *this;
}


int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    myScreen.display(cout);
}
