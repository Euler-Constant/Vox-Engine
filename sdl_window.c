#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{

  if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == -1)) 
  { 
    printf("Could not initialize SDL: %s.\n", SDL_GetError());
    exit(-1);
  }
  else {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      printf("SDL init failed: %s\n", SDL_GetError());
      return 1;
    };
  };

  SDL_Window* window = SDL_CreateWindow("Vox-Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

  if (!window) {
    printf("Window creation failed: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  };

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    printf("Renderer failed: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  };

  int running = 1; 

  while (running) {
    SDL_Event event;  // Container for events
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = 0;  // X button
        };
    };

    // world_update();
    // Append later: sim update (world_update())

    SDL_SetRenderDrawColor(renderer, 0, 0, 5, 255);  // Black
    SDL_RenderClear(renderer);                       // nuke canvas

    // Future: grid pixels
    SDL_RenderPresent(renderer);
  };

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;

};

