// https://leetcode.com/problems/clone-graph/submissions/
// 13/12/2021

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    static const int mxN = 101;
public:
    unordered_map<int, Node*> visited;
    
    void cloneGraphUtil (Node* copy, Node* og) {
        visited[copy->val] = copy;
        
        // cout<<copy->val<<'\t';
        // for (Node* u: og->neighbors) {
        //     cout<<u->val<<' ';
        // }
        // cout<<'\n';
        
        for (Node* u: og->neighbors) {
            if (visited.count(u->val)) {
                copy->neighbors.push_back(visited[u->val]);
            } else {
                copy->neighbors.push_back(new Node(u->val));
                cloneGraphUtil(copy->neighbors.back(), u);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        Node* copy = new Node(node->val);
        cloneGraphUtil(copy, node);
        return copy;
    }
};
