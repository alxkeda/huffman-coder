#include "../include/encode.h"

std::map<const char, std::string> create_encoding(std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies) {
    std::map<const char, std::string> encoding;
    std::string temp;
    while(frequencies.size() > 1) {
        const Node* LEFT = frequencies.top(); frequencies.pop();
        const Node* RIGHT = frequencies.top(); frequencies.pop();
        const Node HEAD = Node(NULL, 0, LEFT, RIGHT);
        frequencies.push(new const Node(NULL, LEFT->frequency + RIGHT->frequency, LEFT, RIGHT));
    }
    const Node* HEAD = frequencies.top();
    traverse(&encoding, HEAD, &temp, frequencies);
    return encoding;
}

void traverse(std::map<const char, std::string>* encoding, const Node* curr, std::string* temp, std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies) {
    if(curr->character != NULL) {
        (*encoding)[curr->character] = *temp;
        return;
    } else {
        (*temp).push_back('0');
        traverse(encoding, curr->left, temp, frequencies);
        (*temp).pop_back();

        (*temp).push_back('1');
        traverse(encoding, curr->right, temp, frequencies);
        (*temp).pop_back();
        return;
    }
}

std::string encode(std::string sequence, std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies) {
    std::string output;
    std::map<const char, std::string> encoding = create_encoding(frequencies);
    for(char c : sequence) {
        output.append(encoding.at(c));
    }
    return output;
}