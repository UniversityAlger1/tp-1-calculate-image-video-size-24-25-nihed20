#include "config/coloredBitmap.h"
#include <string.h> // Pour strcmp
#include <stdio.h>  // Pour printf (en cas de debug)

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value:
//   Colored image size in the specified unit, or -1 if an invalid unit is passed
float coloredBitmap(int w, int h, char* unit) {
    // Validation des dimensions
    if (w <= 0 || h <= 0) {
        fprintf(stderr, "Erreur : dimensions invalides (w=%d, h=%d).\n", w, h);
        return -1; // Retourne -1 pour indiquer une erreur
    }

    // Calcul de la taille en bits
    // Chaque pixel utilise 3 octets (24 bits), donc taille totale en bits :
    float sizeInBits = (float)(w * h * 3 * 8);

    // Conversion en fonction de l'unité spécifiée
    if (strcmp(unit, "bt") == 0) { // Bits
        return sizeInBits;
    } else if (strcmp(unit, "ko") == 0) { // Kilobits
        return sizeInBits / 1024;
    } else if (strcmp(unit, "mo") == 0) { // Megabits
        return sizeInBits / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) { // Gigabits
        return sizeInBits / (1024 * 1024 * 1024);
    } else {
        fprintf(stderr, "Erreur : unité invalide (%s). Utilisez 'bt', 'ko', 'mo' ou 'go'.\n", unit);
        return -1; // Retourne -1 pour indiquer une erreur
    }
}
