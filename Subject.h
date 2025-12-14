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

    virtual void addObserver(Observer* obs) = 0;
    virtual void rmvObserver(Observer* obs) = 0;
    virtual void notify(int prg,const std::string& path) = 0;

    virtual ~Subject() = default;


};

#endif //PRG_1_SUBJECT_H