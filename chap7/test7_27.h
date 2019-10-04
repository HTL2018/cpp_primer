#ifndef CP5_test_7_27_h
#define CP5_test_7_27_h

#include <iostream>
#include <string>

class Screen {
    public:
        typedef std::string::size_type pos;
        //using pos = std::string::size_type;

        Screen() = default;
        Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' ') { }
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c) {  }

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const {return contents[r*width+c]; }

        Screen &move(pos r, pos c);
        Screen &set(char);

        Screen &display(std::ostream &os)
        {
            do_display(os); return *this;
        }
        const Screen &display(std::ostream &os) const
        {
            do_display(os); return *this;
        }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
        void do_display(std::ostream &os) const {os << contents;}
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

#endif
