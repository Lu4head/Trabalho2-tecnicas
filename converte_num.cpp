#include <iostream>

using namespace std;

int main() {
    int min = 0;
    int max = 255;
    char caracteres[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`";
    int numCaracteres = sizeof(caracteres);
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
