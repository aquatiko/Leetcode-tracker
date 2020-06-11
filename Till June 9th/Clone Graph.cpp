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
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        Node *head = new Node(node->val);
        mp[node] = head;

        for(int i=0;i<(node->neighbors).size();i++)
        {   //cout<<node->val<<"**"<<(node->neighbors)[i]->val<<"**   ";
            if(mp.find((node->neighbors)[i])==mp.end())
                (head->neighbors).push_back(cloneGraph((node->neighbors)[i]));
            else
                (head->neighbors).push_back(mp[(node->neighbors)[i]]);
        }
        return head;
    }
};
