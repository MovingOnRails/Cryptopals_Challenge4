#include <stdio.h>
#include <stdint.h>
#include "../Challenge3/main.c"

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Must pass 1 argument\n");
    }
    FILE *infile = fopen("./input.txt","r");
    if(infile == NULL){
        perror("error when opening file");
        exit(1);
    }
    FILE *outfile = fopen("./out.txt","w");
    if(infile == NULL){
        perror("error when opening file");
        exit(1);
    }
    char hexStringToBreak[256];
    int i=0;
    while(fgets(hexStringToBreak, sizeof(hexStringToBreak), infile)){
        hexStringToBreak[strcspn(hexStringToBreak, "\n")] = '\0';
        int rawStringToBreakLength = strlen(hexStringToBreak)/2;
        
        
        int xorByte = singleByteXOR_getMostProbableRawByte(hexStringToBreak);
        
        uint8_t* rawStringToBreak = calloc(rawStringToBreakLength+1, sizeof(uint8_t));
        hexStringToRawString(hexStringToBreak, rawStringToBreak);
        uint8_t* singleByteRawString = createSingleByteRawString(xorByte, rawStringToBreakLength);
        uint8_t* rawResultString = calloc((rawStringToBreakLength)+1, sizeof(uint8_t));

        xorAgainstEncodedString_rawStrings(rawStringToBreak,singleByteRawString, rawResultString, rawStringToBreakLength);

        fprintf(outfile, "i: %i || ", i);
        fprintf(outfile, "xorByte: %x || ", xorByte);
        fprintf(outfile, "string: %s\n",rawResultString);
        i++;
    }
    fclose(infile);
    fclose(outfile);
    return 0;
}