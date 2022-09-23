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

    std::unordered_map<char, Symbol> cf_table = Metadata::mk_unordered_cftable(input);

    try {
        output << encode(input, cf_table);
    } catch (const char *err) {
        output.close();
        std::cerr << err << std::endl;
        return EXIT_FAILURE;
    }

    output.close();

}