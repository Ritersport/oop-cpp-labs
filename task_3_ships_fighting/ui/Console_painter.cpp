#include <cstring>
#include <iostream>
#include "Console_painter.h"


void clear_cli() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void Console_painter::clear() {
    string_buffer.clear();

    memset(my_playfield, ' ', PLAYFIELD_HEIGHT * PLAYFIELD_WIDTH);
    memset(enemy_playfield, ' ', PLAYFIELD_HEIGHT * PLAYFIELD_WIDTH);

    clear_cli();
}

void Console_painter::flush() {
    fflush(stdout);
    printf("  0 1 2 3 4 5 6 7 8 9     0 1 2 3 4 5 6 7 8 9\n");
    printf(" _____________________   _____________________\n");
    char heading_symbol = 'a';
    for (size_t y = 0; y < PLAYFIELD_HEIGHT; y++) {

        printf("%c", heading_symbol);
        heading_symbol++;
        printf("|");

        for (auto &x: my_playfield) {
            printf("%c|", x[y]);
        }

        printf("   ");
        printf("|");
        for (auto &x: enemy_playfield) {
            printf("%c|", x[y]);
        }
        printf("\n");
        if (y != PLAYFIELD_HEIGHT - 1) {
            printf(" |=|=|=|=|=|=|=|=|=|=|   |=|=|=|=|=|=|=|=|=|=|");
            printf("\n");
        }
    }
    printf(" ---------------------   ---------------------");
    std::cout << string_buffer << std::endl;

}

void Console_painter::draw_ship(Ship &ship) {
    for (auto i: ship.get_body()) {
        my_playfield[i.x][i.y] = '#';
    }
}

void Console_painter::draw_prev_turns(Point point, Turn_result type) {
    enemy_playfield[point.x][point.y] = type;
}

void Console_painter::draw_string(std::string string) {

}

void Console_painter::clear_buffer() {
    string_buffer.clear();

    memset(my_playfield, ' ', PLAYFIELD_HEIGHT * PLAYFIELD_WIDTH);
    memset(enemy_playfield, ' ', PLAYFIELD_HEIGHT * PLAYFIELD_WIDTH);
}
