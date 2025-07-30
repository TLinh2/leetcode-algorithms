/*
#LeetCode (#67)
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

*/
/*
    Ý tưởng thuật toán
    Cộng như cách chúng ta tư duy trên giấy 
    - Hàm add_two_char thực hiện phép cộng 2 bit của 2 chuỗi, ở dạng char (thay vì int), 
    Đầu vào char c1(tượng trưng cho một bit ở chuỗi 1), c2 (tượng trưng cho một bit ở chuỗi 2),
    Trả về kết quả là một mảng 2 phần tử {a, b} với a là kết quả, b là số nhớ:
        +> 1 + 1 = 0, nhớ 1. -> return {0, 1}
        +> 1 + 0 = 1, nhớ 0. -> return {1, 0}
        +> 0 + 1 = 1, nhớ 0. -> return {1, 0}
        +> 0 + 0 = 0, nhớ 0. -> return {0, 0}
        
    - Hàm add_binary thực hiện phép cộng của 2 chuỗi bit:
        1. Khởi tạo 2 con trỏ riêng biệt cho 2 chuỗi.
        2. Gán biến vòng lặp cho độ dài chuỗi ngắn hơn cho phép cộng 2 chuỗi không bằng nhau.
        3. Khởi tạo một vòng lặp chạy từ cuối lên
            3.1. Cộng 2 bit của 2 chuỗi.
            3.2. Lấy số nhớ gán tạm vào biến temp.
            3.3. Cộng số nhớ từ vòng lặp trước nếu có.
            3.4. Ghi lại biến nhớ cho vòng lặp sau.
            3.5. Ghép kết quả vào result.
        4. Nếu chuỗi nào dài hơn thì còn số -> Tự cộng với chính nó và biến nhớ.
        5. Nếu 2 chuỗi đã chạy hết số mà vẫn còn số nhớ, gắn luôn vào result.
*/

#include <bits/stdc++.h>

using namespace std;


vector <char> add_two_char (char c1, char c2){
    if (c1 == '1' && c2 == '1'){
        return {'0', '1'}; // biến đầu là kết quả, biến sau là biến nhớ
    }
    if (c1 == '0' && c2 == '1'){
        return {'1', '0'}; 
    }
    if (c1 == '1' && c2 == '0'){
        return {'1', '0'};
    }
    if (c1 == '0' && c2 == '0'){
        return {'0', '0'};
    }
    return {-1, -1}; // nếu c1, c2 không phải 0, 1
}

char add_mem_process (char a, char b){
    if (a == '1' || b == '1'){
        return '1';
    }
    else {
        return '0';
    }
}

string add_binary (string s1, string s2){
    // 1. Khởi tạo 2 con trỏ riêng biệt cho 2 chuỗi
    int index_s1 = s1.length() - 1;
    int index_s2 = s2.length() - 1;

    char add_mem = '0'; // add_mem là biến nhớ cho mỗi vòng
    string result = ""; // result là chuỗi kết quả đang tìm
    vector <char> sum; // sum là kết quả của phép cộng 2 bit một (của hàm add_two_char)

    // 2. Gán biến vòng lặp cho độ dài chuỗi ngắn hơn cho phép cộng 2 chuỗi không bằng nhau
    int iterations = min(index_s1, index_s2);

    // 3. Khởi tạo một vòng lặp chạy từ cuối lên
    while (iterations >= 0){

        // 3.1. Cộng 2 bit của 2 chuỗi
        sum = add_two_char(s1[index_s1], s2[index_s2]);
        
        // 3.2. Lấy số nhớ gán tạm vào biến temp
        char temp = sum[1];

        // 3.3. Cộng số nhớ từ vòng lặp trước nếu có
        sum = add_two_char(sum[0], add_mem); 

        // 3.4. Ghi lại biến nhớ cho vòng lặp sau
        add_mem = add_mem_process(temp, sum[1]); 

        // 3.5. Ghép kết quả vào result
        result = sum[0] + result; // vì đang đi từ cuối chuỗi lên
        
        index_s1 --;
        index_s2 --;
        iterations --;
    }

    // 4. Nếu chuỗi nào dài hơn thì còn số -> Tự cộng với chính nó và biến nhớ
    while (index_s1 >= 0){
        sum = add_two_char(s1[index_s1], add_mem);
        add_mem = sum[1];

        result = sum[0] + result;
        index_s1 --;
    }
    while (index_s2 >= 0){
        sum = add_two_char(s2[index_s2], add_mem);
        add_mem = sum[1];

        result = sum[0] + result;
        index_s2 --;
    }
    
    // 5. Nếu 2 chuỗi đã chạy hết số mà vẫn còn số nhớ, gắn luôn vào result
    if (index_s1 == -1 && index_s2 == -1 && add_mem != '0'){
        result  = add_mem + result;
    }

    return result;
}
int main(){
    string a = "101011";
    string b = "1101";

    string result = add_binary(a, b);
    cout << result;
}