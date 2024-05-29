#include "../../include/header.h"
#include <dbg.h>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // // 二维的二分搜索
        // // 展开就成为一维的了
        // int size_w = 0;
        // int size_h = matrix.size();
        // if(size_h != 0) size_w = matrix[0].size();

        // // 二分区间左开右闭 序列索引  i * size_h + j -> matrix[i][j];

        // int left = 0;
        // int right = size_h * size_w;
 
        // while(left < right){
        //     int mid = (left + right);
        //     int x = matrix[mid / size_w][mid % size_w];
        //     if(x > target){
        //         right = mid; 
        //     }  
        //     else if(x < target){
        //         left = mid + 1;
        //     }
        //     else{
        //         return true;
        //     }
        // }   
        // return false;
        


        //先在第一列二分搜索 然后再在行搜索
        int size_w = 0;
        int size_h = matrix.size();
        if(size_h != 0) size_w = matrix[0].size(); 
        
        int left = 0;
        int right = size_h;
        
        while(left < right){
            int mid = (left + right) / 2;
            int x = matrix[mid][0];
            if(target > x ){
                left = mid + 1;
            }
            else if(target < x){
                right = mid;
            }
            else{
                return true;
            }
        }
        
        int h = left - 1;
        if(h < 0) return false;
        left = 0;
        right = size_w;
        
        while(left < right){
            int mid = (left + right) / 2;
            int x = matrix[h][mid];
            if(target > x ){
                left = mid + 1;
            }
            else if(target < x){
                right = mid;
            }
            else{
                return true;
            }
            
        }
        return false;
        
        
    }
};

int main(){
    vector<vector<int>> matrix {{1}};
    int target = 0;
    Solution solution;
    dbg(matrix);
    if(solution.searchMatrix(matrix, target)){
        dbg("find!");
    }
    return 0;
}