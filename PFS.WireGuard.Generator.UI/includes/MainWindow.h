#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QComboBox>
#include <QCompleter>
#include <QStringListModel>
#include <QVBoxLayout>
#include <QWidget>
#include <QApplication>

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

    void on_edit_button_clicked(int active_tab);

    void on_edit_button_clicked();

    void on_delete_button_clicked(int active_tab);

    void on_delete_button_clicked();

    void on_add_client_button_clicked();

    void on_save_button_clicked(int active_tab);

    void on_save_button_clicked();

    void on_cancel_button_clicked();

    void on_cancel_button_clicked(int active_tab);

    void on_clients_combo_box_activated(int index);



private:
    Ui::MainWindow *ui;
    PFSWireGuardGeneratorCore::Server _server;

    QComboBox* _clients_combo_box;
    QStringList _clients_list;

    bool is_editing = false;
};
#endif // MAINWINDOW_H
