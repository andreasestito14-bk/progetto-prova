//
// Created by andre on 13/12/2025.
//

#include "Controller.h"

Controller::Controller(Model *md): model (md){}

void Controller::openingError(int percentage, std::string path){
    model->setProgress(percentage, path);
}

void Controller::updatePercentage(int percentage, std::string path){
    model->setProgress(percentage,path);
}