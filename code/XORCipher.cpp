#include "XORCipher.h"

XORCipher::XORCipher(const std::string& key) : key(key) {}

std::string XORCipher::encrypt(const std::string& input) const {
    std::string result = "";
    size_t keyLength = key.length();

    for (size_t i = 0; i < input.length(); ++i) {
        result += input[i] ^ key[i % keyLength]; // XOR each character with the key
    }

    return result;
}

std::string XORCipher::decrypt(const std::string& input) const {
    // XOR cipher is symmetric, encryption and decryption are the same
    return encrypt(input);
}

