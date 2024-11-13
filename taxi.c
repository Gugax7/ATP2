#include <stdio.h>
#include <stdlib.h>
#include <math.h>


char* escolhe_taxi(char* tf1,char* vqr1,char* tf2,char* vqr2)
{
  float tar1 = atof(tf1);
  float vakm1 = atof(vqr1);
  float tar2 = atof(tf2);
  float vakm2 = atof(vqr2);
  
  if(tar1 == tar2 && vakm1 == vakm2){
    return "Tanto faz";
  }
  if(tar1 > tar2 && vakm1 > vakm2){
    return "Empresa 2";
  }
  if(tar2 > tar1 && vakm2 > vakm1){
    return "Empresa 1";
  }
  if(tar2 > tar1){
    float km;
    for(km = 0; tar1 + vakm1 * km <(tar2 + vakm2 * km); km+=0.01);
    char *mensagem = (char*)malloc(100);
    km = floor(km * 100) / 100;
    if(km == floor(km)){
      sprintf(mensagem, "Empresa 1 quando a distância < %.1f, Tanto faz quando a distância = %.1f, Empresa 2 quando a distância > %.1f", km, km, km);
    return mensagem;
    };
    km-=0.01;
    sprintf(mensagem, "Empresa 1 quando a distância < %.2f, Tanto faz quando a distância = %.2f, Empresa 2 quando a distância > %.2f", km, km, km);
    return mensagem;
  }
  if(tar1 > tar2){
    float km;
    for(km = 0; tar2 + vakm2 * km < (tar1 + vakm1 * km); km+=0.01);
    char *mensagem = (char*)malloc(100);
    km = floor(km * 100) / 100;
    if(km == floor(km)){
      sprintf(mensagem, "Empresa 2 quando a distância < %.1f, Tanto faz quando a distância = %.1f, Empresa 1 quando a distância > %.1f", km, km, km);
    return mensagem;
    }
    sprintf(mensagem, "Empresa 2 quando a distância < %.2f, Tanto faz quando a distância = %.2f, Empresa 1 quando a distância > %.2f", km, km, km);
    return mensagem;
  }
  
  return "deu erro";
  
}
int main(){
    char* actual0 = escolhe_taxi("2.5","1.0","5.0","0.75");
    printf("%s", actual0);
    return 0;
}