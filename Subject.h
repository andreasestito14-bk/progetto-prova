//
// Created by andre on 06/12/2025.
//
#include <iostream>
#include <memory>
#include "Observer.h"

class Subject {

public:

    virtual void addObserver(std::weak_ptr<Observer> obs) = 0;
    virtual void rmvObserver(std::weak_ptr<Observer> obs) = 0;
    virtual void notify() = 0;
    virtual ~Subject(){}


};