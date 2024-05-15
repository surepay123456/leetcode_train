#include "../../include/header.h"

class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        // 用一个标识符来标记 前面的差是正还是 负
        // 每次isIncrease变换值的时候结果加一 标识符的初始值无法确定
        // 后一个减去前一个 维护preminus minus  如果minus==0 则不更新preminus
        // 如果preminus与minus符号相反则结果加1 还是涉及到初始的时候
        // 只有当preminus = 0 的时候 无论minus是什么符号0除外 更新   result++;
        // preminus = minus;
        bool isIncrease = true;
        int preminus = 0;
        int minus = 0;
        int result = 0;
        //遍历nums
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return 1;
        result = 1;
        for (int i = 0; i <= n - 2; i++) {
            minus = nums[i + 1] - nums[i];
            if (minus == 0) continue;
            if (preminus == 0) {
                result++;
                preminus = minus;
            }
            if ((minus > 0 && preminus < 0) || (minus < 0 && preminus > 0)) {
                result++;
                preminus = minus;
            }
        }
        return result;
    }
};