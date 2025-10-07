//
// Created by ECSS11 on 10/7/2025.
//
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char open[] = {'(', '{', '['};
        char close[] = {')', '}', ']'};

        stack<char> ss;

        for (int i = 0; i < s.length(); i++) {
            if (find(open, open + 3, s[i]) != open + 3) {
                ss.push(s[i]);
                continue;
            }

            int location;
            for (int j = 0; j < 3; j++) {
                if (s[i] == close[j]) {
                    location = j;
                }
            }

            if (ss.empty() || ss.top() != open[location]) {
                return false;
            }

            ss.pop();
        }

        return ss.empty();
    }
};


int main() {
    Solution s;
    cout << s.isValid("]");
}