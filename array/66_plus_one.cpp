/*
LeetCode #66

You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

@@ Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

@@ Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

@@ Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

*/


#include <bits/stdc++.h>

using namespace std;

deque<int> plus_one(deque<int> input_array){
    int i = input_array.size() - 1;
    int add_num = 0;
    do {
        if (add_num != 0 || i == (input_array.size() - 1)){
            if (input_array[i] != 9){
                input_array[i] += 1;
                add_num = 0;
            }
            else{
                input_array[i] = 0;
                if (i == 0){
                    input_array.push_front(1);
                    return input_array;
                }
                add_num = 1;
                i --;
            }
        }
    }while(add_num != 0);

    return input_array;
}

void cout_deque (deque<int> input_array){
    for (int x : input_array)
        cout << x << " ";
    cout << "\n";
}

int main(){
    deque<int> input_array_1 = {4, 3, 2, 1};
    deque<int> input_array_2 = {9, 8, 9};
    deque<int> input_array_3 = {9, 9, 9};

    cout_deque (plus_one(input_array_1));
    cout_deque (plus_one(input_array_2));
    cout_deque (plus_one(input_array_3));
    
}
