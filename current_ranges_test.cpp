#include "current_ranges.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>

int main ()
{
	// Check for No (0) Current readings
  	std::vector<CurrentReadingsParameters*> RangeAndReadings = {};
	processCurrentReadingsData({}, RangeAndReadings);
	assert(RangeAndReadings.empty() == true);
	
	// Number of Ranges in the Current Readings
  	std::vector<CurrentReadingsParameters*> RangeAndReadings = {};
	processCurrentReadingsData({ 1, 2, 2, 3, 4, 24, 25, 26 }, RangeAndReadings);
	assert(RangeAndReadings.size()==2);
	
	// Check for Minimum and Maximum values of ranges
  	std::vector<CurrentReadingsParameters*> RangeAndReadings = {};
	processCurrentReadingsData({ 1, 2, 2, 3, 4, 24, 25, 26 }, RangeAndReadings);
	assert(RangeAndReadings[0]->current_max == 4);
	assert(RangeAndReadings[1]->current_min == 24);
	

}
