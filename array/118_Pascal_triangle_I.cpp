/*

Problem #118:
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]
*/


#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> solve_pascal_triangle_I(int number_of_rows){
    vector <vector<int>> results (number_of_rows);
    vector <int> prev_row;
    int length_of_cur_row = 1;
    for (int i=0; i<number_of_rows; i++){
        vector<int> cur_row (length_of_cur_row);

        cur_row[0] = 1;
        
        for (int j=1; j<length_of_cur_row; j++){
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
    return results;
}


void print_row(vector<int> a){
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}

void print_rows(vector <vector<int>> a){
    for (int i=0; i<a.size(); i++){
        cout << "row " << i << ": ";
        print_row(a[i]);
        cout << "\n";
    }
}

int main(){
    int number_of_rows = 10;
    vector <vector<int>> results = solve_pascal_triangle_I(number_of_rows);
    cout << "size of results: " << results.size() << "\n";
    print_rows(results);
}
