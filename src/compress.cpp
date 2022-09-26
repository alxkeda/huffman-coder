#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../include/f.h"
#include "../include/encode.h"

int main() {

    std::ofstream output("../data/output.txt"); std::ofstream input_binary("../data/input_binary.txt");
    std::ifstream f("../data/input.txt");
    std::stringstream buffer;
    buffer << f.rdbuf(); const std::string input = buffer.str();

    const std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies = Metadata::collect_freq(input);

    try {
        std::string encoded = encode(input, frequencies);
        output << encoded; input_binary << encoded;
    } catch (const char *err) {
        output.close();
        std::cerr << err << std::endl;
        return EXIT_FAILURE;
    }

    output.close();

}