#pragma once

#include "IGuiManager.hpp"
#include "../DataManager/DataManager.hpp"

#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace masalamo
{

class GuiManager : public IGuiManager
{
public:
    GuiManager(IDataManager& dataManager);
    ~GuiManager() override;
private:
    void createMainWindow();
    IDataManager& dataManager_;
    std::unique_ptr<QLabel> label_;
    std::unique_ptr<QTableWidget> table_;
    std::unique_ptr<QTableWidgetItem> newItem_;
};

} // masalamo
