#include "Ships_factory.h"

#include <memory>
#include "Smol_ship.h"
#include "Big_ship.h"
#include "Huge_ship.h"
#include "Incredibly_huge_ship.h"

std::unique_ptr<Ship> Ships_factory::create(Ship_type type, Direction dir) {
    return creators[type](dir);
}

Ships_factory::Ships_factory() {
    creators.insert(std::make_pair(SMOL, [](Direction dir) { return std::make_unique<Smol_ship>(dir); }));
    creators.insert(std::make_pair(BIG, [](Direction dir) { return std::make_unique<Big_ship>(dir); }));
    creators.insert(std::make_pair(HUGE, [](Direction dir) { return std::make_unique<Huge_ship>(dir); }));
    creators.insert(std::make_pair(INCREDIBLY_HUGE, [](Direction dir) {
        return std::make_unique<Incredibly_huge_ship>(dir);
    }));
}
