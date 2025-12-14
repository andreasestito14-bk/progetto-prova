#include <iostream>
#include <wx/wx.h>
#include "View.h"
#include <memory>

class MyApp : public wxApp {
public:

    Model* model= nullptr;
    Controller* controller = nullptr;

    virtual bool OnInit() override {
        model = new Model();
        controller = new Controller(model);

        View* view = new View(model, controller);
        view->Show(true);

        return true;
    }

    virtual int OnExit() override {
            delete controller;
            delete model;
            return 0;
    }
};

wxIMPLEMENT_APP(MyApp);
