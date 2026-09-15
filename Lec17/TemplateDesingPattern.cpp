#include <iostream>
using namespace std;

class ModelTrainer {
public:
    void TrainPipeline(const string& path) {
        load(path);
        preProcess();
        trainModel();
        evaluateModel();
        saveModel();
    }

protected:
    void load(string path) {
        cout<<"[Common] Loading dataset from "<<path<<endl;
    }

    virtual void preProcess() {
        cout<<"[Common] Spliting into training/testing and normalizing"<<endl;
    }

    virtual void trainModel() = 0;

    virtual void evaluateModel() = 0;

    virtual void saveModel() {
        cout<<"[Common] saving model"<<endl;
    }
};


class NeuralNetwork : public ModelTrainer {
public:
    void trainModel() override {
        cout<<"[NeuralNet] Training Neural Network"<<endl;
    }

    void evaluateModel() override {
        cout<<"[NeuralNet] evaluating accuracy and precision of Neural Network"<<endl;
    }

    void saveModel() override {
        cout<<"[NeuralNet] Saving Neural Network"<<endl;
    }
};

class MobileV2 : public ModelTrainer {
public:
    void trainModel() override {
        cout<<"[MobileV2] Training MobileV2"<<endl;
    }

    void evaluateModel() override {
        cout<<"[MobileV2] evaluating accuracy and precision of MobileV2"<<endl;
    }
};

int main() {
    ModelTrainer* neuralNetwork = new NeuralNetwork();
    neuralNetwork -> TrainPipeline("/data/Images");

    ModelTrainer* mobileV2 = new MobileV2();
    mobileV2 -> TrainPipeline("data/plant/Images");
}