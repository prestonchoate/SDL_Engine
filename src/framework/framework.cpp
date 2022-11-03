#include "framework.h"

Framework::Framework(int height_, int width_): height(height_), width(width_)
{

    Uint32 windowFlags = SDL_WINDOW_VULKAN | SDL_WINDOW_ALLOW_HIGHDPI;
    SDL_Init(SDL_INIT_VIDEO); // Initializing SDL as Video
    SDL_CreateWindowAndRenderer(width, height, windowFlags, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);      // setting draw color
    SDL_RenderClear(renderer);      // Clear the newly created window
    SDL_RenderPresent(renderer);    // Reflects the changes done in the
                                    //  window.
}

Framework::~Framework()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Framework::drawCircle(int center_x, int center_y, int radius_)
{
        // Setting the color to be RED with 100% opaque (0% trasparent).
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // Drawing circle
        for(int x=center_x-radius_; x<=center_x+radius_; x++){
            for(int y=center_y-radius_; y<=center_y+radius_; y++){
                if((std::pow(center_y-y,2)+std::pow(center_x-x,2)) <= 
                    std::pow(radius_,2)){
                    SDL_RenderDrawPoint(renderer, x, y);
                }
            }
        }

        // Show the change on the screen
        SDL_RenderPresent(renderer);
}

void Framework::moveCircle()
{
        // Setting the color to be RED with 100% opaque (0% trasparent).
        
        SDL_Event event;    // Event variable
        while(!(event.type == SDL_QUIT)){

            // Circle will go down!
            for(int i=0; i<height; i++){
                SDL_Delay(10);  // setting some Delay
                SDL_PollEvent(&event);  // Catching the poll event.
                if(event.type == SDL_QUIT) return;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderClear(renderer);
                drawCircle(width/2, i, 25);
            }

            // Circle will go up!
            for(int i=height; i>0; i--){
                SDL_Delay(10);  // setting some Delay
                SDL_PollEvent(&event);  // Catching the poll event.
                if(event.type == SDL_QUIT) return;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderClear(renderer);
                drawCircle(width/2, i, 25);
            }
        }
        
    }

    int Framework::run()
    {
        SDL_Event event;
        while (!(event.type == SDL_QUIT)) {
            //TODO: Implement update and render loop
            SDL_Delay(10);
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT) {
                return 0;
            }
            update();
            render();
        }
        return 0;
    }

    void Framework::update()
    {
        
    }

    void Framework::render()
    {

    }