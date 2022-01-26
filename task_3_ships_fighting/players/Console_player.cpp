#include <iostream>
#include "Console_player.h"
#include "../playfield/ships/Ships_factory.h"

Point Console_player::do_turn() {
    int x = 0;
    char y = 0;


    while (true) {
        printf("type your coords, firstly y, then x (like this: a 0):\n");

        scanf("%c %d", &y, &x);


        if ('a' <= y && y <= 'z') {
            y -= 'a';
        } else if ('A' <= y && y <= 'Z') {
            y -= 'A';
        }

        if (0 <= x && x < PLAYFIELD_WIDTH && 0 <= y && y < PLAYFIELD_HEIGHT) {
            break;
        } else {
            printf("Unacceptable coordinates\n");
            continue;
        }
    }

    last_shoot = Point{x, y};
    return last_shoot;
}


void Console_player::push_turn_result(Turn_result result) {
    turn_history[last_shoot.x][last_shoot.y] = result;
}

void Console_player::add_context_info(std::shared_ptr<IPainter> &painter) {
    for (auto &i: my_ships) {
        painter->draw_ship(*i);
    }

    for (int y = 0; y < PLAYFIELD_HEIGHT; y++) {
        for (int x = 0; x < PLAYFIELD_WIDTH; x++) {
            painter->draw_prev_turns(Point{x, y}, turn_history[x][y]);
        }
    }
}

Console_player::Console_player() {
    verbose = true;
}

void Console_player::init_playfield(std::shared_ptr<IPainter> &painter) {
    for (auto i: available_ships) {
        int x = 0;
        char y = 0;
        char dir = 0;
        Direction actual_dir = UP;
        std::string ship_type = type_to_string(i);
        painter->clear();
        for (auto &s: my_ships) {
            painter->draw_ship(*s);
        }
        painter->flush();

        while (true) {
            printf("Now placing %s ship\nPlace your ship, enter ship head coordinates and direction (like this: a 0 d),\nAvailable directions u - up, r - right, l - left, d - down:\n",
                   ship_type.c_str());


            scanf("%c %d %c", &y, &x, &dir);

            if ('a' <= y && y <= 'z') {
                y -= 'a';
            } else if ('A' <= y && y <= 'Z') {
                y -= 'A';
            }


            switch (dir) {
                case 'd': {
                    actual_dir = UP;
                    break;
                }
                case 'r': {
                    actual_dir = LEFT;
                    break;
                }
                case 'l': {
                    actual_dir = RIGHT;
                    break;
                }
                case 'u': {
                    actual_dir = DOWN;
                    break;
                }
                default: {
                    dir = -1;
                    break;
                }
            }

            if (!(0 <= x && x < PLAYFIELD_WIDTH && 0 <= y && y < PLAYFIELD_HEIGHT && dir != -1)) {
                printf("Unacceptable coordinates\n");
                continue;
            }

            auto tmp_ship = Ships_factory::getInstance().create(i, actual_dir);
            tmp_ship->set_head(Point{x, y});
            tmp_ship->finalize();
            if (!validate_ship(*tmp_ship)) {
                printf("Unable to place ship, thy other coordinates\n");
            } else {
                my_ships.push_back(std::move(tmp_ship));
                break;
            }
        }


    }

}

std::string Console_player::type_to_string(Ship_type type) {
    switch (type) {
        case SMOL: {
            return std::string{"smol"};
        }
        case BIG: {
            return std::string{"big"};
        }
        case HUGE: {
            return std::string{"huge"};
        }
        case INCREDIBLY_HUGE: {
            return std::string{"incredibly huge"};
        }

    }
}
