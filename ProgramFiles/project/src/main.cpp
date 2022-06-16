#include "../inc/ApiCommunicator/ApiCommunicator.hpp"
#include "../inc/DataParser/Reader.hpp"
#include "../inc/DataParser/Parser.hpp"
#include "../inc/DataManager/DataManager.hpp"
#include "../inc/GuiManager/GuiManager.hpp"
#include "../inc/Timer/Timer.hpp"

#include <QApplication>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    auto apiCommunicator = std::make_unique<masalamo::ApiCommunicator>();
    auto reader = std::make_unique<masalamo::Reader>(*apiCommunicator);
    auto parser = std::make_unique<masalamo::Parser>(*reader);
    auto timer = std::make_unique<masalamo::Timer>();
    auto dataManager = std::make_shared<masalamo::DataManager>(*parser, *timer);
    auto guiManager = std::make_unique<masalamo::GuiManager>(*dataManager);

    return app.exec();
}