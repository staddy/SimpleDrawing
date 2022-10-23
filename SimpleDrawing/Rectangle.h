#ifndef DRAWING_RECTANGLE_H
#define DRAWING_RECTANGLE_H


#include "Polygon.h"

namespace SimpleDrawing {

    class Rectangle : public Polygon {
    public:
        Rectangle(const Point &i_position, size_t i_width, size_t i_height);

    };

}

#endif //DRAWING_RECTANGLE_H
