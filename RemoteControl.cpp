#include "RemoteControl.h"
RemoteControl::RemoteControl(HardwareSerial& serial, bool bTimer){
	pSBUS = new SBUS(serial);
	info = new Info();
	//set initial speed data
	parameters = new int[2];
	
	pSBUS->begin(bTimer);
}
bool RemoteControl::receiveMsg(){
	pSBUS->process();
	
	//use convert to set Info*
	if(pSBUS->getNormalizedChannel(2) < 0)
		convert(opfward, pSBUS->getNormalizedChannel(2)); // [-90 ~ 0)
	if(pSBUS->getNormalizedChannel(2) >= 0)
		convert(opbward, pSBUS->getNormalizedChannel(2)); // [0 ~ 69]
//	if(pSBUS->getNormalizedChannel(1) < 0)
//		convert(left_shift, pSBUS->getNormalizedChannel(1)); // [-65 ~ 0)
//	if(pSBUS->getNormalizedChannel(1) >=0)
//		convert(right_shift, pSBUS->getNormalizedChannel(1)); // [0 ~ 68]
	
}


void RemoteControl::convert(operation op, int v){
// underdevelopment
/*convert information from different channel to 
	information { speed, direction, angle };
	*/
	switch(op){
		case opfward:
			parameters[s_y] = map(v, -90, 0, 0, 255);
			info->dir = forward;
			break;
		case opbward:
			parameters[s_y] = map(v, 0, 69, 0, 255);
			info->dir = backward;
			break;
		case left_shift:
			parameters[s_x] = map(v, -65, 0, 0, 255);
			info->dir = ltranslation;
			break;
		case right_shift:
			parameters[s_y] = map(v, 0, 68, 0, 255);
			info->dir = rtranslation;
			break;
	}
	
	info->s = sqrt(parameters[s_x]*parameters[s_x] + parameters[s_y]*parameters[s_y]);
}