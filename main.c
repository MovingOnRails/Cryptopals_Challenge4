#include <stdio.h>

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Must pass 1 argument\n");
    }
    FILE *file = fopen("./input.txt","r");
    if(file == NULL){
        perror("error when opening file");
        exit(1);
    }
    int i=0;
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), file)){
        
    }
}