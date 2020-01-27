#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "Picture.hpp"

class OSRedirector {
    private:
        std::ostringstream _oss;
        std::streambuf *_backup;
        std::ostream &_c;


    public:
        OSRedirector(std::ostream &c) : _c(c) {
            _backup = _c.rdbuf();
            _c.rdbuf(_oss.rdbuf());
        }

        ~OSRedirector() {
            _c.rdbuf(_backup);
        }

        const std::string getContent() {
            _oss << std::flush;
            return _oss.str();
        }
};

const std::string image = "         _|_\n"
              "   ,_.-_' _ '_-._,\n"
              "    \\ (.)(.)(.) /\n"
              " _,  `\\_-===-_/`  ,_\n"
              ">  |----\"\"\"\"\"----|  <\n"
              "`\"\"`--/   _-@-\\--`\"\"`\n"
              "     |===L_I===|\n"
              "      \\       /\n"
              "      _\\__|__/_\n"
              "     `\"\"\"\"`\"\"\"\"`\n";


Test(Picture, new_from_file) {
    Picture* pic = new Picture("../media/alien.txt");
    cr_assert(pic->data == image);

    Picture* wrong = new Picture("ezuiehuizheu");
    cr_assert(wrong->data == "ERROR");
}

Test(Picture, getFromFile) {
    Picture* pic = new Picture("jjjj");
    bool status = pic->getPictureFromFile("../media/alien.txt");
    cr_assert(pic->data == image);
    cr_assert(status == true);
    status = pic->getPictureFromFile("kjeioioeji");
    cr_assert(pic->data == "ERROR");
    cr_assert(status == false);
}