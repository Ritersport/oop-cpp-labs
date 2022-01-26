#include "Incredibly_huge_ship.h"

Incredibly_huge_ship::Incredibly_huge_ship(Direction dir) : Ship(dir) {}

void Incredibly_huge_ship::finalize() {
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
    body.push_back(head + offset * 3);
}
