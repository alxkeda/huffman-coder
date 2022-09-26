#pragma once

#include <string>
#include <map>

#include "f.h"

const Node* decode_tree(std::string* sequence, int* i);
std::map<std::string, char> create_tree(std::string sequence);
void traverse(std::map<std::string, char>* encoding, const Node* curr, std::string* temp);
std::string decode(std::string sequence);