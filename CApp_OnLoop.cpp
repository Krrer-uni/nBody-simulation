#include "CApp.h"

void CApp::OnLoop(){


    // for(auto planet = planet_vec.begin() ;  planet != planet_vec.end() ; planet ++){
    //     (*planet)->ax = (*planet)->ay = 0;
    //     if ((*planet)->x > window_width*2 || (*planet)->x < - window_width || (*planet)->y > window_height * 2 || (*planet)->y < -window_height)
    //     {
    //         free(*planet);
    //         planet = planet_vec.erase(planet);

    //     }
        
    // }

    // for(int i = 0; i < planet_vec.size(); i++){
    //     for(int j = i+1; j < planet_vec.size(); j++){
    //         double dist = std::abs(planet_vec[i]->x - planet_vec[j]->x) + std::abs(planet_vec[i]->y -planet_vec[j]->y);
    //         if(dist < (planet_vec[i]->radius + planet_vec[j]->radius)/2 && i != j){
    //             double new_r = std::cbrt(planet_vec[i]->get_M() + planet_vec[j]->get_M());
    //             double new_x = (planet_vec[i]->x *planet_vec[i]->get_M() + planet_vec[j]->x * planet_vec[j]->get_M())/ std::pow(new_r,3);
    //             double new_y = (planet_vec[i]->y *planet_vec[i]->get_M() + planet_vec[j]->y * planet_vec[j]->get_M())/ std::pow(new_r,3);
    //             double new_Vx = (planet_vec[i]->V_x *planet_vec[i]->get_M() + planet_vec[j]->V_x * planet_vec[j]->get_M())/ std::pow(new_r,3);
    //             double new_Vy = (planet_vec[i]->V_y *planet_vec[i]->get_M() + planet_vec[j]->V_y * planet_vec[j]->get_M())/ std::pow(new_r,3);
    //             auto new_planet = new Planet(new_x,new_y,new_r,new_Vx,new_Vy);
    //             new_planet->color[0] =  (planet_vec[i]->radius > planet_vec[j]->radius) ? planet_vec[i]->color[0] : planet_vec[j]->color[0];
    //             new_planet->color[1] =  (planet_vec[i]->radius > planet_vec[j]->radius) ? planet_vec[i]->color[1] : planet_vec[j]->color[1];
    //             new_planet->color[2] =  (planet_vec[i]->radius > planet_vec[j]->radius) ? planet_vec[i]->color[2] : planet_vec[j]->color[2];
    //             new_planet->color[3] =  (planet_vec[i]->radius > planet_vec[j]->radius) ? planet_vec[i]->color[3] : planet_vec[j]->color[3];
    //             free(planet_vec[j]);
    //             free(planet_vec[i]);
    //             planet_vec.erase(planet_vec.begin() + j);
    //             planet_vec.erase(planet_vec.begin() + i);
    //             planet_vec.push_back(new_planet);

    //         }
    //     }
    // }

    // for(auto planet_iter = planet_vec.begin();planet_iter != planet_vec.end();){
    //      for(auto second_planet_iter = planet_vec.begin();second_planet_iter != planet_vec.end();){
    //         double dist = std::abs((*planet_iter)->x - (*second_planet_iter)->x) + std::abs((*planet_iter)->y - (*second_planet_iter)->y); 
    //         if(dist < (*planet_iter)->radius && planet_iter != second_planet_iter){
    //             double new_x = ((*planet_iter)->x + (*second_planet_iter)->x)/2;
    //             double new_y = ((*planet_iter)->x + (*second_planet_iter)->y)/2; 
    //             double new_r = ((*planet_iter)->x + (*second_planet_iter)->y); 
    //             auto new_planet = new Planet(new_x,new_y,new_r);
    //             planet_vec.push_back(new_planet);
    //             free(*planet_iter);
    //             free(*second_planet_iter);

    //             second_planet_iter = planet_vec.erase(second_planet_iter);
    //             planet_iter = planet_vec.erase(planet_iter);
    //             // planet_iter++;
    //             // second_planet_iter+=2;
    //         }else{
    //             second_planet_iter++;
    //         }
    //     }
    //     planet_iter++;
    // }

    for(auto &main_planet : planet_vec){
        for(auto &other_planet: planet_vec){
                double dx = main_planet->x - other_planet->x;
                double dy = main_planet->y - other_planet->y;
                double r = std::sqrt(dx * dx + dy * dy);   
                double a =  G*other_planet->get_M()/(r*r + softening_factor);
                if(r != 0){
                    double ax = a * dx/r;
                    double ay = a * dy/r;
                    main_planet->ax -= ax;
                    main_planet->ay -= ay;
                }
        }
    }

    for(auto &planet : planet_vec){
        planet->x += planet->V_x * dt + planet->ax * dt *dt /2;
        planet->y += planet->V_y *dt + planet->ay * dt *dt /2;
        planet->V_x += planet->ax *dt;
        planet->V_y += planet->ay * dt;

        // if(planet->x > window_height) planet->x -= window_width;
        // if(planet->x < 0) planet->x += window_width;
        // if(planet->y > window_width) planet->y -= window_height;
        // if(planet->y < 0) planet->y += window_height;

        // planet->y %= window_height;
    }
}