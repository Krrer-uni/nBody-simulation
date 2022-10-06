#include "planet.h"
#include <random>
Planet::Planet(){  
}

Planet::Planet(double x, double y){   
    this->x = x;
    this->y = y; 
    this->V_x = 0;
    this->V_y = 0;
    this->ax = 0;
    this->ay = 0;
    this->radius = 3;
}

Planet::Planet(double x, double y, double radius){   
        std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> color_dist(128,255);

    //też po chuju
    std::uniform_int_distribution<std::mt19937::result_type> vel_dist(0,20);
    this->x = x;
    this->y = y; 
    this->V_x = 0;
    this->V_y = 0;
    // this->V_x = (500 - y)/500*((double)vel_dist(rng));
    // this->V_y = -(500 - x)/500*(double)vel_dist(rng);
    this->ax = 0;
    this->ay = 0;
    this->radius = radius;
    //tak wiem że po chuju

    this->color[0] = color_dist(rng);
    this->color[1] = color_dist(rng);
    this->color[2] = color_dist(rng);
    this->color[3] = 5;
}

Planet::Planet(double x, double y, double radius, double V_x, double V_y){   
       std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> color_dist(128,255);

    this->x = x;
    this->y = y; 
    this->V_x = V_x;
    this->V_y = V_y;
    this->ax = 0;
    this->ay = 0;
    this->radius = radius;

    //this->color[0] = color_dist(rng);
    //this->color[1] = color_dist(rng);
    //this->color[2] = color_dist(rng);
    //this->color[3] = 5;
    
    if (radius == 1) //jasnoniebieski
    {
    this->color[0] = 199;
    this->color[1] = 231;
    this->color[2] = 255;
    this->color[3] = 5;
    }
    else if (radius == 2) //fioletowy
    {
    this->color[0] = 235;
    this->color[1] = 173;
    this->color[2] = 231;
    this->color[3] = 5;
    }
    else if (radius == 3) //brzoskwiniowy
    {
    this->color[0] = 255;
    this->color[1] = 221;
    this->color[2] = 198;
    this->color[3] = 5;
    }
    else if (radius == 4) //pistacjowy
    {
    this->color[0] = 197;
    this->color[1] = 235;
    this->color[2] = 209;
    this->color[3] = 5;
    }
    else
    {
    this->color[0] = 119;
    this->color[1] = 134;
    this->color[2] = 158;
    this->color[3] = 255;
    }
    
    
}


double Planet::get_M(){
    return std::pow(this->radius,3);
}
