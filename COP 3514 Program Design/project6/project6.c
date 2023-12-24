// Zahran Yahia Khan
// This program reads words from a user-specified file, extracts the first letter of each word, 
// decodes the message, and writes the result to a new file with a "decoded_" prefix added to the original file name.

#include <stdio.h>
#include <string.h>

#define max_words 1000 // the input text does not have more than 1000 words
#define word_length 100 // each word does not have more than 100 characters
#define FILE_NAME 100 //  file names (including the output file name) do not exceed 100 characters
 
void decode(char words[][101], int num_words, char *result); // function declaration

int main()
{
    char file_name[FILE_NAME + 1];
    char decoded_file_name[FILE_NAME + 1 + 8]; // 8 is the length of "decoded_" prefix

    // Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open the input file
    FILE *input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // there are no punctuations in the file
    // reading words from the file into an array
    char words[max_words+1][word_length + 1];
    int num_words = 0;

    // fscanf returns 1 if it successfully reads a word
    while (!feof(input_file) && !ferror(input_file) && num_words < max_words) {
        if (fscanf(input_file, "%100s", words[num_words]) == 1) {
            num_words++;
        } else {
            // handling the case where fscanf fails
            break;
        }
    }

    // The format specifier "%100s" indicates that it should read up to 100 characters, excluding white spaces, 
    // and store the result in words[num_words], where num_words is the index of the current word being read.

    // Close the input file
    fclose(input_file);

    // make the decoded file name using strcpy() and strcat() functions
    strcpy(decoded_file_name, "decoded_");
    strcat(decoded_file_name, file_name);

    printf("Output file name:\n%s\n", decoded_file_name);

    // calling the decode function
    char result[max_words + 1];  // +1 for null terminator
    decode(words, num_words, result);

    // Open the output file
    FILE *output_file = fopen(decoded_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write the result to the output file using fputs
    fputs(result, output_file);
    // Close the output file
    fclose(output_file);

    // Display the result
    printf("result: %s\n", result);

    return 0;
}

void decode(char words[][101], int num_words, char *result) {
    int i;
    int index = 0;

    // Iterating through words and extracting the first letter
    for (i = 0; i < num_words; i++) {
        result[index++] = words[i][0];
    }

    // Add null terminator at the end
    result[index] = '\0';
}