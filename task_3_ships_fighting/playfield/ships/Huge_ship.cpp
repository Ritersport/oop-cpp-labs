#include "Huge_ship.h"

Huge_ship::Huge_ship(Direction dir) : Ship(dir) {
}

void Huge_ship::finalize() {
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

    body.push_back(head);
    body.push_back(head + offset);
    body.push_back(head + offset * 2);
}
