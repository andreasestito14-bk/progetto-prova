//
// Created by andre on 09/12/2025.
//

#ifndef PRG_1_CONTROLLER_H
#define PRG_1_CONTROLLER_H
#include <iostream>
#include <memory>
#include "Model.h"

class Controller{
public:

    explicit Controller( Model* md): model (md){}

    void increment(){
        int value = model->getCounter();
        value ++;
        model->setCounter(value);
    }
    void decrement(){
        int value = model->getCounter();
        value --;
        model->setCounter(value);;
    }


private:
    Model* model;

};


#endif //PRG_1_CONTROLLER_H
