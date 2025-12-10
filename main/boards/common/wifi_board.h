#ifndef WIFI_BOARD_H
#define WIFI_BOARD_H

#include <string>

#include "board.h"

class WifiBoard : public Board {
protected:
    bool wifi_config_mode_ = false;
    bool wifi_connected_notified_ = false;
    void EnterWifiConfigMode();
    virtual std::string GetBoardJson() override;
    virtual void OnWifiConnected(const std::string& /*ssid*/) {}

public:
    WifiBoard();
    virtual std::string GetBoardType() override;
    virtual void StartNetwork() override;
    virtual NetworkInterface* GetNetwork() override;
    virtual const char* GetNetworkStateIcon() override;
    virtual void SetPowerSaveMode(bool enabled) override;
    virtual void ResetWifiConfiguration();
    virtual AudioCodec* GetAudioCodec() override { return nullptr; }
    virtual std::string GetDeviceStatusJson() override;
};

#endif // WIFI_BOARD_H
