#include <stdio.h>
#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored image)
//   durationCredits: duration in seconds of the credits (black and white image)
//   fps: Frames Per Second of the video
//   unit: Unit of the output value. It could be 'bt' bytes, 'ko' kilobytes, 'mo' megabytes, 'go' gigabytes
// Return value:
//   Video size based on the specified unit
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Vérification des paramètres
    if (w <= 0 || h <= 0 || durationMovie < 0 || durationCredits < 0 || fps <= 0) {
        fprintf(stderr, "Erreur : paramètres invalides.\n");
        return -1.0f; // Retourner une valeur d'erreur
    }

    // Calcul du nombre de pixels par image
    long long pixelsPerFrame = (long long)w * h;

    // Taille d'une image en octets
    long long colorFrameSize = pixelsPerFrame * 3; // 3 octets par pixel pour la couleur
    long long bwFrameSize = pixelsPerFrame;       // 1 octet par pixel pour noir et blanc

    // Nombre total d'images dans chaque section
    long long colorFrames = (long long)durationMovie * fps;
    long long bwFrames = (long long)durationCredits * fps;

    // Taille totale des sections en octets
    long long colorSize = colorFrames * colorFrameSize;
    long long bwSize = bwFrames * bwFrameSize;

    // Taille totale en octets
    long long totalSizeBytes = colorSize + bwSize;

    // Conversion en fonction de l'unité
    if (strcmp(unit, "bt") == 0) { // Octets
        return (float)totalSizeBytes;
    } else if (strcmp(unit, "ko") == 0) { // Kilooctets
        return totalSizeBytes / 1024.0f;
    } else if (strcmp(unit, "mo") == 0) { // Mégaoctets
        return totalSizeBytes / (1024.0f * 1024.0f);
    } else if (strcmp(unit, "go") == 0) { // Gigaoctets
        return totalSizeBytes / (1024.0f * 1024.0f * 1024.0f);
    } else {
        fprintf(stderr, "Erreur : unité inconnue (%s). Utilisez 'bt', 'ko', 'mo' ou 'go'.\n", unit);
        return -1.0f; // Retourner une valeur d'erreur pour unité invalide
    }
}