#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H

#include <iostream>
#include <cstdlib>
using namespace std;

class AccessControl {
public:
    static bool transmit() {
        int r = rand() % 2;

        if (r == 0) {
            cout << "[AccessControl] Collision occurred!\n";
            return false;
        } else {
            cout << "[AccessControl] Channel free, transmitting...\n";
            return true;
        }
    }
};

#endif