//
// Created by andre on 06/12/2025.
//

#ifndef PRG_1_OBSERVER_H
#define PRG_1_OBSERVER_H

#include <iostream>

class Observer {

public:
    virtual void update(int prg, std::string path) = 0;

    virtual ~Observer() = default;
};

#endif //PRG_1_OBSERVER_H