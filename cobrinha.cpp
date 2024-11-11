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
  
    for(int i = 0; i < (int)grid.size(); i++){
      for(int j = 0; j < (int)grid[0].size(); j++){
        if(grid[i][j] == 'h'){
          current_x = j;
          current_y = i;
        }
      }
    }

    int is_searching = 0;
    while(is_searching == 0){
      posicao = {current_x, current_y};
      cord.push_back(posicao);
      cout << posicao[0] << "," << posicao[1] << endl;
      if(grid[current_y][current_x + 1] == '<'){
        current_x++;
      }
      else if(grid[current_y][current_x - 1] == '>'){
        current_x--;
      }
      else if(grid[current_y + 1][current_x] == '^'){
        current_y++;
      }
      else if(grid[current_y - 1][current_x] == 'v'){
        current_y--;
      }
      else{
        is_searching = 1;
      }
      
    }
    cout << posicao[0] << "," << posicao[1] << endl;
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