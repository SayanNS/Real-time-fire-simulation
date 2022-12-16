#include "noise.h"

std::tuple<double, double> noise(double tan1, double tan2, double t)
{
	return std::make_tuple(tan1 * t, tan2 * (t - 1));
}

double interpolate(std::tuple<double, double> values, double t)
{
	double left, right;
	std::tie(left, right) = values;
	return left * (1 - t) + right * t;
}

double smoothstep(double t)
{
	return t * t * (3 - 2 * t);
}