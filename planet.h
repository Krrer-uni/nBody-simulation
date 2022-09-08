#include <SDL.h>

class Planet {

    public:
    double ax;
    double ay;

    double V_x;
    double V_y;

    double x;
    double y;
    double radius;

    uint8_t color[4];
    Planet();
    Planet(double x, double y);
    Planet(double x, double y, double radius);
    Planet(double x, double y, double radius, double V_x, double V_y);
};