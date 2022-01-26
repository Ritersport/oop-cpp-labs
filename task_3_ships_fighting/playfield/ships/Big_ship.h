#ifndef SHIPSFIGHT_BIG_SHIP_H
#define SHIPSFIGHT_BIG_SHIP_H


#include "Ship.h"
#include "../direction.h"

class Big_ship : public Ship {
public:
    explicit Big_ship(Direction dir);

    void finalize() override;

};


#endif //SHIPSFIGHT_BIG_SHIP_H
