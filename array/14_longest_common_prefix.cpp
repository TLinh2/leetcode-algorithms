/*

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/


#include <bits/stdc++.h>

using namespace std;

string solve_longest_common_prefix(vector<string>& strs){
    string result = "";
    int i = 0;
    
    int flag = 0;
    while (true){
        int j = 1;
        while (j < strs.size()){
            if (strs[j][i] != strs[j-1][i]){
                return result;
            }
            j += 1;
        }
        result += strs[0][i];
        i += 1;
    }

    return result;
}

int main(){
    vector<string> strs1 = {"flower", "flow", "flown"};
    cout << "Result 1: " << solve_longest_common_prefix(strs1);

    vector<string> strs2 = {"dog","racecar","car"};
    cout << "\nResult 2: " << solve_longest_common_prefix(strs2);

}
