#include "../include/f.h"

Node::Node(const char* character, int frequency, const Node* left, const Node* right) : character(character), frequency(frequency), left(left), right(right) {}
// Node::Node(const Node* prev) : character(prev->character), frequency(prev->frequency), left(prev->left), right(prev->right) {}

const std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> Metadata::collect_freq(const std::string sequence) {
    std::map<const char*, int> ftable;
    std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies;
    for(char c : sequence) {
        if(ftable.find(&sequence.at(sequence.find(c))) != ftable.end()) {
            ftable.at(&sequence.at(sequence.find(c))) += 1;
        } else {
            ftable[&sequence.at(sequence.find(c))] = 1;
        }
    }

    for(std::map<const char*, int>::const_iterator iter = ftable.begin(); iter != ftable.end(); ++iter) {
        frequencies.push(Node((iter->first), iter->second, nullptr, nullptr));
    }
    const std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> f = frequencies;

    return f;
}