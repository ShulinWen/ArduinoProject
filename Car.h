#ifndef CAR_H
#define CAR_H

#include "info.h"
#include "Wheel.h"
//Overall control for the car.
class Car{
public:
	Car() = default;
	Car(int*); 
	~Car();
	
	void setPins(int*);
	void ParameterSetup(double r,
						double l1, double l2, double l3, double l4,
						double theta1,double theta2, double theta3, double theta4,
						double alpha1, double alpha2, double alpha3, double alpha4,
						double beta1, double beta2, double beta3, double beta4); // Setup car's parameter for use in movement
	void ParameterSetup(double r, 
						double p1, double p2, double p3, double p4);
	bool Move(Info*); /* direct the car to move according to info
						{Speed, Angle , direction} */
						
	void manualChange(int w, Speed sp); /* manually change the state of wheel */
	
	double getSpeed() const { return sqrt(_v_y * _v_y + _v_x * _v_x); }
	double getAngle() const { return omega; }
					  
private:
	double      calcSpeed(int i);
	Wheel     **wheelGroup; 	//an Array to store the pointers of the four wheels
	double    **_R; //only for the matrix, it is not R
	double    r;   //default r = 1
	double    _v_y; // car's speed in y axis. (m/s)
	double    _v_x;
	double    omega; // car's rotation angle. (-180~180);
	bool      bSetup; // check for setup of parameters.
};

#endif
