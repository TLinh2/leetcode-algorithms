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