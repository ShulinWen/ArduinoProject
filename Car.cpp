#include "stdafx.h"

Car::Car(){
	r = 1;
	_R = new int[4][3]; // all zero matrix.
	bSetup = false;
}

Car::Car(int* pins) {
	r = 1;
	_R = new int[4][3]; // all zero matrix.
	
	setPins(pins);
					
	bSetup = false;  // haven't setup parameter.
}

void Car::setPins(int* pins){
	wheelGroup = { new Wheel(pins[0], pins[1]), 
				   new Wheel(pins[2], pins[3]), 
				   new Wheel(pins[4], pins[5]), 
				   new Wheel(pins[6], pins[7])
				   };  	//initialize four wheels.	
}

// setup _R and r
void Car::ParameterSetup(double r,
						 double l1, double l2, double l3, double l4,
						 double theta1,double theta2, double theta3, double theta4,
						 double alpha1, double alpha2, double alpha3, double alpha4,
						 double beta1, double beta2, double beta3, double beta4)
{
	this.r = r;
	
	_R[0][0] = cos(theta1 - alpha1) / sin(alpha1) ;
	_R[0][1] = sin(theta1 - alpha1) / sin(alpha1) ;
	_R[0][2] = l1 * sin(theta1 - alpha1 - beta1) / sin(alpha1) ;
	_R[1][0] = cos(theta2 - alpha2) / sin(alpha2) ;
	_R[1][1] = sin(theta2 - alpha2) / sin(alpha2) ;
	_R[1][2] = l2 * sin(theta2 - alpha2 - beta2) / sin(alpha2) ;
	_R[2][0] = cos(theta3 - alpha3) / sin(alpha3) ;
	_R[2][1] = sin(theta3 - alpha3) / sin(alpha3) ;
	_R[2][2] = l3 * sin(theta3 - alpha3 - beta3) / sin(alpha3) ;
	_R[3][0] = cos(theta4 - alpha4) / sin(alpha4) ;
	_R[3][1] = sin(theta4 - alpha4) / sin(alpha4) ;
	_R[3][2] = l4 * sin(theta4 - alpha4 - beta4) / sin(alpha4) ;
	
	bSetup = true;
}
// am simplified version for parameterSetup.
void Car::ParameterSetup(double r, 
					    double p1, double p2, double p3, double p4)
{
	this.r = r; 
	for(int z = 0; z <= 1; z++){
		for(int i = 0; i <= 1; i++)
			for(int j = 0; j <= 1; j++)
				_R[i+2*z][j] = -2*i+1;  /* 就是theta=0的前两列*/
	}
	
	_R[0][2] = p1; _R[1][2] = p2; _R[2][2] = p3; _R[3][2] = p4;
	
	bSetup = true;
}

//assistance for calculating w_i 
double Car::calcSpeed(int i){
	double w_i = - ( 1 / r ) * ( _R[i-1][0] * _v_x 
								 +_R[i-1][1] * _v_y
								 +_R[i-1][2] * omega);
	return w_i;
}

bool Car::move(Info* info){
	if(bSetup){
		//constants used in R
		_v_y = sin(info->s);
		_v_x = cos(info->s);
		omega = info->angle;
		//speed for each wheel
		double _w_1 = calcSpeed(1);
		double _w_2 = calcSpeed(2);
		double _w_3 = calcSpeed(3);
		double _w_4 = calcSpeed(4);
		//move wheel
		wheelGroup[0] -> move(_w_1);
		wheelGroup[1] -> move(_w_2);
		wheelGroup[2] -> move(_w_3);
		wheelGroup[3] -> move(_w_4);
		
		return true;
	}
	else
		return false;
}

bool Car::manualChange(int w, Speed sp){
	if(w >= 0 && w <= 3){
		wheelGroup[w] -> move(sp);
		return true;
	}
	else{
		return false;
	}
}

//destructor for class
Car::~Car() {
	if(wheelGroup) delete wheelGroup; 
	if(_R)         delete _R;
}