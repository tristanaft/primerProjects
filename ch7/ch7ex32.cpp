#include <iostream>
#include <string>
#include <vector>

class Window_mgr{
public:
    //location ID for each screen in vector
    using ScreenIndex = std::vector<Screen>::size_type;
    //function to reset screen at given index to blank
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens{Screen(24,80,' ')};
};

class Screen{

//friend class Window_mgr;
friend void Window_mgr::clear(ScreenIndex);

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

    Screen &display(std::ostream &os)
                    {do_display(os); return *this;}

    const Screen &display(std::ostream &os) const
                    {do_display(os); return *this;}

    Screen &set(char c);
    Screen &set(pos r, pos col, char c);


private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;

    void do_display(std::ostream &os) const {os<<contents;}
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

inline
Screen &Screen::set(char c){
    contents[cursor] = c; //set the character at the cursor to c
    return *this;
}

inline
Screen &Screen::set(pos r, pos col, char c){
    contents[r*width + col] = c; //set the character at the cursor to c
    return *this;
}


void Window_mgr::clear(ScreenIndex i){
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width,' ');
}




int main(){

    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << '\n';
    myScreen.display(std::cout);
    std::cout << '\n';

    return 0;
}