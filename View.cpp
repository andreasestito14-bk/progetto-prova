//
// Created by andre on 10/12/2025.
//
#include "View.h"

View::View(Model* md, Controller* ctr, wxWindow *parent, wxWindowID id,
const wxString &title, const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style) {

    model = md;
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
    chooseButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::ChooseFiles), NULL, this);

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

        loader = new Loader(controller, files);

        loader->Run();
    }
}




void View::init() {
    model->addObserver(shared_from_this());
}

void View::unregister() {
    model->rmvObserver(shared_from_this());
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
        gauge->SetValue(prg);
    }
}

View::~View(){
        model->rmvObserver(shared_from_this());
        chooseButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::ChooseFiles), NULL, this);


}