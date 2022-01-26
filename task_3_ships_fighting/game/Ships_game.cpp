#include "Ships_game.h"
#include <iostream>
#include "../players/Player_factory.h"

Ships_game::Ships_game(Game_config &config) {
    players.push_back(Player_factory::getInstance().create(config.player1_type));
    players.push_back(Player_factory::getInstance().create(config.player2_type));
}

Game_stats Ships_game::run() {
    Game_stats stats = Game_stats();
    init();

    while (tick()) {
        stats.steps++;
    }

    for (int i = 0; i < players.size(); i++) {
        if (players[i]->get_ships_left() != 0) {
            stats.winner = i;
            break;
        }
    }
    return stats;
}

bool Ships_game::tick() {

    for(size_t i = 0; i < players.size(); i++) {
        size_t turning_id = i % players.size();
        size_t attacking_id = (i + 1) % players.size();

        perform_turn(turning_id, attacking_id);

        if(players[attacking_id]->get_ships_left() == 0) {
            return false;
        }
    }
    return true;
}

void Ships_game::init() {
    for (auto &i: players) {
        i->init_playfield(painter);
    }
}

void Ships_game::perform_turn(size_t turning_id, size_t attacking_id) {
    painter->clear();

    //first player turn
    if (players[turning_id]->if_verbose()) {
        players[turning_id]->add_context_info(painter);
        painter->flush();
    }
    Turn_result result = players[attacking_id]->get_turn_result(players[turning_id]->do_turn());
    players[turning_id]->push_turn_result(result);
}
