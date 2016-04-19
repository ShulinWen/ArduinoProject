#include "Wheel.h"

Wheel::Wheel(int d1, int d2, int p1){
	D1 = d1; D2 = d2; P1 = p1;
	sp = 0;  dir = stay;
	setPinMode(D1, D2, P1);
}

void Wheel::setPinMode(int d1, int d2, int p1){
	setPins(d1, d2, p1);
	pinMode(d1, OUTPUT);
	pinMode(d2, OUTPUT);	
	pinMode(p1, OUTPUT);
}

void Wheel::move(Speed s, bool bforward){
	sp = s;
	if( s == 0 ) {
		dir = stay;
		return;
	}
	else
		dir = (direction)(bforward ? 1 : 0 ); // forward 
	if(bforward){
		digitalWrite(D1, HIGH);
		digitalWrite(D2, LOW);
	}else{
		digitalWrite(D1, LOW);
		digitalWrite(D2, HIGH);
	}
	analogWrite(P1, s);
}

void Wheel::setPins(int d1, int d2, int p1){
	D1 = d1; D2 = d2; P1 = p1;
}