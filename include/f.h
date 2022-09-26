#pragma once

#include <string>
#include <map>
#include <queue>

class Node {
    public:
        const char character;
        int frequency;
        const Node* left;
        const Node* right;
        
        struct CompNodeFreq {
            bool operator()(const Node* node1, const Node* node2) {
                return (*node1).frequency > (*node2).frequency;
            };
        };

        Node(const char character, int freq, const Node* left, const Node* right);
        // Node(const Node*);
};

class Metadata {
    public:
        static std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> collect_freq(std::string sequence);
};