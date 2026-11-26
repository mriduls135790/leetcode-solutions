class Solution {
public:
    bool canAliceWin(int n) {
        int m = sqrt(433 - 8 * n) -1;
        return ~m&2;
    }
};