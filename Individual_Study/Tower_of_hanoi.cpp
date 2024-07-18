a#include <string>
#include <vector>

using namespace std;


vector<vector<int>> Tower_of_hanoi(int n, int start, int end) {
    vector<vector<int>> result;
    if (n == 1) {
        result.push_back({ start,end });
    }
    else {
        vector<vector<int>> partial;
        if (start == 1 && end == 2) {
            // (n-1개)1 -> 3 / n -> 2번으로 / (n-1개)3 -> 2
            result = Tower_of_hanoi(n - 1, 1, 3);
            result.push_back({ 1,2 });
            partial = Tower_of_hanoi(n - 1, 3, 2);
            result.insert(result.end(), partial.begin(), partial.end());
        }
        else if (start == 1 && end == 3) {
            // (n-1개)1 -> 2 / n -> 3번으로 / (n-1개)2 -> 3
            result = Tower_of_hanoi(n - 1, 1, 2);
            result.push_back({ 1,3 });
            partial = Tower_of_hanoi(n - 1, 2, 3);
            result.insert(result.end(), partial.begin(), partial.end());
        }
        else if (start == 2 && end == 3) {
            // (n-1개)2 -> 1 / n -> 3번으로 / (n-1개)1 -> 3
            result = Tower_of_hanoi(n - 1, 2, 1);
            result.push_back({ 2,3 });
            partial = Tower_of_hanoi(n - 1, 1, 3);
            result.insert(result.end(), partial.begin(), partial.end());
        }
        else if (start == 2 && end == 1) {
            // (n-1개)2 -> 3 / n -> 1번으로 / (n-1개)3 -> 1
            result = Tower_of_hanoi(n - 1, 2, 3);
            result.push_back({ 2,1 });
            partial = Tower_of_hanoi(n - 1, 3, 1);
            result.insert(result.end(), partial.begin(), partial.end());
        }
        else if (start == 3 && end == 1) {
            // (n-1개)3 -> 2 / n -> 1번으로 / (n-1개)2 -> 1
            result = Tower_of_hanoi(n - 1, 3, 2);
            result.push_back({ 3,1 });
            partial = Tower_of_hanoi(n - 1, 2, 1);
            result.insert(result.end(), partial.begin(), partial.end());
        }
        else if (start == 3 && end == 2) {
            // (n-1개)3 -> 1 / n -> 2번으로 / (n-1개)1 -> 2
            result = Tower_of_hanoi(n - 1, 3, 1);
            result.push_back({ 3,2 });
            partial = Tower_of_hanoi(n - 1, 1, 2);
            result.insert(result.end(), partial.begin(), partial.end());
        }
    }
    return result;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    answer = Tower_of_hanoi(n, 1, 3);
    return answer;
}