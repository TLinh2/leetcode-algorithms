/*

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]
 
*/


#include <bits/stdc++.h>

using namespace std;

vector <int> solve_pascal_triangle_II(int number_of_rows){
    number_of_rows += 1;
    vector <vector<int>> results (number_of_rows);
    vector <int> prev_row;
    int length_of_cur_row = 1;
    int i=0;
    for (; i<number_of_rows; i++){
        vector<int> cur_row (length_of_cur_row);

        cur_row[0] = 1;
        int j=1;

        for (; j<length_of_cur_row; j++){
            if (!prev_row.empty()){
                int temp;
                if (j == (length_of_cur_row - 1)){
                    cur_row[j] = 1;
                }
                else{
                    cur_row[j] = prev_row[j-1] + prev_row[j];
                }
            }
        }

        prev_row = cur_row;
        results[i] = cur_row;
        length_of_cur_row ++;
    }
    return results[i-1];
}


void print_row(vector<int> a){
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}

int main(){
    int number_of_rows = 0;
    vector <int> results = solve_pascal_triangle_II(number_of_rows);
    print_row(results);
}
