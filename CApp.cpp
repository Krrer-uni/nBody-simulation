#include "CApp.h"
#include <iostream>
CApp::CApp(){
    displayWindow = NULL;
    displaySurface = NULL;
    hello = NULL;
    Running = true;
    window_height = 900;
    window_width = 1600;
    planet_start_count = 400;
    planet_start_radius = 4;
    softening_factor = 0.1;
    dt = 0.01;
    last_time = SDL_GetTicks();
    G = 3;
}

int CApp::OnExecute(){
    if(OnInit() == false){
        return -1;
    }
    Running = true;
    SDL_Event Event;

    while(Running) {
        
        Uint64 start = SDL_GetPerformanceCounter();

        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();

        //tu nie działa
        Uint64 end = SDL_GetPerformanceCounter();

        
    	float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
        
	    std::cout << "Current FPS: " << std::to_string(1.0f / elapsed) << std::endl;

        dt = (last_time - end)/1000.0f;
        last_time = end;
    }
    OnCleanup();
 
    return 0;
}

int main(int argc, char* argv[]){
    //po chuju, nie używać
    CApp theApp;

    return theApp.OnExecute();
}