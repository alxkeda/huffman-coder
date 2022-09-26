#include "../include/encode.h"

std::map<const char*, std::string>* create_encoding(std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies) {
    std::map<const char*, std::string>* encoding;
    std::string temp;
    const Node HEAD = Node(nullptr, 0, nullptr, nullptr);
    while(frequencies.size() > 1) {
        const Node* LEFT = &frequencies.top(); 
        frequencies.pop();
        const Node* RIGHT = &frequencies.top();
        frequencies.pop();
        const Node HEAD = Node(nullptr, 0, LEFT, RIGHT);
        frequencies.push(Node(nullptr, LEFT->frequency + RIGHT->frequency, LEFT, RIGHT));
    }
    traverse(encoding, &HEAD, &temp);
    return encoding;
}

void traverse(std::map<const char*, std::string>* encoding, const Node* curr, std::string* temp) {
    if(curr->character != nullptr) {
        (*encoding)[curr->character] = *temp;
        return;
    } else {
        (*temp).push_back('0');
        traverse(encoding, curr->left, temp);
        (*temp).pop_back();

        (*temp).push_back('1');
        traverse(encoding, curr->right, temp);
        (*temp).pop_back();
        return;
    }
}

std::string encode(std::string sequence, std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies) {
    std::string output;
    std::map<const char*, std::string>* encoding = create_encoding(frequencies);
    for(char character : sequence) {
        output.append((*encoding).at(&character));
    }
    return output;
}