#ifndef WHEEL_H
#define WHEEL_H

#include <Arduino.h>
#include "info.h"
//control wheel.
class Wheel{
public:
	Wheel() : dir(dStay), sp(0), D1(1), D2(2), P1(3) {}
	Wheel(int, int, int);
	~Wheel() = default;
	void      setPins(int, int, int);  //set/change two pin number for output.
	void      move(double);
	void      setPinMode(int, int, int);  // set Wheel pin modes
	bool      stop() { move(0); }
	Direction getDir() const { return dir; }
	double     getSp() const { return sp; }
private:
	Direction dir;
	double     sp; // 0 ~ 255
	int       D1;
	int       D2;
	int       P1;
};

#endif