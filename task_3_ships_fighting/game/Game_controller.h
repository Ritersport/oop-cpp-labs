#ifndef SHIPSFIGHT_GAME_CONTROLLER_H
#define SHIPSFIGHT_GAME_CONTROLLER_H


#include "game_config.h"
#include "Ships_game.h"
#include "Game_stats.h"

class Game_controller {
public:
    explicit Game_controller(Game_config &config);

    ~Game_controller() = default;

    void run();

private:
    Game_config config;
    Ships_game game_core;
};


#endif //SHIPSFIGHT_GAME_CONTROLLER_H
