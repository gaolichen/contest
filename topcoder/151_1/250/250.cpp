#include<string>
#include<cmath>
#include<iostream>
using namespace std;

struct Archimedes{
	double pi;
	double approximatePi(int numSides){
		pi=acos(-1.0);
		return sin(pi/(numSides))*numSides;
	}

};