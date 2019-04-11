#ifndef GRAPH_H
#define GRAPH_H
#include "system.h"
#include "random.h"
#include "plotter.h"
#include "token.h"
#include <iostream>
#include "queue.h"
#include "vector.h"
#include "number.h"
#include "variables.h"
#include "operators.h"
#include "exponents.h"
#include "function.h"
#include "parentheses.h"
#include "shunting_yard.h"
#include "tokenizer.h"

class Grapher{
public: Vector <particle*> shapes;
private:
    int run = 1000;
    double min;
    double max;
    string str;
    int movementCounter;


public: Grapher(){
    }

    void set(string str, double min, double max, int run, int movementCounter){

        this->run = run;
        this->max = max;
        this->min = min;
        this->str = str;
        this->movementCounter = movementCounter;
    }

    //creation of points using a string
    Vector<particle*> modify(){

        Vector<particle*> shapes;

        //make tokens from string
        Tokenizer tkn (str);
        tkn.process();

        //set queue of tokens equal to output of tokenizer
        Queue <Token*> prefix = tkn.tokenize();

        //use shunting yard to get postfix
        shunting_yard sh (prefix);
        sh.calculate();
        Queue <Token*> pf = sh.postfix();

        //creation of plotter, this will make an array of points
        Plotter plotter1(pf,min,max,run,movementCounter);

        //save points
        Queue<point> points = plotter1.Process();

        // making a new circle based on the points given by the plotter
        for (int i=0; i<run; i++){
            double x = points.top().getx();
            double y = points.top().gety();
            points.pop();
            particle* p = new Circle(x,y);
            shapes.Insert(p);
        }
        return shapes;
    }

    //funct used to change the values of x,y for the circles
    Vector<particle*> reSet(int min, int max, string str){

        //tokenize using the new input string
        Tokenizer tkn (str);
        tkn.process();

        //create prefix
        Queue <Token*> prefix = tkn.tokenize();

        //create postfix
        shunting_yard sh (prefix);
        sh.calculate();
        Queue <Token*> pf = sh.postfix();

        //caluclates points
        Plotter plotter1(pf,min,max,run,movementCounter);
        Queue<point> points = plotter1.Process();


        //resets circles with new points
        for (int i=0; i<run; i++){

            double x = points.top().getx();
            double y = points.top().gety();
            points.pop();
            static_cast <Circle*> (shapes[i])->reSet(x,y);
        }
        return shapes;

    }
};

#endif // GRAPH_H
