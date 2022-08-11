#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main(int argc, char* argv[]){
    //extern int errno;
    if(argc != 2){
        fprintf(stderr, "Error: no hay 1 solo argumento");
        return 1;
    }
    FILE* file = fopen(argv[1], "rt+");
    if(file == NULL){
        perror("Error");
        return 2;
    }
    char chr = fgetc(file);
    int chr_count = 0;
    while(chr != EOF){
        if(chr == 'a') chr_count++;
        chr = fgetc(file);
    }
    fprintf(file, "\nCantidad de a: %d", chr_count);
    if(fclose(file) == EOF){
        perror("Error");
        return 3;
    }
    return 0;
}