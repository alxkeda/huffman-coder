#include "encode.h"

std::unordered_map<char, std::string> create_encoding(std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies) {
    std::unordered_map<char, std::string> encoding;
    const Node HEAD = Node(NULL, 0, nullptr, nullptr);
    std::string temp;
    while(frequencies.size() > 3) {
        const Node* LEFT = &frequencies.top(); frequencies.pop();
        const Node* RIGHT = &frequencies.top(); frequencies.pop();
        const Node HEAD = Node(NULL, 0, LEFT, RIGHT);
        frequencies.push(Node(NULL, LEFT->frequency + RIGHT->frequency, LEFT, RIGHT));
    }
    traverse(&encoding, &HEAD, &temp);
    return encoding;
}

void traverse(std::unordered_map<char, std::string>* encoding, const Node* curr, std::string* temp) {
    if(curr->character != NULL) {
        (*encoding)[curr->character] = *temp;
    } else {
        (*temp).push_back('0');
        traverse(encoding, curr->left, temp);
        (*temp).pop_back();

        (*temp).push_back('1');
        traverse(encoding, curr->right, temp);
        (*temp).pop_back();
    }
}

std::string encode(std::string sequence, std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies) {
    std::string output;
    std::unordered_map<char, std::string> encoding = create_encoding(Metadata::collect_freq(sequence));
    for(char character : sequence) {
        output.append(encoding.at(character));
    }
}