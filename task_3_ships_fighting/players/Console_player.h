#ifndef SHIPSFIGHT_CONSOLE_PLAYER_H
#define SHIPSFIGHT_CONSOLE_PLAYER_H


#include "Player.h"

class Console_player : public Player {
public:
    Console_player();

    ~Console_player() override = default;

    Point do_turn() override;

    void push_turn_result(Turn_result result) override;

    void add_context_info(std::shared_ptr<IPainter> &painter) override;

    void init_playfield(std::shared_ptr<IPainter> &painter) override;

private:
    static std::string type_to_string(Ship_type type);
};


#endif //SHIPSFIGHT_CONSOLE_PLAYER_H
