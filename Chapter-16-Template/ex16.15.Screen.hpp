#ifndef ex16_15_Screen_hpp
#define ex16_15_Screen_hpp

#include <iostream>
#include <string>
#include <algorithm>

using pos = std::string::size_type;

template <pos, pos> class Screen;

template <pos H, pos W> 
std::istream& operator>>(std::istream &, Screen<H, W> &);

template <pos H, pos W> 
std::ostream& operator<<(std::ostream &, Screen<H, W> &);

template <pos H, pos W>
class Screen {
    friend std::istream& operator>> <H, W>(std::istream &, Screen<H, W> &);
    friend std::ostream& operator<< <H, W>(std::ostream &, Screen<H, W> &);
public:
    Screen() = default;
    Screen(char c) : contents(H * W, c) {}

    char get() {return contents[cursor];}
    char get(pos r, pos c) {return contents[r * W + c];}
    
    inline Screen& move(pos r, pos c);
    inline Screen& set(pos r, pos c , char ch);
    inline Screen& set(char ch);
    
private:
    std::string contents;
    pos cursor = 0;
};

template <pos H, pos W>
std::istream& operator>>(std::istream &is, Screen<H, W> &s) {
    std::string input;
    is >> input;
    for (auto c : input)
        s.set(c); 
    return is;
}

template <pos H, pos W>
std::ostream& operator<<(std::ostream &os, Screen<H, W> &s) {
    for (pos r = 0; r != H; ++r) {
        for(pos c = 0; c != W; ++c)
            os << s.get(r, c);
        os << std::endl;
    }
    return os;
}

template <pos W, pos H>
inline Screen<W, H>& Screen<W, H>::move(pos r, pos c) {
    cursor = r * W + c;
    return *this;  
}

template <pos W, pos H>
inline Screen<W, H>& Screen<W, H>::set(pos r, pos c, char ch) {
   contents[r * W + c] = ch; 
   return *this;
}

template <pos W, pos H>
inline Screen<W, H>& Screen<W, H>::set(char ch) {
    contents[cursor++] = ch; 
    cursor = std::min(cursor, H * W);
    return *this;
}
#endif 

