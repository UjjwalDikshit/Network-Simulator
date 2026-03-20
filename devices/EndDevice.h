#ifndef END_DEVICE_H
#define END_DEVICE_H

#include "Device.h"

class Hub; // forward declaration
class Switch;

class EndDevice : public Device {
private:
    Hub* connectedHub;
    Switch* connectedSwitch;

public:
    EndDevice(int id);

    void connectHub(Hub* hub);
    void connectSwitch(Switch* sw);

    void send(DataPacket packet);
    void receive(DataPacket packet);
};

#endif