#include <gtest/gtest.h>
#include "../Loader.h"
#include "../Model.h"

class MockObserver1 : public Observer {
public:
    std::vector<int> progresses;
    std::vector<std::string> paths;

    void update(int prg, std::string path) override {
        progresses.push_back(prg);
        paths.push_back(path);
    }
};


TEST(LoaderTest, LoaderNotifiesProgressThroughModel) {

    Model* model = new Model;
    MockObserver1* obs = new MockObserver1;
    model->addObserver(obs);

    std::vector<std::string> files = {"testfile.txt"};

    // simulo un file vuoto
    Loader loader(model, files);
    // chiamata diretta senza thread
    loader.Entry();

    //il loader ha notificato almeno una volta il Model
    EXPECT_FALSE(obs->progresses.empty());
    EXPECT_EQ(obs->paths[0], "testfile.txt");
}

