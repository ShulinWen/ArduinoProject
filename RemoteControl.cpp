#include "stdafx.h"
RemoteControl::RemoteControl(HardwareSerial& serial, bool bTimer){
	pSBUS = new SBUS(serial);
	info = new Info();
	
	pSBUS->begin(bTimer);
}
bool RemoteControl::receiveMsg(){
	pSBUS->process();
	//use convert to set Info*
}


void RemoteControl::convert(){
// underdevelopment
/*convert information from different channel to 
	information { speed, direction, angle };
	*/
}