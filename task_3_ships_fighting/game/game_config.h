#ifndef SHIPSFIGHT_GAME_CONFIG_H
#define SHIPSFIGHT_GAME_CONFIG_H

#include <cstddef>
#include <string>

struct Game_config {
    std::string player1_type = "random";
    std::string player2_type = "random";
    size_t rounds = 1;
};

#endif //SHIPSFIGHT_GAME_CONFIG_H
