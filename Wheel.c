#include "stdafx.h"

Wheel::Wheel(int e, int m){
	E = e; M = m;
	sp = 0;  dir = stay;
	setPinMode(E, M);
}

void Wheel::setPinMode(int p1, int p2){
	pinMode(p1, OUTPUT);
	pinMode(p2, OUTPUT);	
}

void Wheel::move(Speed s){
	sp = s;
	if( s == 0 ) {
		dir = stay;
		return;
	}
	else
		dir = s / s;
	digitalWrite(dir);
	analogWrite(s);
}