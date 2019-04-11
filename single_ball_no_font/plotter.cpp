
using namespace std;
#include "queue.h"
#include "token.h"
#include "rpn.h"
#include "point.h"
#include "plotter.h"
//#include <math.h>

Plotter::Plotter(){

}

Plotter::Plotter(Queue<Token*> postFix, int x1, int x2, int points, int counter){
    this->postFix = postFix;
    range = abs(x1-x2);
    ticks = range;
    ticks /=points;
    this->points = points;
    min = x1;
    max = x2;
    this->movementCounter = counter;
}

Queue<point> Plotter::Process(){

double x,y;

    //gets an x value from the domain and passes it to the rpn to get a y value
    for (double i= min; i< max; i+=ticks){
        RPN rpnFunct(postFix);
         y =rpnFunct.calculate(i);
         x = i;

        //transform cords
        transform(x,y);
        xVal.pushback(x);
        yVal.pushback(y);

        //make a point using x,y
        point xy(x,y);
        cords.pushback(xy);
    }
    return cords;

}

void Plotter::transform(double &x,double &y){

    //converts x value to vector points
    x = (x*(SCREENWIDTH/range)) + (SCREENWIDTH/2) + (movementCounter)
            *((SCREENWIDTH/2)/(range/2));

    //converts y value to vector points
    y = -1*(y*(SCREENHEIGHT/range)) + (SCREENHEIGHT/2);
}

double Plotter::getX(){
    return xVal.pop();
}

double Plotter::getY(){
    return yVal.pop();
}

