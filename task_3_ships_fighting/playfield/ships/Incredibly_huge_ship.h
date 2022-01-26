#ifndef SHIPSFIGHT_INCREDIBLY_HUGE_SHIP_H
#define SHIPSFIGHT_INCREDIBLY_HUGE_SHIP_H


#include "Ship.h"
#include "../direction.h"

class Incredibly_huge_ship : public Ship {
public:
    explicit Incredibly_huge_ship(Direction dir);

    void finalize() override;
};


#endif //SHIPSFIGHT_INCREDIBLY_HUGE_SHIP_H
