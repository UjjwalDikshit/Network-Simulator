#ifndef SWITCH_H
#define SWITCH_H

#include "Device.h"
#include <map>
#include <vector>

class Switch : public Device {
private:
    std::vector<Device*> connectedDevices;
    std::map<int, Device*> macTable; // deviceID → device pointer

public:
    Switch(int id);

    void connectDevice(Device* device);

    void receive(DataPacket packet);
};

#endif