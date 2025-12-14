#ifndef PRG_1_CONTROLLER_H
#define PRG_1_CONTROLLER_H

#include <vector>
#include <string>
#include "Model.h"
#include "Loader.h"

class Controller {
public:
    explicit Controller(Model* md);
    void startLoading(const std::vector<std::string>& files);

    ~Controller();



private:
    Model* model;
    Loader* loader = nullptr;
};

#endif //PRG_1_CONTROLLER_H
