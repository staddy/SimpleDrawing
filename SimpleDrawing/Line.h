#ifndef DRAWING_LINE_H
#define DRAWING_LINE_H


#include "IRenderable.h"

namespace SimpleDrawing {

    class Line : public IRenderable {
    public:
        void render(ICanvas &o_canvas, const IBrush &i_brush) override;

        Line(const Point &i_from, const Point &i_to);

    private:
        Point d_from;
        Point d_to;
    };

}

#endif //DRAWING_LINE_H
