#ifndef SHIPSFIGHT_IPAINTER_H
#define SHIPSFIGHT_IPAINTER_H

#include <string>
#include "../playfield/ships/Ship.h"
#include "../game/Turn_result.h"

class IPainter {
public:
    virtual void draw_ship(Ship &ship) = 0;

    virtual void draw_prev_turns(Point point, Turn_result type) = 0;

    virtual void draw_string(std::string string) = 0;

    virtual void flush() = 0;

    virtual void clear_buffer() = 0;

    virtual void clear() = 0;
};

#endif //SHIPSFIGHT_IPAINTER_H
