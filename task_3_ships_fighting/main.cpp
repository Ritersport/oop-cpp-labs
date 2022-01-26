#include <iostream>
#include <ctime>
#include "optionparser.h"
#include "game/game_config.h"
#include "arg_checker.h"
#include "game/Game_controller.h"

enum optionIndex {
    UNKNOWN, HELP, PLAYER_1_TYPE, PLAYER_2_TYPE, COUNT
};

const option::Descriptor usage[] =
        {
                {UNKNOWN,       0, "",      "",       option::Arg::None,                 "USAGE: ships [options]\n\n"
                                                                                         "Options:"},
                {HELP,          0, "",     "help",   option::Arg::None,                 "   --help  \tPrint usage and exit."},
                {PLAYER_1_TYPE, 0, "",     "first",  Arg_Checker::optional_player_type, "   --first=<random|optimal|console> \tfirst player type"},
                {PLAYER_2_TYPE, 0, "",     "second", Arg_Checker::optional_player_type, "   --second=<random|optimal|console> \tsecond player type"},
                {COUNT,         0, "",     "count",  Arg_Checker::optional_numeric,     "   --count=<number_of_rounds> \tNumber of rounds in series"},
                {0,             0, nullptr, nullptr,  nullptr,                           nullptr}

        };


int main(int argc, char *argv[]) {
    //ignoring program name
    srand(time(NULL));
    argc -= (argc > 0);
    argv += (argc > 0);

    option::Stats stats(usage, argc, argv);
    option::Option options[stats.options_max], buffer[stats.buffer_max];
    option::Parser parse(usage, argc, argv, options, buffer);

    if (parse.error()) {
        std::cout << "Arguments parsing error" << std::endl;
        option::printUsage(std::cout, usage);
        return 1;
    }

    if (options[HELP] || argc == 0) {
        option::printUsage(std::cout, usage);
        return 0;
    }

    //prepare game config
    Game_config config = Game_config();
    if (options[PLAYER_1_TYPE]) {
        config.player1_type = std::string(options[PLAYER_1_TYPE].arg);
    }

    if (options[PLAYER_2_TYPE]) {
        config.player2_type = std::string(options[PLAYER_2_TYPE].arg);
    }

    if (options[COUNT]) {
        long count = strtol(options[COUNT].arg, nullptr, 10);
        if (count >= 1) {
            config.rounds = count;
        }
    }
    Game_controller(config).run();
    return 0;
}