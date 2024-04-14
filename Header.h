#pragma once
#include <iostream>
#include <iomanip>
#include "math.h"
using namespace std;

double funxy(double x, double y) {
	return 2 * x * x + 4 * x * y + 8 * y * y + 100;
}
double funxh(double h) {
	return 2 * (5+h)*(5+h) + 4 * (5 + h) * 5 + 8 * 5 * 5 + 100;
}
double funyh(double h) {
	return 2 * 5 * 5 + 4 * (5 + h) * 5 + 8 *(5+h)*(5+h) + 100;
}
double met_sechenx(double a, double b, double eps) {
	double tao = (sqrt(5) - 1) / 2;
	double x1 = a + (1 - tao) * (b - a);
	double x2 = a + tao * (b - a);
	double fx1 = funxh(x1);
	double fx2 = funxh(x2);
	int i = 1;
	while (abs(b - a) > eps) {
		i++;
		if (fx1 > fx2) {
			a = x1;
			x1 = x2;
			x2 = a + tao * (b - a);
			fx1 = fx2;
			fx2 = funxh(x2);

		}
		else {
			b = x2;
			x2 = x1;
			x1 = a + (1 - tao) * (b - a);
			fx2 = fx1;
			fx1 = funxh(x1);

		}
	}
	double min = (b + a) / 2;
	return min;

}
double met_secheny(double a, double b, double eps) {
	double tao = (sqrt(5) - 1) / 2;
	double x1 = a + (1 - tao) * (b - a);
	double x2 = a + tao * (b - a);
	double fx1 = funyh(x1);
	double fx2 = funyh(x2);
	int i = 1;
	while (abs(b - a) > eps) {
		i++;
		if (fx1 > fx2) {
			a = x1;
			x1 = x2;
			x2 = a + tao * (b - a);
			fx1 = fx2;
			fx2 = funyh(x2);

		}
		else {
			b = x2;
			x2 = x1;
			x1 = a + (1 - tao) * (b - a);
			fx2 = fx1;
			fx1 = funyh(x1);

		}
	}
	double min = (b + a) / 2;
	return min;

}
void coordinateDescent(double x, double y, double eps) {
	double epsi = 0.001;
	double a = -20;
	double b = 20;
	double h = met_sechenx(a,b,epsi);
	double x1 = x + h;
	double x2 = y;
	h = met_sechenx(a, b, eps);
	x2 = x2 + h;
	
}