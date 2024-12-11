#include <string>
#include <iostream>
using namespace std;


// ascii -> numeros vão de 60 ate 71
// vou receber 5 caracteres então minha string vai de 0 a 4
// j que posso escrever _ -> 2, 5, 11, 14
// i que posso escrever _ -> 1, 2, 3
// j que posso escrever | -> 1, 3, 4, 6, 10, 12, 13, 15
// i que posso escrever | -> 2, 3

std::string seven_segmentify(const std::string& time) {
    std::string clock;
    int index = 0;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 16; j++){
        // vamos arrumar primeiro os _
        if(i == 0){
                if((j == 2 && (time[0] == '2' || time[0] == '3' || time[0] == '5' ||time[0] == '6' ||time[0] == '7' ||time[0] == '8' ||time[0] == '9'))){
              //  printf("_");
                clock+="_";
                }
                else if((j == 5 && (time[1] == '2' || time[1] == '3' || time[1] == '5' ||time[1] == '6' ||time[1] == '7' ||time[1] == '8' ||time[1] == '9' || time[1]=='0'))){
               // printf("_");
                clock+="_";
                }
                else if((j == 11 && (time[3] == '2' || time[3] == '3' || time[3] == '5' ||time[3] == '6' ||time[3] == '7' ||time[3] == '8' ||time[3] == '9' || time[3]=='0'))){
               // printf("_");
                clock+="_";
                }
                else if((j == 14 && (time[4] == '2' || time[4] == '3' || time[4] == '5' ||time[4] == '6' ||time[4] == '7' ||time[4] == '8' ||time[4] == '9' || time[4]=='0'))){
               // printf("_");
                clock+="_";
                }
                else if(j != 0){
                    //printf(" ");
                    clock+=" ";
                }
                
            }
            else if(i == 1){
                if(j == 8){
                   // printf(".");
                    clock+=".";
                }
                else if(j == 2 && (time[0] == '2' || time[0] == '3' || time[0] == '4' || time[0] == '5' || time[0] == '6' || time[0] == '8' || time[0] == '9')){
                  // printf("_");
                    clock+="_";
                }
                else if(j == 5 && (time[1] == '2' || time[1] == '3' || time[1] == '4' || time[1] == '5' || time[1] == '6' || time[1] == '8' || time[1] == '9')){
                   // printf("_");
                    clock+="_";
                }
                else if(j == 11 && (time[3] == '2' || time[3] == '3' || time[3] == '4' || time[3] == '5' || time[3] == '6' || time[3] == '8' || time[3] == '9')){
                   // printf("_");
                    clock+="_";
                }
                else if(j == 14 && (time[4] == '2' || time[4] == '3' || time[4] == '4' || time[4] == '5' || time[4] == '6' || time[4] == '8' || time[4] == '9')){
                   // printf("_");
                    clock+="_";
                }
                // j que posso escrever | -> 1l, 3r / 4l, 6r / 10l, 12r / 13l, 15r
                // numeros com | na direita -> 1,2,3,4,7,8,9,0
                // numeros com | na esquerda -> 4,5,6,8,9,0
                else if((time[0] == '1' || time[0] == '2' || time[0] == '3' || time[0] == '4' || time[0] == '7' ||  time[0] == '8' || time[0] == '9') && (j == 3)){
                   // printf("|");
                    clock+="|";
                }
                else if((time[0] == '4' ||time[0] == '5' || time[0] == '6' ||   time[0] == '8' || time[0] == '9') && (j == 1)){
                  // printf("|");
                    clock+="|";
                }

                // segundo numero
                else if((time[1] == '1' || time[1] == '2' || time[1] == '3' || time[1] == '4' || time[1] == '7' ||  time[1] == '8' || time[1] == '9' || time[1] == '0') && (j == 6)){
                   // printf("|");
                    clock+="|";
                }
                else if((time[1] == '4' ||time[1] == '5' || time[1] == '6' ||   time[1] == '8' || time[1] == '9' || time[1] == '0') && (j == 4)){
                  //  printf("|");
                    clock+="|";
                }

                // terceiro numero
                else if((time[3] == '1' || time[3] == '2' || time[3] == '3' || time[3] == '4' || time[3] == '7' ||  time[3] == '8' || time[3] == '9' || time[3] == '0') && (j == 12)){
                  //  printf("|");
                    clock+="|";
                }
                else if((time[3] == '4' ||time[3] == '5' || time[3] == '6' ||   time[3] == '8' || time[3] == '9' || time[3] == '0') && (j == 10)){
                  //  printf("|");
                    clock+="|";
                }

                // quarto numero
                else if((time[4] == '1' || time[4] == '2' || time[4] == '3' || time[4] == '4' || time[4] == '7' ||  time[4] == '8' || time[4] == '9' || time[4] == '0') && (j == 15)){
                  //  printf("|");
                    clock+="|";
                }
                else if((time[4] == '4' ||time[4] == '5' || time[4] == '6' ||   time[4] == '8' || time[4] == '9' || time[4] == '0') && (j == 13)){
                   // printf("|");
                    clock+="|";
                }

                else if(j != 0){
                    //printf(" ");
                    clock+=" ";
                }
                
            }
            // agora linha 3
            else if(i == 2){
                // numeros com _ em baixo serao 2,3,5,6,8,9,0
                if(j == 8){
                   // printf(".");
                    clock+=".";
                }
                else if(j == 2 && (time[0] == '2' || time[0] == '3' || time[0] == '5' || time[0] == '6' || time[0] == '8' || time[0] == '9')){
                   // printf("_");
                    clock+="_";
                }
                else if(j == 5 && (time[1] == '2' || time[1] == '3' || time[1] == '5' || time[1] == '6' || time[1] == '8' || time[1] == '9' || time[1] == '0')){
                   // printf("_");
                    clock+="_";
                }
                else if(j == 11 && (time[3] == '2' || time[3] == '3' || time[3] == '5' || time[3] == '6' || time[3] == '8' || time[3] == '9' || time[3] == '0')){
                    //printf("_");
                    clock+="_";
                }
                else if(j == 14 && (time[4] == '2' || time[4] == '3' || time[4] == '5' || time[4] == '6' || time[4] == '8' || time[4] == '9' || time[4] == '0')){
                    //printf("_");
                    clock+="_";
                }
                // j que posso escrever | -> 1l, 3r / 4l, 6r / 10l, 12r / 13l, 15r
                // numeros com | na direita -> 1,3,4,5,6,7,8,9,0
                // numeros com | na esquerda -> 2,6,8,0
                else if((time[0] == '1' || time[0] == '3' || time[0] == '4' || time[0] == '5' || time[0] == '6' ||  time[0] == '7' || time[0] == '8' || time[0] == '9') && (j == 3)){
                    //printf("|");
                    clock+="|";
                }
                else if((time[0] == '2' ||time[0] == '6' || time[0] == '8') && (j == 1)){
                    //printf("|");
                    clock+="|";
                }

                // segundo numero
                else if((time[1] == '1' || time[1] == '3' || time[1] == '4' || time[1] == '5' || time[1] == '6' ||  time[1] == '7' || time[1] == '8' || time[1] == '9' || time[1] == '0') && (j == 6)){
                   // printf("|");
                    clock+="|";
                }
                else if((time[1] == '2' ||time[1] == '6' || time[1] == '8'|| time[1] == '0') && (j == 4)){
                    //printf("|");
                    clock+="|";
                }


                // terceiro numero
                else if((time[3] == '1' || time[3] == '3' || time[3] == '4' || time[3] == '5' || time[3] == '6' ||  time[3] == '7' || time[3] == '8' || time[3] == '9' || time[3] == '0') && (j == 12)){
                    //printf("|");
                    clock+="|";
                }
                else if((time[3] == '2' ||time[3] == '6' || time[3] == '8'|| time[3] == '0') && (j == 10)){
                    //printf("|");
                    clock+="|";
                }

                // quarto numero
                else if((time[4] == '1' || time[4] == '3' || time[4] == '4' || time[4] == '5' || time[4] == '6' ||  time[4] == '7' || time[4] == '8' || time[4] == '9' || time[4] == '0') && (j == 15)){
                    //printf("|");
                    clock+="|";
                }
                else if((time[4] == '2' ||time[4] == '6' || time[4] == '8'|| time[4] == '0') && (j == 13)){
                    //printf("|");
                    clock+="|";
                }
                else if(j != 0){
                    //printf(" ");
                    clock+=" ";
                }
            }
            index++;
        }
        //printf("\n");
      if(i != 2) clock+="\n";
    }
    return clock;
}

int main(){

    cout << seven_segmentify("00:00") << endl;
    cout << seven_segmentify("11:11") << endl;
    cout << seven_segmentify("22:22") << endl;
    cout << seven_segmentify("33:33") << endl;
    cout << seven_segmentify("44:44") << endl;
    cout << seven_segmentify("55:55") << endl;
    cout << seven_segmentify("66:66") << endl;
    cout << seven_segmentify("77:77") << endl;
    cout << seven_segmentify("88:88") << endl;
    cout << seven_segmentify("99:99") << endl;
    printf("%s%c%s", "vamo ver", '\n', "SE ISSO FUNCIONA");

    return 0;
}