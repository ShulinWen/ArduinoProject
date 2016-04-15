#ifndef WHEEL_H
#define WHEEL_H

#include "info.h"
//control wheel.
class Wheel{
public:
	Wheel(int, int);
	~Wheel() = default;
	void      setPins(int, int);  //set/change two pin number for output.
	bool      move(Speed s);
	bool      stop() { move(0); }
	direction getDir() const { return dir; }
	Speed     getSp() const { return sp; }
private:
	void       setPinMode(int, int);  // set Wheel pin modes
	direction dir;
	Speed     sp; // 0 ~ 255
	int       E;
	int       M;
};

#endif