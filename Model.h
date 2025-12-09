//
// Created by andre on 06/12/2025.
//

#ifndef PRG_1_MODEL_H
#define PRG_1_MODEL_H

#include "Subject.h"
#include <list>

class Model : public Subject {

public:

    virtual void addObserver(std::shared_ptr<Observer> obs) override{
        obsList.push_back(obs);
    }

    virtual void rmvObserver(std::shared_ptr<Observer> obs) override{
        for(std::list<std::weak_ptr<Observer>>::iterator itr = obsList.begin(); itr != obsList.end(); ++itr){
            std::shared_ptr<Observer> sp_2 = itr->lock();

            //controllo se è scaduto oppure se corrisponde al puntatore che sto cercando
            if( !sp_2 or sp_2 == obs ){
                itr = obsList.erase(itr);
            }
        }
    }

    virtual void notify() override {

        for(std::list<std::weak_ptr<Observer>>::iterator itr= obsList.begin(); itr!= obsList.end(); ++itr){
            std::shared_ptr<Observer> sp = itr->lock();

            if(sp){
                sp->update();
            }
            else
                //elimino weak pointer scaduti
                itr = obsList.erase(itr);
        }

    }


private:

    std::list<std::weak_ptr<Observer>> obsList;



};




#endif //PRG_1_MODEL_H
