#include "cf.h"

Node::Node(int freq, bool is_lf) {
    frequency = freq;
    is_leaf = is_lf;
}

std::map<char, Symbol> Metadata::collect_ordered_freq(std::string sequence) { // collects counts of each symbol
    std::map<char, Symbol> metadata;
    for(char character : sequence) {
        if(metadata.find(character) == metadata.end()) {
            metadata[character] = Symbol();
        } else {
            metadata[character].frequency++;
        }
    }
    return metadata;
}