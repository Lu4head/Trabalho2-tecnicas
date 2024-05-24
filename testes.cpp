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
    char nome_arquivo_input[] = "img0.foo2" ;
    ifstream input_file("./Exemplos/img0.foo", ios::binary);
    ofstream output_file(nome_arquivo_input);

    if(input_file.fail()){
        cout << "Erro ao abrir o arquivo " << nome_arquivo_input << endl;
        return 1;
    }

    char registro;
    int altura , largura;
    //char **dados_convertidos;
    input_file >> largura >> altura;
    output_file << largura << " " << altura << endl;

    for(int i = 0; i < altura ; ++i){
        for(int j = 0; j < largura ; ++j){
            input_file.read(&registro, 1);
            char registro_convertido = converte_registro(registro);
            output_file << registro_convertido;
        }
        output_file << '\n';
    }


    //delete[] dados_convertidos;
    input_file.close();
    output_file.close();   

    return 0;
}