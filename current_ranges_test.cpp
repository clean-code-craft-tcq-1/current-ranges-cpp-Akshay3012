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
	processCurrentReadingsData({ 1, 2, 2, 3, 4, 24, 25, 26 }, RangeAndReadings);
	assert(RangeAndReadings.size()==2);
	
	// Check for Minimum, Maximum values and total number of readings of ranges
	processCurrentReadingsData({ 1, 2, 2, 3, 4, 24, 25, 26 }, RangeAndReadings);
	assert(RangeAndReadings[0]->current_max == 4);
	assert(RangeAndReadings[1]->current_min == 26);
	assert(RangeAndReadings[0]->number_of_readings == 5);
	assert(RangeAndReadings[1]->number_of_readings == 3);
	

}
