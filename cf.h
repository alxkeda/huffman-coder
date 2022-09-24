#pragma once

#include <iostream>
#include <string>
#include <map>
#include <queue>

class Node {
    public:
        bool is_leaf;
        int frequency;
        Node();
        Node Leaf();
        Node Branch();
};

class Metadata {
    public:
        static std::map<char, Symbol> collect_ordered_freq(std::string sequence);
};