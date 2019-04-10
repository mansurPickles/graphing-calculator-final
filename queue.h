#ifndef QUEUE_H
#define QUEUE_H
#include "linked_list_functions.h"
#include "list.h"

template <class T>

class Queue
{
public:
    Queue<T>(){
        used =0;
        front = NULL;
        end = NULL;

    }

    Queue<T>(const Queue<T> & RHS){
        this->front = NULL;
        this->end = NULL;
        this->_queue = RHS._queue;
        this->used = RHS.used;
        this->front = _queue.Begin();
        this->end = _queue.LastNode();

    }



    ~Queue(){}

    //doesnt need

    Queue &operator = (const Queue& RHS){
        front = NULL;
        end = NULL;
        _queue = RHS._queue;
        used = RHS.used;
        front = _queue.Begin();
        end = _queue.LastNode();
    }


    void pushback(T item){
        front = _queue.Begin();
        end = _queue._InsertAfter(item,end);
        used++;
    }

    T pop(){
        T temp = *front;
        front = _queue._DeleteNode(front,front);
        end = _queue.LastNode();
        --used;
        return temp;
    }

    T top() {
        T temp = *front;
        return temp;

    }

    bool empty(){
        if (used==0){
            return true;
        }

        else {
            return false;
        }
    }

    int getUsed(){
        return used;
    }

    template <class U>
    friend ostream& operator <<(ostream& outs, const Queue <U> &a){
        typename List<U>::Iterator start = a.front;
        while (start!=NULL){
            outs<< *start <<  " ";
            start++;
        }
        return outs;
    }




private:

    List <T> _queue;
    int used;
    typename List<T>::Iterator front;
    typename List<T>::Iterator end;


};

#endif // QUEUE_H
