#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "Buzz.hpp"
#include "Woody.hpp"
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

Test(Speak_Es, Toy) {
    OSRedirector oss(std::cout);

    Toy* toy = new Toy(Toy::ToyType::BASIC_TOY, "Emile", "jhefie");
    bool status = toy->speak_es("Bonjour ;)");
    cr_assert_eq(oss.getContent(), "");
    cr_assert(status == false);

    auto e = toy->getLastError();
    cr_assert(e.type == Toy::Error::SPEAK);
    cr_assert(e.where() == "speak_es");
    cr_assert(e.what() == "wrong mode");
}

Test(Speak_Es, Buzz) {
    OSRedirector oss(std::cout);

    Buzz* buzz = new Buzz("Eclair", "jhefie");
    bool status = buzz->speak_es("Je suis buzz ;)");
    cr_assert_eq(oss.getContent(), "BUZZ: Eclair senorita \"Je suis buzz ;)\" senorita\n");
    cr_assert(status == true);

    auto e = buzz->getLastError();
    cr_assert(e.type == Toy::Error::UNKNOWN);
    cr_assert(e.where() == "");
    cr_assert(e.what() == "");
}

Test(Speak_Es, Woody) {
    OSRedirector oss(std::cout);

    Woody* woddy = new Woody("Marionette", "jhefie");
    bool status = woddy->speak("Je suis woody ;)");
    cr_assert_eq(oss.getContent(), "");
    cr_assert(status == false);

    auto e = woody->getLastError();
    cr_assert(e.type == Toy::Error::SPEAK);
    cr_assert(e.where() == "speak_es");
    cr_assert(e.what() == "wrong mode");
}


