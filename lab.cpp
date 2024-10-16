#include <iostream>
#include <string>

class CaesarCipher {
public:
    CaesarCipher(int shift) : shift(shift) {}

    std::string encrypt(const std::string& plaintext) {
        std::string ciphertext = "";
        for (char ch : plaintext) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                ciphertext += (ch - base + shift) % 26 + base;
            } else {
                ciphertext += ch; 
            }
        }
        return ciphertext;
    }

    std::string decrypt(const std::string& ciphertext) {
        std::string plaintext = "";
        for (char ch : ciphertext) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                plaintext += (ch - base - shift + 26) % 26 + base; 
            } else {
                plaintext += ch; 
            }
        }
        return plaintext;
    }

private:
    int shift;
};

int main() {
    int shift;
    std::cout << "Enter the shift value: ";
    std::cin >> shift;

    CaesarCipher cipher(shift);
    
    std::string plaintext;
    std::cout << "Enter the plaintext: ";
    std::cin.ignore(); 
    std::getline(std::cin, plaintext);

    std::string encrypted = cipher.encrypt(plaintext);
    std::cout << "Encrypted text: " << encrypted << std::endl;

    std::string decrypted = cipher.decrypt(encrypted);
    std::cout << "Decrypted text: " << decrypted << std::endl;

    return 0;
}
