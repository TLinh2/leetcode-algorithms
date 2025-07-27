/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Example 5:
Input: s = "([)]"
Output: false
*/

/*
    Ý tưởng thuật toán

    * Không cần biết mở bao nhiêu ngoặc, nhưng cứ đến ngoặc đóng, phải kiểm tra ngoặc gần nhất mở có cùng loại không. 
    - Lưu những ngoặc đã mở vào một stack là opened_brackets. Ngoặc mở gần nhất sẽ luôn xuất hiện trên đầu.
    - Khi bắt đầu gặp ngoặc đóng thì kiểm tra ngoặc mở gần nhất.
    - Kiểm tra ngoặc đóng/ ngoặc mở có cùng loại hay không bằng hàm convert_bracket_to_int.
    - Nếu bằng thì pop ngoặc mở gần nhất đó ra ngoài, nếu không lập tức return false.
    - Xử lý ngoại lệ :
        + Trường hợp '(){' : Kiểm tra opened_brackets, nếu kết thúc vòng lặp vẫn còn thì return false.
        + Trường hợp '()]' : Khi đến ngoặc đóng thì kiểm tra opened_bracket có = 0? Nếu có, retrun false.

*/
#include <bits/stdc++.h>

using namespace std;

int convert_bracket_to_int (char bracket){
    if (bracket == '(' || bracket == ')'){
        return 1;
    }
    if (bracket == '{' || bracket == '}'){
        return 2;
    }
    if (bracket == '[' || bracket == ']'){
        return 3;
    }
    return 0;
}

bool is_valid(string s){
    stack <char> opened_brackets;

    int i = 0;
    while (i < s.length()){
        if (s[i] == '{' || s[i] == '(' || s[i] == '['){
            opened_brackets.push(s[i]);
        }
        else if (s[i] == '}' || s[i] == ')' || s[i] == ']'){
            if (opened_brackets.size() == 0){
                return false;
            }
            if (convert_bracket_to_int(s[i]) == convert_bracket_to_int(opened_brackets.top())){
                opened_brackets.pop();
            }
            else {
                return false;
            }
        }
        i += 1;
    }

    if (opened_brackets.size() != 0){
        return false;
    }

    return true;
}

int main(){
    string s = "()[]{}";
    cout << is_valid(s);
}