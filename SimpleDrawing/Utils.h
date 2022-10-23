#ifndef DRAWING_UTILS_H
#define DRAWING_UTILS_H

#include <cstddef>

namespace SimpleDrawing {

    struct Point {
        size_t x{0};
        size_t y{0};

        Point() = default;

        Point(size_t i_x, size_t i_y) : x{i_x}, y{i_y} {}
    };

    Point operator+(const Point &i_left, const Point &i_right);

    Point operator-(const Point &i_left, const Point &i_right);

    struct Color {
        unsigned char blue{0};
        unsigned char green{0};
        unsigned char red{0};

        Color() = default;

        Color(unsigned char i_red, unsigned char i_green, unsigned char i_blue) : red{i_red}, green{i_green},
                                                                                  blue{i_blue} {}

        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color Yellow;
        static const Color Cian;
        static const Color Magenta;
    };

}

#endif //DRAWING_UTILS_H
