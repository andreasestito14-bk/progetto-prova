//
// Created by andre on 11/12/2025.
//

#ifndef PRG_1_LOADER_H
#define PRG_1_LOADER_H

#include <wx/wx.h>
#include <iostream>
#include "Controller.h"


class Loader: public wxThread {

public:
    Loader(Controller* controller, std::vector<std::string>& files);

    virtual ExitCode Entry() override;

private:
    Controller* controller;
    std::vector<std::string> files;
};




#endif //PRG_1_LOADER_H
