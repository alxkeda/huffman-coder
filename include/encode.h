#pragma once

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cstring>

#include "f.h"

std::map<char, std::string> create_encoding(std::string sequence, std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies);
void traverse(std::map<char*, std::string>* encoding, Node* curr, std::string* temp);
std::string encode(std::string sequence, std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies);

struct map_cmp {
   bool operator()(char const* a, char const* b) const {
      return std::strcmp(a, b) < 0;
   }
};