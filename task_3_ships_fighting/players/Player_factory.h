#ifndef SHIPSFIGHT_PLAYER_FACTORY_H
#define SHIPSFIGHT_PLAYER_FACTORY_H


#include <string>
#include <memory>
#include <unordered_map>
#include <functional>
#include "Player.h"

class Player_factory {
public:
    bool contains_player(std::string &player_type);
    std::unique_ptr<Player> create(const std::string &id);


    static Player_factory &getInstance() {
        static Player_factory instance;
        return instance;
    }

    Player_factory(Player_factory const &) = delete;

    void operator=(Player_factory const &) = delete;

private:
    Player_factory();

    std::unordered_map<std::string, std::function<std::unique_ptr<Player>()>> creators;
};


#endif //SHIPSFIGHT_PLAYER_FACTORY_H
