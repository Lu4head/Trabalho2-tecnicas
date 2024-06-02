// Integrantes do grupo:
// Nome: Luan Emanuel R. Argentato     RA: 2184611
// Nome: Gustavo T. Duzzi              RA: 2214047
// Nome: Guilherme Santos Gollino      RA: 2226090 

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
    int altura , largura;

    if (argc < 3) { // Verifica se todos os parametros necessários foram passados
        cout << "Uso: " << argv[0] << " <arquivo_de_entrada> <arquivo_de_saida>" << endl;
        return 1;
    }
    ifstream input_file(argv[1], ios::binary); // argv[1] é o nome do arquivo de entrada	
    if (!input_file) { // Verificação de erro na abertura do arquivo de entrada
        cout << "Erro ao abrir o arquivo " << argv[1] << endl;
        exit (-1);
    }
    ofstream output_file(argv[2]); // argv[2] é o nome do arquivo de saída
    if (!output_file) { // Verificação de erro na criação do arquivo de saída 
        cout << "Erro ao criar o arquivo " << argv[2] << endl;
        exit(-1);
    }
    input_file.seekg(0, ios::end); // Posiciona o ponteiro de leitura no final do arquivo
    int fim_do_arquivo = input_file.tellg(); // Armazena a posição do ponteiro de leitura
    input_file.seekg(0, ios::beg); // Posiciona o ponteiro de leitura no início do arquivo

    unsigned char registro;
    input_file >> largura >> altura; // Lê a largura e a altura da imagem
    output_file << largura << " " << altura << endl; // Armazena a largura e altura da imagem no arquivo de saída
    cout << "colunas (largura): " << largura << "\nlinhas (altura): " << altura << endl; // Exibe largura e altura no terminal
    for(int i = 0; i < altura ; ++i){ // Percorre as linhas da imagem
        for(int j = 0; j < largura ; ++j){ // Percorre as colunas da imagem
            input_file.read(reinterpret_cast<char*>(&registro), 1); // Lê um byte do arquivo de entrada
            output_file << converte_registro(registro); // Converte o byte lido e armazena no arquivo de saída
        }
        output_file << '\n'; // Finaliza a linha
    }
    
    if(input_file.tellg() != fim_do_arquivo){ // Verifica se o arquivo foi lido completamente
        cout << "Erro ao ler o arquivo " << argv[1] << endl;
        return -1;
    }
    
    cout << "Arquivo " << argv[2] << " convertido com sucesso!" << endl;

    input_file.close();
    output_file.close();   

    return 0;
}