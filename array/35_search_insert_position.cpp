/*

Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

*/

#include <bits/stdc++.h>

using namespace std;

int search_insert_position(vector <int>& nums, int target){
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right){
        int middle = (left + right)/2;

        if (target < nums[middle]){
            right = middle - 1;
        }

        else if (target > nums[middle]){
            left = middle + 1;
        }
        else {
            return middle;
        }
    }
    return left;  // Vị trí cần chèn nếu không tìm thấy 

}

int main(){
    vector <int> nums = {1, 3, 5, 6};
    int target = 4;

    int result_index = search_insert_position(nums, target);
    cout << "Result: "  << result_index;
}