#include "edit_ssh.h"
#include "ui_edit_ssh.h"

#include "fmt/SSHBean.hpp"

EditSSH::EditSSH(QWidget *parent) : QWidget(parent), ui(new Ui::EditSSH) {
    ui->setupUi(this);
}

EditSSH::~EditSSH() {
    delete ui;
}

void EditSSH::onStart(QSharedPointer<NekoRay::ProxyEntity> _ent) {
    this->ent = _ent;
    auto bean = this->ent->SSHBean();

    ui->user->setText(bean->user);
    ui->password->setText(bean->password);
    ui->privateKey->setPlainText(bean->privateKey);
    ui->privateKeyPassphrase->setText(bean->privateKeyPassphrase);
    ui->hostKey->setText(bean->hostKey);
    ui->clientVersion->setText(bean->clientVersion);
}

bool EditSSH::onEnd() {
    auto bean = this->ent->SSHBean();

    bean->user = ui->user->text();
    bean->password = ui->password->text();
    bean->privateKey = ui->privateKey->toPlainText();
    bean->privateKeyPassphrase = ui->privateKeyPassphrase->text();
    bean->hostKey = ui->hostKey->text();
    bean->clientVersion = ui->clientVersion->text();

    return true;
}
