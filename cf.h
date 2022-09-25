#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

class Node {
    public:
        char character;
        int frequency;
        Node* left;
        Node* right;
        Node(char character, int freq, Node* left, Node* right);
};

class Metadata {
    public:
        void collect_ordered_freq(std::string sequence);
};