/*
    File: main.cpp

    Author: Angel Guzman
    RedID: 826746811
    Class: CS 530 Section 5
    Project: Assignment #1

    File-description:
    This is a file reader application that will open and read any byte in the user-specified file,
        writing the result in printable (human-readable) ASCII hexadecimal or binary format for each byte. 

*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>
#include <sstream>

// function to read binary data from a file
std::vector<unsigned char> readBinaryFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    //tries to open file 
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    // Read binary data into a vector
    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(file), {});
    return buffer;
}

// Function to write binary data to the terminal
void writeBinary(const std::vector<unsigned char>& data) {
    size_t address = 0;
    for (size_t i = 0; i < data.size(); i += 6) {
        std::cout << std::setw(8) << std::setfill('0') << std::hex << address << ": ";

        // Write binary data
        for (size_t j = 0; j < 6 && i + j < data.size(); ++j) {
            std::cout << std::bitset<8>(data[i + j]);
            if (j < 5) std::cout << " ";
        }

        // Write human-readable representation
        std::cout << " ";
        for (size_t j = 0; j < 6 && i + j < data.size(); ++j) {
            unsigned char byte = data[i + j];
            if (byte >= 32 && byte <= 126) { // Printable ASCII characters range
                std::cout << static_cast<char>(byte);
            } else {
                std::cout << ".";
            }
        }

        std::cout << std::endl;

        address += 6;
    }
}

// Function to write hexadecimal data to the terminal
void writeHex(const std::vector<unsigned char>& data) {
    size_t address = 0;
    for (size_t i = 0; i < data.size(); i += 16) {
        std::cout << std::setw(8) << std::setfill('0') << std::hex << address << ": ";

        // Write hexadecimal data
        for (size_t j = 0; j < 16 && i + j < data.size(); ++j) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i + j]);
            if (j % 2 != 0) std::cout << " ";
        }

        // Write human-readable representation
        std::cout << " ";
        for (size_t j = 0; j < 16 && i + j < data.size(); ++j) {
            unsigned char byte = data[i + j];
            if (byte >= 32 && byte <= 126) { // Printable ASCII characters range
                std::cout << static_cast<char>(byte);
            } else {
                std::cout << ".";
            }
        }

        std::cout << std::endl;

        address += 16;
    }
}


int main(int argc, char* argv[]) {
    if (argc != 3 && argc != 4) {
        std::cerr << "Usage: " << argv[0] << " [-b] <file_path> <binary|hex>" << std::endl;
        return 1;
    }
    //offset used for the -b arg
    int argOffset = 1;
    if (argc == 5 && std::string(argv[1]) == "-b") {
        argOffset = 2;
    }

    std::string filePath = argv[argOffset];
    std::string outputType = argv[argOffset + 1];

    if (outputType != "binary" && outputType != "hex") {
        std::cerr << "Invalid output type. Please specify 'binary' or 'hex'." << std::endl;
        return 1;
    }

    std::vector<unsigned char> data = readBinaryFile(filePath);

    if (outputType == "binary") {
        writeBinary(data);
    } else if (outputType == "hex") {
        writeHex(data);
    }

    return 0;
}
