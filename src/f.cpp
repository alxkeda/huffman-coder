#include "../include/f.h"

Node::Node(const char character, int frequency, const Node* left, const Node* right) : character(character), frequency(frequency), left(left), right(right) {}
// Node::Node(const Node* prev) : character(prev->character), frequency(prev->frequency), left(prev->left), right(prev->right) {}

std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> Metadata::collect_freq(std::string sequence) {
    std::map<const char, int> ftable;
    std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies;
    for(char c : sequence) {
        if(ftable.find(c) != ftable.end()) {
            ftable.at(c) += 1;
        } else {
            ftable[c] = 1;
        }
    }

    for(std::map<const char, int>::const_iterator iter = ftable.begin(); iter != ftable.end(); ++iter) {
        frequencies.push(new const Node(iter->first, iter->second, nullptr, nullptr));
    }
    return frequencies;
}