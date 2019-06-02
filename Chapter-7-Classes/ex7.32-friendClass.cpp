/*
 * about the frend class
 */
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;

class Screen {
public:
    using pos = string::size_type;    
    friend class Window_mgr; 
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

class Window_mgr {
private:
    // Screen vector for window
    std::vector<Screen> screens{Screen(24, 80, ' ')};
public:
    typedef std::vector<Screen>::size_type ScreenIndex;
    void clear(ScreenIndex);
    void addScreen(const Screen & );
    void displayWin(void);


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

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
    }

void Window_mgr::addScreen(const Screen &srn) {
    this->screens.push_back(srn);
}

void Window_mgr::displayWin(void) {
    for (auto &src : screens)
        src.display(cout); 
} 

int main() {
    Screen myScreen(5, 5, 'X');
    Window_mgr wins; 
    myScreen.move(4, 0).set('#').display(cout);
    myScreen.display(cout);

    wins.addScreen(myScreen);
    wins.displayWin();
    
    wins.clear(1);
    wins.displayWin();
}
