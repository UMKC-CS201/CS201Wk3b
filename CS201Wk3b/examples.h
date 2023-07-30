#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void readData(vector<int>& data);
//PRE: vector is empty
//POST: vector is loaded with ONLY numeric values in the input file

void example1();
//PRE:  none
//POST: load a vector with numeric data and print

void example2();
//PRE:  none
//POST: read input file - integer, operand, integer and perform the operation & print results

int example3();
//PRE:  none
//POST: read input from keyboard until a valid value is entered between 1-99, return that integer