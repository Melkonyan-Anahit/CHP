#include <iostream>
#include <string>

using namespace std;

string encodeCaesarCipher(const string& text, int shift) {
    string encoded = text;
    for (size_t i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            encoded[i] = (text[i] - base + shift) % 26 + base;
        }
    }
    return encoded;
}

string runLengthEncode(const string& text) {
    string encoded;
    int n = text.size();

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i + 1 < n && text[i] == text[i + 1]) {
            i++;
            count++;
        }
        encoded += text[i] + to_string(count);
    }
    return encoded;
}

string runLengthDecode(const string& encoded) {
    string decoded;
    int n = encoded.size();
    
    for (int i = 0; i < n;) {
        char ch = encoded[i++];
        int count = 0;


        while (i < n && isdigit(encoded[i])) {
            count = count * 10 + (encoded[i++] - '0');
        }

        decoded.append(count, ch);
    }
    return decoded;
}

string decodeCaesarCipher(const string& encodedText, int shift) {
    string decoded = encodedText;
    for (size_t i = 0; i < encodedText.size(); i++) {
        if (isalpha(encodedText[i])) {
            char base = islower(encodedText[i]) ? 'a' : 'A';
            decoded[i] = (encodedText[i] - base - shift + 26) % 26 + base;
        }
    }
    return decoded;
}

int main() {
    string text = "Hhheeeeello";
    int shift = 3;
    string encodedText = encodeCaesarCipher(text, shift);
    cout << "Encoded Text (Caesar cipher): " << encodedText << endl;

    string compressedText = runLengthEncode(encodedText);
    cout << "Compressed Text (RLE): " << compressedText << endl;

    string decompressedText = runLengthDecode(compressedText);
    cout << "Decompressed Text (RLE): " << decompressedText << endl;
    
    string decodedText = decodeCaesarCipher(decompressedText, shift);
    cout << "Decoded Text (Caesar cipher): " << decodedText << endl;


    return 0;
}
