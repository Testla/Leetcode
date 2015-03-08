#include <map>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
	    std::unordered_map<int, int> map;
	    std::unordered_map<int, int>::iterator it;
	    for (int i = 0; i < numbers.size(); ++i) {
		    if ((it = map.find(target - numbers[i])) != map.end())
			    return std::vector<int> {it->second + 1, i + 1};
		    else
			    map.insert(std::make_pair(numbers[i], i));
	    }		    
    }
};
