#include "IO.h"
#include <iostream>

IO::IO() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow("Tetris",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              800, 600,
                              SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
}

IO::~IO() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Color IO::GetSDLColor(color pC) {
    switch (pC) {
    case BLACK:   return { 0, 0, 0, 255 };
    case RED:     return { 255, 0, 0, 255 };
    case GREEN:   return { 0, 255, 0, 255 };
    case BLUE:    return { 0, 0, 255, 255 };
    case CYAN:    return { 0, 255, 255, 255 };
    case MAGENTA: return { 255, 0, 255, 255 };
    case YELLOW:  return { 255, 255, 0, 255 };
    case WHITE:   return { 255, 255, 255, 255 };
    default:      return { 255, 255, 255, 255 };
    }
}

void IO::DrawRectangle(int pX1, int pY1, int pX2, int pY2, color pC) {
    SDL_Color sdlColor = GetSDLColor(pC);
    SDL_SetRenderDrawColor(renderer, sdlColor.r, sdlColor.g, sdlColor.b, sdlColor.a);

    SDL_Rect rect = { pX1, pY1, pX2 - pX1, pY2 - pY1 };
    SDL_RenderFillRect(renderer, &rect);
}

void IO::ClearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(renderer);
}

void IO::UpdateScreen() {
    SDL_RenderPresent(renderer);
}

int IO::GetScreenHeight() {
    return 600;
}

int IO::Pollkey() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            return event.key.keysym.sym;
        }
    }
    return -1;
}

int IO::IsKeyDown(int pKey) {
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    return state[SDL_GetScancodeFromKey(pKey)];
}
