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

#include <constants.h>
System::System(){

    {
        movementCounter = 0;
        run =1000;
        str = "cos x";
        g.set(str,-10,10,run,movementCounter);
        shapes = g.modify();
        min = -10;
        max = 10;
        range = abs(min-max);
        size=0;
    }

}

//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command){

    //used when user presses the 'm' key. This prints the menu and allows
    //the user to select an equation from an array
    if (command==-1){
        int index;
        for (int i=0; i< size; i++){
            cout << i << ": "<< equations[i] << endl;
        }
        cout << "Please select an equation: " << endl;
        cin >> index;

        //gets the string from the array
        str = equations[index];

        //calculates new points and sets new x,y based on string
        g.set(str,-10,10,run,movementCounter);
        shapes = g.modify();
        command=0;
    }
    //used when user presses 'f' this allows user to input new string
    if (command==9){
        str ="";
        getline (cin,str);

        //calculates new points and sets new x,y based on string
        g.set(str,-10,10,run,movementCounter);
        shapes = g.modify();

        //adds string to stringArray
        equations[size] = str;
        size++;
        command =0;
    }
    //used when user presses 'r' resets values redraws cos x
    if (command==10){
        movementCounter=0;
        str = "cos x";
        min = -10;
        max = 10;
        g.set(str,min,max,run,movementCounter);
        shapes = g.modify();
        command =0;
    }

    //used when user presses 'up' zooms in by changing domain
    if (command==8){

        //ensures we domain != 0
        if (min+2!=max-2){
            min = min +1;
            max = max -1;
        }
        //redraw
        g.set(str,min,max,run,movementCounter);
        shapes = g.modify();
        command =0;

    }

    //used when user presses 'down' zooms out by changing domain
    if (command==2){
        min = min -1;
        max = max +1;

        //redraw
        g.set(str,min,max,run,movementCounter);
        shapes = g.modify();
        command =0;

    }


    //used when user presses 'left' pans left by changing domain
    if (command==4){
        movementCounter += 1;
        min = min -1;
        max = max -1;

        //redraw
        g.set(str,min,max,run,movementCounter);
        shapes = g.modify();
        command =0;

    }

    //used when user presses 'right' pans right by changing domain
    if (command==6){
        movementCounter += -1;
        min = min +1;
        max = max +1;

        //redraw
        g.set(str,min,max,run,movementCounter);
        shapes = g.modify();
        command =0;

    }

    //default value, calls the step function
    if (command==0){
        for (int i=0; i<run; i++){
            (shapes[i])->particleStep(command);
        }
    }
}



void System::Draw(sf::RenderWindow& window){

    //range is abs value of domain
    range = abs(min-max);

    //scaler is used properly scale points
    int scaler = ((movementCounter)
                  *((SCREEN_WIDTH/2)/(range/2))) + (SCREEN_WIDTH/2);

    //clears window
    window.clear();
    for (int i=0; i<run; i++){
        (shapes[i])->particleDraw(window);
    }

    //draws x and y axis lines
    particle* xdraw = new hLine(0,SCREEN_WIDTH/2);
    xdraw->particleDraw(window);

    particle* ydraw = new vLine(scaler, 0);
    ydraw->particleDraw(window);

}

