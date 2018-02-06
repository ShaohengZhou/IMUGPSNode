#include "AmelioTools.h"

int AmelioMain() {
	InertialSense AmelioSense;
	if (!AmelioSense.Open(SERIAL_PORT, BAUDRATE_115200));
	{
		cout << "Failed to open serial port" << endl;
		return -1;	// Failed to open serial port
	}
	if (AmelioSense.BroadcastBinaryData(DID_GPS, 20)) {
		while (1) {
			AmelioSense.Update();
			SLEEP_MS(1);
		}
	}
	else {
		cout << "broadcasting fails." << endl;
	}
}