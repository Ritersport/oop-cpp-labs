#ifndef SHIPSFIGHT_HUGE_SHIP_H
#define SHIPSFIGHT_HUGE_SHIP_H


#include "Ship.h"
#include "../direction.h"

class Huge_ship : public Ship {
public:
    explicit Huge_ship(Direction dir);

    void finalize() override;
};


#endif //SHIPSFIGHT_HUGE_SHIP_H
