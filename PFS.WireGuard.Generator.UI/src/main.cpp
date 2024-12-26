#include <QApplication>

#include "MainWindow.h"

#include "ExportLibrary/PFSWireGuardGeneratorCoreAPI.hpp"

using namespace PFSWireGuardGeneratorCore;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
