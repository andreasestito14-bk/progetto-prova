//
// Created by andre on 13/12/2025.
//

#include "Model.h"

void Model::addObserver(std::shared_ptr<Observer> obs){
obsList.push_back(obs);
}

void Model::rmvObserver(std::shared_ptr<Observer> obs){
    for(std::list<std::weak_ptr<Observer>>::iterator itr = obsList.begin(); itr != obsList.end(); ++itr){
        std::shared_ptr<Observer> sp_2 = itr->lock();

        //controllo se è scaduto oppure se corrisponde al puntatore che sto cercando
        if( !sp_2 or sp_2 == obs ){
            itr = obsList.erase(itr);
        }
    }
}

void Model::notify(int prg, std::string path) {

    for(std::list<std::weak_ptr<Observer>>::iterator itr= obsList.begin(); itr!= obsList.end(); ++itr){
        std::shared_ptr<Observer> sp = itr->lock();

        if(sp){
            sp->update(prg, path);
        }
        else
            //elimino weak pointer scaduti
            itr = obsList.erase(itr);
    }

}

int Model::getProgress() {return progress;}

void Model::setProgress(int prg, std::string path) {
    progress = prg;
    notify(prg, path);
}

