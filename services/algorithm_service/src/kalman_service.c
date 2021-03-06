#include "kalman_service.h"


double KalmanFilter(const double ResrcData, double ProcessNiose_Q, double MeasureNoise_R)
{

    static int isFirstTimeExcuted = 1;

	double R = MeasureNoise_R;
	double Q = ProcessNiose_Q;

	static double x_last = 0;
	double x_mid = x_last;
	double x_now;

	static double p_last = 0;
	double p_mid;
	double p_now;

	double kg;

    if(isFirstTimeExcuted)
	{
        isFirstTimeExcuted = 0;
        x_last = ResrcData;
        p_last = ResrcData;
        return ResrcData;
    }

	x_mid = x_last;
	p_mid = p_last + Q;


	kg = p_mid / (p_mid + R);
	x_now = x_mid + kg * (ResrcData - x_mid);
	p_now = (1 - kg) * p_mid;
	p_last = p_now;
	x_last = x_now;

	return x_now;
}


double KalmanVarFilter(KALMAN_VAR* kalmanVar)
{
	double x_mid = kalmanVar->xlast;
	double x_now;

	double p_mid;
	double p_now;

	double kg;

    if(kalmanVar->isFirstTimeExcuted)
	{
        kalmanVar->isFirstTimeExcuted = 0;
        kalmanVar->xlast = kalmanVar->currentData;
        kalmanVar->plast = kalmanVar->currentData;
        return kalmanVar->currentData;
    }

	x_mid = kalmanVar->xlast;
	p_mid = kalmanVar->plast + kalmanVar->ProcessNiose_Q;


	kg = p_mid / (p_mid + kalmanVar->MeasureNoise_R);
	x_now = x_mid + kg * (kalmanVar->currentData - x_mid);
	p_now = (1 - kg) * p_mid;
	kalmanVar->plast = p_now;
	kalmanVar->xlast = x_now;

	return x_now;
}


