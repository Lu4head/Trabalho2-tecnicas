#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

unsigned char converte_registro(unsigned char registro){
    int min = 0 , max = 255;
    const unsigned char caracteres[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`.";
    int numCaracteres = sizeof(caracteres) - 1;
    double variacao =  (max - min + 1) / (numCaracteres);

    int indice = (registro - min) / variacao;
    if (indice < 0) indice = 0;
    else if (indice >= numCaracteres) indice = numCaracteres - 1;    
    return caracteres[indice];
}


int main(){
    setlocale(LC_ALL,"Portuguese");

    const char nome_arquivo_input[] = "img0.foo" ;
    const char nome_arquivo_output[] = "img0.foo2" ;

    ifstream input_file(nome_arquivo_input, ios::binary);
    ofstream output_file(nome_arquivo_output);

    if(input_file.fail()){
        cout << "Erro ao abrir o arquivo " << nome_arquivo_input << endl;
        return 1;
    }
    unsigned char registro;
    int altura , largura;
    input_file >> largura >> altura;
    output_file << largura << " " << altura << endl;

    for(int i = 0; i < altura ; ++i){
        for(int j = 0; j < largura ; ++j){
            input_file.read(reinterpret_cast<char*>(&registro), 1);
            output_file << converte_registro(registro);
        }
        output_file << '\n';
    }

    input_file.close();
    output_file.close();   

    return 0;
}