#ifndef SHIPSFIGHT_SHIPS_FACTORY_H
#define SHIPSFIGHT_SHIPS_FACTORY_H


#include <string>
#include <memory>
#include <unordered_map>
#include <functional>
#include "Ship.h"
#include "Ship_type.h"
#include "../direction.h"

class Ships_factory {
public:
    std::unique_ptr<Ship> create(Ship_type type, Direction);

    static Ships_factory &getInstance() {
        static Ships_factory instance;
        return instance;
    }

    Ships_factory(Ships_factory const &) = delete;

    void operator=(Ships_factory const &) = delete;

private:
    Ships_factory();

    std::unordered_map<Ship_type, std::function<std::unique_ptr<Ship>(Direction dir)>> creators;
};


#endif //SHIPSFIGHT_SHIPS_FACTORY_H
