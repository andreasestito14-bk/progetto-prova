//
// Created by andre on 09/12/2025.
//

#ifndef PRG_1_VIEW_H
#define PRG_1_VIEW_H

#include "Observer.h"
#include "Model.h"
#include <memory>
#include "Controller.h"
#include "Loader.h"
#include <wx/wx.h>

class View : public Observer ,public wxFrame , public std::enable_shared_from_this<View>{

public:

    View(Model* md, Controller* ctr,  wxWindow* parent=NULL, wxWindowID id =wxID_ANY,
    const wxString& title = "Schermata di caricamento file", const wxPoint& pos =wxDefaultPosition,
    const wxSize& size = wxSize( 500,300 ), long style =wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

    void init();
    void unregister();

    void ChooseFiles(wxCommandEvent&);


    virtual void update(int prg, std::string path) override;

    virtual ~View();

private:
    Model* model;
    Controller* controller;

    wxStaticText* currentFile;
    wxStaticText* percentage;
    wxGauge* gauge;
    wxButton* chooseButton;
    Loader* loader;
};


#endif //PRG_1_VIEW_H
