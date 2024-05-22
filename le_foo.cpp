#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>

using namespace std;

int main(){
    setlocale(LC_ALL,"Portuguese");
    ifstream file("./Exemplos/img0.foo", ios::binary);
    if (file.is_open()) {
        // Get the size of the file
        file.seekg(0, ios::end);
        int fileSize = file.tellg();
        file.seekg(0, ios::beg);

        // Create a buffer to hold the file data
        char* buffer = new char[fileSize];

        // Read the file data into the buffer
        file.read(buffer, fileSize);

        // Output the buffer as binary values
        for (int i = 0; i < fileSize; i++) {
            //cout << static_cast<int>(buffer[i]) << " ";
        }

        // Open the output file
        ofstream outputFile("imo0.foo2_teste");

        // Check if the output file is open
        if (outputFile.is_open()) {
            // Write the translated characters to the output file
            for (int i = 0; i < fileSize; i++) {
                int value = static_cast<int>(buffer[i]);
                char translatedChar;

                // Determine the translated character based on the value
                if (value >= 200) {
                    translatedChar = '$';
                } else if (value >= 180) {
                    translatedChar = '@';
                } else if (value >= 160) {
                    translatedChar = 'B';
                } else if (value >= 140) {
                    translatedChar = '%';
                } else if (value >= 120) {
                    translatedChar = '8';
                } else if (value >= 100) {
                    translatedChar = '&';
                } else if (value >= 80) {
                    translatedChar = 'W';
                } else if (value >= 60) {
                    translatedChar = 'M';
                } else if (value >= 40) {
                    translatedChar = '#';
                } else if (value >= 20) {
                    translatedChar = '*';
                } else {
                    translatedChar = ' ';
                }

                // Write the translated character to the output file
                outputFile << translatedChar;
            }

            // Close the output file
            outputFile.close();
        } else {
            cout << "Failed to create the output file." << endl;
        }
        // Clean up the buffer
        delete[] buffer;

        file.close();
    } else {
        cout << "Failed to open the file." << endl;
    }

    return 0;
}
