
#include "../../include/header.h"

class Solution {
   private:
    vector<int> minus(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> result(n);
        for (int i = 0; i <= n - 1; i++) {
            result[i] = gas[i] - cost[i];
        }

        return result;
    }

   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 到第i号加油站亏的油
        // 例子 [1, 2, 3, 4, 5] [3, 4, 5, 1, 2]
        // [-2, -2, -2, 3, 3] 表示如果i->i+1的所得
        // 现在要求从i走一圈油量始终不能小于0 还有个如果sum <
        // 0肯定会木有方案能通过 从最大的序列开始哇 -> 不能
        // 因为从小的正数累加是阔以大于这个最大序列的

        //转换思路 如果从当前开始sum 如果sum < 0了 则[0, i]区间都不可行
        //这就是局部最优的体现 sum重新从i + 1加起

        vector<int> travel = minus(gas, cost);

        int sum = 0;
        for (auto num : travel) {
            sum += num;
        }
        if (sum < 0) return -1;

        //>=0 说明存在解决方案
        sum = 0;
        int start;
        int n = travel.size();
        for (int i = 0; i <= n - 1; i++) {
            sum += travel[i];
            if (sum < 0) {
                sum = 0;
                start = i + 1;  // 入股 i == n - 1依然进入此判断， 这没有解咯
                                // 矛盾 所以不会进入此判断
            }
        }

        return start;
    }
};