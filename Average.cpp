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
	if (n < 100) {
		_n = n;
	} else {
		_n = N_AVG;
	}
	_calc = true; // new calulation is necessary
}


void Average::putValue(float value)
{
	_values[_ind] = value;
	_ind++;
	_ind %= _n;
	if (_i < _n) _i++;
	_calc = true;
}

float Average::getAverage()
{
	if (_calc) {
		float fn = (float)_i;
		for(int j = 0; j < _n; j++) {
			_avg += _values[j];
			_sigma += _values[j]*_values[j];
		}
		_avg /= fn;
		_sigma /= fn;
		_sigma = sqrt((_sigma - _avg*_avg)/fn);
	}
	_calc = false;
	return _avg;
}

float Average::getSigma()
{
	if(_calc) Average::getAverage();
	return _sigma;
}
