#pragma once

#include <string>
#include <unordered_map>
#include <queue>

class Node {
    public:
        char character;
        int frequency;
        const Node* left;
        const Node* right;
        
        struct CompNodeFreq {
            bool operator()(const Node& node1, const Node& node2) {
                return node1.frequency > node2.frequency;
            };
        };

        Node(char character, int freq, const Node* left, const Node* right);
};

class Metadata {
    public:
        static std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> collect_freq(std::string sequence);
};