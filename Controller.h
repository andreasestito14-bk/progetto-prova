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

    explicit Controller( std::shared_ptr<Model> md): model (md){}

    //TODO: azioni del modello...



private:
    std::shared_ptr<Model> model;

};


#endif //PRG_1_CONTROLLER_H
