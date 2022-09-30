#include "CApp.h"
#include <iostream>

CApp::CApp(){
    displayWindow = NULL;
    displaySurface = NULL;
    hello = NULL;
    Running = true;
    window_height = 1000;
    window_width = 1000;
    planet_start_count = 500;
    planet_start_radius = 4;
    softening_factor = 0.1f;
    time_factor = 3.0f;
    dt = 0.01;
    last_time = SDL_GetTicks();
    G = 3.0f;
    FPS_CAP = 144.0f;
    TPF = 1.0f/FPS_CAP;
    tree = new quadTree(window_width,0,window_height,0,&planet_vec);
    tree_threshold = 1;
}

int CApp::OnExecute(){
    if(OnInit() == false){
        return -1;
    }
    Running = true;
    SDL_Event Event;

    last_time = SDL_GetPerformanceCounter();

    while(Running) {
        
        Uint64 loop_start = SDL_GetPerformanceCounter();

        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();

        Uint64 loop_end = SDL_GetPerformanceCounter();        
    	float elapsed = (loop_end - loop_start) / (float)SDL_GetPerformanceFrequency();

        dt = time_factor * (loop_end - last_time)/(float)SDL_GetPerformanceFrequency();  
        last_time = loop_end;
        
        // std::cout << elapsed << std::endl;
        if(elapsed < TPF)
        SDL_Delay((TPF - elapsed)*1000.0f);

        
        loop_end = SDL_GetPerformanceCounter();        
    	elapsed = (loop_end - loop_start) / (float)SDL_GetPerformanceFrequency();
	    std::cout << "Current FPS: " << std::to_string(1.0f / elapsed) << std::endl;
    }
    OnCleanup();
 
    return 0;
}

int main(int argc, char* argv[]){
    //po chuju, nie używać
    CApp theApp;

    return theApp.OnExecute();
}