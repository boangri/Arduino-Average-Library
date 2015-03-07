/*
	Average.h - Library for computing average values and standard deviation 
	
	Created by Boris A. Gribovskiy, March 7, 2015.
	Released into the public domain
*/
#ifndef AVERAGE_H
#define AVERAGE_H
#define N_AVG 100

#include "Arduino.h"

class Average
{
    public:
		Average();
		void putValue(float value);
		float getAverage();
		float getSigma();
    private:
		float _values[N_AVG];
		int _ind;
		int _n;
		bool _calc;
		float _avg;
		float _sigma;
};

#endif
