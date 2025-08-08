/*
LeetCode #225
@@ Implement a last-in-first-out (LIFO) stack using only two queues. 
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

@@ Implement the MyStack class:
- void push(int x) Pushes element x to the top of the stack.
- int pop() Removes the element on the top of the stack and returns it.
- int top() Returns the element on the top of the stack.
- boolean empty() Returns true if the stack is empty, false otherwise.

Notes:
You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. 
You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations. 

Example 1:
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
*/

/*
    Ý tưởng thuật toán
    Problem này có thể giải quyết đơn giản bằng 2 queues, nhưng tôi tăng độ khó chỉ chơi 1 queue
    1. Tạo một kiểu dữ liệu MyStack
    2. Trong hàm push:
        + Đẩy dữ liệu mới vào trước đã
        + Bắt đầu một vòng lặp
        + Đẩy từng phẩn tử lại về đằng sau trừ phần tử cuối cùng (lý do i=1)
        + Bằng cách push này, khi pop thì phần tử front luôn là mới nhất
*/

#include <bits/stdc++.h>
using namespace std;

//    1. Tạo một kiểu dữ liệu MyStack
struct MyStack {
    queue <int> my_stack;

//    2. Trong hàm push:
    void push (int x){
        // Đẩy dữ liệu mới vào trước đã
        my_stack.push(x);

        int n = my_stack.size();
        // Bắt đầu một vòng lặp
        for (int i = 1; i < n; i++){
            // Đẩy từng phẩn tử lại về đằng sau trừ phần tử cuối cùng (lý do i=1)
            int temp = my_stack.front();
            my_stack.pop();
            my_stack.push(temp);
        }
        
    }

    // Bằng cách push này, khi pop thì phần tử front luôn là mới nhất
    int pop (){
       int temp = my_stack.front();
       my_stack.pop();
       return temp;
    }
    int top(){
        return (my_stack.front());
    }
    bool empty(){
        if (my_stack.size() == 0){
            return true;
        }
        else {
            return false;
        }
    }
};

int main(){

    MyStack* ex_stack = new MyStack();

    ex_stack->push(2);
    ex_stack->push(7);
    ex_stack->push(5);
    ex_stack->push(6);

    while (!(ex_stack->empty())){
        cout << ex_stack->pop() << " ";
        
    }
    delete ex_stack;
}