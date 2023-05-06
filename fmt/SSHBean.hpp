#pragma once

#include "fmt/AbstractBean.hpp"
#include "fmt/V2RayStreamSettings.hpp"

namespace NekoRay::fmt {
    class SSHBean : public AbstractBean {
    public:
        QString user = "root";
        QString password = "";
        QString privateKey = "";
        QString privateKeyPassphrase = "";
        QString hostKey = "";
        QString clientVersion = "";

        QSharedPointer<V2rayStreamSettings> stream = QSharedPointer<V2rayStreamSettings>(new V2rayStreamSettings());

        SSHBean() : AbstractBean(0) {
            _add(new configItem("user", &user, itemType::string));
            _add(new configItem("password", &password, itemType::string));
            _add(new configItem("privateKey", &privateKey, itemType::string));
            _add(new configItem("privateKeyPassphrase", &privateKeyPassphrase, itemType::string));
            _add(new configItem("hostKey", &hostKey, itemType::string));
            _add(new configItem("clientVersion", &clientVersion, itemType::string));
        };

        QString DisplayType() override { return "SSH"; };

        // CoreObjOutboundBuildResult BuildCoreObjV2Ray() override;

        CoreObjOutboundBuildResult BuildCoreObjSingBox() override;
    };
} // namespace NekoRay::fmt