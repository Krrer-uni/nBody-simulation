#include "CApp.h"

bool CApp::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }

    if((displayWindow = SDL_CreateWindow("My Game Window",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          window_width, window_height,
                          SDL_WINDOW_OPENGL)) == NULL) {
        return false;
    }


    renderer = SDL_CreateRenderer(displayWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_UpdateWindowSurface( displayWindow);


    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> height_dist(0,window_height);
    std::uniform_int_distribution<std::mt19937::result_type> width_dist(0,window_width);
    std::uniform_int_distribution<std::mt19937::result_type> radius_dist(0,4);
    std::uniform_real_distribution<double> vel_dist(0,8);
    for(int i = 0; i < planet_start_count; i++){
        planet_vec.push_back(new Planet(width_dist(rng), height_dist(rng),radius_dist(rng),vel_dist(rng)-4,vel_dist(rng)-4));
    }
    // planet_vec.push_back(new Planet(window_width/2, window_height/2, 50.0, 0,0));
    return true;
}