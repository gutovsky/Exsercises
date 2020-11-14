class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
    	vector<int> running_sum = {nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
        	running_sum.push_back(running_sum[i-1] + nums[i]);
        }
        return running_sum;
    }
};