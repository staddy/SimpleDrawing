#ifndef DRAWING_IRENDERABLE_H
#define DRAWING_IRENDERABLE_H


#include "ICanvas.h"
#include "IBrush.h"

namespace SimpleDrawing {

    class IRenderable {
    public:
        virtual void render(ICanvas &o_canvas, const IBrush &i_brush) = 0;

        virtual ~IRenderable() = default;
    };

}

#endif //DRAWING_IRENDERABLE_H
