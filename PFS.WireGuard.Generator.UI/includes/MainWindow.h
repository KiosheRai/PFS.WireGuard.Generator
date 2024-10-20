#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include "ExportLibrary/PFSWireGuardGeneratorCoreAPI.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_edit_button_clicked(bool& is_editing);

    void on_edit_button_clicked();

    void on_clients_combo_box_currentIndexChanged(int index);

    void on_delete_button_clicked(bool checked);

    void on_delete_button_clicked();

private:
    Ui::MainWindow *ui;
    PFSWireGuardGeneratorCore::Server _server;
    bool _is_editing;
    bool _is_client_selected;
};
#endif // MAINWINDOW_H
