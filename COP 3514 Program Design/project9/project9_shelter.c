// Zahran Yahia Khan. This program searches for animals in a data file (animals.txt) for adoption purposes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_animals 200 // maximum number of animals
#define max_length 101 // since the maximum length for name, species, and gender is 100 characters

int compare_animals(const void *p, const void *q);

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

    qsort(animals, num_animals, sizeof(struct Animal), compare_animals);

    // Open the output file
    FILE *outputFile = fopen("results.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    // Search for matching animals and write to the output file
    int i;
    for (i = 0; i < num_animals; i++) {
        fprintf(outputFile, "%s %d %s %.2lf %s\n",
            animals[i].species, animals[i].age, animals[i].name, animals[i].weight, animals[i].gender);
        
    }

    // Close the input file
    fclose(inputFile);

    // Close the output file
    fclose(outputFile);

    printf("Output file name: results.txt\n");

    return 0;
}

// Comparison function for qsort
int compare_animals(const void *p, const void *q) {
    // Cast the pointers to struct Animal
    // Use pointer type specifier to avoid explicit casting
    const struct Animal *animalA = p;
    const struct Animal *animalB = q;

    // Compare by species first
    int species_comparison = strcmp(animalA->species, animalB->species);
    if (species_comparison != 0) {
        return species_comparison;
    }

    // If species is the same, compare by age
    return animalA->age - animalB->age;
}
