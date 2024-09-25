#include <stdio.h>
int main(){

    FILE* file;
    FILE* bin_file;
    
    bin_file = fopen("arquivo.bin", "rb");
    file = fopen("arquivo.txt", "r");
    
    
    
    
	char string[1000];
    fseek(file,-20,SEEK_END);
    fread(string,sizeof(string),1,file);
    
    fwrite(string,sizeof(string),1,bin_file);
	fread(string,sizeof(string),1,bin_file);
    printf("%s", string);
    
    return 0;
}
