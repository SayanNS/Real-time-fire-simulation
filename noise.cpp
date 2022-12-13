#include "noise.h"

double noise(double tan1, double tan2, double t)
{
	return tan1 * t - smoothstep(t) * (t * (tan1 - tan2) + tan2);
}

double smoothstep(double t)
{
	return t * t * (3 - 2 * t);
}