#include "edit_wireguard.h"
#include "ui_edit_wireguard.h"

#include "fmt/WireGuardBean.hpp"

EditWireGuard::EditWireGuard(QWidget *parent) : QWidget(parent), ui(new Ui::EditWireGuard) {
    ui->setupUi(this);
}

EditWireGuard::~EditWireGuard() {
    delete ui;
}

void EditWireGuard::onStart(QSharedPointer<NekoRay::ProxyEntity> _ent) {
    this->ent = _ent;
    auto bean = this->ent->WireGuardBean();

    ui->privateKey->setText(bean->privateKey);
    ui->peerPublicKey->setText(bean->peerPublicKey);
    ui->preSharedKey->setText(bean->preSharedKey);
    ui->reserved->setText(bean->reserved);
    ui->mtu->setText(Int2String(bean->mtu));
}

bool EditWireGuard::onEnd() {
    auto bean = this->ent->WireGuardBean();

    bean->privateKey = ui->privateKey->text();
    bean->peerPublicKey = ui->peerPublicKey->text();
    bean->preSharedKey = ui->preSharedKey->text();
    bean->reserved = ui->reserved->text();
    bean->mtu = ui->mtu->text().toInt();

    return true;
}
