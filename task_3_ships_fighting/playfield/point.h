#ifndef SHIPSFIGHT_POINT_H
#define SHIPSFIGHT_POINT_H

#include <cstddef>

struct Point {
    int x = 0;
    int y = 0;

    Point operator+(const Point &a) const;

    Point operator-(const Point &other) const;
};

bool operator==(const Point &point1, const Point &point2);

bool operator!=(const Point &point1, const Point &point2);

Point operator*(const Point &point1, int val);

Point operator*(int val, const Point &point1);

#endif //SHIPSFIGHT_POINT_H
