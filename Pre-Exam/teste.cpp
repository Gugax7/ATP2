#include <iostream>
#include <string>
#include <vector>

/*void geraSubconjuntos(const std::string &input, std::string subconjuntoAtual, int index) {
    std::cout << index << " " <<  input.size() << std::endl;
    if (index == input.size()) {  // Caso base: todos os caracteres foram processados
        std::cout << "{" << subconjuntoAtual << "}" << std::endl;
        return;
    }

    // Caso 1: não incluir o caractere atual no subconjunto
    geraSubconjuntos(input, subconjuntoAtual, index + 1);

    // Caso 2: incluir o caractere atual no subconjunto
    geraSubconjuntos(input, subconjuntoAtual + input[index], index + 1);
}

void conjuntoPotencia(const std::string &input) {
    geraSubconjuntos(input, "", 0);
}*/

void generateSub(std::string &input, std::string current_sub, int index){
    if(index == input.size()){
        std::cout << "{" << current_sub << "}" << std::endl;
        return;
    }

    generateSub(input, current_sub ,index+1);
    generateSub(input,current_sub+input[index], index+1);
}

int main() {
    std::string letras;
    std::cout << "Digite uma string: ";
    std::cin >> letras;

    std::cout << "Conjunto potência:\n";
    generateSub(letras,"",0);

    return 0;
}