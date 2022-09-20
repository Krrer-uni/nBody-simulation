#pragma once

#include <SDL.h>
#include "utility.h"
#include "planet.h"
#include <vector>
#include <random>
#include <cmath>
class CApp {

    private:
        bool Running;

        SDL_Window* displayWindow;
        SDL_Surface* displaySurface;
        SDL_Surface* hello;
        SDL_Renderer* renderer;
        int window_height;
        int window_width;
        std::vector<Planet*> planet_vec;
        int planet_start_count;
        int planet_start_radius;
        double softening_factor;
        double dt;
        double last_time;
        double time_factor;
        double G;
        uint8_t FPS_CAP;
        double TPF; //time per frame
    public:
 
        CApp();

        int OnExecute();

    public:
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender();
        void OnCleanup();
 
};
 
