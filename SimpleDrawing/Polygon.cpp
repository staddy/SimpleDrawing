#include "Polygon.h"
#include "Line.h"

namespace SimpleDrawing {

    Polygon::Polygon(std::vector<Point> i_vertices) : d_vertices{std::move(i_vertices)} {}

    void Polygon::render(ICanvas &o_canvas, const IBrush &i_brush) {
        for (size_t i = 0; i < d_vertices.size(); ++i)
            Line(d_vertices[i], i + 1 < d_vertices.size() ? d_vertices[i + 1] : d_vertices[0]).render(o_canvas,
                                                                                                      i_brush);
    }

}
