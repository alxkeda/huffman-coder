// #include <iostream>
// #include <string>
// #include <fstream>
// #include <sstream>

// #include "../include/f.h"
// #include "../include/decode.h"

// int main() {

//     std::ofstream output("../data/output.txt");
//     std::ifstream f("../data/input_binary.txt");
//     std::stringstream buffer;
//     buffer << f.rdbuf(); std::string input = buffer.str() + ']'; // end character, for decoding

//     std::priority_queue<Node, std::vector<Node>, Node::CompNodeFreq> frequencies = Metadata::collect_freq(input);

//     try {
//         std::string decoded = decode(input);
//         output << decoded;
//     } catch (const char *err) {
//         output.close();
//         std::cerr << err << std::endl;
//         return EXIT_FAILURE;
//     }

//     output.close();

// }