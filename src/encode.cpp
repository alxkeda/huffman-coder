#include "../include/encode.h"

#include <string>
#include <map>
#include <queue>

std::map<const char, std::string> create_tree(std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies, std::string* tree) {
    std::map<const char, std::string> encoding;
    std::string temp;
    while(frequencies.size() > 1) {
        const Node* LEFT = frequencies.top(); frequencies.pop();
        const Node* RIGHT = frequencies.top(); frequencies.pop();
        const Node HEAD = Node(NULL, 0, LEFT, RIGHT);
        frequencies.push(new const Node(NULL, LEFT->frequency + RIGHT->frequency, LEFT, RIGHT));
    }
    const Node* HEAD = frequencies.top();
    traverse(&encoding, HEAD, &temp, tree);
    return encoding;
}

void traverse(std::map<const char, std::string>* encoding, const Node* curr, std::string* temp, std::string* tree) {
    if(curr->character != NULL) {
        (*encoding)[curr->character] = *temp;
        
        (*tree).push_back('1');

        (*tree).push_back(curr->character);
        return;
    } else {
        (*tree).push_back('0');

        (*temp).push_back('0');
        traverse(encoding, curr->left, temp, tree);
        (*temp).pop_back();

        (*temp).push_back('1');
        traverse(encoding, curr->right, temp, tree);
        (*temp).pop_back();
        return;
    }
}

std::string encode(std::string sequence, std::priority_queue<const Node*, std::vector<const Node*>, Node::CompNodeFreq> frequencies) {
    std::string output; std::string tree = "]";
    std::map<const char, std::string> encoding = create_tree(frequencies, &tree);
    for(char c : sequence) {
        output.append(encoding.at(c));
    }
    output.append(tree);
    return output;
}