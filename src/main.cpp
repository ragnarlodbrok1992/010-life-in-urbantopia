#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <iostream>
#include <string>
#include <vector>

#include "entities/iso-tile.hpp"

// Engine state - initial message
const std::string engineState = "Tech Demo"; // No version because of no plan

// Static helper variables
static int TILE_ID = 0;
static std::vector<IsoTile*> TILES;


int main(void) {
    std::cout << "Life In Ubrantopia - " << engineState << std::endl;

    // SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("An SDL2 window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Rect rect;
    rect.x = 10;
    rect.y = 10;
    rect.w = 100;
    rect.h = 100;

    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            // Global events
            if (event.type == SDL_QUIT) {
                running = false;
            }

            // Keyboard events
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                    case SDLK_w:
                        std::cout << "Up key pressed" << std::endl;
                        rect.y -= 10;
                        break;
                    case SDLK_s:
                        std::cout << "Down key pressed" << std::endl;
                        rect.y += 10;
                        break;
                    default:
                        break;
                }
            }
        }

        // Start of the render frame
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
        SDL_RenderClear(renderer); // Clear the screen (to red)

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        // Last frame call
        SDL_RenderPresent(renderer); // Draw to the screen
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    std::cout << "All went well, goodbye!" << std::endl;
    return 0;
}
