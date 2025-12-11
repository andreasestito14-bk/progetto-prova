//
// Created by andre on 11/12/2025.
//

#include "Loader.h"
#include <wx/event.h>
#include <fstream>



Loader::Loader(Controller* controller, std::vector<std::string>& files): controller(controller), files(files){}

wxThread::ExitCode Loader::Entry(){

    int totalFiles = files.size();
    int currentFile = 0;

    for ( std::string& path : files){
        currentFile++;

        std::ifstream file(path, std::ios::binary);

        if(!file.is_open()){
            //Se il file non è apribile mando -1 come errore
            controller->openingError(-1,path);
        }else{

            //calcolo dimensione
            file.seekg(0, std::ios::end);
            size_t fileSize = file.tellg();
            file.seekg(0, std::ios::beg);

            size_t processed = 0;
            const size_t CHUNK = 4096;
            char buffer[CHUNK];

            while (!TestDestroy() && (file.read(buffer, CHUNK) || file.gcount() > 0))
            {
                processed += file.gcount();

                int progress = (processed *100) / fileSize;
                controller->updatePercentage(progress,path);

            }
        }


    }
    return (wxThread::ExitCode)0;
}