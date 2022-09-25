#pragma once

#include <string>
#include <unordered_map>
#include <queue>

#include "f.h"

std::unordered_map<char, std::string> create_encoding(std::string sequence, std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies);
void traverse(std::unordered_map<char, std::string>* encoding, const Node* curr, std::string* temp);
std::string encode(std::string sequence, std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies);