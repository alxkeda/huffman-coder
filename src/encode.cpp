#include "../include/encode.h"

std::map<const char*, std::string> create_encoding(std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies) {
    std::map<const char*, std::string> encoding;
    std::string temp;
    Node head = Node(nullptr, 0, nullptr, nullptr);
    while(frequencies.size() > 1) {
        Node* LEFT = new Node(&frequencies.top()); frequencies.pop();
        Node* RIGHT = new Node(&frequencies.top()); frequencies.pop();
        head = Node(nullptr, 0, LEFT, RIGHT);
        frequencies.push(Node(nullptr, LEFT->frequency + RIGHT->frequency, LEFT, RIGHT));
    }
    traverse(&encoding, &head, &temp);
    return encoding;
}

void traverse(std::map<const char*, std::string>* encoding, Node* curr, std::string* temp) {
    if(curr->character != NULL) {
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
    std::map<const char*, std::string> encoding = create_encoding(frequencies);
    for(char character : sequence) {
        output.append(encoding.at(&character));
    }
    return output;
}