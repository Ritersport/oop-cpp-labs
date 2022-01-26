#ifndef SHIPSFIGHT_CONSOLE_PAINTER_H
#define SHIPSFIGHT_CONSOLE_PAINTER_H


#include "IPainter.h"
#include "../game/Turn_result.h"
#include "../game/settings.h"
#include "../optionparser.h"


enum Cell_type {
    WATER = ' ',
    SHIP = '#',
    BROKEN_SHIP = '%'
};

class Console_painter : public IPainter {
public:
    void draw_ship(Ship &ship) override;

    void draw_prev_turns(Point point, Turn_result type) override;

    void draw_string(std::string string) override;

    void clear_buffer() override;

    void flush() override;

    void clear() override;

private:
    std::string string_buffer = std::string();

    char my_playfield[PLAYFIELD_WIDTH][PLAYFIELD_HEIGHT] = {0};
    char enemy_playfield[PLAYFIELD_WIDTH][PLAYFIELD_HEIGHT] = {0};

};


#endif //SHIPSFIGHT_CONSOLE_PAINTER_H
