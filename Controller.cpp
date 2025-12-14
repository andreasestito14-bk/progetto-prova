#include "Controller.h"

Controller::Controller(Model* md): model(md) {}

void Controller::startLoading(const std::vector<std::string>& files) {
    loader = new Loader(model, files);
    loader->Run();
}

Controller::~Controller() {}