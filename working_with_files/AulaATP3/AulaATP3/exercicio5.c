#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main(){

    FILE* file;
    FILE* bin_file;
    
    bin_file = fopen("arquivo.bin", "rb");
    file = fopen("arquivo.txt", "r");
    char str[] = "Caqui";
    char current_char;
    bool prob_word = false;
    int i = 0;
    int line = 1;
    while(!feof(file)){
    	current_char = getc(file);
    	if (current_char == str[i]){
			prob_word = true;
			i++;
		}else{
			prob_word = false;
			i = 0;
		}
		if(current_char == '\n'){
			line++;
		}
		if(i == strlen(str)){
			printf("%i", line);
			i = 0;
		}
	}
 		
    
    return 0;
}
