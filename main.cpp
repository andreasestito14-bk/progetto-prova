#include <iostream>
#include <wx/wx.h>
#include "View.h"
#include <memory>
/*
class MyApp : public wxApp{
public:
    virtual bool OnInit() override{
        std::shared_ptr<Model> md = std::make_shared<Model>();
        std::shared_ptr<Controller> ctr = std::make_shared<Controller>(md);

        std::shared_ptr<View> vw = std::make_shared<View>(md,ctr);
        vw->init();

        vw->Show(true);
        return true;


    }
};
 */
class MyApp : public wxApp{
public:
    std::shared_ptr<Model> model;
    std::shared_ptr<Controller> controller;
    std::shared_ptr<View> view;

    virtual bool OnInit() override{
            model = std::make_shared<Model>();
            controller = std::make_shared<Controller>(model);

            view = std::make_shared<View>(model, controller);
            view->init();
            view->Show(true);

            return true;
    }
};

wxIMPLEMENT_APP(MyApp);