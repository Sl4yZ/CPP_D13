#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

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

const std::string image_def = "           .-'\"\"\"'-.\n"
                              "      ,____|_______|____,\n"
                              "       '._____________.'\n"
                              "           |.-- --.|\n"
                              "           |(o) (o)|\n"
                              "          (|       |)\n"
                              "           |   U   |\n"
                              " __        | .___. |\n"
                              "/|||       |       |\n"
                              "||||       :       :\n"
                              "|  |/)      `.___.'\n"
                              " \\  /       __) (__\n"
                              "  \\/\\      /\\ \\ / /\\\n"
                              "   \\ \\    /\\ \\ ^ / /\\\n"
                              "    \\ \\  / |  |0_/\\_ \\\n"
                              "     \\ \\/ /|  | \\  /\\ \\\n"
                              "      \\  / |  |0//\\\\ \\ \\\n"
                              "       \\/  | /   \\ |  \\ \\\n"
                              "           |/ .-. \\|  / /\n"
                              "        .-'|-( ~ )-| / /\n"
                              "        \\  |--`-'--|/ /\n"
                              "         \\ |       | /\n"
                              "          \\|   |   |/\n"
                              "           |   |   |\n"
                              "           |   |   |\n"
                              "           |   |   |\n"
                              "           |   |   |\n"
                              "           |   |   |\n"
                              "           |___|___|\n"
                              "          `|---|---|'\n"
                              "          *|   |   |*\n"
                              "           |_._|_._|\n"
                              "          /'  /|\\  '\\\n"
                              "         /   /^ ^\\   \\\n"
                              "        /__.'     `.__\\\n";

Test(Woody, new) {
    // OSRedirector oss(std::cout);
    // cr_assert_eq(oss.getContent(), "poney Created\n");

    Woody* woody = new Woody("Woody", "../media/alien.txt");
    Woody* def = new Woody("def");
    cr_assert(woody->getAscii() == image);
    cr_assert(woody->getType() == Toy::ToyType::WOODY);
    cr_assert(woody->getName() == "Woody");
    cr_assert(def->getAscii() == image_def);
    cr_assert(def->getName() == "def");
}

