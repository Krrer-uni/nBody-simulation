#include "CApp.h"

CApp::CApp(){
    displayWindow = NULL;
    displaySurface = NULL;
    hello = NULL;
    Running = true;
    window_height = 1000;
    window_width = 1000;
    planet_start_count = 4090;
    planet_start_radius = 3;
    softening_factor = 0.1;
    dt = 0.05;
    G = 4;
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