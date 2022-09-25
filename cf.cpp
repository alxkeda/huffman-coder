#include "cf.h"

Node::Node(char character, int frequency, Node* left, Node* right) : character(character), frequency(frequency), left(left), right(right) {}

std::priority_queue<int> collect_ordered_freq(std::string sequence) { // stores objects associating characters with their frequencies into a priority queue
    std::unordered_map<char, int> ftable;
    std::priority_queue<Node> frequencies;
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
}