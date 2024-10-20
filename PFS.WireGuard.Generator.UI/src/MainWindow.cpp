#include "MainWindow.h"
#include "QMessageBox"
#include "./ui_MainWindow.h"

using namespace PFSWireGuardGeneratorCore;

void initializeServer(const Server& server, Ui::MainWindow* ui);
void initializeClients(const Server& server, Ui::MainWindow* ui);

void clearClientFields(const Server& server, Ui::MainWindow* ui);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), _server("MainServer"),
    _is_editing(true), _is_client_selected(false)
{
    ui->setupUi(this);

    PFSWireGuardGeneratorCore::Client client("kekes12"), client2("JOra)"), client3("mrAladin");

    _server.addClient(client);
    _server.addClient(client2);
    _server.addClient(client3);

    initializeServer(_server, ui);
    initializeClients(_server, ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void initializeServer(const Server& server, Ui::MainWindow* ui)
{
    ui->server_name_text_box->setText(QString::fromStdString(server.getName()));
    ui->server_addres_text_box->setText(QString::fromStdString(server.getAddress()));
    ui->server_listen_port_text_box->setText(QString::fromStdString(server.getListenPort()));

    ui->server_post_ups_text_box->setText(QString::fromStdString(server.getPostUps().front() +
                                                          '\n' +server.getPostUps().back()));
    ui->server_pre_downs_text_box->setText(QString::fromStdString(server.getPreDowns().front() +
                                                          '\n' + server.getPreDowns().back()));

    ui->server_number_of_clients_text_box->setText(QString::number(server.getClients().size()));
}

void initializeClients(const Server& server, Ui::MainWindow* ui)
{
    ui->clients_combo_box->blockSignals(true);
    ui->clients_combo_box->clear();
    ui->clients_combo_box->setCurrentIndex(-1);
    ui->clients_combo_box->blockSignals(false);

    for(auto& client : server.getClients())
    {
        ui->clients_combo_box->addItem(QString::fromStdString(client.getUserName()));
    }
}

void clearClientFields(const Server& server, Ui::MainWindow* ui)
{
    ui->client_user_name_text_box->clear();
    ui->client_address_text_box->clear();
    ui->client_DNS_text_box->clear();
    ui->client_allowed_ips_text_box->clear();
    ui->client_endpoint_text_box->clear();
    ui->client_persistent_keepalive_text_box->clear();
}

void MainWindow::on_edit_button_clicked(bool& is_editing)
{
    if(ui->info_tabs->currentIndex() == 0)
    {
        if(is_editing)
        {
            ui->server_name_text_box->setReadOnly(false);
            ui->server_addres_text_box->setReadOnly(false);
            ui->server_listen_port_text_box->setReadOnly(false);
            ui->server_post_ups_text_box->setReadOnly(false);
            ui->server_pre_downs_text_box->setReadOnly(false);
            QMessageBox::information(this, "Editor", "You can edit server fields");
            is_editing = false;
            ui->clients_tab->setEnabled(false);
        }
        else
        {
            ui->server_name_text_box->setReadOnly(true);
            ui->server_addres_text_box->setReadOnly(true);
            ui->server_listen_port_text_box->setReadOnly(true);
            ui->server_post_ups_text_box->setReadOnly(true);
            ui->server_pre_downs_text_box->setReadOnly(true);
            QMessageBox::information(this, "Save", "Your changes are saved!");
            is_editing = true;
            ui->clients_tab->setEnabled(true);
        }
    }
    else
    {
        if(is_editing)
        {
            ui->client_user_name_text_box->setReadOnly(false);
            ui->client_address_text_box->setReadOnly(false);
            ui->client_DNS_text_box->setReadOnly(false);
            ui->client_allowed_ips_text_box->setReadOnly(false);
            ui->client_endpoint_text_box->setReadOnly(false);
            ui->client_persistent_keepalive_text_box->setReadOnly(false);
            QMessageBox::information(this, "Editor", "You can edit client fields");
            is_editing = false;
            ui->server_tab->setEnabled(false);
        }
        else
        {
            ui->client_user_name_text_box->setReadOnly(true);
            ui->client_address_text_box->setReadOnly(true);
            ui->client_DNS_text_box->setReadOnly(true);
            ui->client_allowed_ips_text_box->setReadOnly(true);
            ui->client_endpoint_text_box->setReadOnly(true);
            ui->client_persistent_keepalive_text_box->setReadOnly(true);
            QMessageBox::information(this, "Save", "Your changes are saved!");
            is_editing = true;
            ui->server_tab->setEnabled(true);
        }
    }
}

void MainWindow::on_edit_button_clicked()
{
    on_edit_button_clicked(_is_editing);
}

void MainWindow::on_clients_combo_box_currentIndexChanged(int index)
{
    ui->client_user_name_text_box->setText(QString::fromStdString(_server.getClients()[index].getUserName()));
    ui->client_address_text_box->setText(QString::fromStdString(_server.getClients()[index].getAddress()));
    ui->client_DNS_text_box->setText(QString::fromStdString(_server.getClients()[index].getDNS()));
    ui->client_allowed_ips_text_box->setText(QString::fromStdString(_server.getClients()[index].getAllowedIps().back()));
    ui->client_endpoint_text_box->setText(QString::fromStdString(_server.getClients()[index].getEndpoint()));
    ui->client_persistent_keepalive_text_box->setText(QString::fromStdString(_server.getClients()[index].getPersistentKeepalive()));
    _is_client_selected = true;
}


void MainWindow::on_delete_button_clicked(bool is_client_selected)
{
    if(ui->info_tabs->currentIndex() == 1)
    {
        if(is_client_selected)
        {
            int current_index = ui->clients_combo_box->currentIndex();
            auto new_clients_vector = _server.getClients();
            QString deleted_user_name = QString::fromStdString(_server.getClients()[current_index].getUserName());

            if (current_index >= 0 && current_index < _server.getClients().size())
            {
                new_clients_vector.erase(new_clients_vector.begin() + current_index);
                _server.setClients(new_clients_vector);
                _is_client_selected = false;

                QMessageBox::information(this, "Delete", deleted_user_name + " is deleted.");

            }

            if (_server.getClients().size() == 0) {
                clearClientFields(_server, ui);
                _is_client_selected = false;
            }

            initializeServer(_server, ui);
            initializeClients(_server, ui);
        }
    }
}


void MainWindow::on_delete_button_clicked()
{
    on_delete_button_clicked(_is_client_selected);
}

