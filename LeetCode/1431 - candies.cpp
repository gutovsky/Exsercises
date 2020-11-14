#include <algorithm>

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    	vector<bool> result;
        int max_candies = GetMaxCandies(candies);
        for (int kid_candies : candies) {
        	if (kid_candies + extraCandies >= max_candies) {
        		result.push_back(true);
        	}
        	else {
        		result.push_back(false);
        	}
        }
        return result;
    }
private:   
	int GetMaxCandies(const vector<int>& candies) {
		return *(max_element(candies.begin(), candies.end()));
	}
};