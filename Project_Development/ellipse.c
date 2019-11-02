#include <windows.h> 
#include <stdlib.h>

LONG WINAPI WndProc( HWND, UINT, WPARAM, LPARAM ); 
 
int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, 
LPSTR lpszCmdLine, int nCmdShow ){ 
 
    /* The Entry for windows program, just like main() in dos */ 
 
    WNDCLASS wc; 
    HWND hwnd; 
    MSG msg; 
 
    wc.style = 0;                                    // Class style 
    wc.lpfnWndProc = (WNDPROC)WndProc;              // Window procedure address 
    wc.cbClsExtra = 0;                              // Class extra bytes 
    wc.cbWndExtra = 0;                              // Window extra bytes 
    wc.hInstance = hInstance;                        // Instance handle 
    wc.hIcon = LoadIcon( NULL, IDI_WINLOGO );        // Icon handle 
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );      // Cursor handle 
    wc.hbrBackground = (HBRUSH)( COLOR_WINDOW + 1 ); // Background color 
    wc.lpszMenuName = NULL;                          // Menu name 
    wc.lpszClassName = "WinSDKtest";                // WNDCLASS name 
 
    RegisterClass( &wc ); 
 
    hwnd = CreateWindow ( 
        "WinSDKtest",              // WNDCLASS name 
        "SDK Application",          // Window title 
        WS_OVERLAPPEDWINDOW,        // Window style 
        CW_USEDEFAULT,              // Horizontal position 
        CW_USEDEFAULT,              // Vertical position        
        CW_USEDEFAULT,              // Initial width 
        CW_USEDEFAULT,              // Initial height 
        HWND_DESKTOP,              // Handle of parent window 
        NULL,                      // Menu handle 
        hInstance,                  // Application's instance handle 
        NULL                        // Window-creation data 
    ); 
 
    ShowWindow( hwnd, nCmdShow ); 
    UpdateWindow( hwnd ); 
 
    while (  GetMessage( &msg, NULL, 0, 0 )  ) { 
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    } 
 
    return msg.wParam; 
} 
 
 
LRESULT CALLBACK WndProc( HWND hwnd, UINT message, WPARAM wParam, 
LPARAM lParam ) 
{ 
    /* Windows will call this function anytime... */ 
 
    PAINTSTRUCT ps; 
    HDC hdc; 
 
    switch(message){ 
   
    case WM_PAINT: 
 
        hdc = BeginPaint( hwnd, &ps ); 
 
        Ellipse( hdc, 0, 0, 800, 600 ); 
        // Here we Draw an ellipse in the window of our program 
        EndPaint( hwnd, &ps ); 
 
        break; 
                              // Someone like to write return here. 
    case WM_DESTROY: 
 
        PostQuitMessage(0); 
        break; 
 
    default: 
        return DefWindowProc( hwnd, message, wParam, lParam ); 
 
    } 
 
    return 0; 
} 