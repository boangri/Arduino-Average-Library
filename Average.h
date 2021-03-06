/*
	Average.h - Library for computing average values and standard deviation 
	
	Created by Boris A. Gribovskiy, March 7, 2015.
	Released into the public domain
*/
#ifndef AVERAGE_H
#define AVERAGE_H
#define N_AVG 16

#include "Arduino.h"

class Average
{
    public:
		Average(int n);
		void putValue(float value);
		float getAverage();
		float getSigma();
		void reset();
		
    private:
		float _values[N_AVG];
		int _i; // number of measured values
		int _ind; // current index (pointer in array)
		int _n;  // size of array
		float _average;
		float _sigma;
		boolean _valid;
		void calc();
};

#endif
