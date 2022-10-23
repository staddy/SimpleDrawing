#ifndef DRAWING_SQUARE_H
#define DRAWING_SQUARE_H


#include "Rectangle.h"

namespace SimpleDrawing {

    class Square : public Rectangle {
    public:
        Square(const Point &i_point, size_t i_size);
    };

}

#endif //DRAWING_SQUARE_H
