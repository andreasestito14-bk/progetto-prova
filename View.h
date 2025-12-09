//
// Created by andre on 09/12/2025.
//

#ifndef PRG_1_VIEW_H
#define PRG_1_VIEW_H

#include "Observer.h"
#include "Model.h"
#include <memory>
#include "Controller.h"

class View : public Observer , public std::enable_shared_from_this<View>{

public:

    View(std::shared_ptr<Model> md, std::shared_ptr<Controller> ctr): model(md), controller(ctr){}

    void init(){
        auto sp= model.lock();
        if(sp)
            sp->addObserver(shared_from_this());
    }

    void unregister(){
        auto sp = model.lock();
        if (sp)
            sp->rmvObserver(shared_from_this());
    }

    //TODO: funzione aggiornamento display

    virtual void update() override{
        //TODO: aggiornamento del display...
    }

    //TODO: azioni di aggiornamento display...


    virtual ~View() {
        auto sp = model.lock();
        if (sp)
            sp->rmvObserver(shared_from_this());
    }

private:

    std::weak_ptr<Model> model;
    std::shared_ptr<Controller> controller;


};


#endif //PRG_1_VIEW_H
