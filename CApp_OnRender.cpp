#include "CApp.h"

void CApp::OnRender(){
    SDL_SetRenderDrawColor(renderer, 0x77,0x86,0x9E,0xFF);
    SDL_RenderClear(renderer);

    // SDL_Rect fillRect  = {window_width / 4, window_height /4, window_width /2 , window_height /2};
    // SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    // SDL_RenderFillRect(renderer,&fillRect);

    // SDL_SetRenderDrawColor(renderer, 0x00,0xFF,0x00,0xFF);
    // DrawFillCircle(renderer, window_width/ 2, window_height/2, window_height/4);

    // for(const auto &planet : planet_vec){
    //     if(planet->radius > 10){
    //         DrawFillCircle(renderer, (int)(planet->x), (int)(planet->y), (int)(planet->radius));
    //     }
    // }
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    for(const auto &planet : planet_vec){
        
        // if(planet->radius > 10){
        //     continue;
        // }
        SDL_SetRenderDrawColor(renderer, planet->color[0], planet->color[1], planet->color[2], 128);
        DrawFillCircle(renderer, (int)(planet->x), (int)(planet->y), (int)(planet->radius));
    }
    SDL_RenderPresent(renderer);
    // SDL_UpdateWindowSurface( displayWindow);
}