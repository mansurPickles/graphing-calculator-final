#ifndef PARTICLE_H
#define PARTICLE_H
#include "random.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include "system.h"
#include "random.h"
#include <iostream>
#include <constants.h>
#include "circle.h"
#include "vector.h"
using namespace std;

class particle
{


public:

    particle(){


    }

    virtual ~particle(){
//        cout<< "deleting particle \n";
    }

    virtual void particleStep(int command){
//    cout << "shouldnt be here\n";
    }

    int particleSize();

    virtual void particleDraw(sf::RenderWindow& window){
//        cout << "shuldernt be here\n";

//        window.clear();
//    for (int i=0; i< 15; i++){
//    window.draw(array[i]);
//    }
    }




private:
};

class Circle: public particle
{
public:
    Circle(int xpos, int ypos){
        Random rand;

//        cout << "creation of circle object \n";
        circle = sf::CircleShape(1);
        circle.setPosition(sf::Vector2f(xpos, ypos));
//        vel = sf::Vector2f(rand.Next(-5,5), rand.Next(-5,5)); //random velocity
//        circle.setFillColor(sf::Color(r, g, b));

        vel = sf::Vector2f(0, 0); //random velocity
        circle.setFillColor(sf::Color(255,192,203));



    }

    void reSet(double x, double y){
        circle.setPosition(x,y);
    }

    ~Circle(){
//        delete circle;
//        cout << "deleting circle";
    }

    void particleStep(int command){

        //all this is the responsibility of the
        // individual object:
       circle.move(vel);
        sf::Vector2f pos = circle.getPosition();
        if ((pos.x)>=SCREEN_WIDTH-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);

    }

    void particleDraw(sf::RenderWindow& window){
    window.draw(circle);

    }

private:
    sf::CircleShape circle;
    sf::Vector2f vel;
};

class Square: public particle
{
public:
    Square(int xpos, int ypos, int v1, int r, int g, int b):particle(){
        Random rand;
        this->v1 = v1;

//        cout << "creation of circle object \n";
        square = sf::RectangleShape();
        square.setSize(sf::Vector2f(this->v1,this->v1));
        square.setPosition(sf::Vector2f(xpos, ypos));
        vel = sf::Vector2f(rand.Next(-5,5), rand.Next(-5,5)); //random velocity
        square.setFillColor(sf::Color(r, g, b));


    }

    ~Square(){
//        delete circle;
//        cout << "deleting square";
    }

    void particleStep(int command){

        //all this is the responsibility of the
        // individual object:


       square.move(vel);
        sf::Vector2f pos = square.getPosition();
        if ((pos.x)>=SCREEN_WIDTH-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);

        square.setOrigin(v1/2,v1/2);
        square.rotate(random_rotate);





    }

    void particleDraw(sf::RenderWindow& window){
    window.draw(square);

    }

private:
    sf::RectangleShape square;
    sf::Vector2f vel;
    const int random_rotate = rand()%10+1;
    int v1;
};

class Rectangle: public particle
{
public:
    Rectangle(int xpos, int ypos, int v1, int r, int g, int b):particle(){
        this->v1 = v1;
        Random rand;

//        cout << "creation of circle object \n";
        rectangle = sf::RectangleShape();
        rectangle.setSize(sf::Vector2f(v1,v1*1.2));
        rectangle.setPosition(sf::Vector2f(xpos, ypos));
        vel = sf::Vector2f(rand.Next(-5,5), rand.Next(-5,5)); //random velocity
        rectangle.setFillColor(sf::Color(r, g, b));


    }

    ~Rectangle(){
//        delete circle;
//        cout << "deleting square";
    }

    void particleStep(int command){

        //all this is the responsibility of the
        // individual object:


       rectangle.move(vel);
        sf::Vector2f pos = rectangle.getPosition();
        if ((pos.x)>=SCREEN_WIDTH-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);

        rectangle.setOrigin(v1/2,v1/2);
        rectangle.rotate(random_rotate);





    }

    void particleDraw(sf::RenderWindow& window){
    window.draw(rectangle);

    }

private:
    sf::RectangleShape rectangle;
    sf::Vector2f vel;
    const int random_rotate = rand()%10+1;
    int v1;
};

class Triangle: public particle
{
public:
    Triangle(int xpos, int ypos, int v1, int r, int g, int b):particle(){
        Random rand;
        this->v1 = v1;

//        cout << "creation of circle object \n";
       triangle = sf::CircleShape (v1,3);
//        triangle.setSize(sf::Vector2f(getV1(),getV1()*1.2));
        triangle.setPosition(sf::Vector2f(xpos, ypos));
        vel = sf::Vector2f(rand.Next(-5,5), rand.Next(-5,5)); //random velocity
        triangle.setFillColor(sf::Color(r, g, b));


    }

    ~Triangle(){
//        delete circle;
//        cout << "deleting square";
    }

