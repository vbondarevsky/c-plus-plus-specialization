#include <vector>
#include <map>
#include <algorithm>
#include <string>


#ifdef TEST
#include "region.h"
#endif

bool operator<(const Region &left, const Region &right) {
    return std::tie(left.std_name, left.parent_std_name, left.names, left.population)
           < std::tie(right.std_name, right.parent_std_name, right.names, right.population);
}

int FindMaxRepetitionCount(const std::vector<Region> &regions) {
    int maxRepetitions = 0;
    std::map<Region, int> counters;

    for (const auto &region : regions) {
        maxRepetitions = std::max(maxRepetitions, ++counters[region]);
    }

    return maxRepetitions;
}