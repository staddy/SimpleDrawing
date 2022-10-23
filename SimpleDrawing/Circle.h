#ifndef DRAWING_CIRCLE_H
#define DRAWING_CIRCLE_H


#include "Polygon.h"

namespace SimpleDrawing {

    class Circle : public Polygon {
    public:
        Circle(const Point &i_center, size_t i_radius, double i_error = 0.05);

    private:
        static std::vector<Point> evaluateVertices(const Point &i_center, size_t i_radius, double i_error);
    };

}

#endif //DRAWING_CIRCLE_H
