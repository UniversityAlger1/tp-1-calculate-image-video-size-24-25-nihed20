#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored image)
//   durationCredits: duration in seconds of the credits (black & white image)
//   fps: Frames Per Second of the video
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Validation des dimensions et paramètres
    if (w <= 0 || h <= 0 || durationMovie < 0 || durationCredits < 0 || fps <= 0) {
        return 0; // Retourne 0 si les paramètres sont invalides
    }

    // Taille d'un cadre en bits
    float frameSizeColoredBits = (float)(w * h * 3 * 8);  // Couleur : 3 bytes/pixel
    float frameSizeBWBits = (float)(w * h * 8);           // Noir et blanc : 1 byte/pixel

    // Calcul de la taille totale pour chaque section
    float sizeMovieBits = frameSizeColoredBits * fps * durationMovie; // Taille de la section couleur
    float sizeCreditsBits = frameSizeBWBits * fps * durationCredits;  // Taille de la section noir et blanc

    // Taille totale en bits
    float totalSizeBits = sizeMovieBits + sizeCreditsBits;

    // Conversion en fonction de l'unité
    if (strcmp(unit, "bt") == 0) { // Bits
        return totalSizeBits;
    } else if (strcmp(unit, "ko") == 0) { // Kilobits
        return totalSizeBits / 1024;
    } else if (strcmp(unit, "mo") == 0) { // Megabits
        return totalSizeBits / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) { // Gigabits
        return totalSizeBits / (1024 * 1024 * 1024);
    } else {
        return -1; // Retourne -1 si l'unité est invalide
    }
}