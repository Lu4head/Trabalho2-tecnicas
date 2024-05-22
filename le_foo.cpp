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
            cout << static_cast<int>(static_cast<unsigned char>(buffer[i])) << " ";
        }

        // Clean up the buffer
        delete[] buffer;

        file.close();
    } else {
        cout << "Failed to open the file." << endl;
    }

    return 0;
}
