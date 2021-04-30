#pragma once
#include <vector>

using namespace std;


struct CurrentReadingsParameters{
	int current_min;
	int current_max;
	int number_of_readings;
};


std::vector<int> sortCurrentReadingsData (std::vector<int>&);

void processCurrentReadingsData(std::vector<int>, std::vector<CurrentReadingsParameters*>&);

void displayRangeAndNumberOfReadings(std::vector<CurrentReadingsParameters*>&);
