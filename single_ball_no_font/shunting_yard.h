#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "stack.h"
#include "queue.h"
#include "token.h"
#include "vector.h"


class shunting_yard
{
public:
    shunting_yard(const Queue<Token*>& in);

    void show();

    void calculate();

    Queue<Token*> postfix();


private:
Queue <Token*> inf;
Queue <Token*> outf;
Stack <Token*> s1;
int stackPri;
int currentPri;
};

#endif // SHUNTING_YARD_H
