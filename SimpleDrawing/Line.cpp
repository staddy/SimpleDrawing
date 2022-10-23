#include "Line.h"

#include <algorithm>
#include <iostream>

namespace SimpleDrawing {

    Line::Line(const Point &i_from, const Point &i_to) : d_from{i_from}, d_to{i_to} {}

    void Line::render(ICanvas &o_canvas, const IBrush &i_brush) {
        auto xIsConst = d_from.x == d_to.x;
        auto minMax = xIsConst ? std::minmax(d_from.y, d_to.y) : std::minmax(d_from.x, d_to.x);
        auto dydx =
                (static_cast<double>(d_to.y) - d_from.y) / (static_cast<double>(d_to.x) - d_from.x);
        for (auto i = minMax.first; i <= minMax.second; ++i) {
            i_brush.setPoint(o_canvas, {xIsConst ? d_from.x : i,
                                        xIsConst ? i : (
                                                static_cast<size_t>((static_cast<double>(i) - d_from.x) * dydx) +
                                                d_from.y)});
        }
    }

}
