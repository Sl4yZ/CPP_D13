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

Test(Toy, new) {
    // OSRedirector oss(std::cout);
    // cr_assert_eq(oss.getContent(), "poney Created\n");

    Toy* toy = new Toy();
    cr_assert(toy->getType() == Toy::ToyType::BASIC_TOY);
    cr_assert(toy->getName() == "toy");
    cr_assert(toy->getAscii() == "");

    Toy* alien = new Toy(Toy::ToyType::ALIEN, "Alien", "../media/alien.txt");
    cr_assert(alien->getType() == Toy::ToyType::ALIEN);
    cr_assert(alien->getName() == "Alien");
    cr_assert(alien->getAscii() == image);

    Toy* wrong = new Toy(Toy::ToyType::BASIC_TOY, "Wrong Toy", "jhziuhu");
    cr_assert(wrong->getType() == Toy::ToyType::BASIC_TOY);
    cr_assert(wrong->getName() == "Wrong Toy");
    cr_assert(wrong->getAscii() == "ERROR");
}

Test(Toy, getType) {
    Toy* alien = new Toy(Toy::ToyType::ALIEN, "Alien", "../media/alien.txt");
    cr_assert(alien->getType() == Toy::ToyType::ALIEN);
    delete alien;
}

Test(Toy, getName) {
    Toy* alien = new Toy(Toy::ToyType::ALIEN, "Alien", "../media/alien.txt");
    cr_assert(alien->getName() == "Alien");
}

Test(Toy, setName) {
    Toy* alien = new Toy(Toy::ToyType::ALIEN, "Alien", "../media/alien.txt");
    cr_assert(alien->getName() == "Alien");
    alien->setName("Emile");
    cr_assert(alien->getName() == "Emile");
}


Test(Toy, getAscii) {
    Toy* alien = new Toy(Toy::ToyType::ALIEN, "Alien", "../media/alien.txt");
    cr_assert(alien->getAscii() == image);
}

Test(Toy, setAscii) {
    Toy* alien = new Toy(Toy::ToyType::ALIEN, "Alien", "jzhi");
    cr_assert(alien->getAscii() == "ERROR");
    alien->setAscii("../media/alien.txt");
    cr_assert(alien->getAscii() == image);
}


Test(Toy, duplicate) {
    Toy* alien = new Toy(Toy::ToyType::ALIEN, "Alien", "../media/alien.txt");
    Toy* copy = alien;

    cr_assert(alien->getAscii() == copy->getAscii());
    cr_assert(alien->getName() == copy->getName());
    cr_assert(alien->getType() == copy->getType());
}