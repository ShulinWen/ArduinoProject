#include "RemoteControl.h"
RemoteControl::RemoteControl(HardwareSerial& serial, bool bTimer){
	pSBUS = new SBUS(serial);
	info = new Info();
	//set initial velocity data
	a_velocity = new int[2];
	
	pSBUS->begin(bTimer);
}
bool RemoteControl::receiveMsg(){
	pSBUS->process();
	
	//use convert to set Info*
	if(pSBUS->getNormalizedChannel(2) < 0)
		convert(opForward, pSBUS->getNormalizedChannel(2)); // [-90 ~ 0)
	if(pSBUS->getNormalizedChannel(2) >= 0)
		convert(opBackward, pSBUS->getNormalizedChannel(2)); // [0 ~ 69]
	if(pSBUS->getNormalizedChannel(1) < 0)
		convert(opLeft_shift, pSBUS->getNormalizedChannel(1)); // [-65 ~ 0)
	if(pSBUS->getNormalizedChannel(1) >=0)
		convert(opRight_shift, pSBUS->getNormalizedChannel(1)); // [0 ~ 68]
	
}


void RemoteControl::convert(operation op, int v){
// underdevelopment
/*convert information from different channel to 
	information { speed, direction, angle };
	*/
	switch(op){
		case opForward:
			a_velocity[v_y] = map(-v, 0, 90, 0, 255);
			break;
		case opBackward:
			a_velocity[v_y] = -map(v, 0, 69, 0, 255);
			break;
		case opLeft_shift:
			a_velocity[v_x] = -map(-v, 0, 65, 0, 255);
			break;
		case opRight_shift:
			a_velocity[v_x] = map(v, 0, 68, 0, 255);
			break;
	}
	angle[sin_theta] = a_velocity[v_y] / sqrt( a_velocity[v_y] * a_velocity[v_y] + a_velocity[v_x] * a_velocity[v_x]);
	angle[cos_theta] = a_velocity[v_x] / sqrt( a_velocity[v_y] * a_velocity[v_y] + a_velocity[v_x] * a_velocity[v_x]);
	info->setVelocity(a_velocity);
	info->setAngle(angle);
}