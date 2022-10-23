#ifndef DRAWING_BUFFERCANVAS_H
#define DRAWING_BUFFERCANVAS_H


#include <vector>

#include "ICanvas.h"

namespace SimpleDrawing {

    class BufferCanvas : public ICanvas {
    public:
        BufferCanvas(size_t i_width, size_t i_height, const Color &i_color = {0, 0, 0});

        [[nodiscard]] size_t width() const;

        [[nodiscard]] size_t height() const;

        [[nodiscard]] const std::vector<Color> &buffer() const;

        void setPixel(size_t i_x, size_t i_y, const Color &i_color) override;

    private:
        size_t d_width;
        size_t d_height;
        std::vector<Color> d_buffer;
    };

}

#endif //DRAWING_BUFFERCANVAS_H
