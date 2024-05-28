// tratamento que resulta igual o do professor (quase)
#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

char converte_registro(unsigned char registro) {

    const char caracteres[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`.";
    double num_caracteres = sizeof(caracteres); // Número de elementos na lista de caracteres
    double tam_intervalos = 256 / num_caracteres; // Tamanho de cada intervalo 
    double intervalo = 256 / tam_intervalos; // Número de intervalos em que será dividida a lista de caracteres

    int indice = registro / intervalo; // Indice da lista de caracteres a ser utilizado com base no valor do registro

    // Certificar-se de que o índice está dentro dos limites
    if (indice < 0) indice = 0;
    else if (indice >= num_caracteres - 1) indice = num_caracteres - 1;
    
    return caracteres[indice];
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Portuguese");

    if (argc < 3) { // Verifica se todos os parametros necessários foram passados
        cout << "Uso: " << argv[0] << " <arquivo_de_entrada> <arquivo_de_saida>" << endl;
        return 1;
    }

    ifstream input_file(argv[1], ios::binary); // argv[1] é o nome do arquivo de entrada	
    ofstream output_file(argv[2]); // argv[2] é o nome do arquivo de saída


    if(input_file.fail()){
        cout << "Erro ao abrir o arquivo " << argv[1] << endl;
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