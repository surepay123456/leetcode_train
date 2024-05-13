#include "../../include/header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit;
        int n = prices.size();
        if(n == 0 || n == 1) return 0;
        profit.resize(n - 1);
        int sum = 0;
        for(int i = 0; i <= n - 2; i++){
            int getpro = prices[i + 1] - prices[i];
            sum += getpro > 0 ? getpro : 0;
        } 

        return sum;
         
    }
};