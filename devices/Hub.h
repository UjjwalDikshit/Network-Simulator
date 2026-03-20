#ifndef HUB_H
#define HUB_H

#include "Device.h"
#include <vector>

class Hub : public Device {
private:
    std::vector<Device*> connectedDevices;

public:
    Hub(int id);

    void connectDevice(Device* device);

    void receive(DataPacket packet);  // when hub receives data
};

#endif