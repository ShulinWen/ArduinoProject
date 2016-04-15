#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <Arduino.h>
#include "SBUS.h"
class RemoteControl{
public:
	RemoteControl(HardwareSerial&, bool);
	~RemoteControl() { if(pSBUS) delete pSBUS; if(info) delete info; }
	bool receiveMsg();
	Info* getCurrentState() const { return info; }
private:
	void convert();
	SBUS*     pSBUS;
	Info*     info;
};

#endif
