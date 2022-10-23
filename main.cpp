#include <windows.h>

#include "SimpleDrawing/BufferCanvas.h"
#include "SimpleDrawing/Rectangle.h"
#include "SimpleDrawing/Line.h"
#include "SimpleDrawing/Brush.h"
#include "SimpleDrawing/Square.h"
#include "SimpleDrawing/Circle.h"

SimpleDrawing::BufferCanvas canvas(640, 480);

LRESULT WindowProc(HWND windowHandle, UINT message, WPARAM wp, LPARAM lp) {
    switch (message) {
        case WM_PAINT: {
            static HDC deviceContextHandle;  // device context (DC) for window
            static PAINTSTRUCT paintStruct;  // paint data for BeginPaint and EndPaint

            static const char *buffer = reinterpret_cast<const char *>(canvas.buffer().data());
            static const BITMAPINFO bitmapInfo = {sizeof(BITMAPINFOHEADER),
                                                  static_cast<LONG>(canvas.width()),
                                                  static_cast<LONG>(canvas.height()), 1, 24,
                                                  BI_RGB, static_cast<DWORD>(canvas.width() * canvas.height() * 3), 0,
                                                  0, 0, 0};

            deviceContextHandle = BeginPaint(windowHandle, &paintStruct);
            SetDIBitsToDevice(deviceContextHandle, 0, 0,
                              bitmapInfo.bmiHeader.biWidth,
                              bitmapInfo.bmiHeader.biHeight,
                              0, 0, 0,
                              bitmapInfo.bmiHeader.biHeight,
                              buffer,
                              &bitmapInfo,
                              DIB_RGB_COLORS);
            EndPaint(windowHandle, &paintStruct);
            break;
        }
        default:
            return DefWindowProc(windowHandle, message, wp, lp);
    }
    return 0;
}

int WinMain(HINSTANCE i_instanceHandle,
            HINSTANCE i_previousHandle,
            LPSTR i_commandLine,
            int i_show) {
    if (!i_previousHandle) {
        WNDCLASS windowClass = {0};
        windowClass.lpfnWndProc = WindowProc;
        windowClass.hInstance = i_instanceHandle;
        windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
        windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
        windowClass.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
        windowClass.lpszClassName = "MainWindow";
        RegisterClass(&windowClass);
    }

    {
        using namespace SimpleDrawing;
        Line({10, 10}, {10, 10}).render(canvas, Brush(Color::Magenta));
        Square({100, 100}, 20).render(canvas, Brush(Color::Cian));
        SimpleDrawing::Rectangle({500, 400}, 20, 1000).render(canvas, Brush(Color::Cian));
        Circle({190, 200}, 1).render(canvas, Brush(Color::Yellow));
        Circle({195, 200}, 2).render(canvas, Brush(Color::Green));
        Circle({195, 200}, 3).render(canvas, Brush(Color::Red));
        Circle({195, 200}, 4).render(canvas, Brush(Color::Magenta));
        Circle({200, 200}, 10).render(canvas, Brush(Color::Yellow));
        Circle({210, 200}, 15).render(canvas, Brush(Color::Magenta));
        Circle({220, 200}, 15).render(canvas, Brush(Color::Blue));
        Circle({230, 200}, 45).render(canvas, Brush(Color::White));
    }

    ShowWindow(CreateWindow("MainWindow",               /* window class name*/
                            "Drawing Demo",                   /* title  */
                            WS_OVERLAPPEDWINDOW,              /* style */
                            CW_USEDEFAULT, CW_USEDEFAULT,     /* position */
                            canvas.width(), canvas.height(),  /* size */
                            nullptr,                          /* parent */
                            nullptr,                          /* menu */
                            i_instanceHandle,
                            nullptr                           /* lparam -- crazytown */
    ), i_show);

    MSG message;
    while (GetMessage(&message, nullptr, 0, 0) > 0) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    return 0;
}