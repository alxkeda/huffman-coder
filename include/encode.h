#pragma once

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cstring>

#include "f.h"

std::map<const char, std::string> create_encoding(std::string sequence, std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies);
void traverse(std::map<const char, std::string>* encoding, const Node* curr, std::string* temp, std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies);
std::string encode(std::string sequence, std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies);