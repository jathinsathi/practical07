#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a DP table initialized with an impossible high value (amount + 1)
        vector<int> dp(amount + 1, amount + 1);
        
        // Base case: 0 coins needed to make an amount of 0
        dp[0] = 0;
        
        // Compute minimum coins for all amounts from 1 to target
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[amount] is still amount + 1, it means the target cannot be reached
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    Solution solver;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    
    cout << "Fewest coins needed: " << solver.coinChange(coins, amount) << endl; // Output: 3 (5 + 5 + 1)
    return 0;
}
