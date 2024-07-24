#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> mem;
    string cur;
    bool isNumber = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') {
            isNumber = true;
        }
        else if (s[i] == '}') {
            if (isNumber) {
                if (mem.find(stoi(cur)) == mem.end()) {
                    mem.insert({ stoi(cur),1 });
                }
                else {
                    mem[stoi(cur)]++;
                }
                cur.clear();
            }
            isNumber = false;
        }
        else if (s[i] == ',') {
            if (mem.find(stoi(cur)) == mem.end()) {
                mem.insert({ stoi(cur),1 });
            }
            else {
                mem[stoi(cur)]++;
            }
            cur.clear();
        }
        else if (isNumber) {
            cur += s[i];
        }
    }
    vector<pair<int, int>> vec(mem.begin(), mem.end());
    sort(vec.begin(), vec.end(), compare);
    for (auto i : vec) {
        answer.push_back(i.first);
    }
    return answer;
}