/*
Leetcode #13
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 
Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

/*
    Ý tưởng thuật toán
    - Bắt đầu một vòng lặp chạy từ cuối chuỗi đổ lên.
    - Convert giá trị La mã thành số int rồi cộng vào result.
    - Nếu phát hiện giá trị thấp hơn giá trị ở vòng lặp trước (tức số La mã đứng sau trong chuỗi) trừ vào result.
    - Kết thúc vòng lặp return result.
*/
#include <bits/stdc++.h>

using namespace std;

int roman_to_integer(string s){
    int result = 0;
    int current = 0;
    int prev = 0;

    int i = s.length() - 1;
    while (i >= 0){
        switch(s[i]){
            case 'I':
                current = 1;
                break;
            case 'V':
                current = 5;
                break;
            case 'X':
                current = 10;
                break;
            case 'L':
                current = 50;
                break;
            case 'C':
                current = 100;
                break;
            case 'D':
                current = 500;
                break;
            case 'M':
                current = 1000;
                break;
            
        }
        if (current < prev){
            result -= current;
        }
        else {
            result += current;
        }
        prev = current;
        i -= 1;
    }

    return result;
}
int main(){
    string s = "III";
    int result = roman_to_integer(s);
    cout << result;
}