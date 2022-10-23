#ifndef DRAWING_BRUSH_H
#define DRAWING_BRUSH_H


#include "IBrush.h"

namespace SimpleDrawing {

    class Brush : public IBrush {
    public:
        Brush(const Color &i_color);

        void setPoint(ICanvas &o_canvas, const Point &i_point) const override;

    private:
        Color d_color;
    };

}


#endif //DRAWING_BRUSH_H
