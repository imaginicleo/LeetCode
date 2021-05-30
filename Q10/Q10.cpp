#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        //构建DFA
        vector<unordered_map<char,set<int>>> states(p.size()+1);

        set<int> endStates;

        int state = 0;
        for (int i = 0; i < p.size(); ++i) {
            if(p[i] == '*') {
                states[state][p[i-1]].insert(state);
            }
            else {
                states[state][p[i]].insert(state+1);
                int count = 0;
                while(i+1+count*2<p.size()&&p[i+1+count*2]=='*') {
                    if (i+2+count*2<p.size())
                        states[state][p[i+2+count*2]].insert(state + 2 + count);
                    else
                        endStates.insert(state);
                    ++count;  
                }
                ++state;
            }
        }
        endStates.insert(state);

        //匹配DFA
        set<int> nowStates;
        set<int> preStates;
        preStates.insert(0);
        for (int i = 0; i < s.size(); ++i) {
            for (auto j : preStates) {
                for (auto tranState: states[j][s[i]]) {
                    nowStates.insert(tranState);
                }
                for(auto tranState: states[j]['.']) {
                    nowStates.insert(tranState);
                }
            }
            if (nowStates.empty()) {
                return false;
            }
            else {
                preStates = nowStates;
                nowStates.clear();
            }
        }

        for (auto e:endStates) {
            if(preStates.count(e))
                return true;
        }
        return false;  
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}