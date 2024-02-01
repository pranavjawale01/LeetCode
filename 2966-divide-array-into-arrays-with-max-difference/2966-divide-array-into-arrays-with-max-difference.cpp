class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> output;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 3) {
            vector<int> temp(3, 0);
            temp[0] = nums[i];
            temp[1] = nums[i+1];
            temp[2] = nums[i+2];
            if (temp[2] - temp[0] > k) {
                return {};
            }
            output.push_back(temp);
        }
        return output;
    }
};