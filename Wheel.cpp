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

void Wheel::move(double velocity){
	if(velocity < 0) {
		dir = dBackward;
		sp = -velocity;
	}else{
		dir = dForward;
		sp = velocity
	}
	
	if( sp == 0 ) {
		dir = stay;
		return;
	}
	
	if(dForward){
		digitalWrite(D1, HIGH);
		digitalWrite(D2, LOW);
	}else{
		digitalWrite(D1, LOW);
		digitalWrite(D2, HIGH);
	}
	if(sp > 255) sp = 255;
		analogWrite(P1, sp);
}

void Wheel::setPins(int d1, int d2, int p1){
	D1 = d1; D2 = d2; P1 = p1;
}