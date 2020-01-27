#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "Buzz.hpp"
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

const std::string image_def = "                                                  .\n"
                              "                                                 //\n"
                              "                          ___                   ////\n"
                              "                       .-'___`-.               |  |\n"
                              "                     .' .'_ _'. '.            /~~/\n"
                              "                     | (| b d |) |          /.    /\n"
                              "                     |  |  '  |  |         /..  /\n"
                              ",                   ,|  | `-' |  |,       /   ./\n"
                              "|'-------------''\"\"/.|  /\\___/\\  |.\\\"\"''-/   (/------'|\n"
                              "|            ____ _.-'\\   /   '-._____.-'   \\         |\n"
                              "|.----------/   ._| _    .---. ===  |_.'\\   /--------.|\n"
                              "'          / \\  | |\\_\\ _ \\=v=/  _   | |  \\ /          '\n"
                              "          /   \\ | | \\_\\_\\ ~~~  (_)  | |  .'\n"
                              "         /_.-'/ \"'|`'--.__.^.__.--'`|'\"'`\n"
                              "        (    /    \\                 /\n"
                              "        \\__.-:     `,..---'\"'---..,'\n"
                              "         \\'  |       :--..___..--:\n"
                              "          \\~~|        \\         /\n"
                              "          /   \\       |`.     .'|\n"
                              "          |  ||       |  :___:  |\n"
                              "          ||||_       |   | |   |\n"
                              "          ||||        |   | |   |\n"
                              "          ````        |.-.| |.-.|\n"
                              "                      |`-'| |`-'|\n"
                              "                      |   | |   |\n"
                              "                     /    | |    \\\n"
                              "                    |_____| |_____|\n"
                              "                    ':---:-'-:---:'\n"
                              "                    /    |   |    \\\n"
                              "                   /.---.|   |.---.\\\n"
                              "                   `.____;   :____.'\n";

Test(Buzz, new) {
    // OSRedirector oss(std::cout);
    // cr_assert_eq(oss.getContent(), "poney Created\n");

    Buzz* buzz = new Buzz("Buzz", "../media/alien.txt");
    Buzz* def = new Buzz("def");
    cr_assert(buzz->getAscii() == image);
    cr_assert(buzz->getType() == Toy::ToyType::BUZZ);
    cr_assert(buzz->getName() == "Buzz");
    cr_assert(def->getAscii() == image_def);
    cr_assert(def->getName() == "def");
}

