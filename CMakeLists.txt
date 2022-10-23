cmake_minimum_required(VERSION 3.23)
project(Drawing)

set(CMAKE_CXX_STANDARD 17)

add_executable(Drawing main.cpp SimpleDrawing/ICanvas.h SimpleDrawing/Utils.h SimpleDrawing/BufferCanvas.cpp SimpleDrawing/BufferCanvas.h SimpleDrawing/IRenderable.h SimpleDrawing/Line.cpp SimpleDrawing/Line.h SimpleDrawing/Brush.cpp SimpleDrawing/Brush.h SimpleDrawing/IBrush.h SimpleDrawing/Polygon.cpp SimpleDrawing/Polygon.h SimpleDrawing/Rectangle.cpp SimpleDrawing/Rectangle.h SimpleDrawing/Utils.cpp SimpleDrawing/Square.cpp SimpleDrawing/Square.h SimpleDrawing/Circle.cpp SimpleDrawing/Circle.h)
