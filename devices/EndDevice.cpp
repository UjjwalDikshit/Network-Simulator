#include "EndDevice.h"
#include "Hub.h"
#include "Switch.h"
#include "../utils/ErrorControl.h"
#include "../protocols/FlowControl.h"
#include "../protocols/AccessControl.h"

#include <iostream>
using namespace std;

EndDevice::EndDevice(int id) : Device(id) {
    connectedHub = nullptr;
    connectedSwitch = nullptr;
}

void EndDevice::connectHub(Hub* hub) {
    connectedHub = hub;
}


void EndDevice::connectSwitch(Switch* sw) {
    connectedSwitch = sw;
}

void EndDevice::send(DataPacket packet) {
    cout << "\n[EndDevice " << deviceID << "] Sending data...\n";

    // Step 1: Access Control
    if (!AccessControl::transmit()) {
        cout << "Retrying...\n";
        return;
    }

    // Step 2: Error Control
    string binaryData = "1010101"; // dummy binary
    string withParity = ErrorControl::addParity(binaryData);

    cout << "[ErrorControl] Data with parity: " << withParity << endl;

    // Step 3: Flow Control
    FlowControl::sendWithAck(withParity);

    // Step 4: Send to network
    packet.display();

    if (connectedSwitch) {
        connectedSwitch->receive(packet);
    } 
    else if (connectedHub) {
        connectedHub->receive(packet);
    } 
    else {
        cout << "No connection!\n";
    }
}

void EndDevice::receive(DataPacket packet) {
    if (packet.receiverID == deviceID) {
        cout << "[EndDevice " << deviceID << "] Received data: "
             << packet.data << endl;
    }
}