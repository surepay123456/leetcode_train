#include "../include/header.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int maxV = 0;

        while (i != j)
        {
            
            if (height[i] > height[j])
            {
                maxV = max(maxV, height[j] * (j - i));
                j --;
            }else{
                maxV = max(maxV, height[i] * (j - i));
                i ++;
            }
               
        }


        return maxV;
        
    }
};

int main(){
    vector<int> height {1,8,6,2,5,4,8,3,7};
    Solution solution;
    cout << solution.maxArea(height) << endl;
    return 1;
}