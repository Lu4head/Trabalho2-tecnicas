// tratamento que resulta igual o do professor (quase)
#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

char converte_registro(char registro) {

    const char caracteres[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`.";


    const int num_intervalos = 4;
    const int intervalo = 256 / num_intervalos;

    
    int indice = registro / intervalo;

    // Certificar-se de que o índice está dentro dos limites
    if (indice < 0) indice = 0;
    else if (indice >= num_intervalos) indice = num_intervalos - 1;

    return caracteres[indice];
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    const char nome_arquivo_input[] = "img2.foo5" ;
    ifstream input_file("./Exemplos/img2.foo", ios::binary);
    ofstream output_file(nome_arquivo_input);

    if(input_file.fail()){
        cout << "Erro ao abrir o arquivo " << nome_arquivo_input << endl;
        return 1;
    }

    char registro;
    int altura , largura;
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

    input_file.close();
    output_file.close();   

    return 0;
}
