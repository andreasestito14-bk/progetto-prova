//
// Created by andre on 06/12/2025.
//

#ifndef PRG_1_MODEL_H
#define PRG_1_MODEL_H

#include "Subject.h"
#include <list>

class Model : public Subject {

public:

    virtual void addObserver(std::weak_ptr<Observer> obs) override{
        obsList.push_back(obs);
    }

    virtual void rmvObserver(std::weak_ptr<Observer> obs) override{
        std::shared_ptr<Observer> sp_1 = obs.lock();

        for(std::list<std::weak_ptr<Observer>>::iterator itr = obsList.begin(); itr != obsList.end(); ++itr){
            std::shared_ptr<Observer> sp_2 = itr->lock();
            if( !sp_2 or sp_2 == sp_1 ){
                itr = obsList.erase(itr);
            }
        }
    }



private:

    std::list<std::weak_ptr<Observer>> obsList;



};




#endif //PRG_1_MODEL_H
