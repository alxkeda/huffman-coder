#include "f.h"

Node::Node(char character, int frequency, const Node* left, const Node* right) : character(character), frequency(frequency), left(left), right(right) {}

std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> collect_freq(std::string sequence) {
    std::unordered_map<char, int> ftable;
    std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies;
    for(char character : sequence) {
        if(ftable.find(character) != ftable.end()) {
            ftable[character]++;
        } else {
            ftable[character] = 1;
        }
    }

    for(std::unordered_map<char, int>::const_iterator iter = ftable.begin(); iter != ftable.end(); ++iter) {
        frequencies.push(Node(iter->first, iter->second, NULL, NULL));
    }

    return frequencies;
}