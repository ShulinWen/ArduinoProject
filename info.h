#ifndef INFO_H
#define INFO_H

//definition of Macro and types
#define Speed double
#define Angle double
#define Power double
enum direction {stay = -1, forward = 1, backward = 0};

// information for the car's movement.
class Info{
public:
	Info() = default;
	Info(Speed sp, Angle a, direction d) {
		if(Varified(sp, a, d)){
			s = sp; angle = a; dir = d;
		}else{
			dir = stay;
			s = angle = 0; //print error information.
		}
	}
	Speed     s;
	Angle     angle;
	direction dir;
private:
	bool Varified(Speed sp, Angle a, direction dir){
		if((sp >= 0 && sp <= 255)
		&& (a >= -180 && a <= 180)
		&& (dir == stay || dir == forward || dir == backward))
			return true;
		else
			return false;
	}
};

#endif
