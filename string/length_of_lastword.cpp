/*
LeetCode #58
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

*/
/*
    Ý tưởng thuật toán
    - Khởi tạo count = 0.
    - Chạy từ cuối chuỗi lên.
    - Count ++ .
    - Khi phát hiện s[i] == ' ' (Khoảng trắng) thì return count.
    - Xử lý ngoại lệ cho trường hợp 'moon  " bằng cách thêm biến flag, để kiểm tra đã đến từ nào chưa.
*/

#include <bits/stdc++.h>

using namespace std;

int find_length_of_lastword(string s){
    int i = s.length() - 1;
    int count = 0;
    bool flag = 0;

    while (i>=0){
        if (s[i] != ' '){
            flag = 1;
        }
        if (flag == 1){
            if (s[i] == ' '){
                return count;
            }
            else {
                count ++;
            }
        }
        i --;
    }
    return count;
}

int main(){
    string s = "luffy is still joyboy ";
    cout << find_length_of_lastword(s);
}