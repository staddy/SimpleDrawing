#include "BufferCanvas.h"

namespace SimpleDrawing {

    BufferCanvas::BufferCanvas(size_t i_width, size_t i_height, const Color &i_color) : d_width{i_width},
                                                                                        d_height{i_height},
                                                                                        d_buffer(i_width * i_height,
                                                                                                 i_color) {

    }

    size_t BufferCanvas::width() const {
        return d_width;
    }

    size_t BufferCanvas::height() const {
        return d_height;
    }

    const std::vector<Color> &BufferCanvas::buffer() const {
        return d_buffer;
    }

    void BufferCanvas::setPixel(size_t i_x, size_t i_y, const Color &i_color) {
        auto position = (d_height - i_y) * d_width + i_x;
        if (position >= d_buffer.size())
            return;
        d_buffer[position] = i_color;
    }

}