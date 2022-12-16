#pragma once

#include <tuple>

std::tuple<double, double> noise(double tan1, double tan2, double t);

double interpolate(std::tuple<double, double> values, double t);

double smoothstep(double t);