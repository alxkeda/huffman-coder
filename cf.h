#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

class Symbol {
    public:
        uint32_t frequency;
        uint32_t high;
        uint32_t low;
        Symbol();
};

class Metadata {
    public:
        static std::unordered_map<char, Symbol> mk_unordered_cftable(std::string s);
        static std::map<char, Symbol> mk_ordered_cftable(std::string s);
        static void print_table(std::unordered_map<char, Symbol> metadata);
    private: 
        static std::map<char, Symbol> collect_ordered_freq(std::string sequence);
};