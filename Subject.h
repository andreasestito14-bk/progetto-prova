//
// Created by andre on 06/12/2025.
//
#ifndef PRG_1_SUBJECT_H
#define PRG_1_SUBJECT_H

#include <iostream>
#include <memory>
#include "Observer.h"

class Subject {

public:

    virtual void addObserver(std::shared_ptr<Observer> obs) = 0;
    virtual void rmvObserver(std::shared_ptr<Observer> obs) = 0;
    virtual void notify(int prg, std::string path) = 0;
    virtual ~Subject(){}


};

#endif //PRG_1_SUBJECT_H