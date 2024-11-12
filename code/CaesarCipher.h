#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>

class CaesarCipher {
private:
    int shift;

public:
    explicit CaesarCipher(int shift = 5);
    std::string encrypt(const std::string& input) const;
    std::string decrypt(const std::string& input) const;
};

#endif

