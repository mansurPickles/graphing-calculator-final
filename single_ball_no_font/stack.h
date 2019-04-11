#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
    Stack<T>(){
                capacity = 500;
                array = new T [capacity];
                used =0;

            }

            ~Stack(){
//                cout << "vector destructor" << endl;

                delete [] array;
            }

            Stack &operator = (const Stack& RHS){
                ClearList();
                capacity = RHS.capacity;
                used = RHS.used;
                array = CopyList(RHS.array,RHS.capacity);
            }

            T* CopyList(T* ptr, int size){
                T* newlist;
                newlist = new T [size];

                for (int i=0; i< size; i++){
                    newlist[i] = ptr[i];
                }

                return newlist;
            }

             T operator [](int order){
                return array[order];
            }



             void ClearList(){
                 for (int i=0; i< used; i++){
                     delete array[i];
                 }
             }

             void pushback(T item){


                 array[used] = item;
                 used++;


             }

             T pop(){
                 --used;
                 return array[used];

             }

             T top ()const {
                 return array[used-1];
             }

             bool empty (){
                 if (used==0){
                     return true;
                 }
                 else {
                     return false;
                 }
             }

             friend ostream& operator <<(ostream& outs, const Stack<T>& a){
                for (int i=0; i< a.used; i++){
                    outs << a.array[i] << " ";
                }
                return outs;

             }

             void reAllocate(){

             }


        public:
            T* array;
            int used;
            int capacity;

        };


#endif // STACK_H
