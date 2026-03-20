#include "Connection.h"
#include <iostream>
using namespace std;

Connection::Connection(Device* d1, Device* d2) {
    device1 = d1;
    device2 = d2;
}

void Connection::transmit(DataPacket packet, Device* sender) {
    cout << "[Connection] Transmitting...\n";

    if (sender == device1) {
        device2->receive(packet);
    } else {
        device1->receive(packet);
    }
}