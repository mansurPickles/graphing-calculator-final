#include "rpn.h"
#include "token.h"
#include "number.h"
#include "operators.h"
#include <math.h>
using namespace std;


RPN::RPN(const Queue<Token*>& pf){
    q1 = pf;
    s1;
}

void RPN::show(){
    cout << "q1--------\n";
    cout << q1;
    cout << "s1--------\n";
    cout << s1;

}

double RPN::calculate(double xVal){
    string xStr = to_string(xVal);
    while (!q1.empty()){
        int a = q1.top()->instanceOf();

        //checks to see if token is a variable, if it is assign double to a new
        // token*
        if (a==1){
            if(q1.top()->getVal()=="x"||q1.top()->getVal()=="X"){
                q1.pop();
                Token* temp = new Number(xStr);
                s1.pushback(temp);
            }

            //else if its just double push through
            else {
                Token* temp = q1.pop();
                s1.pushback(temp);
            }
        }

        //checks to see if token is an operator
        if (a==2){
            Token* temp = q1.pop();

            string optr = temp->getVal();

            if (optr=="+"){
                Token* a = s1.pop();
                Token* b = s1.pop();
                string str1 = a->getVal();
                string str2 = b->getVal();
                double left = stod(str1);
                double right = stod(str2);
                right+=left;

                Token*res = new Number(to_string(right));

                s1.pushback(res);
            }

            else if (optr=="-"){
                Token* a = s1.pop();
                Token* b = s1.pop();
                string str1 = a->getVal();
                string str2 = b->getVal();
                double left = stod(str1);
                double right = stod(str2);
                right-=left;

                Token*res = new Number(to_string(right));

                s1.pushback(res);
            }

            else if (optr=="/"){
                Token* a = s1.pop();
                Token* b = s1.pop();
                string str1 = a->getVal();
                string str2 = b->getVal();
                double left = stod(str1);
                double right = stod(str2);
                right/=left;

                Token*res = new Number(to_string(right));

                s1.pushback(res);
            }

            else if (optr=="*"){
                Token* a = s1.pop();
                Token* b = s1.pop();
                string str1 = a->getVal();
                string str2 = b->getVal();
                double left = stod(str1);
                double right = stod(str2);
                right*=left;

                Token*res = new Number(to_string(right));

                s1.pushback(res);
            }

            else if(optr=="^"){
                Token* a = s1.pop();
                Token* b = s1.pop();
                string str1 = a->getVal();
                string str2 = b->getVal();
                double left = stod(str1);
                double right = stod(str2);
                left = pow(right,left);
                Token*res = new Number(to_string(left));
                s1.pushback(res);
            }

            else if(optr=="sin"){
                Token* a = s1.pop();
                string str1 = a->getVal();
                double left = stod(str1);
                left = sin(left);
                Token*res = new Number(to_string(left));
                s1.pushback(res);

            }

            else if(optr=="cos"){
                Token* a = s1.pop();
                string str1 = a->getVal();
                double left = stod(str1);
                left = cos(left);
                Token*res = new Number(to_string(left));
                s1.pushback(res);

            }

            else if(optr=="tan"){
                Token* a = s1.pop();
                string str1 = a->getVal();
                double left = stod(str1);
                left = tan(left);
                Token*res = new Number(to_string(left));
                s1.pushback(res);

            }

            else if(optr=="sec"){
                Token* a = s1.pop();
                string str1 = a->getVal();
                double left = stod(str1);
                left = 1/(cos(left));
                Token*res = new Number(to_string(left));
                s1.pushback(res);

            }

            else if(optr=="csc"){
                Token* a = s1.pop();
                string str1 = a->getVal();
                double left = stod(str1);
                left = 1/(sin(left));
                Token*res = new Number(to_string(left));
                s1.pushback(res);

            }

            else if(optr=="cot"){
                Token* a = s1.pop();
                string str1 = a->getVal();
                double left = stod(str1);
                left = 1/(tan(left));
                Token*res = new Number(to_string(left));
                s1.pushback(res);

            }

        }
    }

    // ------------- END of tokenizer logic ----------------------

    //returns the stack val amd converts it to a double.
    string result = s1.top()->getVal();
    return stod(result);
}



