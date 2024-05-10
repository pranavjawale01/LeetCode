class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                nums[k++] = nums[i];
            }
        }
        for (int i = n - count; i < n; i++) {
            nums[i] = 0;
        }
    }
};