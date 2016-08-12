#include <SDL2/SDL.h>
#include <stdio.h>

/**
 * The context of the program. Anthing that would need to be passed as a
 * parameter should be included here. This is the sole parameter of any function
 * created here.
 */
typedef struct {
  int quit;
  SDL_Window *window;
  SDL_Surface *screen_surface;
} Context;


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


void handleEvents(Context *);
void draw(Context *);


/**
 * Currently, Opens and closes a window.
 * Ultimately, should display a fancy grid
 */
int main(void)
{
  Context *context = (Context *) malloc(sizeof(Context));
  context->window = NULL;
  context->screen_surface = NULL;
  context->quit = 0;

  SDL_Init(SDL_INIT_VIDEO);
  context->window = SDL_CreateWindow("SDL Tutorial",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH,
                            SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN);
  context->screen_surface = SDL_GetWindowSurface(context->window);

  while(!context->quit) {
    draw(context);
    SDL_UpdateWindowSurface(context->window);
    handleEvents(context);
    SDL_Delay(25);
  }

  SDL_DestroyWindow(context->window);
  SDL_Quit();
  free(context);
  return 0;
}


/**
 * All the drawing logic should happen here.
 * Takes the program's context struct as a parameter.
 */
void draw(Context *context)
{
  SDL_FillRect(context->screen_surface, NULL,
               SDL_MapRGB(context->screen_surface->format, 0xFF, 0xFF, 0xFF));
}

/**
 * Any input events are handled here. Any information that needs to be returned
 * should be included in the context struct and modified there.
 * Takes the program's context struct as a parameter.
 */
void handleEvents(Context *context)
{
  SDL_Event e;
  /*poll events */
  while(SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT)
      context->quit = 1;
  }
}
