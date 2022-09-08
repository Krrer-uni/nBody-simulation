#include "CApp.h"

void CApp::OnCleanup(){
    SDL_FreeSurface(displaySurface);
    displaySurface = NULL;

    SDL_DestroyWindow(displayWindow);
    displayWindow = NULL;

    SDL_DestroyRenderer( renderer );
    renderer = NULL;
    SDL_Quit();
}