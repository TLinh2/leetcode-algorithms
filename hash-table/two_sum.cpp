/*
LeetCode #1
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

*/

/*
    Ý tưởng thuật toán
    Sử dụng bảng băm (unordered_map)
    - Bắt đầu một vòng lặp chạy qua từng phần tử của vector numbers
    - Với mỗi phần tử, thêm vào phần thiếu của phần tử đó để cộng lại bằng target và index lúc này 
    (Ví dụ đến phần tử 2 ở index 1 thì thêm vào là hash_table[7] = 1)
    - Kiểm tra xem hash_table[2] có tồn tại không (giả sử ở index trước đó có phần tử 7)
    - Nếu có thì trả về hash_table[2](index của phần tử 7 ở trước) với index i hiện tại(index của 2 tại vòng lặp lúc này)
    - Nếu không có phần tử nào trả về mảng {-1, -1}
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> find_two_sum(vector <int>numbers, int target){
    int n = numbers.size();
    unordered_map <int, int> hash_table(n);

    for (int i=0; i<n; i++){
        int temp = target - numbers[i];
        hash_table[temp] = i;

        if (hash_table.find(numbers[i]) != hash_table.end()){
            return {hash_table[numbers[i]], i};
        }
    }
    return {-1, -1};
}

int main(){
    vector<int> numbers = {2, 6, 3, 4};
    int target = 9;

    vector<int> result = find_two_sum(numbers, target);
    cout << result[0] << " " << result[1];
}