#ifndef DRAWING_IBRUSH_H
#define DRAWING_IBRUSH_H


#include "ICanvas.h"

namespace SimpleDrawing {

    class IBrush {
    public:
        virtual void setPoint(ICanvas &o_canvas, const Point &i_point) const = 0;

        virtual ~IBrush() = default;
    };

}

#endif //DRAWING_IBRUSH_H
