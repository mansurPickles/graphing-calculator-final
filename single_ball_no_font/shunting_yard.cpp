#include "shunting_yard.h"
#include "token.h"
#include "number.h"
#include "operators.h"
#include <math.h>

shunting_yard::shunting_yard(const Queue<Token*>& in)
{
    inf = in;
    outf;
    s1;
    stackPri = 0;

}

void shunting_yard::calculate(){


    while(!inf.empty()){
        int a = inf.top()->instanceOf();
        string optr = inf.top()->getVal();

        // checks to see if token is a double or variable
        if(a==1){
            Token* temp = inf.pop();
            outf.pushback(temp);
        }


        //checks to see if token is an operator
        else if(a==2){
            Token* temp = inf.pop();
            string optr = temp->getVal();
            int currentPri = static_cast <Operators*>(temp)->getpriority();

            //checks to see if operator is a "{"
            if (currentPri==0){
                s1.pushback(temp);
                stackPri = 0;
            }

            // checks to see if operator is a "}"
            else if (currentPri==5){
                string str;
                if (optr=="}"){
                    str = "{";
                }
                if (optr==")"){
                    str = "(";
                }

                //continues popping until the opening bracket is found
                while(optr!=str){
                    Token* temp2 = s1.pop();
                    optr = temp2->getVal();
                    if (optr!=str){

                        //saves stack pri by what tokens pri comes out
                        stackPri = static_cast <Operators*>(temp2)->getpriority();
                        outf.pushback(temp2);
                    }
                }
            }

            //if stackOri<currPri then just pushback
            else if (stackPri<currentPri){
                s1.pushback(temp);
                stackPri = currentPri;
            }

            //else pop the stack and push the new token in
            else if (stackPri>=currentPri){
                Token* temp2 = s1.pop();
                outf.pushback(temp2);
                s1.pushback(temp);
                stackPri = currentPri;
            }

        }

    }

    // this is used to clear the stack and push all remaining into the queue
    while (!s1.empty()){
        Token* temp = s1.pop();
        outf.pushback(temp);
    }
}



void shunting_yard::show(){
    cout << "inf--------\n";
    cout << inf << endl;
    cout << "outf--------\n";
    cout << outf << endl;
    cout << "s1--------\n";
    cout << s1 << endl;

}


Queue<Token*> shunting_yard::postfix(){
    Queue<Token*> q1;
    q1 = outf;
    return q1;
}
