#include <algorithm>
#include "Ship.h"

bool Ship::if_collide(const Point &point) {
    for (auto i: body) {
        if (i == point) { return true; }
    }
    return false;
}

Ship::Ship(Direction direction) {
    dir = direction;
}

void Ship::set_x(size_t x) {
    head.x = x;
}

void Ship::set_y(size_t y) {
    head.y = y;
}

void Ship::set_head(Point p) {
    head = p;
}

std::vector<Point> &Ship::get_body() {
    return body;
}

bool Ship::on_collide(Point point) {
    bool result = false;
    for(int i = 0; i < body.size(); i++) {
        if(body[i] == point) {
            result = true;
            hits[i] = true;
        }
    }
    return result;
}

bool Ship::is_dead() {
    bool result = true;
    for(int i = 0; i < body.size(); i++) {
        result &= hits[i];
    }
    return result;
}
