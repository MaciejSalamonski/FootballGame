#include "../../inc/GuiManager/GuiManager.hpp"

#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>

#include <iostream>

namespace masalamo
{

GuiManager::GuiManager(IDataManager& dataManager)
    : dataManager_(dataManager)
{
    this->createMainWindow();
}

GuiManager::~GuiManager() = default;

void GuiManager::createMainWindow()
{
    std::cout << "createMainWindow" << '\n';
    label_ = std::make_unique<QLabel>("Football Game");
    table_ = std::make_unique<QTableWidget>(3, 3);
    newItem_ = std::make_unique<QTableWidgetItem>(QString::number(101));
    table_->setItem(1, 1, newItem_.get());
    table_->show();
    label_->show();
}

} // masalamo