//
// Created by andre on 13/12/2025.
//

#include "Model.h"

void Model::addObserver(Observer* obs){
    obsList.push_back(obs);
}

void Model::rmvObserver(Observer* obs){
    obsList.remove(obs);

}

void Model::notify(int prg,const std::string& path) {

    for(std::list<Observer*>::iterator itr= obsList.begin(); itr!= obsList.end(); ++itr){
        (*itr)->update(prg,path);
    }

}

int Model::getProgress() const {return progress;}

void Model::setProgress(int prg, const std::string& path) {
    progress = prg;
    notify(prg, path);
}

Model::~Model() {}