#ifndef PRG_1_LOADER_H
#define PRG_1_LOADER_H

#include <wx/wx.h>
#include <string>
#include "Model.h"

class Loader : public wxThread {
public:

    Loader(Model* model, const std::vector<std::string>& files);

protected:
    virtual ExitCode Entry() override;


private:
    Model* model;
    std::vector<std::string> files;
};

#endif //PRG_1_LOADER_H
