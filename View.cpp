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
    testo = new wxStaticText(panel, wxID_ANY, wxEmptyString);
    btn1 = new wxButton(panel, wxID_ANY, "Aumenta");
    btn2 = new wxButton(panel, wxID_ANY, "Diminuisci");
    gauge = new wxGauge(panel, wxID_ANY, 100, wxDefaultPosition, wxSize(300,25));
    loadButton = new wxButton(panel, wxID_ANY, "Carica");



    //sizer per il layout
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(testo, 0, wxALL | wxALIGN_CENTER_HORIZONTAL);
    vbox->Add(btn1, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    vbox->Add(btn2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    vbox->Add(loadButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    vbox->Add(gauge, 0 ,wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    panel->SetSizer(vbox);

    //barra di stato
    CreateStatusBar();
    SetStatusText("Benvenuto!");

    //timer (simulazione caricamento)
    timer = new wxTimer(this);

    //collego l'evento al controllo
    btn1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::incrementButton), NULL, this);
    btn2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::decrementButton), NULL, this);
    loadButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::loadingButton), NULL, this);
    Bind(wxEVT_TIMER, &View::onTimer, this);
}

//azioni degli eventi
void View::incrementButton(wxCommandEvent& evt){
    controller->increment();
}
void View::decrementButton(wxCommandEvent& evt){
    controller->decrement();
}
void View::loadingButton(wxCommandEvent& evt){
    progress = 0;
    gauge->SetValue(0);
    timer->Start(50);
}

void View::onTimer(wxTimerEvent& evt){
    if(progress < 100){
        progress++;
        gauge->SetValue(progress);
    } else{
        timer->Stop();
        wxMessageBox("Caricamento completato");
    }
}


void View::init() {
    model->addObserver(shared_from_this());
}

void View::unregister() {
    model->rmvObserver(shared_from_this());
}

void View::update(int c) {
    wxString wxIntString = wxString::Format(wxT("%i"),c);
    testo->SetLabel(wxIntString);

}

View::~View(){
        model->rmvObserver(shared_from_this());
    }