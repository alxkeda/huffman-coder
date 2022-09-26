#pragma once

#include <string>
#include <map>
#include <queue>

#include "f.h"

std::map<const char, std::string> create_tree(std::string sequence, std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies);
void traverse(std::map<const char, std::string>* encoding, const Node* curr, std::string* temp, std::string* tree);
std::string encode(std::string sequence, std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies);