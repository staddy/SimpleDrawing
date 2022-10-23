#include "Circle.h"

#include <cmath>

namespace SimpleDrawing {

    Circle::Circle(const Point &i_center, size_t i_radius, double i_error) : Polygon(
            evaluateVertices(i_center, i_radius, i_error)) {}

    std::vector<Point> Circle::evaluateVertices(const Point &i_center, size_t i_radius, double i_error) {
        if (i_radius <= 1)
            return {i_center};
        auto th = std::acos(2.0 * std::pow(1.0 - i_error / static_cast<double>(i_radius), 2.0) - 1.0);
        auto verticesCount = static_cast<size_t>(std::ceil(2.0 * M_PI / th));
        verticesCount /= 4;
        verticesCount *= 4;
        verticesCount += 4;
        auto angle = 2.0 * M_PI / static_cast<double>(verticesCount);
        std::vector<Point> vertices;
        double currentAngle = 0;
        for (size_t i = 0; i < verticesCount; ++i) {
            auto x = static_cast<double>(i_radius) * std::cos(currentAngle);
            auto y = static_cast<double>(i_radius) * std::sin(currentAngle);
            auto point = i_center;
            if (x > 0)
                point = point + Point{static_cast<size_t>(x), 0};
            else if (x < 0)
                point = point - Point{static_cast<size_t>(-x), 0};
            if (y > 0)
                point = point + Point{0, static_cast<size_t>(y)};
            else if (y < 0)
                point = point - Point{0, static_cast<size_t>(-y)};
            vertices.emplace_back(point);
            currentAngle += angle;
        }

        return vertices;
    }

}
