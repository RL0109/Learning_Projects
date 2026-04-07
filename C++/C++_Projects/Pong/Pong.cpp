#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Hello SDL2", 800, 600, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    SDL_FRect player1 = {5, 300, 10, 100};
    SDL_FRect player2 = {785, 300, 10, 100};

    SDL_Event event;
    bool running = true;

    while (running) {
        
        while (SDL_PollEvent(&event)) 
            if (event.type == SDL_EVENT_QUIT)
                running = false;

        const bool* keys = SDL_GetKeyboardState(NULL);

        if (keys[SDL_SCANCODE_W]) {
            std::cout << "Key Pressed!" << "\n";
            player1.y += 100;
        }

        if (keys[SDL_SCANCODE_S]) {
            player1.y -= 100;
        }
        // Draw a dark grey background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_FRect player1 = {5, 300, 10, 100};
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player1);

        
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player2);


        // Draw a white rectangle in the center
        SDL_FRect rect = { 350, 250, 10, 10 };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}