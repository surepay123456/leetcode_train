#include "../include/header.h"

class Solution {
public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // int left_max[n], right_max[n];
        
        // left_max[0] = height[0];
        // right_max[n - 1] = height[n - 1];
        // for (int i = 1; i <=  n - 1; i++){
        //     left_max[i] = max(left_max[i - 1], height[i]);
        // }

        // for (int j = n - 1; j >= 0; j--){
        //     right_max[j] = max(right_max[j + 1], height[j]);
        // }
        
        // int ans = 0;
        // for (int i = 0; i <= n - 1; i++){
        //     ans += min(left_max[i], right_max[i]) - height[i];
        // }
        // return ans;

        // 双指针法
        int n = height.size();
        
        int i = 0;
        int j = n - 1;
        int max_left = 0, max_right = 0;
        int ans = 0;
        
        while(i <= j){
            
            max_left = max(max_left, height[i]);
            max_right = max(max_right, height[j]);
            
            if(max_left > max_right){
                ans += max_right - height[j];
                j--;
            }else{
                ans += max_left - height[i];
                i++;
            }
        }
        return ans;
        
    }
};

int main(){
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    cout << solution.trap(height) << endl;
}