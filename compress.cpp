#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

#include "cf.h"
#include "encode.h"
#include "decode.h"

int main() {

    std::ofstream output("./data/output.txt");
    std::ifstream f("./data/input.txt");
    std::stringstream buffer;
    buffer << f.rdbuf(); std::string input = buffer.str() + "]"; // adds character end sequence, keeps the decoding process free of any additional files containing information about the original uncompressed file

    std::priority_queue<Node> frequencies;

    try {
        output << encode(input, frequencies);
    } catch (const char *err) {
        output.close();
        std::cerr << err << std::endl;
        return EXIT_FAILURE;
    }

    output.close();

}