#include <string>
#include <vector>
#include <iostream>
using namespace std;
using std::string;
using std::vector;

vector<vector<int>> find_snake_on_grid(const vector<string>& grid) {
    int current_x, current_y;
    vector<int> posicao;
    vector<vector<int>> cord;
    
    // Encontrar a posição da cabeça 'h'
    for (int i = 0; i < (int)grid.size(); i++) {
        for (int j = 0; j < (int)grid[0].size(); j++) {
            if (grid[i][j] == 'h') {
                current_x = j;
                current_y = i;
            }
        }
    }

    // Direções de movimento para cada símbolo
    int is_searching = 0;
    while (is_searching == 0) {
        posicao = {current_y, current_x};
        cord.push_back(posicao);
        
        // Verificar e seguir a próxima seta
        if (current_x + 1 < (int)grid[0].size() && grid[current_y][current_x + 1] == '<') {
            current_x++;
        }
        else if (current_x - 1 >= 0 && grid[current_y][current_x - 1] == '>') {
            current_x--;
        }
        else if (current_y + 1 < (int)grid.size() && grid[current_y + 1][current_x] == '^') {
            current_y++;
        }
        else if (current_y - 1 >= 0 && grid[current_y - 1][current_x] == 'v') {
            current_y--;
        }
        else {
            is_searching = 1;  // Se não houver mais setas, encerra a busca
        }
    }
    
    return cord;
}

int main() {
    vector<string> grid = {
        " >>v   ",
        " ^ h   ",
        " ^<<<< "
    };
    
    vector<vector<int>> resultado = find_snake_on_grid(grid);
    
    // Imprimir resultado
    for (vector<int> pos : resultado) {
        cout << "[" << pos[0] << ", " << pos[1] << "]\n";
    }
    
    return 0;
}