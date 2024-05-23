#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Definindo o intervalo de números e o número de caracteres
    int min = 0;
    int max = 255;
    const int numCaracteres = 67;
    char caracteres[numCaracteres] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`";
    double variacao = static_cast<double>(max - min + 1) / (numCaracteres - 1);


    for(int i = min ; i <= max ; ++i){
        int indice = static_cast<int>((i - min) / variacao);
        if(indice >= numCaracteres) {
            indice = numCaracteres - 1;
        }
        cout << "Número: " << i << " -> Caractere: " << caracteres[indice] << endl;
    }

    return 0;
}
