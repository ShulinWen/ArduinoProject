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
	void      convert(Operation, int);
	SBUS*     pSBUS;
	Info*     info;
	int*      a_velocity; //v_x, v_y;
	double*   a_angle; //sin_theta, cos_theta;
};

#endif
