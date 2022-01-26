#ifndef SHIPSFIGHT_SMOL_SHIP_H
#define SHIPSFIGHT_SMOL_SHIP_H


#include "Ship.h"
#include "../direction.h"

class Smol_ship : public Ship {
public:
    explicit Smol_ship(Direction dir);

    void finalize() override;
};


#endif //SHIPSFIGHT_SMOL_SHIP_H
