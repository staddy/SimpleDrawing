#ifndef DRAWING_POLYGON_H
#define DRAWING_POLYGON_H


#include "IRenderable.h"

#include <vector>

namespace SimpleDrawing {

    class Polygon : IRenderable {
    public:
        Polygon(std::vector<Point> i_vertices);

        void render(ICanvas &o_canvas, const IBrush &i_brush) override;

    private:
        std::vector<Point> d_vertices;
    };

}

#endif //DRAWING_POLYGON_H
