#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i < answers.size(); i++) {
        switch (i % 5) {
        case 0:
            if (answers[i] == 1) a++;
            break;
        case 1:
            if (answers[i] == 2) a++;
            break;
        case 2:
            if (answers[i] == 3) a++;
            break;
        case 3:
            if (answers[i] == 4) a++;
            break;
        case 4:
            if (answers[i] == 5) a++;
            break;
        default:
            break;
        }
        if (i % 2 == 0) {
            if (answers[i] == 2) b++;
        }
        else {
            switch ((i / 2) % 4) {
            case 0:
                if (answers[i] == 1) b++;
                break;
            case 1:
                if (answers[i] == 3) b++;
                break;
            case 2:
                if (answers[i] == 4) b++;
                break;
            case 3:
                if (answers[i] == 5) b++;
                break;
            default:
                break;
            }
        }
        switch ((i / 2) % 5) {
        case 0:
            if (answers[i] == 3) c++;
            break;
        case 1:
            if (answers[i] == 1) c++;
            break;
        case 2:
            if (answers[i] == 2) c++;
            break;
        case 3:
            if (answers[i] == 4) c++;
            break;
        case 4:
            if (answers[i] == 5) c++;
            break;
        default:
            break;
        }
    }

    if (a > b && a > c) answer.push_back(1);
    else if (b > a && b > c)answer.push_back(2);
    else if (c > a && c > b)answer.push_back(3);
    else if (a > b && a == c) {
        answer.push_back(1);
        answer.push_back(3);
    }
    else if (a > c && a == b) {
        answer.push_back(1);
        answer.push_back(2);
    }
    else if (b == c && b > a) {
        answer.push_back(2);
        answer.push_back(3);
    }
    else if (a == b && a == c) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    return answer;
}