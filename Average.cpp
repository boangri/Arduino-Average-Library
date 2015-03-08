/*
	Average.cpp - Library for computing average and standard deviation

	Created by Boris A. Gribovskiy, March 7, 2015.
	Released into the public domain
*/
#include "Arduino.h"
#include "Average.h"

Average::Average(int n)
{
	_ind = 0;
	_i = 0;
	_summa = 0.;
	_summa2 = 0.;
	if (n < N_AVG) {
		_n = n;
	} else {
		_n = N_AVG;
	}
}


void Average::putValue(float value)
{
	if (_i < _n) {
		_i++;
		_fi = (float)_i;
	} 
	if (_i == _n) {
		_summa -= _values[_ind];
		_summa2 -= _values[_ind]*_values[_ind];
	}
	_values[_ind] = value;
	_ind++;
	_ind %= _n;
	_summa += value;
	_summa2 += value*value;
}

float Average::getAverage()
{
	return _summa/_fi;
}

float Average::getSigma()
{
	float avg;
	
	avg = _summa/_fi;
	return sqrt((_summa2/_fi - avg*avg)/_fi);
}
