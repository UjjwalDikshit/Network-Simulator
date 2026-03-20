#ifndef ERROR_CONTROL_H
#define ERROR_CONTROL_H

#include <iostream>
using namespace std;

class ErrorControl {
public:
    // Add parity bit (even parity)
    static string addParity(string data) {
        int count = 0;
        for (char c : data) {
            if (c == '1') count++;
        }

        if (count % 2 == 0)
            return data + "0"; // even parity
        else
            return data + "1";
    }

    // Check parity
    static bool checkParity(string data) {
        int count = 0;
        for (char c : data) {
            if (c == '1') count++;
        }

        return (count % 2 == 0);
    }
};

#endif