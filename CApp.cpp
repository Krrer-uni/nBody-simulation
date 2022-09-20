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
    softening_factor = 0.1f;
    time_factor = 2.0f;
    dt = 0.01;
    last_time = SDL_GetTicks();
    G = 3.0f;
    FPS_CAP = 60.0f;
    TPF = 1.0f/FPS_CAP;
}

int CApp::OnExecute(){
    if(OnInit() == false){
        return -1;
    }
    Running = true;
    SDL_Event Event;

    last_time = SDL_GetPerformanceCounter();

    while(Running) {
        
        Uint64 start = SDL_GetPerformanceCounter();

        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();

        Uint64 end = SDL_GetPerformanceCounter();        
    	float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
        
	    std::cout << "Current FPS: " << std::to_string(1.0f / elapsed) << std::endl;

        dt = time_factor * (end - last_time)/(float)SDL_GetPerformanceFrequency();
        std::cout << dt << std::endl;
        last_time = end;

        SDL_Delay(floor(TPF - elapsed));
    }
    OnCleanup();
 
    return 0;
}

int main(int argc, char* argv[]){
    //po chuju, nie używać
    CApp theApp;

    return theApp.OnExecute();
}