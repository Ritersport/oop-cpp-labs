#ifndef SHIPSFIGHT_OPTIMAL_PLAYER_H
#define SHIPSFIGHT_OPTIMAL_PLAYER_H


#include <queue>
#include "Player.h"

class Optimal_player : public Player {
public:
    Optimal_player();

    ~Optimal_player() override = default;
    Point do_turn() override;
    void push_turn_result(Turn_result result) override;
    void add_context_info(std::shared_ptr<IPainter> &painter) override;

private:
    Turn_result last_result = NONE;
    std::queue<Point> point_queue;
    Point last_hit = Point{-1, -1};

    void find_mark_killed();
};


#endif //SHIPSFIGHT_OPTIMAL_PLAYER_H
