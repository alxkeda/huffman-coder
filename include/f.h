#pragma once

#include <string>
#include <map>
#include <queue>

class Node {
    public:
        const char* character;
        int frequency;
        const Node* left;
        const Node* right;
        
        struct CompNodeFreq {
            bool operator()(Node& node1, Node& node2) {
                return node1.frequency > node2.frequency;
            };
        };

        Node(const char* character, int freq, const Node* left, const Node* right);
        Node(const Node*);
};

class Metadata {
    public:
        static const std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> collect_freq(std::string sequence);
};