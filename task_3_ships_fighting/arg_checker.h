#include <cstdio>
#include <cstdlib>
#include "optionparser.h"
#include "players/Player_factory.h"


#ifndef SHIPSFIGHT_ARG_CHECKER_H
#define SHIPSFIGHT_ARG_CHECKER_H


struct Arg_Checker : public option::Arg {
    static void printError(const char *msg1, const option::Option &opt, const char *msg2) {
        fprintf(stderr, "ERROR: %s", msg1);
        fwrite(opt.name, opt.namelen, 1, stderr);
        fprintf(stderr, "%s", msg2);
    }

    static option::ArgStatus optional_player_type(const option::Option &option, bool msg) {
        if (option.arg && option.name[option.namelen] != 0) {
            std::string arg = std::string(option.arg);
            if (Player_factory::getInstance().contains_player(arg)) {
                return option::ARG_OK;
            } else {
                if (msg) {
                    fprintf(stderr, "Player type: '%s' not found\n", option.arg);
                }
                return option::ARG_ILLEGAL;
            }
        } else {
            return option::ARG_IGNORE;
        }
    }

    static option::ArgStatus optional_numeric(const option::Option &option, bool msg) {
        if (option.arg && option.name[option.namelen] != 0) {
            char *endptr = nullptr;
            if (option.arg != nullptr && strtol(option.arg, &endptr, 10)) {}

            if (endptr != option.arg && *endptr == 0) { return option::ARG_OK; }

            if (msg) { printError("Option '", option, "' requires a numeric argument\n"); }
            return option::ARG_ILLEGAL;
        } else {
            if (option.name[option.namelen] == 0) {
                if (msg) { printError("Option '", option, "' requires a numeric argument\n"); }
                return option::ARG_ILLEGAL;
            }
            return option::ARG_IGNORE;
        }
    }
};

#endif //SHIPSFIGHT_ARG_CHECKER_H
