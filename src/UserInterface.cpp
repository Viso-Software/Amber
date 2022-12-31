#include "UserInterface.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include <iostream>

UserInterface::UserInterface()
{

}

void UserInterface::run()
{

    constexpr int WINDOW_HEIGHT {500};
    constexpr int WINDOW_WIDTH {390};

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            std::cout << "ERROR initilizing: " << SDL_GetError();
        }

        SDL_Window* window = SDL_CreateWindow("Amber",
                                    SDL_WINDOWPOS_CENTERED, 
                                    SDL_WINDOWPOS_CENTERED, 
                                    WINDOW_WIDTH, WINDOW_HEIGHT, 0 | SDL_WINDOW_BORDERLESS);

        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        SDL_Rect rect;
        rect.w = 25;
        rect.h = 25;
        rect.x = 25;
        rect.y = 25;

        bool running = true;
        while (running)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

            SDL_RenderClear(renderer);

            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_QUIT:
                        running = false;
                        break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_Q:
                            running = false;
                            break;
                        default:
                            break;
                    }
                    default:
                        break;
                }
            }

            SDL_SetRenderDrawColor(renderer, 255,255,255,255);

            SDL_RenderFillRect(renderer, &rect);
            SDL_RenderPresent(renderer);
            // 60 fps
            SDL_Delay(1000/60);
        }

        SDL_DestroyWindow(window);

}