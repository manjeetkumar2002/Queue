// 1: Reverse Queue: https://www.geeksforgeeks.org/problem...
// 2: Reverse First K Elements of Queue: https://www.geeksforgeeks.org/problem...
// 3: TIme Needed To Buy Tickets: https://leetcode.com/problems/time-ne...
// 4: Implement Stack Using Queue: https://leetcode.com/problems/impleme...
// 5: Implement Queue using Stacks: https://leetcode.com/problems/impleme...

// problem1 : print all element of queue
#include<queue>
#include<iostream>
using namespace std;
// problem 1 : print all element in queue
void printQueue(queue<int>& q){
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
//Approach 2 Queue remains after printing
// space : O(1)
void printQueue(queue<int>& q){
    vector<int> ans;
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        ans.push_back(q.front());
        q.pop();
    }

    for (int i = 0; i < ans.size(); i++)
    {
        q.push(ans[i]);
    }
}
// approach 3 : space O(1)
void printQueue(queue<int>& q){
    int size = q.size();
    while (size--)
    {
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
}

// problem 2 : Queue Reversal using a tempary array
void reverse(queue<int>& q){
    vector<int> temp;
    // store all element in temp
    while (!q.empty())
    {
        temp.push_back(q.front());
        q.pop();
    }
    // reverse traverse temp and store element in q
    for (int i = temp.size()-1; i >=0; i--)
    {
        q.push(temp[i]);
    }
}
#include<stack>
// problem 2 : queue reverse using stack
void reverse(queue<int>& q){
    stack<int> s;
    
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

// problem 3 : reverse first k element in queue

void reverseFirstK(queue<int>& q,int k){
    // store first k in stack 
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    // store the size of q so that we can push this element at the end
    int size = q.size();
    // push stack element in the q
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    // now push starting size element at the end
    for (int i = 0; i < size; i++)
    {
        q.push(q.front());
        q.pop();
    }   
}

// problem 4 : Time needed to buy tickets
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int time = 0;

        for(int i = 0;i<tickets.size();i++)
        q.push(i);


        while(tickets[k]){
            int idx = q.front();
            q.pop();
            tickets[idx]--;
            time++;
            if(tickets[idx])
            q.push(idx);
        }
        return time;
    }
// problem 5: Implement Stack Using Queue: 
class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        // move all element into q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);
        // move all element back to q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int el = q1.front();
        q1.pop();
        return el;
    }
    
    int top() {
        if(q1.empty()) return -1;
        int el = q1.front();
        return el;
    }
    
    bool empty() {
        return q1.empty();
    }
};
// problem 6: Implement Queue using Stacks
#include<stack>
class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        // move all element of s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int poppedEl = s2.top();
        s2.pop();

        // move all element of s2 to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return poppedEl;
    }
    
    int peek() {
        // move all element of s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int frontEl = s2.top();

        // move all element of s2 to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return frontEl;
    }
    
    bool empty() {
        return s1.empty();
    }
};