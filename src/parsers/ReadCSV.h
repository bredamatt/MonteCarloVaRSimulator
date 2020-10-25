#pragma once
#include <string>
#include <vector>
#include <sstream> //istringstream
#include <iostream> // cout
#include <fstream> // ifstream

using namespace std;

/**
 * Reads csv file into table, exported as a vector of vector of doubles.
 * @param inputFileName input file name (full path).
 * @return data as vector of vector of doubles.
 */
vector<vector<double>> parse2DCsvFile(string inputFileName);