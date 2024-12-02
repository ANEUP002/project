#ifndef _IO_
#define _IO_

#ifndef LINUX
#include <SDL2/SDL.h>


#else
#include <SDL/SDL.h>
#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#endif
//#pragma comment (lib, "SDL/lib/SDL.lib")
//#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives_Static.lib")

enum color { BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX };

class IO {
public:
    IO();
    ~IO();

    void DrawRectangle(int pX1, int pY1, int pX2, int pY2, color pC);
    void ClearScreen();
    int GetScreenHeight();
    int InitGraph();
    int Pollkey();
    int Getkey();
    int IsKeyDown(int pKey);
    void UpdateScreen();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Color GetSDLColor(color pC);
};

#endif 
