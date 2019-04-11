#ifndef PLOTTER_H
#define PLOTTER_H
using namespace std;
#include "queue.h"
#include "token.h"
#include "rpn.h"
#include "point.h"

class Plotter {
public: Plotter();

public: Plotter(Queue<Token*> postFix, int x1, int x2, int points, int counter);

    Queue<point> Process();
    void transform(double &x, double &y);
    double getX();
    double getY();


private:
    Queue <point> cords;
    Queue <Token*> postFix;
    Queue<double> xVal;
    Queue<double> yVal;
    double range;
    double ticks;
    double points;
    double min;
    double max;
    const double SCREENWIDTH = 1500;
    const double SCREENHEIGHT = 1500;
    int movementCounter=0;


};
#endif // PLOTTER_H
