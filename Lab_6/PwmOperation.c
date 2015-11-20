#include "PwmOperation.h"
#include "System.h"

// set the duty cycle of the timer4 channel 2
void setDutyCycleTim4Ch2(int ccr2) {
	TIM4_CCR2 = ccr2;
}

// set the percentage the motor should turn
int setMotor (float bb) {
	return (bb * (2400-600)) + 600;
}

void ballUp () {
	setDutyCycleTim4Ch2(1230);
}

void ballDown () {
	setDutyCycleTim4Ch2(1160);
}
