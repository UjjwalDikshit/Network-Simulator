#ifndef DEVICE_H
#define DEVICE_H

#include "../utils/DataPacket.h"

class Device {
protected:
    int deviceID;

public:
    Device(int id) {
        deviceID = id;
    }

    int getID() {
        return deviceID;
    }

    virtual void receive(DataPacket packet) = 0;
};

#endif