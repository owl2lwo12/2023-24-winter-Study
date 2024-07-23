#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 기존의 코드가 잘못 된 이유
포인터 선언: node parent, node left, node right를 각각 node* parent, node* left, node* right로 수정해야 합니다.

초기화: 초기화할 때 NULL 대신 nullptr을 사용합니다.

반환 타입: MakeTree 함수의 반환 타입이 잘못되었습니다. 이 함수는 void 타입이어야 하며, 반환값이 없습니다.

Postorder 함수의 로직: Postorder 함수는 후위 순회(왼쪽, 오른쪽, 루트) 로직을 따르지 않습니다.
*/

typedef struct node {
    int nodeNum = 0;
    vector<int> myVec;
    node* parent = nullptr;
    node* left = nullptr;
    node* right = nullptr;

    node(vector<int> vec, int num) {
        nodeNum = num;
        myVec = vec;
    }
} Node;

bool compare(Node* a, Node* b) {
    if (a->myVec[1] == b->myVec[1]) return a->myVec[0] < b->myVec[0];
    return a->myVec[1] > b->myVec[1];
}

vector<Node*> MakeNodes(const vector<vector<int>>& vec) {
    vector<Node*> result;
    for (int i = 0; i < vec.size(); i++) {
        Node* _node = new Node(vec[i], i + 1);
        result.push_back(_node);
    }
    return result;
}

void MakeTree(vector<Node*>& nodes) {
    sort(nodes.begin(), nodes.end(), compare);

    for (int i = 1; i < nodes.size(); i++) {
        Node* curPos = nodes[0];
        while (true) {
            if (curPos->myVec[0] > nodes[i]->myVec[0]) {
                if (curPos->left == nullptr) {
                    curPos->left = nodes[i];
                    nodes[i]->parent = curPos;
                    break;
                }
                else {
                    curPos = curPos->left;
                }
            }
            else {
                if (curPos->right == nullptr) {
                    curPos->right = nodes[i];
                    nodes[i]->parent = curPos;
                    break;
                }
                else {
                    curPos = curPos->right;
                }
            }
        }
    }
}

vector<int> Preorder(Node* _node) {
    vector<int> result;
    if (_node == nullptr) return result;
    result.push_back(_node->nodeNum);
    vector<int> a;
    if (_node->left != nullptr) {
        a = Preorder(_node->left);
        result.insert(result.end(), a.begin(), a.end());
    }
    if (_node->right != nullptr) {
        a = Preorder(_node->right);
        result.insert(result.end(), a.begin(), a.end());
    }
    return result;
}

vector<int> Postorder(Node* _node) {
    vector<int> result;
    if (_node == nullptr) return result;
    vector<int> a;
    if (_node->left != nullptr) {
        a = Postorder(_node->left);
        result.insert(result.end(), a.begin(), a.end());
    }
    if (_node->right != nullptr) {
        a = Postorder(_node->right);
        result.insert(result.end(), a.begin(), a.end());
    }
    result.push_back(_node->nodeNum);
    return result;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node*> nodes = MakeNodes(nodeinfo);
    MakeTree(nodes);
    answer.push_back(Preorder(nodes[0]));
    answer.push_back(Postorder(nodes[0]));
    return answer;
}
