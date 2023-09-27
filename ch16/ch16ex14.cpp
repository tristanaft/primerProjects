#include <iostream>
#include <string>
#include <vector>

template <std::string::size_type height, std::string::size_type width>
class Screen;

class Window_mgr{
public:
    //location ID for each screen in vector
    using FixedScreen = Screen<24,80>;
    using ScreenIndex = std::vector<FixedScreen>::size_type;
    //function to reset screen at given index to blank
    void clear(ScreenIndex);
    Window_mgr();
private:
    std::vector<FixedScreen> screens;
};

template<std::string::size_type height, std::string::size_type width>
class Screen{
//friend class Window_mgr;
friend void Window_mgr::clear(ScreenIndex);
public:
    using pos = std::string::size_type;
    //typedef pos = std::string::size_type;

    Screen()=default; //default initialization
    Screen(char c):
        cursor(0), contents(height * width, c) {};
    //public methods
    char& get() const {return contents[cursor];} 
    char& get(pos r, pos c) const; //declare here, define elsewhere

    Screen& move(pos r, pos c);

    Screen& display(std::ostream &os)
                    {do_display(os); return *this;}

    const Screen &display(std::ostream &os) const
                    {do_display(os); return *this;}

    Screen& set(char c);
    Screen& set(pos r, pos col, char c);


private:
    pos cursor = 0;
    //pos height = 0;
    //pos width = 0;
    std::string contents;

    void do_display(std::ostream &os) const;
};

template<std::string::size_type height, std::string::size_type width>
inline
Screen<height,width> &Screen<height,width>::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

template<std::string::size_type height, std::string::size_type width>
inline
char& Screen<height,width>::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row+c];
}

template<std::string::size_type height, std::string::size_type width>
inline
Screen<height,width> &Screen<height,width>::set(char c){
    contents[cursor] = c; //set the character at the cursor to c
    return *this;
}

template<std::string::size_type height, std::string::size_type width>
inline
Screen<height,width> &Screen<height,width>::set(pos r, pos col, char c){
    contents[r*width + col] = c; //set the character at the cursor to c
    return *this;
}

template <std::string::size_type height, std::string::size_type width>
inline
void Screen<height, width>::do_display(std::ostream &os) const {
  for (pos i = 0; i != contents.size(); ++i) {
    os << contents[i];
    if ((i + 1) % width == 0 && i + 1 != contents.size())
      os << "\n";
  }
}

template <std::string::size_type height, std::string::size_type width>
std::ostream&
operator<<(std::ostream& os, Screen<height,width>& screen){
    screen.display(os);
    return os;
}

template <std::string::size_type height, std::string::size_type width>
std::istream& operator>>(std::istream& is, Screen<height,width> &screen){
    //This currently reads a single character from input into
    //the current location of the cursor.
    char c;
    is >> c;
    screen.set(c);
    return is;
}




//void Window_mgr::clear(ScreenIndex<height,width> i){
//    Screen &s = screens[i];
//    s.contents = std::string(s.height * s.width,' ');
//}




int main(){

    //Screen myScreen(5, 5, 'X');
    //myScreen.move(4,0).set('#').display(std::cout);
    //std::cout << '\n';
    //myScreen.display(std::cout);
    //std::cout << '\n';

    Screen<5,5> myScreen('.'); //a 5 x 5 screen filled with X
    //myScreen.display(std::cout);

    std::cout << myScreen << '\n';
    //std::cout << "Enter a character: " << std::endl;
    //std::cin >> myScreen;

    std::cout << "Enter x y coords for the screen, and a character: ";
    int x, y;
    std::cin >> x >> y;
    myScreen.move(x,y);
    std::cin >> myScreen;
    
    std::cout << myScreen << std::endl;




    return 0;
}