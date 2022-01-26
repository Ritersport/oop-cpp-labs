#ifndef SHIPSFIGHT_SHIPS_GAME_H
#define SHIPSFIGHT_SHIPS_GAME_H

#include <vector>
#include <memory>
#include "game_config.h"
#include "Game_stats.h"
#include "../players/Player.h"
#include "../ui/Console_painter.h"

class Ships_game {
public:
    explicit Ships_game(Game_config &config);

    Game_stats run();

private:
    void init();

    bool tick();

    std::shared_ptr<IPainter> painter = std::make_shared<Console_painter>();
    std::vector<std::unique_ptr<Player>> players;

    void perform_turn(size_t turning_id, size_t attacking_id);
};

#endif //SHIPSFIGHT_SHIPS_GAME_H



