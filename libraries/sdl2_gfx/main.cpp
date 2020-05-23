//#include <sdl2/sdl.h>
#include <SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

// reffered to https://blog.cormoran-web.com/blog/sdl2.drawshapes/
int main(int argc, char * args[])
{
    SDL_Event ev;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    double g=0.01;
    double y,x;
    double vy,vx;

    y=100;x=50;
    vx=1; vy=0;

    while(true){

        // clear background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // draw circle
        filledCircleRGBA(renderer, (Sint16)x,(Sint16)y,20,255,0,0,255);

        // physics simulation
        vy+=g;

        if(y<0){vy=-vy;y=0;}
        if(y>480){vy=-vy;y=480;}
        if(x>640){vx=-vx;x=640;}
        if(x<0){vx=-vx;x=0;}

        x+=vx; y+=vy;

        // update window
        SDL_RenderPresent(renderer);

        // event handling
        if (SDL_PollEvent(&ev)){
            if (ev.type == SDL_QUIT) {
                break;
            }
        }

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

  return 0;
}
