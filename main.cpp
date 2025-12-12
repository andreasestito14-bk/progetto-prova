#include <iostream>
#include <wx/wx.h>
#include "View.h"
#include <memory>

class MyApp : public wxApp{
public:

    std::shared_ptr<View> view;

    virtual bool OnInit() override{
            Model* model = new Model();
            Controller* controller = new Controller(model);

            view = std::make_shared<View>(model, controller);
            view->init();
            view->Show(true);

            return true;
    }
};

wxIMPLEMENT_APP(MyApp);