#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "Toy.hpp"

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

std::string expected = "Emile\n"
                  "         _|_\n"
                  "   ,_.-_' _ '_-._,\n"
                  "    \\ (.)(.)(.) /\n"
                  " _,  `\\_-===-_/`  ,_\n"
                  ">  |----\"\"\"\"\"----|  <\n"
                  "`\"\"`--/   _-@-\\--`\"\"`\n"
                  "     |===L_I===|\n"
                  "      \\       /\n"
                  "      _\\__|__/_\n"
                  "     `\"\"\"\"`\"\"\"\"`\n\n";

Test(Operator, Toy) {
    OSRedirector oss(std::cout);

    Toy toy(Toy::ToyType::BASIC_TOY, "Emile", "../media/alien.txt");
    std::cout << toy << std::endl;
    cr_assert_eq(oss.getContent(), expected);
    toy << "////LOL";
    cr_assert(toy.getAscii() == "////LOL");
}

