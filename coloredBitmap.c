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

    // Utilisation de long long pour éviter des débordements avec de grandes tailles d'images
    long long sizeInBits = (long long)(w) * (long long)(h) * 3 * 8; // Chaque pixel utilise 3 octets (24 bits)

    // Conversion en fonction de l'unité spécifiée
    if (strcmp(unit, "bt") == 0) { // Bits
        return (float)sizeInBits;
    } else if (strcmp(unit, "ko") == 0) { // Kilobits
        return (float)sizeInBits / 1024;
    } else if (strcmp(unit, "mo") == 0) { // Megabits
        return (float)sizeInBits / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) { // Gigabits
        return (float)sizeInBits / (1024 * 1024 * 1024);
    } else {
        fprintf(stderr, "Erreur : unité invalide (%s). Utilisez 'bt', 'ko', 'mo' ou 'go'.\n", unit);
        return -1; // Retourne -1 pour indiquer une erreur
    }
}