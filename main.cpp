#include <iostream>
#include "devices/EndDevice.h"
#include "devices/Hub.h"
#include "network/Connection.h"
#include "devices/Switch.h"

using namespace std;

int main()
{
    // Create hub
    Hub hub(100);
    Switch sw(200);

    // Create 5 end devices
    EndDevice d1(1), d2(2), d3(3), d4(4), d5(5);

    /* first test */
    // Connection conn(&d1, &d2);

    // DataPacket p(1, 2, "Hello");
    // d1.send(p);
    // conn.transmit(p, &d1);

    /* Test 2 */

    // d1.connectHub(&hub);
    // d2.connectHub(&hub);
    // d3.connectHub(&hub);
    // d4.connectHub(&hub);
    // d5.connectHub(&hub);

    // hub.connectDevice(&d1);
    // hub.connectDevice(&d2);
    // hub.connectDevice(&d3);
    // hub.connectDevice(&d4);
    // hub.connectDevice(&d5);

    // DataPacket p(1, 3, "Hello via Hub");
    // d1.send(p);

    /* Test 3 */

    // Connect devices to switch
    d1.connectSwitch(&sw);
    d2.connectSwitch(&sw);
    d3.connectSwitch(&sw);
    d4.connectSwitch(&sw);
    d5.connectSwitch(&sw);

    hub.connectDevice(&d1);
    hub.connectDevice(&d2);
    hub.connectDevice(&d3);
    hub.connectDevice(&d4);
    hub.connectDevice(&d5);

    // Send data from one device
    DataPacket packet(1, 3, "Hello Device 3");
    d1.send(packet);

     // Send again (now MAC table is learned)
    DataPacket p2(1, 3, "Second message");
    d1.send(p2);

    return 0;
}