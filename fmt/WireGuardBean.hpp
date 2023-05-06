#pragma once

#include "fmt/AbstractBean.hpp"
#include "fmt/V2RayStreamSettings.hpp"

namespace NekoRay::fmt {
    class WireGuardBean : public AbstractBean {
    public:
        QString privateKey = "";
        QString peerPublicKey = "";
        QString reserved = "";
        QString preSharedKey = "";
        int mtu = 1400;

        QSharedPointer<V2rayStreamSettings> stream = QSharedPointer<V2rayStreamSettings>(new V2rayStreamSettings());

        WireGuardBean() : AbstractBean(0) {
            _add(new configItem("privateKey", &privateKey, itemType::string));
            _add(new configItem("peerPublicKey", &peerPublicKey, itemType::string));
            _add(new configItem("reserved", &reserved, itemType::string));
            _add(new configItem("preSharedKey", &preSharedKey, itemType::string));
            _add(new configItem("mtu", &mtu, itemType::integer));
        };

        QString DisplayType() override { return "WireGuard"; };

        CoreObjOutboundBuildResult BuildCoreObjV2Ray() override;

        CoreObjOutboundBuildResult BuildCoreObjSingBox() override;
    };
} // namespace NekoRay::fmt