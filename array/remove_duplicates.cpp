#include <bits/stdc++.h>
using namespace std;

vector <int> remove_duplicates(vector<int> nums){
    if (nums.size()==0){
        return {0};
    }
    vector <int> expectedNums = {};
    expectedNums.push_back(nums[0]);

    int total_number = 1;
    int i = 1;
    while (i<nums.size()){
        if (nums[i] == nums[i-1]){
            i += 1;
            continue;
        }
        expectedNums.push_back(nums[i]);
        total_number += 1;
        i += 1;
    }
    cout << "Total Number: " << total_number;
    return expectedNums;
}
int main(){
    vector <int> nums = {0,0,1,1,1,2,2,3,3,4};
    vector <int> result = remove_duplicates(nums);
    cout << "\nArray result: ";
    for (int i=0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}