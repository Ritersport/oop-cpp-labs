#include "Optimal_player.h"


inline bool bounds(Point point) {
    return 0 <= point.x && point.x < PLAYFIELD_WIDTH && 0 <= point.y && point.y < PLAYFIELD_HEIGHT;
}

Point Optimal_player::do_turn() {
    if (point_queue.empty()) {
        last_shoot = random_shoot();
    } else {
        while (true) {
            if (point_queue.empty()) {
                last_shoot = random_shoot();
                break;
            }
            Point curr_point = point_queue.front();
            point_queue.pop();
            if (turn_history[curr_point.x][curr_point.y] != NONE) {
                continue;
            }
            last_shoot = curr_point;
            break;
        }
    }
    return last_shoot;
}

void Optimal_player::push_turn_result(Turn_result result) {
    turn_history[last_shoot.x][last_shoot.y] = result;
    last_result = result;

    if (result == HIT) {
        point_queue.push(last_shoot + Point{0, 1});
        point_queue.push(last_shoot + Point{0, -1});
        point_queue.push(last_shoot + Point{-1, 0});
        point_queue.push(last_shoot + Point{1, 0});
    }

    if (result == KILL) {
        find_mark_killed();
    }

}

void Optimal_player::add_context_info(std::shared_ptr<IPainter> &painter) {
    for (auto &i: my_ships) {
        painter->draw_ship(*i);
    }

    for (int y = 0; y < PLAYFIELD_HEIGHT; y++) {
        for (int x = 0; x < PLAYFIELD_WIDTH; x++) {
            painter->draw_prev_turns(Point{x, y}, turn_history[x][y]);
        }
    }
}

Optimal_player::Optimal_player() {
    verbose = true;
    for (int y = 0; y < PLAYFIELD_HEIGHT; y++) {
        for (int x = 0; x < PLAYFIELD_WIDTH; x++) {
            turn_history[x][y] = NONE;
        }
    }
}

void Optimal_player::find_mark_killed() {
    std::queue<Point> empty;
    std::swap(point_queue, empty);

    std::queue<Point> queue;
    queue.push(last_shoot);

    while (true) {
        if (queue.empty()) {
            break;
        }

        Point curr_point = queue.front();
        queue.pop();

        switch (turn_history[curr_point.x][curr_point.y]) {
            case HIT: {
                turn_history[curr_point.x][curr_point.y] = KILL;
                break;
            }
            case NONE: {
                turn_history[curr_point.x][curr_point.y] = MISS;
                break;
            }
            default: {
                break;
            }
        }

        if (turn_history[curr_point.x][curr_point.y] == KILL) {
            Point point = curr_point + Point{0, -1};
            if (bounds(point) && turn_history[point.x][point.y] != KILL && turn_history[point.x][point.y] != MISS) {
                queue.push(point);
            }

            point = curr_point + Point{0, 1};
            if (bounds(point) && turn_history[point.x][point.y] != KILL && turn_history[point.x][point.y] != MISS) {
                queue.push(point);
            }

            point = curr_point + Point{-1, 0};
            if (bounds(point) && turn_history[point.x][point.y] != KILL && turn_history[point.x][point.y] != MISS) {
                queue.push(point);
            }

            point = curr_point + Point{1, 0};
            if (bounds(point) && turn_history[point.x][point.y] != KILL && turn_history[point.x][point.y] != MISS) {
                queue.push(point);
            }

            point = curr_point + Point{1, -1};
            if (bounds(point) && turn_history[point.x][point.y] != KILL && turn_history[point.x][point.y] != MISS) {
                queue.push(point);
            }

            point = curr_point + Point{-1, -1};
            if (bounds(point) && turn_history[point.x][point.y] != KILL && turn_history[point.x][point.y] != MISS) {
                queue.push(point);
            }

            point = curr_point + Point{1, 1};
            if (bounds(point) && turn_history[point.x][point.y] != KILL && turn_history[point.x][point.y] != MISS) {
                queue.push(point);
            }

            point = curr_point + Point{-1, 1};
            if (bounds(point) && turn_history[point.x][point.y] != KILL && turn_history[point.x][point.y] != MISS) {
                queue.push(point);
            }
        }
    }
}

