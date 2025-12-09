//
// Created by andre on 06/12/2025.
//


#include <iostream>

class Observer {

public:
    virtual void update() = 0;

    virtual ~Observer(){}
};