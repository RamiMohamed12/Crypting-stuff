#include <iostream>
#include <cstdio> // For std::remove
#include "CaesarCipher.h"
#include "XORCipher.h"
#include "FileUtils.h"

int main() {
    try {
        const std::string sourceFile = "CYPHER.txt";
        std::string destFile;
        int mode;

        std::cout << "Choose the security mode (1 = Caesar, 2 = XOR, 3 = Combination): ";
        std::cin >> mode;

        std::cout << "Enter the name of the destination file: ";
        std::cin >> destFile;

        // Read the content of the source file
        std::string content = readFile(sourceFile);

        // Apply the chosen encryption method
        std::string result;
        switch (mode) {
            case 1: {
                CaesarCipher caesarCipher(5); // Shift by 5 for Caesar
                result = caesarCipher.encrypt(content);
                break;
            }
            case 2: {
                XORCipher xorCipher("mysecretkey"); // Key for XOR
                result = xorCipher.encrypt(content);
                break;
            }
            case 3: {
                CaesarCipher caesarCipher(5);
                XORCipher xorCipher("mysecretkey");
                // Combination: Caesar first, then XOR
                std::string caesarResult = caesarCipher.encrypt(content);
                result = xorCipher.encrypt(caesarResult);
                break;
            }
            default:
                throw std::invalid_argument("Invalid security mode. Choose 1, 2, or 3.");
        }

        // Write the encrypted result to the destination file
        writeFile(destFile, result);

        // Empty the content of the original CYPHER.txt file (but keep the file)
        std::ofstream emptyFile(sourceFile, std::ios::out | std::ios::trunc);
        if (!emptyFile) {
            throw std::runtime_error("Error: Could not open the file '" + sourceFile + "' to clear its content.");
        }
        emptyFile.close(); // Close the file after truncating

        std::cout << "Operation successful! Encrypted result saved to: " << destFile << std::endl;
        std::cout << "File '" << sourceFile << "' has been emptied." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

