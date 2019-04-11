#ifndef SYSTEM_H
#define SYSTEM_H
#include "vector.h"
#include <SFML/Graphics.hpp>
#include "random.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include "particle.h"
#include "graph.h"

using namespace std;
class System
{
public:
    System();
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& widnow);
    void randomCreation();
    void reSet(double x, double y);

private:

    string str;
    int run;
    Vector <particle*> shapes;
    Grapher g;
    int min;
    int max;
    int movementCounter =0;
    string equations [200];
    double range;
    int size;


};

#endif // SYSTEM_H
