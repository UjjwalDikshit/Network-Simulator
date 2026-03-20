#include "Switch.h"
#include <iostream>
using namespace std;

Switch::Switch(int id) : Device(id) {}

void Switch::connectDevice(Device* device) {
    connectedDevices.push_back(device);
}

void Switch::receive(DataPacket packet) {
    cout << "\n[Switch " << deviceID << "] Received packet\n";

    // Step 1: Learn sender
    macTable[packet.senderID] = nullptr;
    for (auto device : connectedDevices) {
        if (device->getID() == packet.senderID) {
            macTable[packet.senderID] = device;
        }
    }

    cout << "[Switch] Learned Device " << packet.senderID << endl;

    // Step 2: Check if receiver is known
    if (macTable.find(packet.receiverID) != macTable.end()) {
        cout << "[Switch] Forwarding to Device "
             << packet.receiverID << endl;

        Device* target = macTable[packet.receiverID];
        if (target) {
            target->receive(packet);
        }
    } else {
        // Step 3: Broadcast if unknown
        cout << "[Switch] Unknown receiver → Broadcasting\n";

        for (auto device : connectedDevices) {
            if (device->getID() != packet.senderID) {
                device->receive(packet);
            }
        }
    }
}