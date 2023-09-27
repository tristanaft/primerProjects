#include <iostream>
#include <string>

class Screen{

public:
    typedef std::string::size_type pos;
    Screen()=default; //default initialization
    Screen(pos ht, pos wd):
        height(ht), width(wd), contents(ht*wd,' ') {};
    Screen(pos ht, pos wd, char c):
        height(ht), width(wd), contents(ht*wd,c) {};

    //public methods
    char get() const
        {return contents[cursor];} 
    char get(pos r, pos c) const; //declare here, define elsewhere
    
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
};

inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row+c];
}

int main(){
    return 0;
}