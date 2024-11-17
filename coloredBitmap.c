#include "config/coloredBitmap.h"
#include <string.h> // Pour strcmp

// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN

   // Validation des dimensions
   if (w <= 0 || h <= 0) {
       return 0; // Retourne 0 si largeur ou hauteur est invalide
   }

   // Calcul de la taille en bits (1 byte = 8 bits, et chaque pixel utilise 3 bytes)
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
       return -1; // Retourne -1 si l'unité est invalide
   }
   // YOUR CODE HERE - END
}
