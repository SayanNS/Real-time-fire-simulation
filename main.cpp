#include <iostream>
#include <vector>
#include "noise.h"
#include <SDL.h>

char const* TITLE = "SDL";
int const WIDTH = 500;
int const HEIGHT = 500;
int const POINTS = 6;
int const ITERATIONS = WIDTH / (POINTS * 5);

struct Point
{
    Point(double x, double y)
    {
        this->x = static_cast<int>(x / (POINTS - 1) * WIDTH);
        this->y = static_cast<int>((0.5 - y / (POINTS - 1)) * HEIGHT);
    }

    int x;
    int y;
};


int main(int argc, char *args[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow(
        TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        0);

    if (window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (renderer == nullptr) {
        std::cout << "Renderer could not be created!: SDL_Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);

    std::vector<double> angles;
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < POINTS; i++) {
        double angle = static_cast<double>(std::rand()) / RAND_MAX * 2 - 1;
        angles.push_back(angle);
    }

    Point p0(0, 0);

    for (int i = 0; i < POINTS - 1; i++) {
        for (int l = 1; l < ITERATIONS + 1; l++) {
            double x = static_cast<double>(l) / ITERATIONS;
            double y = interpolate(noise(angles[i], angles[i + 1], x), smoothstep(x));
            Point p1(x + i, y);
            SDL_RenderDrawLine(renderer, p0.x, p0.y, p1.x, p1.y);
            p0 = p1;
        }
    }

    SDL_RenderPresent(renderer);
    
    SDL_Event event;
    bool quit = false;

    while (!quit && SDL_WaitEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            quit = true;
            break;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
