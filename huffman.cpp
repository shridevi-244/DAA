#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Huffman {
    char data[100];
    double freq[100];
    int left[100], right[100];
    string codes[100]; // Stores bit strings for each character
    int n, size;

public:
    // Find index of minimum frequency node that hasn't been used
    int findMin(bool used[]) {
        double minVal = 1e9;
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (!used[i] && freq[i] < minVal) {
                minVal = freq[i];
                index = i;
            }
        }
        return index;
    }

    // Traverse tree to generate bit codes
    void generateCodes(int root, string code) {
        if (root == -1) return;

        // Leaf node detection
        if (left[root] == -1 && right[root] == -1) {
            codes[root] = code;
            cout << data[root] << " : " << code << endl;
            return;
        }

        generateCodes(left[root], code + "0");
        generateCodes(right[root], code + "1");
    }

    void build() {
        cout << "Enter number of characters: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter character and frequency: ";
            cin >> data[i] >> freq[i];
            left[i] = right[i] = -1;
        }

        size = n;
        bool used[100];
        for (int i = 0; i < 100; i++) used[i] = false;

        // Build the Huffman Tree
        for (int i = 0; i < n - 1; i++) {
            int min1 = findMin(used);
            used[min1] = true;

            int min2 = findMin(used);
            used[min2] = true;

            data[size] = '$'; // Internal node marker
            freq[size] = freq[min1] + freq[min2];
            left[size] = min1;
            right[size] = min2;
            used[size] = false; // New combined node is available
            size++;
        }

        cout << "\nHuffman Codes:\n";
        generateCodes(size - 1, "");

        // --- Encoding Section ---
        string word, encoded = "";
        cout << "\nEnter word to encode: ";
        cin >> word;

        for (int i = 0; i < word.length(); i++) {
            for (int j = 0; j < n; j++) {
                if (data[j] == word[i]) {
                    encoded += codes[j];
                    break;
                }
            }
        }
        cout << "Encoded string: " << encoded << endl;

        // --- Decoding Section ---
        string decoded = "";
        int current = size - 1; // Start at the root of the tree
        for (int i = 0; i < encoded.length(); i++) {
            if (encoded[i] == '0')
                current = left[current];
            else
                current = right[current];

            // If we reach a leaf node
            if (left[current] == -1 && right[current] == -1) {
                decoded += data[current];
                current = size - 1; // Return to root for next character
            }
        }
        cout << "Decoded word: " << decoded << endl;
    }
};

int main() {
    Huffman h;
    h.build();
    return 0;
}