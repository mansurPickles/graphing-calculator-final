#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include "token.h"
#include "vector.h"
#include "queue.h"
#include "number.h"
#include "variables.h"
#include "operators.h"
#include "function.h"
#include "exponents.h"
#include "parentheses.h"

class Tokenizer{
public: Tokenizer(string s){
        str = s;
        size = str.length();
    }

public: void process(){
            for (int i=0; i< size; i++){
            if (str.at(i)==' '){
                strArr.pushback(temp);
                temp = "";
            }
            else {
                temp += str.at(i);
            }
        }
            strArr.pushback(temp);
            temp = "";
    }

public: Queue<Token*> tokenize(){
        while(!strArr.empty()){
            string str = strArr.top();

            if (str=="+" || str=="-" || str=="*" || str=="/"){
                Token* tkn = new Operators (str);
                output.pushback(tkn);
            }

            else if(str=="sin"||str=="cos"||str=="tan"
                    ||str=="sec"||str=="csc"||str=="cot"){
                Token* tkn = new Functions (str);
                output.pushback(tkn);
            }

            else if(str=="("||str=="{"||str==")"||str=="}"){
                Token* tkn = new  Parentheses(str);
                output.pushback(tkn);
            }

            else if(str=="X"||str=="x"){
                Token* tkn = new  Variable(str);
                output.pushback(tkn);
            }

            else if(str=="^"){
                Token* tkn = new  Exponents(str);
                output.pushback(tkn);
            }

            else{
                Token* tkn = new  Number(str);
                output.pushback(tkn);
            }
            strArr.pop();


        }
        Queue<Token*> pf = output;
        return pf;
    }

public: void show(){
        cout << strArr;
    }



private:
    Queue <string> strArr;
    string str;
    Queue <Token*> output;
    int size;
    string temp;
};

#endif // TOKENIZER_H
