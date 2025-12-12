#include <iostream>
#include <wx/wx.h>
#include "View.h"
#include <memory>

class MyApp : public wxApp{
public:

    std::shared_ptr<View> view;
    std::shared_ptr<Model> model;
    std::shared_ptr<Controller> controller;

    virtual bool OnInit() override{

            model = std::make_shared<Model>();
            controller = std::make_shared<Controller>(model.get());
            view = std::make_shared<View>(model.get(), controller.get());
            view->init();
            view->Show(true);

            return true;
    }
};

wxIMPLEMENT_APP(MyApp);