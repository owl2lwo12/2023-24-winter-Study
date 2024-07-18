#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a; //생각지도 못한 쉬운 방법이다 생각을 더 해볼걸
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> sortable;
    for (int i = 0; i < numbers.size(); i++) {
        sortable.push_back(to_string(numbers[i]));
    }
    sort(sortable.begin(), sortable.end(), compare);
    if (sortable[0] == "0") { //예외 처리는 확실하게 할 것
        answer = "0";
        return answer;
    }
    for (int i = 0; i < sortable.size(); i++) {
        answer += sortable[i];
    }
    return answer;
}