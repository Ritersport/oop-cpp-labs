#include "Player_factory.h"
#include "Random_player.h"
#include "Console_player.h"
#include "Optimal_player.h"

bool Player_factory::contains_player(std::string &player_type) {
    return creators.end() != creators.find(player_type);
}

std::unique_ptr<Player> Player_factory::create(const std::string &id) {
    return creators[id]();
}

Player_factory::Player_factory() {
    creators.insert(std::make_pair(std::string("random"), [] { return std::make_unique<Random_player>(); }));
    creators.insert(std::make_pair(std::string("console"), [] { return std::make_unique<Console_player>(); }));
    creators.insert(std::make_pair(std::string("optimal"), [] { return std::make_unique<Optimal_player>(); }));
}
