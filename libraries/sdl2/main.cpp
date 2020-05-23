//#include <sdl2/sdl.h>
#include <SDL.h>

// reffered to https://blog.cormoran-web.com/blog/sdl2.drawshapes/
int main(int argc, char * args[])
{
    SDL_Event ev;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    while(true){

        // clear background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // draw red rectangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect rect;
        rect.x=50; rect.y=50; rect.w=100; rect.h=100;
        SDL_RenderDrawRect(renderer,&rect);

        // update window
        SDL_RenderPresent(renderer);

        // event handling
        SDL_PollEvent(&ev);
        if (ev.type == SDL_QUIT) {
            break;
        }

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

  return 0;
}
