#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
}

void PID::UpdateError(double cte) {

	static double cte_prev = cte;

	p_error = cte * Kp;

	i_error += cte * Ki;
	if (i_error < -I_limit) {
		i_error = -I_limit;
	} else if (i_error > I_limit) {
		i_error = I_limit;
	}

	d_error = (cte - cte_prev) * Kd;
	cte_prev = cte;
}

double PID::TotalError() {
	return -(p_error + i_error + d_error);
}

