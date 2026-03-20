#ifndef DATA_PACKET_H
#define DATA_PACKET_H

#include <iostream>
using namespace std;

class DataPacket {
public:
    int senderID;
    int receiverID;
    string data;

    DataPacket(int s, int r, string d) {
        senderID = s;
        receiverID = r;
        data = d;
    }

    void display() {
        cout << "Packet from Device " << senderID
             << " to Device " << receiverID
             << " | Data: " << data << endl;
    }
};

#endif