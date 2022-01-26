#ifndef SHIPSFIGHT_RANDOM_PLAYER_H
#define SHIPSFIGHT_RANDOM_PLAYER_H


#include "Player.h"

class Random_player : public Player {
public:
    Random_player() = default;

    ~Random_player() override = default;

    Point do_turn() override;
    void push_turn_result(Turn_result result) override;
    void add_context_info(std::shared_ptr<IPainter> &painter) override;
};


#endif //SHIPSFIGHT_RANDOM_PLAYER_H
