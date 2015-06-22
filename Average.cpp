/*
	Average.cpp - Library for computing average and standard deviation

	Created by Boris A. Gribovskiy, March 7, 2015.
	Released into the public domain
*/
#include "Arduino.h"
#include "Average.h"

Average::Average(int n)
{
	reset();
	if (n < N_AVG) {
		_n = n;
	} else {
		_n = N_AVG;
	}
}

void Average::reset() {
	_ind = 0;
	_i = 0;
	_valid = false;	
}

void Average::putValue(float value)
{
	if (_i < _n) {
		_i++;
	} 
	_values[_ind] = value;
	_ind++;
	_ind %= _n;
	_valid = false;
}

float Average::getAverage()
{
	if (_valid) {
		return _average;
	} else {
		if (_i == 0) return 0.0;
		calc();
		return _average;
	}
}

float Average::getSigma()
{
	if (_valid) {
		return _sigma;
	} else {
		if (_i < 2) return -1.0; // error
		calc();
		return _sigma;
	}
}

void Average::calc() {
	_average = _sigma = 0.0;
	for (int i = 0; i < _i; i++) {
		float f = _values[i];
		_average += f;
		_sigma += f*f;
	}
	float fi = (float)_i;
	_average /= fi;
	_sigma /= fi;
	_sigma -= _average*_average;
	_sigma /= fi;
	_sigma = sqrt(_sigma);
	_valid = true;
}

