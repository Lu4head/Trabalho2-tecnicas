#include <iostream>

using namespace std;

int main() {
    // Definindo o intervalo de números e o número de caracteres
    int min = 0;
    int max = 255;
    const int numCaracteres = 67;
    char caracteres[numCaracteres] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`";
    double variacao = (1 + max - min) / numCaracteres;
    
    for(int i = min ; i <= max ; ++i){
        int indice = (i - min) / variacao;
        if(indice >= numCaracteres) {
            indice = numCaracteres - 1;
        }
        cout << "Número: " << i << " -> Caractere: " << caracteres[indice] << endl;
    }


    return 0;
}
