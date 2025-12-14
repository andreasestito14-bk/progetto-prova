#include "Loader.h"
#include <fstream>

Loader::Loader(Model* model, const std::vector<std::string>& files): wxThread(wxTHREAD_DETACHED), model(model), files(files) {}

wxThread::ExitCode Loader::Entry() {
    for(const std::string& path : files) {

        std::ifstream file(path, std::ios::binary);
        if(!file.is_open()) {
            model->setProgress(-1, path);
        }else {

            file.seekg(0, std::ios::end);
            size_t fileSize = file.tellg();
            file.seekg(0, std::ios::beg);

            size_t processed = 0;
            const size_t CHUNK = 4096;
            char buffer[CHUNK];

            while (!TestDestroy() && (file.read(buffer, CHUNK) || file.gcount() > 0)) {
                processed += file.gcount();
                int progress = (processed * 100) / fileSize;
                model->setProgress(progress, path);

                wxMilliSleep(10);
            }


        }
    }

    return (wxThread::ExitCode)0;
}
