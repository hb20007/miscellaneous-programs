#pragma once
#include <iostream>
using namespace std;

const int defaultrownum = 20;
const int defaultcolnum = 60;

const int maxrownum = 100;
const int maxcolnum = 100; //Maximum coordinates a user may insert

enum Status { DEAD, ALIVE };

#include "utilities.h" //Note the position of this #include statement. If I put it before it will cause a runtime error cuz utilities.h references the 2 consts and enum defined above 

void welcome();

class Life {
public:
	Life();
	void initialize();
	void print() const;
	void update();
	void setmaxrow(int row);
	void setmaxcol(int col);
	int getmaxrow() const;
	int getmaxcol() const;
private:
	int neighbor_count(int, int) const; 
	Status grid[maxrownum][maxcolnum]; // Contains the alive/dead status of all the cells
	void zeroGrid(); 
	int maxrow;
	int maxcol;
};