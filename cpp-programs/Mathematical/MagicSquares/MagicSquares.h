//Function prototypes and constants

#pragma once

const int arrayMaxSize = 20;

int main();
void restart(); 
void menu(std::string &selection); //Note the neccessity of std:: here cuz string is not a purely default datatypes and u need to define a namespace where it's in
void parseInput(std::string &input);
int getSize();
void magicSquareChecker();
void displaySquareArray(int [arrayMaxSize][arrayMaxSize], int arraySize);
bool checkingAlgorithm(int userArray[arrayMaxSize][arrayMaxSize], int arraySize, int& magicSum);
void magicSquareGenerator();