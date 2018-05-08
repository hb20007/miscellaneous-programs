#pragma once
#include <iostream>
using namespace std;
#include "life.h"

int max(int, int);
int min(int, int);
bool user_says_yes();
void copy2DArrays(Status destination[maxrownum][maxcolnum], Status source[maxrownum][maxcolnum], int rows, int columns);
