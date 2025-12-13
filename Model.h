//
// Created by andre on 06/12/2025.
//

#ifndef PRG_1_MODEL_H
#define PRG_1_MODEL_H

#include "Subject.h"
#include <list>

class Model : public Subject {

public:
    virtual void addObserver(std::shared_ptr<Observer> obs) override;
    virtual void rmvObserver(std::shared_ptr<Observer> obs) override;
    virtual void notify(int prg, std::string path) override;

    int getProgress();
    void setProgress(int prg, std::string path);

private:
    int progress = 0;
    std::list<std::weak_ptr<Observer>> obsList;

};




#endif //PRG_1_MODEL_H
