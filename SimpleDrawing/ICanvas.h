#ifndef DRAWING_ICANVAS_H
#define DRAWING_ICANVAS_H


#include <cstddef>

#include "Utils.h"

namespace SimpleDrawing {

    class ICanvas {
    public:
        virtual void setPixel(size_t i_x, size_t i_y, const Color &i_color) = 0;

        virtual ~ICanvas() = default;
    };

}

#endif //DRAWING_ICANVAS_H
