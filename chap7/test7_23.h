#ifndef CP5_test_7_23_h
#define CP5_test_7_23_h

#include <iostream>
#include <string>

class Screen {
    public:
        typedef std::string::size_type pos;
        //using pos = std::string::size_type;

        Screen() = default;
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c) {  }

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const {return contents[r*width+c]; }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

#endif
