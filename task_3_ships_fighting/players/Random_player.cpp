#include "Random_player.h"

Point Random_player::do_turn() {
    last_shoot = random_shoot();
    return last_shoot;
}

void Random_player::push_turn_result(Turn_result result) {
    turn_history[last_shoot.x][last_shoot.y] = result;
}

void Random_player::add_context_info(std::shared_ptr<IPainter> &painter) {
    for (auto &i: my_ships) {
        painter->draw_ship(*i);
    }

}