    void particleStep(int command){

        //all this is the responsibility of the
        // individual object:


       triangle.move(vel);
        sf::Vector2f pos = triangle.getPosition();
        if ((pos.x)>=SCREEN_WIDTH-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);

        triangle.setOrigin(v1,v1);
        triangle.rotate(random_rotate);



    }

    void particleDraw(sf::RenderWindow& window){
    window.draw(triangle);

    }

private:
    sf::CircleShape triangle;
    sf::Vector2f vel;
    const int random_rotate = rand()%10+1;
    int v1;
};

class Star: public particle
{
public:
    Star(int xpos, int ypos, int v1, int r, int g, int b):particle(){
        this->b = b;
        this->g = g;
        this->r = r;
        this->v1 = v1;
        Random rand;
//        cout << "creation of star object \n";
       star = sf::CircleShape (v1,5);
        star.setPosition(sf::Vector2f(xpos, ypos));
        vel = sf::Vector2f(rand.Next(-5,5), rand.Next(-5,5)); //random velocity
        star.setFillColor(sf::Color(r, g, b));


    }

    ~Star(){
//        delete circle;
//        cout << "deleting square";
    }

    void particleStep(int command){

        //all this is the responsibility of the
        // individual object:


       star.move(vel);
        sf::Vector2f pos = star.getPosition();
        if ((pos.x)>=SCREEN_WIDTH-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);

        static int red = r;
        static int blue = b;
        static int green = g;

        if (blue<245){
            blue+=1;
        }

        if (red<245){
            red+=1;
        }

        if (green<245){
            green+=1;
        }

        if (blue>=245){
            blue = 0;
        }

        if (red>=245){
            red = 0;
        }

        if (green>=245){
            green = 0;
        }


        star.setFillColor(sf::Color(red, blue, green));
        star.setOrigin(v1,v1);
        star.rotate(random_rotate);





    }

    void particleDraw(sf::RenderWindow& window){
    window.draw(star);

    }

private:
    sf::CircleShape star;
    sf::Vector2f vel;
    const int random_rotate = rand()%10+1;
    int v1;
    int r;
    int g;
    int b;
};

class Line: public particle
{
public:
   Line(int x1pos, int y1pos):particle(){

//        cout << "creation of circle object \n";
        line = sf::RectangleShape();
        if (x1pos==0){
        line.setSize(sf::Vector2f(SCREEN_WIDTH,1));
        }
        else {
           line.setSize(sf::Vector2f(1,SCREEN_HEIGHT));
        }
        line.setPosition(sf::Vector2f(x1pos, y1pos));
        vel = sf::Vector2f(0,0); //random velocity
        line.setFillColor(sf::Color(255, 255, 255));


    }

    ~Line(){
//        delete circle;
//        cout << "deleting square";
    }

    void particleStep(int command){

        //all this is the responsibility of the
        // individual object:


       line.move(vel);
        sf::Vector2f pos = line.getPosition();
        if ((pos.x)>=SCREEN_WIDTH-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);



    }

    void particleDraw(sf::RenderWindow& window){
    window.draw(line);

    }

private:
    sf::RectangleShape line;
    sf::Vector2f vel;
    const int random_rotate = rand()%10+1;
    int v1;
};

class vLine: public particle
{
public:
   vLine(int x1pos, int y1pos):particle(){

//        cout << "creation of circle object \n";
        line = sf::RectangleShape();
        line.setSize(sf::Vector2f(1,SCREEN_WIDTH));

        line.setPosition(sf::Vector2f(x1pos, y1pos));
        vel = sf::Vector2f(0,0); //random velocity
        line.setFillColor(sf::Color(255, 255, 255));


    }

    ~vLine(){
//        delete circle;
//        cout << "deleting square";
    }

    void particleStep(int command){

        //all this is the responsibility of the
        // individual object:


       line.move(vel);
        sf::Vector2f pos = line.getPosition();
        if ((pos.x)>=SCREEN_WIDTH-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);



    }

    void particleDraw(sf::RenderWindow& window){
    window.draw(line);

    }

private:
    sf::RectangleShape line;
    sf::Vector2f vel;
    const int random_rotate = rand()%10+1;
    int v1;
};

class hLine: public particle
{
public:
   hLine(int x1pos, int y1pos):particle(){

//        cout << "creation of circle object \n";
        line = sf::RectangleShape();
           line.setSize(sf::Vector2f(SCREEN_WIDTH,1));

        line.setPosition(sf::Vector2f(x1pos, y1pos));
        vel = sf::Vector2f(0,0); //random velocity
        line.setFillColor(sf::Color(255, 255, 255));


    }

    ~hLine(){
//        delete circle;
//        cout << "deleting square";
    }

    void particleStep(int command){

        //all this is the responsibility of the
        // individual object:


       line.move(vel);
        sf::Vector2f pos = line.getPosition();
        if ((pos.x)>=SCREEN_WIDTH-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);



    }

    void particleDraw(sf::RenderWindow& window){
    window.draw(line);

    }

private:
    sf::RectangleShape line;
    sf::Vector2f vel;
    const int random_rotate = rand()%10+1;
    int v1;
};




#endif // PARTICLE_H
