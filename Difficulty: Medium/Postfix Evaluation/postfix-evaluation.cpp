#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void solve(stack<int> &s , string &op){
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();

        int temp = 0;

        if(op == "*"){
            temp = a * b;
        }
        else if(op == "/"){
            // floor division (handles negatives properly)
            temp = (a % b == 0) ? (a / b) : (a / b - ((a < 0) ^ (b < 0)));
        }
        else if(op == "+"){
            temp = a + b;
        }
        else if(op == "-"){
            temp = a - b;
        }
        else if(op == "^"){
            temp = pow(a, b);   // power instead of XOR
        }

        s.push(temp);
    }
    
    int evaluatePostfix(vector<string>& arr) {
        stack<int> s;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == "*" || arr[i] == "/" || arr[i] == "+" || arr[i] == "-" || arr[i] == "^"){
                solve(s, arr[i]);
            } else {
                s.push(stoi(arr[i]));
            }
        }
        
        return s.top();
    }
};
