#include <gtest/gtest.h>
#include "../Model.h"

// Mock di Observer
class MockObserver2 : public Observer {
public:
    int lastProgress = -1;
    std::string lastPath;
    virtual void update(int prg, std::string path) override {
        lastProgress = prg;
        lastPath = path;
    }
};

TEST(TestModel, AddAndNotifyObserver) {
    Model* m = new Model;
    MockObserver2* obs = new MockObserver2;

    m->addObserver(obs);
    m->setProgress(50, "file1.txt");

    EXPECT_EQ(obs->lastProgress, 50);
    EXPECT_EQ(obs->lastPath, "file1.txt");
}

TEST(TestModel, RemoveObserver) {
    Model* m = new Model;
    MockObserver2* obs = new MockObserver2;

    m->addObserver(obs);
    m->rmvObserver(obs);
    m->setProgress(70, "file2.txt");

    // observer rimosso -> non deve ricevere update
    EXPECT_NE(obs->lastProgress, 70);
}
