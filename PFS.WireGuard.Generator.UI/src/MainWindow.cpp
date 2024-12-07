#include "MainWindow.h"
#include "QMessageBox"
#include "./ui_MainWindow.h"

using namespace PFSWireGuardGeneratorCore;

void initializeServer(Server& server, Ui::MainWindow* ui);
void initializeClients(const Server& server,QStringList& clients_list, QComboBox *clients_combo_box);
void initializeClient(const Client& client, Ui::MainWindow* ui);

void clearClientFields(Ui::MainWindow* ui);
void clearServerFields(Ui::MainWindow* ui);

void showEditButtons(Ui::MainWindow* ui);
void hideEditButtons(Ui::MainWindow* ui);

void blockClientFields(Ui::MainWindow* ui);
void blockServerFields(Ui::MainWindow* ui);

void unblockClientFields(Ui::MainWindow* ui);
void unblockServerFields(Ui::MainWindow* ui);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), _server("MainServer"),
    _clients_combo_box(nullptr), _clients_list {}
{
    ui->setupUi(this);

    ui->save_button->hide();
    ui->cancel_button->hide();


    //Configurator::configureServerToFile(_server, _server.getName() + ".conf");

    initializeServer(_server, ui);

    QVBoxLayout *layout = new QVBoxLayout(this);
    _clients_combo_box = findChild<QComboBox*>("clients_combo_box");


    if (_clients_combo_box) {
        _clients_combo_box->setEditable(true);

        initializeClients(_server, _clients_list, _clients_combo_box);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void initializeServer(Server& server, Ui::MainWindow* ui)
{
    server = PFSWireGuardGeneratorCore::Configurator::getServer("MainServer.conf");
    ui->server_name_text_box->setText(QString::fromStdString(server.getName()));
    ui->server_addres_text_box->setText(QString::fromStdString(server.getAddress()));
    ui->server_listen_port_text_box->setText(QString::fromStdString(server.getListenPort()));

    ui->server_post_ups_text_box->setText(QString::fromStdString(server.getPostUps().front() +
                                                          '\n' +server.getPostUps().back()));
    ui->server_pre_downs_text_box->setText(QString::fromStdString(server.getPreDowns().front() +
                                                          '\n' + server.getPreDowns().back()));

    ui->server_number_of_clients_text_box->setText(QString::number(server.getClients().size()));
}

void initializeClients(const Server& server, QStringList& clients_list, QComboBox *clients_combo_box)
{

    clients_list.clear();
    clients_combo_box->clear();

    for(const auto& client : server.getClients())
    {
        clients_list.append(QString::fromStdString(client.getUserName()));
    }

    clients_combo_box->addItems(clients_list);

    QCompleter *completer = new QCompleter(clients_list, nullptr);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    clients_combo_box->setCompleter(completer);

    clients_combo_box->setCurrentIndex(-1);
    clients_combo_box->setCurrentText("");

}

void initializeClient(const Client& client, Ui::MainWindow* ui)
{
    ui->client_user_name_text_box->setText(QString::fromStdString(client.getUserName()));
    ui->client_address_text_box->setText(QString::fromStdString(client.getAddress()));
    ui->client_DNS_text_box->setText(QString::fromStdString(client.getDNS()));
    ui->client_allowed_ips_text_box->setText(QString::fromStdString(client.getAllowedIps().back()));
    ui->client_endpoint_text_box->setText(QString::fromStdString(client.getEndpoint()));
    ui->client_persistent_keepalive_text_box->setText(QString::fromStdString(client.getPersistentKeepalive()));
}

void clearClientFields(Ui::MainWindow* ui)
{
    ui->client_user_name_text_box->clear();
    ui->client_address_text_box->clear();
    ui->client_DNS_text_box->clear();
    ui->client_allowed_ips_text_box->clear();
    ui->client_endpoint_text_box->clear();
    ui->client_persistent_keepalive_text_box->clear();
}

void clearServerFields(Ui::MainWindow* ui)
{
    ui->server_name_text_box->clear();
    ui->server_addres_text_box->clear();
    ui->server_listen_port_text_box->clear();
    ui->server_post_ups_text_box->clear();
    ui->server_pre_downs_text_box->clear();
}

void showEditButtons(Ui::MainWindow* ui)
{
    ui->edit_button->hide();
    ui->delete_button->hide();

    ui->save_button->show();
    ui->cancel_button->show();
}

void hideEditButtons(Ui::MainWindow* ui)
{
    ui->save_button->hide();
    ui->cancel_button->hide();

    ui->edit_button->show();
    ui->delete_button->show();
}

void blockClientFields(Ui::MainWindow* ui)
{
    ui->client_user_name_text_box->setReadOnly(true);
    ui->client_address_text_box->setReadOnly(true);
    ui->client_DNS_text_box->setReadOnly(true);
    ui->client_allowed_ips_text_box->setReadOnly(true);
    ui->client_endpoint_text_box->setReadOnly(true);
    ui->client_persistent_keepalive_text_box->setReadOnly(true);
}

void blockServerFields(Ui::MainWindow* ui)
{
    ui->server_name_text_box->setReadOnly(true);
    ui->server_addres_text_box->setReadOnly(true);
    ui->server_listen_port_text_box->setReadOnly(true);
    ui->server_post_ups_text_box->setReadOnly(true);
    ui->server_pre_downs_text_box->setReadOnly(true);
}

void unblockClientFields(Ui::MainWindow* ui)
{
    ui->client_user_name_text_box->setReadOnly(false);
    ui->client_address_text_box->setReadOnly(false);
    ui->client_DNS_text_box->setReadOnly(false);
    ui->client_allowed_ips_text_box->setReadOnly(false);
    ui->client_endpoint_text_box->setReadOnly(false);
    ui->client_persistent_keepalive_text_box->setReadOnly(false);
}

void unblockServerFields(Ui::MainWindow* ui)
{
    ui->server_name_text_box->setReadOnly(false);
    ui->server_addres_text_box->setReadOnly(false);
    ui->server_listen_port_text_box->setReadOnly(false);
    ui->server_post_ups_text_box->setReadOnly(false);
    ui->server_pre_downs_text_box->setReadOnly(false);
}

void MainWindow::on_edit_button_clicked(int active_tab)
{
    showEditButtons(ui);
    is_editing = true;
    ui->add_client_button->setEnabled(false);

    switch (active_tab)
    {
    case 0:
        ui->clients_tab->setEnabled(false);
        unblockServerFields(ui);
        break;
    case 1:
        unblockClientFields(ui);
        ui->server_tab->setEnabled(false);
        break;
    default:
        break;
    }
}

void MainWindow::on_edit_button_clicked()
{
    on_edit_button_clicked(ui->info_tabs->currentIndex());
}

void MainWindow::on_clients_combo_box_activated(int index)
{
    Client& client = _server.getClientByIndex(index);
    initializeClient(client, ui);
}

void MainWindow::on_delete_button_clicked(int active_tab)
{
    switch (active_tab)
    {
    case 0:

        break;
    case 1:
        if(ui->clients_combo_box->currentIndex() != -1)
        {
            int current_index = ui->clients_combo_box->currentIndex();
            QString deleted_user_name = QString::fromStdString(_server.getClientByIndex(current_index).getUserName());

            _server.deleteClientByIndex(current_index);
            Configurator::deleteClientFile(deleted_user_name.toStdString() + ".conf");

            QMessageBox::information(this, "Delete", deleted_user_name + " is deleted.");

            clearClientFields(ui);

            Configurator::configureServerToFile(_server,"MainServer.conf");

            initializeServer(_server, ui);
            initializeClients(_server, _clients_list, _clients_combo_box);

            ui->add_client_button->setEnabled(true);
        }
        break;
    default:
        break;
    }
}

void MainWindow::on_delete_button_clicked()
{
    on_delete_button_clicked(ui->info_tabs->currentIndex());
}

void MainWindow::on_add_client_button_clicked()
{
    showEditButtons(ui);

    ui->server_tab->setEnabled(false);
    ui->add_client_button->setEnabled(false);

    PFSWireGuardGeneratorCore::Client client("");

    client.setAddress(_server.getNextFreeIP() + "/32");

    clearClientFields(ui);
    initializeClient(client, ui);

    unblockClientFields(ui);
}

void MainWindow::on_save_button_clicked(int active_tab)
{
    Client tmp("TMP");

    Client& current_client = is_editing ? _server.getClientByIndex(ui->clients_combo_box->currentIndex())
                                        : tmp;

    switch (active_tab)
    {
    case 0:
        break;
    case 1:
        if (is_editing)
        {
            Configurator::renameClientFile(current_client.getUserName() + ".conf",
                                           ui->client_user_name_text_box->toPlainText().toStdString() + ".conf");

            current_client.setUserName(ui->client_user_name_text_box->toPlainText().toStdString());
            current_client.setAddress(ui->client_address_text_box->toPlainText().toStdString());
        }
        else
        {
            current_client.setUserName(ui->client_user_name_text_box->toPlainText().toStdString());
            current_client.setDNS(ui->client_DNS_text_box->toPlainText().toStdString());
            current_client.setEndpoint(ui->client_endpoint_text_box->toPlainText().toStdString());
            current_client.setPersistentKeepalive(ui->client_persistent_keepalive_text_box->toPlainText().toStdString());

            current_client = AdapterAPI::configure(current_client);

            _server.addClient(current_client);
        }

        Configurator::configureServerToFile(_server, "MainServer.conf");
        Configurator::configureClientToFile(current_client, current_client.getUserName() + ".conf");

        hideEditButtons(ui);

        ui->server_tab->setEnabled(true);
        ui->add_client_button->setEnabled(true);

        blockClientFields(ui);

        initializeServer(_server, ui);
        initializeClients(_server, _clients_list, _clients_combo_box);

        is_editing = false;

        ui->add_client_button->setEnabled(true);

        break;
    default:
        break;
    }
}

void MainWindow::on_save_button_clicked()
{
    on_save_button_clicked(ui->info_tabs->currentIndex());
    clearClientFields(ui);
}

void MainWindow::on_cancel_button_clicked()
{
    on_cancel_button_clicked(ui->info_tabs->currentIndex());
}

void MainWindow::on_cancel_button_clicked(int active_tab)
{
    switch (active_tab)
    {
    case 0:

        break;
    case 1:
        if(!is_editing)
            _server.deleteClientByIndex(_server.getClients().size() - 1);

        clearClientFields(ui);

        hideEditButtons(ui);

        ui->server_tab->setEnabled(true);
        ui->add_client_button->setEnabled(true);

        initializeClients(_server, _clients_list, _clients_combo_box);

        is_editing = false;

        ui->add_client_button->setEnabled(true);
        break;
    default:
        break;
    }
}


