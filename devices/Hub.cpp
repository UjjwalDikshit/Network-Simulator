#include "Hub.h"
#include <iostream>
using namespace std;

Hub::Hub(int id) : Device(id) {}

void Hub::connectDevice(Device* device) {
    connectedDevices.push_back(device);
}

void Hub::receive(DataPacket packet) {
    cout << "\n[Hub " << deviceID << "] Broadcasting data...\n";

    for (auto device : connectedDevices) {
        // Do not send back to sender
        if (device->getID() != packet.senderID) {
            device->receive(packet);
        }
    }
}