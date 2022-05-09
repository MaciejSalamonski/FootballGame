#include "../inc/ApiCommunicator/ApiCommunicator.hpp"
#include "../inc/DataParser/Reader.hpp"
#include "../inc/DataParser/Parser.hpp"
#include "../inc/DataManager/DataManager.hpp"
#include "../inc/Timer/Timer.hpp"

//#include <QApplication>
//#include <QLabel>
//#include <QTableWidget>
//#include <QTableWidgetItem>

#include <string>
#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
    //QApplication app(argc, argv);
    //std::unique_ptr<QLabel> label = std::make_unique<QLabel>("Football Game");
    //std::unique_ptr<QTableWidget> table = std::make_unique<QTableWidget>(3, 3);
    //std::unique_ptr<QTableWidgetItem> newItem = std::make_unique<QTableWidgetItem>("chuj");
    //table->setItem(1, 1, newItem.get());
    //table->show();
    //label->show();

    auto apiCommunicator = std::make_unique<masalamo::ApiCommunicator>();
    auto reader = std::make_unique<masalamo::Reader>(*apiCommunicator);
    auto parser = std::make_unique<masalamo::Parser>(*reader);
    auto timer = std::make_shared<masalamo::Timer>();
    auto dataManager = std::make_unique<masalamo::DataManager>(*parser, *timer);
    //auto dataManager = std::make_unique<masalamo::DataManager>(*parser);
    auto data = dataManager->getData();

    //return app.exec();
    std::string elo;
    while (true)
    {
        std::cin >> elo;
        if(elo == "q")
        {
            break;
        }
    }
    

    return 0;
    //return 0;
}