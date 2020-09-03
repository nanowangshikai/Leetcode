#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        int val;
        vector<Node*> neighbours;

        Node(){
            val=0;
            neighbours=vector<Node*>();
        }

        Node(int _val){
            val = _val;
            neighbours = vector<Node*>();
        }

        Node(int _val, vector<Node*> _neighbours){
            val = _val;
            neighbours = _neighbours;
        }
};

class Solution{
    public:
    unordered_map<Node*, Node*> visited;
        Node* cloneGraph(Node* node ){
            if(node == nullptr) return node;
            if(visited.find(node) != visited.end()){
                return visited[node];
            }

            Node* cloneNode = new Node(node->val); // clone first val from node to cloneNode
            visited[node] = cloneNode; // store hash table

            for(auto& neighbor: node->neighbours){
                cloneNode->neighbours.emplace_back(cloneGraph(neighbor));
            }

            return n;
        }
};


int main(){
    // Solution s;


    Node* node = new Node(1,  ) ;



    // s.cloneGraph(node);
}