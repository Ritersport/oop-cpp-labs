cmake_minimum_required(VERSION 3.21)
project(ShipsFight)

set(CMAKE_CXX_STANDARD 14)

add_executable(ships main.cpp game/Ships_game.cpp game/Ships_game.h playfield/direction.h game/game_config.h arg_checker.h players/Player_factory.cpp players/Player_factory.h players/Player.h players/Random_player.cpp players/Random_player.h players/Console_player.cpp players/Console_player.h players/Optimal_player.cpp players/Optimal_player.h playfield/ships/Ship.h playfield/ships/Ships_factory.cpp playfield/ships/Ships_factory.h playfield/ships/Ship_type.h playfield/ships/Smol_ship.cpp playfield/ships/Smol_ship.h playfield/ships/Huge_ship.cpp playfield/ships/Huge_ship.h playfield/ships/Big_ship.cpp playfield/ships/Big_ship.h playfield/ships/Incredibly_huge_ship.cpp playfield/ships/Incredibly_huge_ship.h game/Game_controller.cpp game/Game_controller.h game/Game_stats.h playfield/point.cpp playfield/point.h playfield/ships/Ship.cpp players/Player.cpp playfield/direction.cpp ui/IPainter.h ui/Console_painter.cpp ui/Console_painter.h game/Turn_result.h game/settings.h)
