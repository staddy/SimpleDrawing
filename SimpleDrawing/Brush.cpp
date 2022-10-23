#include "Brush.h"

namespace SimpleDrawing {

    Brush::Brush(const Color &i_color) : d_color{i_color} {}

    void Brush::setPoint(ICanvas &o_canvas, const Point &i_point) const {
        o_canvas.setPixel(i_point.x, i_point.y, d_color);
    }

}
