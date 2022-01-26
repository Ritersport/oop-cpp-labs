#include "Big_ship.h"

Big_ship::Big_ship(Direction dir) : Ship(dir) {}

void Big_ship::finalize() {
    body.clear();
    Point offset;
    switch (dir) {
        case UP: {
            offset = Point{0, 1};
            break;
        }
        case RIGHT: {
            offset = Point{-1, 0};
            break;
        }
        case DOWN: {
            offset = Point{0, -1};
            break;
        }
        case LEFT: {
            offset = Point{1, 0};
            break;
        }
    }

    body.push_back(head + offset * 0);
    body.push_back(head + offset * 1);
}

