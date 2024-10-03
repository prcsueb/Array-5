/*
    tc : o(n) sc o(1)
*/
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector<pair<int, int>> dp = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(char ch : instructions) {
            if(ch == 'L')
                i = (i + 3) % 4;
            else if(ch == 'R') 
                i = (i + 1) % 4;
            else {
                x += dp[i].first;
                y += dp[i].second;
            }
        }
        return (x == 0 && y == 0) || i != 0;
    }
};