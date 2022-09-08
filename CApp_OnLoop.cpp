#include "CApp.h"

void CApp::OnLoop(){

    for(auto &planet : planet_vec){
        planet->ax = planet->ay = 0;
    }

    for(auto &main_planet : planet_vec){
        for(auto &other_planet: planet_vec){
            // if(main_planet->x > other_planet->x){
                double dx = main_planet->x - other_planet->x;
                double dy = main_planet->y - other_planet->y;
                double r = std::sqrt(dx * dx + dy*dy);
                double M = other_planet->radius*other_planet->radius;
                double a =  G*M/(r*r + softening_factor);
                if(r != 0){
                    double ax = a * dx/r;
                     double ay = a * dy/r;
                    main_planet->ax -= ax;
                    main_planet->ay -= ay;
                }
                

                
                // other_planet->ax += ax;

                // main_planet->ay -= ay;
                // other_planet->ay += ay;
            // }
        }
    }

    for(auto &planet : planet_vec){
        planet->x += planet->V_x * dt + planet->ax * dt *dt /2;
        planet->y += planet->V_y *dt + planet->ay * dt *dt /2;
        planet->V_x += planet->ax *dt;
        planet->V_y += planet->ay * dt;

        // if(planet->x > window_height) planet->x -= window_height;
        // if(planet->x < 0) planet->x += window_height;
        // if(planet->y > window_width) planet->y -= window_width;
        // if(planet->y < 0) planet->y += window_height;

        // planet->y %= window_height;
    }
}