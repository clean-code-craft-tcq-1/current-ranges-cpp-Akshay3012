#include "current_ranges.h"
#include <iostream>
#include <algorithm>

std::vector<int> sortCurrentReadingsData (std::vector<int>& periodicCurrentSample)
{
	sort(periodicCurrentSample.begin(), periodicCurrentSample.end());
	return periodicCurrentSample;
}

void processCurrentReadingsData(std::vector<int> inputCurrentSamples, std::vector<CurrentReadingsParameters*>& currentParam_st)
{
	std::vector<int> sortedCurrentSample = sortCurrentReadingsData(inputCurrentSamples);
	int reading_min = 0;
	int reading_max = 0;
	int totalReadings = 0;
    if(0 == inputCurrentSamples.empty())
    {
        for (std::vector<int>::iterator i = sortedCurrentSample.begin(); i != sortedCurrentSample.end(); ++i)
        {
            if (*i- reading_max <= 1 )
            {
                 reading_max = *i;
                 totalReadings = totalReadings+1 ;  
                 //reading_min = 0;
                 //currentParam_st.push_back(new CurrentReadingsParameters{ reading_min,reading_max,totalReadings });
            }
            else
            {
                currentParam_st.push_back(new CurrentReadingsParameters{ reading_min,reading_max,totalReadings });
                 reading_max = *i;
                 totalReadings = 1 ;  
                 reading_min = *i;
    
            }
        }
        currentParam_st.push_back(new CurrentReadingsParameters{ reading_min,reading_max,totalReadings });
    }
    
    else
    {
    }
    
    displayRangeAndNumberOfReadings(currentParam_st);

}

void displayRangeAndNumberOfReadings(std::vector<CurrentReadingsParameters*>& updatedCurrentReadings)
{
	cout << "Range , Readings" << endl;
	for (const auto& i : updatedCurrentReadings)
		cout << i->current_min << "To" << i->current_max << "  ,  " << i->number_of_readings << endl;
}

