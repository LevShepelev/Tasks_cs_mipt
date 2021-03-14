#include <stdio.h>
#include <stdlib.h>
 
#define ERROR_FILE_OPEN -3
 void read() {
    FILE *input = NULL;
    char number[20];
 
    input = fopen("bin_file.txt", "rb");
    if (input == NULL) {
        printf("Error opening file");
        exit(ERROR_FILE_OPEN);
    }
 
    fread(number, sizeof(char), 20, input);
    printf("%s", number);
 
    fclose(input);
}

void write() {
    FILE *output = NULL;
    char number[20];
 
    output = fopen("bin_file.txt", "wb");
    if (output == NULL) {
        printf("Error opening file");
        exit(ERROR_FILE_OPEN);
    }
 
    scanf("%s", number);
    fwrite(number, sizeof(char), 20, output);
 
    fclose(output);
}
int main()
    {
    write();
    read();
    }