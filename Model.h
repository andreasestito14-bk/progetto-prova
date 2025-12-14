//
// Created by andre on 06/12/2025.
//

#ifndef PRG_1_MODEL_H
#define PRG_1_MODEL_H

#include "Subject.h"
#include <list>

class Model : public Subject {

public:
    virtual void addObserver(Observer* obs) override;
    virtual void rmvObserver(Observer* obs) override;
    virtual void notify(int prg, const std::string& path) override;

    int getProgress() const;
    void setProgress(int prg, const std::string& path);

    virtual ~Model();

private:
    int progress = 0;
    std::list<Observer*> obsList;

};




#endif //PRG_1_MODEL_H
