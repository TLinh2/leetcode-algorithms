/*
LeetCode #28
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

 
Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

*/

/*
    Ý tưởng thuật toán
    Sử dụng thuật toán KMP (Knuth-Morris-Pratt Algorithm) để tìm một chuỗi A trong chuỗi B
    - Tạo hàm failure cho thuật toán KMP, (đầu vào là một string s):
        1. Đặt j = 1, k = 0.
        2. Khởi tạo mảng failure với các phần tử là 0.
        3. Bắt đầu một vòng lặp.
        4. Kiểm tra s[j] == s[k] ?
        5. Nếu bằng thì lưu vào mảng failure độ dài của chuỗi đã trùng tính cho đến phần tử j.
        6. Ngược lại thì index k phải quay về vị trí fail[k-1].
        7. Nếu k == 0 rồi thì không quay về nữa.
    => Ví dụ nếu string s là 'abacab' thì đầu ra là '[0, 0, 1, 0, 1, 2]'.
    
    - Tạo hàm thuật toán KMP (đầu vào là 2 string haystack, needle):
        a. Khởi tạo biến index_haystack cho string haystack, index_needle cho string needle.
        b. Lấy mảng failure cho string needle.
        c. Khởi tạo một vòng lặp.
        d. Kiểm tra haystack[index_haystack] == needle[index_needle].
        e. Nếu bằng, index_needle ++.
        f. Nếu không bằng, index_needle chỉ việc quay về vị trí failure[index_needle - 1], giảm sự so sánh thừa.
        g. Nếu trùng phần tử cuối cùng của string needle, return vị trí bắt đầu của chuỗi trùng.
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> build_failure_function(string s){
    // 1. Đặt j = 1, k = 0.
    int k = 0;
    int j = 1;
    // 2. Khởi tạo mảng failure với các phần tử là 0.
    vector <int> fail(s.length(), 0);

    // 3. Bắt đầu một vòng lặp.
    while (j < s.length()){
        // 4. Kiểm tra s[j] == s[k] ?
        if (s[j] == s[k]){
            // 5. Nếu bằng thì lưu vào mảng failure độ dài của chuỗi đã trùng tính cho đến phần tử j.
            fail[j] = k + 1;
            j++;
            k++;
        }
        // 6. Ngược lại thì index k phải quay về vị trí fail[k-1].
        else if (k > 0){
            k = fail[k - 1];
        }
        // 7. Nếu k == 0 rồi thì không quay về nữa.
        else {
            j ++;
        }
    }
    return fail;
}

int kmp_algorithm(string haystack, string needle){
    // a. Khởi tạo biến index_haystack cho string haystack, index_needle cho string needle.
    int index_needle = 0;
    int index_haystack = 0;

    // b. Lấy mảng failure cho string needle.
    vector <int> failure_array = build_failure_function(needle);

    // c. Khởi tạo một vòng lặp.
    while (index_haystack < haystack.length()){

        //d. Kiểm tra haystack[index_haystack] == needle[index_needle].
        if (haystack[index_haystack] == needle[index_needle]){
                // g. Nếu trùng phần tử cuối cùng của string needle, return vị trí bắt đầu của chuỗi trùng.
            if (index_needle == needle.length()-1){
                return index_haystack - index_needle;
            }
            // e. Nếu bằng, index_needle ++.
            index_haystack++;
            index_needle ++;
        }
        else {
            if (index_needle > 0){
                // f. Nếu không bằng, index_needle chỉ việc quay về vị trí failure[index_needle - 1], giảm sự so sánh thừa.
                index_needle = failure_array[index_needle-1];
            }
            else {
                index_haystack++;
            }
        }
    }

    return -1;
}

int main(){
    string haystack = "abacaabaccabacabaabb";
    string needle =   "abacab";
    
    cout << kmp_algorithm(haystack, needle);
}