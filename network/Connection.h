#ifndef CONNECTION_H
#define CONNECTION_H

#include "../devices/Device.h"

class Connection {
private:
    Device* device1;
    Device* device2;

public:
    Connection(Device* d1, Device* d2);

    void transmit(DataPacket packet, Device* sender);
};

#endif