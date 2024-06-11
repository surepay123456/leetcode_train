#include "../../include/header.h"

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  //孩子胃口
        sort(s.begin(), s.end());  //饼干尺寸

        //先从饼干尺寸开始 最大的是否能满足此时的孩子胃口i 如果不行则i--
        //如果行则 i--;j--;

        //边界条件 i<0表示遍历完孩子了 && j<0 表示用完饼干了
        int i = g.size() - 1;
        int j = s.size() - 1;
        int num = 0;
        while (i >= 0 && j >= 0) {
            if (g[i] <= s[j]) {
                num++;
                i--;
                j--;
            } else {
                i--;
            }
        }
        return num;
    }
};