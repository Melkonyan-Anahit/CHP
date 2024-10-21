#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string encrypt(const string &text) {
    int rows = (text.length() + 2) / 3; 
    vector<vector<char>> table(rows, vector<char>(3, ' '));

   
    for (int i = 0; i < text.length(); ++i) {
        table[i / 3][i % 3] = text[i];
    }

    string encrypted;
    for (int col = 0; col < 3; ++col) {
        for (int row = 0; row < rows; ++row) {
            encrypted += table[row][col];
        }
    }

    return encrypted;
}

string decrypt(const string &encrypted) {
    int rows = (encrypted.length() + 2) / 3; 
    vector<vector<char>> table(rows, vector<char>(3, ' ')); 

    
    int index = 0;
    for (int col = 0; col < 3; ++col) {
        for (int row = 0; row < rows; ++row) {
            if (index < encrypted.length()) {
                table[row][col] = encrypted[index++];
            }
        }
    }

   
    string decrypted;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (table[row][col] != ' ') { 
                decrypted += table[row][col];
            }
        }
    }

    return decrypted;
}

int main() {
    string text;
    cout << "Enter the text to encrypt: ";
    getline(cin, text);

    string encrypted = encrypt(text);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = decrypt(encrypted);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
