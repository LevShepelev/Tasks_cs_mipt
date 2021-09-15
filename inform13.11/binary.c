#include <stdio.h>
#include <stdlib.h>
 
#define ERROR_FILE_OPEN -3
 void read() {
    FILE *input = NULL;
    int number;
 
    input = fopen("bin_file.txt", "rb");
    if (input == NULL) {
        printf("Error opening file");
        exit(ERROR_FILE_OPEN);
    }
 
    fread(&number, sizeof(int), 1, input);
    printf("%d", number);
 
    fclose(input);
}

void write() {
    FILE *output = NULL;
    int number;
 
    output = fopen("bin_file.txt", "wb");
    if (output == NULL) {
        printf("Error opening file");
        exit(ERROR_FILE_OPEN);
    }
 
    scanf("%d", &number);
    fwrite(&number, sizeof(int), 1, output);
 
    fclose(output);
}
int main()
    {
    write();
    read();
    }