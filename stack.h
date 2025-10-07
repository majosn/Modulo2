//
// Created by majo on 10/7/25.
//

#ifndef STACK_H
#define STACK_H


template <typename T>
class Stack{
private:
    T datos[];
    T tope;
public:
    Stack( ){
        tope = -1;

}
    void push(T Valor){
        tope++;
        datos[tope] = valor;
    };

    T top(){
        return datos[tope]
    }

    void pop(){
        int v = datos[tope];
        tope--;
    };

    bool isEmpty( ){
        return (tope == -1);
    };

    bool isFull( ){
        return (tope == MAX-1);
    }
};


#endif //STACK_H
