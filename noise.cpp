#include "noise.h"
#include <iostream>

//Noise::Noise(int points)
//{
//	for (int i = 0; i < points; i++) {
//		int random_number = rand();
//		std::cout << random_number << std::endl;
//	}
//}
//
//double Noise::f(double x)
//{
//	return 0;
//}

// y = tan1 * t;
// y = tan2 * (1 - t)

double interpolate(double tan1, double tan2, double t)
{
	return tan1 + (tan2 - tan1) * t;
}

double smoothstep(double t)
{
	return t * t * (3 - 2 * t);
}