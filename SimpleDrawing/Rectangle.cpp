#include "Rectangle.h"

namespace SimpleDrawing {

    Rectangle::Rectangle(const Point &i_position, size_t i_width, size_t i_height) : Polygon(
            {i_position, i_position + Point{i_width, 0}, i_position + Point{i_width, i_height},
             i_position + Point{0, i_height}}) {}

}
