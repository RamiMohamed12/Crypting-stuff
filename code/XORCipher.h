#ifndef XORCIPHER_H
#define XORCIPHER_H

#include <string>

class XORCipher {
private:
    std::string key; // The key for XOR encryption

public:
    // Constructor to initialize the key
    explicit XORCipher(const std::string& key);

    // Encrypt or decrypt a string using XOR cipher
    std::string encrypt(const std::string& input) const;

    // XOR cipher is symmetric, so the same function can decrypt
    std::string decrypt(const std::string& input) const;
};

#endif

