#include "Smol_ship.h"

Smol_ship::Smol_ship(Direction dir) : Ship(dir) {

}

void Smol_ship::finalize() {
    body.clear();
    body.push_back(head);
}
