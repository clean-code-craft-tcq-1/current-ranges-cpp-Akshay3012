#include "current_ranges.h"
#include <assert.h>
#include <cmath>

int main ()
{
  std::vector<CurrentReadingsParameters*> RangeAndReadings = {};
	processCurrentReadingsData({ 1, 2, 2, 3, 4, 24, 25, 26 }, RangeAndReadings);
	assert(RangeAndReadings.size()==2);
}
