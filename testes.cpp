#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int converte_registro(char registro){
    int registro_int = abs((unsigned char) registro);

    int min = 3;
    int max = 255;
    char caracteres[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`.";
    int numCaracteres = sizeof(caracteres);
    double variacao = static_cast<double>(max - min + 1) / (numCaracteres - 1);

    int indice = static_cast<int>((registro_int - min) / variacao);
        
    char registro_convertido = caracteres[indice];

    return registro_convertido;

    //return registro_int;
}

int main(){
    setlocale(LC_ALL,"Portuguese");

    ifstream input_file("./Exemplos/img0.foo", ios::binary);
    ofstream output_file("img0.foo2");

    if(input_file.fail()){
        cout << "Erro ao abrir o arquivo de entrada" << endl;
        return 1;
    }
    if(output_file.fail()){
        cout << "Erro ao abrir o arquivo de saída" << endl;
        return 1;
    }

    char registro;
    input_file.seekg(0, ios::end);
    int tamanho_arquivo = input_file.tellg();
    input_file.seekg(0, ios::beg);
    char* dados_convertidos = new char[tamanho_arquivo];
    int tamanho_primeira_linha = 0;
    bool escrever_como_char = true; // Variável para controlar o modo de escrita

    for(int indice = 0; indice < tamanho_arquivo; ++indice){
        input_file.read(&registro, sizeof(registro));
        
        if (escrever_como_char) {
            output_file << registro; // Escreve como char
            tamanho_primeira_linha++;
        } else {
            char registro_convertido = converte_registro(registro);
            dados_convertidos[indice - tamanho_primeira_linha] = registro_convertido;
        }

        if (registro == '\n') {
            escrever_como_char = false; // Altera o modo de escrita para int
        }

    }

    if (!escrever_como_char) {
        for(int i = 0; i < tamanho_arquivo - tamanho_primeira_linha; ++i){
            output_file << dados_convertidos[i] << " "; // Escreve como int
        }
    }

    delete[] dados_convertidos;
    input_file.close();
    output_file.close();   

    return 0;
}