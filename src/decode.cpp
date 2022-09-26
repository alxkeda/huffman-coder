#include "../include/decode.h"

#include <string>
#include <map>
#include <stdexcept>

const Node* decode_tree(std::string* sequence, int* i) {
    const char c = (*sequence)[*i];
    if(c == '1') {
        (*i)++; const char c = (*sequence)[*i]; (*i)++;
        return new const Node(c, NULL, nullptr, nullptr);
    } else if(c == '0') {
        (*i)++; return new const Node(NULL, 0, decode_tree(sequence, i), decode_tree(sequence, i));
    } else {
        throw std::logic_error("Could not parse the tree");
    }
}

std::map<std::string, char> create_tree(std::string sequence) {
    std::map<std::string, char> encoding;
    std::string temp; int i = sequence.find(']') + 1;
    const Node* HEAD = decode_tree(&sequence, &i);
    traverse(&encoding, HEAD, &temp);
    return encoding;
}

void traverse(std::map<std::string, char>* encoding, const Node* curr, std::string* temp) {
    if(curr->character != NULL) {
        (*encoding)[*temp] = curr->character;
        return;
    } else {
        (*temp).push_back('1');
        traverse(encoding, curr->left, temp);
        (*temp).pop_back();

        (*temp).push_back('0');
        traverse(encoding, curr->right, temp);
        (*temp).pop_back();
        return;
    }
}

std::string decode(std::string sequence) {
    std::string output;
    std::map<std::string, char> encoding = create_tree(sequence);
    int begin = 0;
    for(int i=0; i<sequence.length(); i++) {
        std::string substr = sequence.substr(begin, i - begin);
        if(encoding.find(substr) != encoding.end()) {
            output.push_back(encoding.at(substr));
            begin = i;
        }
        
    }
    return output;
}