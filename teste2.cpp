// tratamento mais claro, luan preferiu
#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

char converte_registro(char registro) {
    
    const char caracteres[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`.";

    int indice = static_cast<int>(registro);
    
 
    if (indice < 0) indice = 0;
    else if (indice >= sizeof(caracteres) - 1) indice = sizeof(caracteres) - 2;

    return caracteres[indice];
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    char nome_arquivo_input[] = "img0.foo5" ;
    ifstream input_file("./Exemplos/img1.foo", ios::binary);
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