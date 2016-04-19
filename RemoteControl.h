#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <Arduino.h>
#include "SBUS.h"
#include "Info.h"

class RemoteControl{
public:
	RemoteControl(HardwareSerial&, bool);
	~RemoteControl() { if(pSBUS) delete pSBUS; if(info) delete info; }
	bool receiveMsg();
	Info* getCurrentState() const { return info; }
private:
	void convert(operation, int);
	SBUS*     pSBUS;
	Info*     info;
	int*      parameters; //s_x, s_y;
};

#endif
