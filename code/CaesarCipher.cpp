#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(int shift) : shift(shift % 26) {}

std::string CaesarCipher::encrypt(const std::string& input) const {
    std::string result = "";
    for (char c : input) {
        if (isalpha(c)) {
            char offset = islower(c) ? 'a' : 'A';
            result += (c - offset + shift) % 26 + offset; // Rotate within the alphabet
        } else {
            result += c; // Leave non-alphabetic characters unchanged
        }
    }
    return result;
}

std::string CaesarCipher::decrypt(const std::string& input) const {
    std::string result = "";
    for (char c : input) {
        if (isalpha(c)) {
            char offset = islower(c) ? 'a' : 'A';
            result += (c - offset + 26 - shift) % 26 + offset; // Reverse the rotation
        } else {
            result += c; // Leave non-alphabetic characters unchanged
        }
    }
    return result;
}

