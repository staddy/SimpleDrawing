#include "Utils.h"

namespace SimpleDrawing {

    const Color Color::Black = {0, 0, 0};
    const Color Color::White = {255, 255, 255};
    const Color Color::Red = {255, 0, 0};
    const Color Color::Green = {0, 255, 0};
    const Color Color::Blue = {0, 0, 255};
    const Color Color::Yellow = {255, 255, 0};
    const Color Color::Cian = {0, 255, 255};
    const Color Color::Magenta = {255, 0, 255};

    Point operator+(const Point &i_left, const Point &i_right) {
        return {i_left.x + i_right.x, i_left.y + i_right.y};
    }

    Point operator-(const Point &i_left, const Point &i_right) {
        return {i_left.x - i_right.x, i_left.y - i_right.y};
    }

}