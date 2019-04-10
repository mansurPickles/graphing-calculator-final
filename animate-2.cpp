#include "animate.h"
#include "constants.h"
#include <iostream>
using namespace std;
#include "system.h"


animate::animate()

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will


    system = System();
    window.setFramerateLimit(60);

    mouseIn = true;




    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);







    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }


    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update(){
    //cause changes to the data for the next frame
    system.Step(command);
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);





    }
}
void animate::render(){
       window.clear();
       Draw();
       window.display();
}



void animate::processEvents()
{
   sf::Event event;
   float mouseX, mouseY;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code){
                case sf::Keyboard::Left:
                   command = 4;
                   break;
               case sf::Keyboard::Right:
                   command = 6;
                   break;

               case sf::Keyboard::F:{
                   cout << "Please enter an input: \n";
                   command =9;
                   break;
               }

               case sf::Keyboard::M:{
                   command =-1;
                   break;
               }


               case sf::Keyboard::Up:{
                   command =8;
                   break;
               }
               case sf::Keyboard::Down:{
                   command =2;
                   break;
               }

               case sf::Keyboard::R:{
                   command =10;
                   break;
               }
               case sf::Keyboard::Escape:
                   window.close();
                break;
               }


               break;
           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...
               break;
           case sf::Event::MouseButtonReleased:
                   if (event.mouseButton.button == sf::Mouse::Right)
                   {
//                       cout<< "RIGHT CLICK " <<
                               mouse_pos_string(window);

                   }
                   else{
//                       cout<< "LEFT CLICK " <<
                               mouse_pos_string(window);
                   }
                   break;

               default:
                   break;
           }
       }
}
void animate::run()
{


   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
