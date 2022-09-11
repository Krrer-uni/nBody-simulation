#include "CApp.h"

CApp::CApp(){
    displayWindow = NULL;
    displaySurface = NULL;
    hello = NULL;
    Running = true;
    window_height = 1000;
    window_width = 1000;
    planet_start_count = 400;
    planet_start_radius = 4;
    softening_factor = 5;
    dt = 0.05;
    G = 3;
}

int CApp::OnExecute(){
    if(OnInit() == false){
        return -1;
    }
    Running = true;
    SDL_Event Event;
 
    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }
    // int a;
    OnCleanup();
 
    return 0;
}

int main(int argc, char* argv[]){
    //po chuju, nie używać
    CApp theApp;

    return theApp.OnExecute();
}