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

Test(Speak, Toy) {
    OSRedirector oss(std::cout);

    Toy* toy = new Toy(Toy::ToyType::BASIC_TOY, "Emile", "jhefie");

    toy->speak("Bonjour ;)");
    cr_assert_eq(oss.getContent(), "Emile \"Bonjour ;)\"\n");
}

Test(Speak, Buzz) {
    OSRedirector oss(std::cout);

    Buzz* buzz = new Buzz("Eclair", "jhefie");

    buzz->speak("Je suis buzz ;)");
    cr_assert_eq(oss.getContent(), "BUZZ: Eclair \"Je suis buzz ;)\"\n");
}

Test(Speak, Woody) {
    OSRedirector oss(std::cout);

    Woody* woddy = new Buzz("Marionette", "jhefie");

    woddy->speak("Je suis woody ;)");
    cr_assert_eq(oss.getContent(), "WOODY: Marionette \"Je suis woody ;)\"\n");
}


