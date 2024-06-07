class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start < 0 || start >= arr.size()) {
            return false;
        }
        if (arr[start] < 0) {
            return false;
        }
        if (arr[start] == 0) {
            return true;
        }
        int jump = arr[start];
        arr[start] = -arr[start];
        bool can_reach_left = canReach(arr, start - jump);
        bool can_reach_right = canReach(arr, start + jump);
        return can_reach_left || can_reach_right;
    }
};
