//
// Created by andre on 10/12/2025.
//
#include "View.h"

View::View(Model* md, Controller* ctr, wxWindow *parent, wxWindowID id,
const wxString &title, const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style) {

    model = md;
    model->addObserver(this);
    controller = ctr;

    //creazione del panel
    wxPanel *panel = new wxPanel(this);

    //creazione dei controlli
    currentFile = new wxStaticText(panel, wxID_ANY, wxEmptyString);
    percentage = new wxStaticText(panel, wxID_ANY, "0%");
    gauge = new wxGauge(panel, wxID_ANY, 100, wxDefaultPosition, wxSize(300,25));
    chooseButton = new wxButton(panel, wxID_ANY, "Scegli file");


    //sizer per il layout
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(currentFile, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    vbox->Add(percentage, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    vbox->Add(gauge, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    vbox->Add(chooseButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

    panel->SetSizer(vbox);

    //barra di stato
    CreateStatusBar();
    SetStatusText("Benvenuto!");


    //collego l'evento al controllo
    chooseButton->Bind(wxEVT_BUTTON,&View::ChooseFiles, this);
}

//azioni degli eventi
void View::ChooseFiles(wxCommandEvent& evt ) {
    wxFileDialog dlg(this,"Seleziona file da scaricare", "","","Tutti i file (*.*)|*.*",wxFD_OPEN | wxFD_MULTIPLE);

    if(dlg.ShowModal() == wxID_OK){
        wxArrayString sel;
        dlg.GetPaths(sel);

        std::vector<std::string> files;
        for(wxString& fls : sel){
            files.push_back(fls.ToStdString());
        }

        controller->startLoading(files);
    }
}


void View::update(int prg, std::string path) {
    if(prg == -1){
        currentFile->SetLabel("Impossibile aprire: " + path);
    }
    else if(prg >-1 and prg <100){
        currentFile->SetLabel("Caricando: " + path);
        wxString wxIntString = wxString::Format("%i%%",prg);
        percentage->SetLabel(wxIntString);
        gauge->SetValue(prg);
    }else{
        percentage->SetLabel("Caricamento completato!");
        gauge->SetValue(100);
    }
}

View::~View(){
    model->rmvObserver(this);
}