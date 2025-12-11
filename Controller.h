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

    void openingError(int percentage, std::string path){
        model->setProgress(percentage, path);
    }
    void updatePercentage(int percentage, std::string path){
        model->setProgress(percentage,path);
    }


private:
    Model* model;


};


#endif //PRG_1_CONTROLLER_H
