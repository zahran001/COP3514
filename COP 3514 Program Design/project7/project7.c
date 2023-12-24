// Zahran Yahia Khan. This program searches for animals in a data file (animals.txt) for adoption purposes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_animals 200 // maximum number of animals
#define max_length 101 // since the maximum length for name, species, and gender is 100 characters

// define the structure for an animal
struct Animal {
    char name[max_length];
    char species[max_length];
    char gender[max_length];
    int age;
    double weight;
};

int main() {
    // Declaring the variables
    struct Animal animals[max_animals]; // array of Animal structures
    int num_animals = 0; // number of animals 
    char find_species[max_length];
    char find_gender[max_length];

    // Open the input file
    FILE *inputFile = fopen("animals.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    // Read data from the file and fill the array with the data.
    while(!feof(inputFile)&&!ferror(inputFile)){
        if(fscanf(inputFile, "%s %s %s %d %lf", animals[num_animals].name, animals[num_animals].species, animals[num_animals].gender, &animals[num_animals].age, &animals[num_animals].weight) == 5)
        {
            num_animals++;
        }
    }

    // Get input from the user for species and gender
    printf("Enter the species: ");
    scanf("%s", find_species);
    printf("Enter the gender: ");
    scanf("%s", find_gender);

    // Open the output file
    FILE *outputFile = fopen("results.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    // Search for matching animals and write to the output file
    int i;
    for (i = 0; i < num_animals; i++) {
        if (strcmp(animals[i].species, find_species) == 0 &&
            strcmp(animals[i].gender, find_gender) == 0) {
            fprintf(outputFile, "%s %d %.2lf\n",
                    animals[i].name, animals[i].age, animals[i].weight);
        }
    }

    // Close the input file
    fclose(inputFile);

    // Close the output file
    fclose(outputFile);

    printf("Output file name: results.txt\n");

    return 0;
}
