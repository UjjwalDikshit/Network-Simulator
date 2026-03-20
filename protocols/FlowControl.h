#ifndef FLOW_CONTROL_H
#define FLOW_CONTROL_H

#include <iostream>
using namespace std;

class FlowControl {
public:
    static void sendWithAck(string data) {
        cout << "\n[FlowControl] Sending frame: " << data << endl;

        cout << "[FlowControl] Waiting for ACK...\n";

        // simulate ACK
        cout << "[FlowControl] ACK received!\n";
    }
};

#endif