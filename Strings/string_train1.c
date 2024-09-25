#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse(char string[]){
    char aux;
    printf("%i", strlen(string));
    for(int i = 0, j = strlen(string) - 2; i < j; i++,j--){
        aux = string[j];
        string[j] = string[i];
        string[i] = aux;
    }
}
bool palyndrome_check(char string[]){
    bool is_palyndrome = true;
    for(int i = 0, j = strlen(string) - 2; i < j; i++,j--){
        if(string[i] != string[j]){
            printf("\ni(%i): %c, j(%i): %c",i , string[i],j, string[j]);
            is_palyndrome = false;
        }
    }
    return is_palyndrome;
}

void check_substring(char string1[], char string2[], char receive[]){
    int bigger_length = 0;
    int count = 0;
    char current_substring[50];
    char bigger_substring[50];

    for(int i = 0; i < strlen(string1) - 2; i++){
        for(int j = 0; j < strlen(string2) - 2; j++){
            if(string1[i] == string2[j]){
                current_substring[count] = string2[j];
                count++;
                if(count > bigger_length){
                    strcpy(bigger_substring,current_substring);
                    bigger_length = count;
                }
                while(string1[i+1] == string2[j+1]){
                    i++;
                    j++;  
                    count++;
                    current_substring[count] = string2[j];
                    if(count + 1 > bigger_length){
                        strcpy(bigger_substring,current_substring);
                        bigger_length = count + 1;
                    }      
                }
                count = 0;
                
            }
        }
        
    }
    strcpy(receive,bigger_substring);
}

int vogal_count(char string[]){
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == 'A' || string[i] == 'a'
        || string[i] == 'E' || string[i] == 'e'
        || string[i] == 'I' || string[i] == 'i'
        || string[i] == 'O' || string[i] == 'o'
        || string[i] == 'U' || string[i] == 'u'){

            count++;
        }
    }
    return count++;
}

int main(){
    char name[50];
    char string1[] = "leite";
    char string2[] = "azeite";
    char string3[50];
    printf("Say my name:");
    fgets(name,sizeof(name),stdin);
    reverse(name);
    printf("Name:");
    int i = 0; char c = name[i]; 


    while( c != '\0'){
        printf("%c",c);
        i++;
        c = name[i];
    }

    check_substring(string1,string2,string3);
    printf("%s", string3);
    //printf("\nnumber of vogals: %i", vogal_count(name));
    //printf("\nis palyndrome: %i", palyndrome_check(name));





    return 0;
}