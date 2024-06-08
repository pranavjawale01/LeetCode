class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int frq = 0;
        int winner = 0;
        for (int i = 1; i < n; i++) {
            if (skills[winner] > skills[i]) {
                frq++;
            } else {
                winner = i;
                frq = 1;
            }
            if (frq == k) {
                return winner;
            }
        }
        return winner;
    }
};