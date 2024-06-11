#include "../include/header.h"

class Solution {

    // private:
    //     class MyQueue{
    //     public:
            
    //         deque<int> que;
            
    //         void pop(int value){
    //             if( !que.empty() && value == que.front()){
    //                 que.pop_front();
    //                 }
    //         }
        
    //         int front(){
    //             return que.front();
    //         }
    //     }

private: 
    class MyQueue{
        public:
            deque<int> que;
            
            void pop(int value){
                if( !que.empty() && value == que.front()){
                    que.pop_front();
                    }
            }

            // 新加入的值要保证单调队列 单调递减 所以front比它小的都应该pop
            void push(int value){

                while (! que.empty() && value > que.back())
                {
                    que.pop_back();
                }
                
                que.push_back(value);
                
                
            }
        
            int front(){
                return que.front();
            } 

    };

public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> ans;
        // int max_num = INT_MIN;
        // int i = 0;
        // int j = 0;
        // int n = nums.size(); 
        // // 滑动一次 去除元素nums[i] 获得元素nums[j] 
        // // 得到元素 max(max_num, nums[j]);
        // // 去除元素 nums[i]不是最大值不更新 是最大值：最大值有多个？ 不更新: 更新
        // // 如何更新     
        
        // 使用滑动窗口法问题在于当去除最大的元素，没有次最大元素的信息，导致无法更新结果

        // // 扩张条件 j < i + k - 1
        // // 收缩条件 j > i + k - 1
        // // 满足条件 j = i + k - 1 i, j移动时时刻维护一个max_num 此时存结果ans 
        // // [i, j] 
        // int count = 0 ; //存最大值的数量， 来判断是否更新最大值
        // while (j <= n - 1)
        // {
        //     if ( j < i + k - 1)
        //     {
        //         if(nums[j] == max_num){
        //             count ++;
        //         }
        //         if(nums[j] > max_num){
        //         max_num = max(max_num, nums[j]);
        //         count = 1;
        //         }
        //         j++;
        //     }
        //     else if( j > i + k - 1){
        //         if(nums[i] == max_num){
        //             if(count == 1){
        //                 //选第二大的 更新max_num
        //             }
        //         }
        //         i++;
        //     }
        //     else{
        //         ans.push_back(max_num);
        //     }
            
        // }
        // return ans;        
        
        MyQueue que;
        vector<int> result;
        int n = nums.size();
        for(int i = 0; i < k ; i++){
            que.push(nums[i]);
        }

        result.push_back(que.front());
        
        for(int i = k; i <= n - 1; i++){
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }

        return result;
    }
};

int main(){
    vector<int> nums {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution solution;
    vector<int> ans;
    ans = solution.maxSlidingWindow(nums, k);
    for(auto& x : ans){
        cout << x << endl;
    } 
    return 0;
}