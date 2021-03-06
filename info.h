#ifndef INFO_H
#define INFO_H

#include <string.h>

//definition of Macro and types
#define Power double

enum Velocity  {v_x, v_y};								    			// have signs and scale.
enum Angle     {sin_theta, cos_theta};
enum Operation {opForward, opBackward, opLeft_shift, opRight_shift};    // remote control operation types.
enum Direction {dStay = -1, dForward = 1, dBackward = 0, dUndefine = 2};// used in wheel control. use bit manipulation to reverse.

/* information for the car's movement.
 not doing normalization at this class. */
class Info{
public:
	Info() { defaultSetup(); }
	
	Info(int* a_v, double* a_a, double w) {
		if(Varified(a_v, a_a, w)){
			a_velocity = a_v; a_angle = a_a; omega = w; 
		}else{
			defaultSetup();
			//print error information.
		/*	Serial.println("Error angle range: sin theta " + 
			a_a[sin_theta] + " " + " cos theta " + a_a[cos_theta]);*/
		}
	}
	//set and get function.
	void      setVelocity(int* a_v) { a_velocity = a_v; }
	int*      getVelocity() { return a_velocity; }
	void      setAngle(double* a_a) { a_angle = a_a; }
	double*   getAngle() { return a_angle; }
	void      setAngularVelocity(double o) { omega = o; }
	double   getAngularVelocity() { return omega; }
//	void      setDirection(Direction d) { dir = d; }
//	Direction  getDirection() { return dir; }
private:
	void defaultSetup() {
		a_velocity[v_x] = 0; a_velocity[v_y] = 0;
		a_angle[sin_theta] = 0; a_angle[cos_theta] = 1; // theta = 0;
		omega = 0; 
	  //dir = dUndefine;
	}
	
	bool Varified(int* a_v, double* a_a, double w){
		if(Varified(a_a))
			return true;
		else
			return false;
	}
	
/*	bool Varified(double* a_v){
		varify velocity value, underdevelop. 
		return true;
	}
	bool Varified(double* a_v){
		varify angular velocity value, underdevelop. 
		return true;
	}
*/
	//Verify triangular function
	bool Varified(double* a_a){
		if( (a_a[sin_theta] >= -1 && a_a[sin_theta] <= 1) && 
			(a_a[cos_theta] >= -1 && a_a[cos_theta] <= 1) &&
			(a_a[sin_theta] * a_a[sin_theta] + a_a[cos_theta]*a_a[cos_theta] == 1)
	      )
			return true;
		else
			return false;
	}
	
	int*   a_velocity; // abstract concept. 
	double*   a_angle; // 0 ~ 360
	double    omega; /* abstract concept.angular speed, 
						positive sign -> anti-clockwise. negative sign -> clockwise.*/
//	Direction dir;
};

#endif
