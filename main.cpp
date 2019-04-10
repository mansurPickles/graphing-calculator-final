#include <iostream>
#include "animate.h"
#include "vector.h"
#include "system.h"
#include "random.h"
//#include "plotter.h"
//#include "token.h"
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

using namespace std;

int main()
{
    animate game;

    game.run();
    cout<<endl<<endl<<"------ MAIN EXITING --------------------------"<<endl;
    return 0;
}
