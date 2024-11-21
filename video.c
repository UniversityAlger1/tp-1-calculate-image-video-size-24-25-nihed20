#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
  // Calculer la taille d'un frame en bits pour chaque section
    float colorFrameSize = w * h * 3 *fps*durationMovie; // Section couleur : 3 octets/pixel
    float bwFrameSize = w * h* fps*durationCredits;    // Section noir et blanc : 1 octet/pixel
    // Taille totale de la video
    float totalSize = colorFrameSize *8 + bwFrameSize*1;

    // Conversion en fonction de l'unité
    if (strcmp(unit, "bt") == 0) {
        return totalSize / 8; // Convertir en octets
    } else if (strcmp(unit, "ko") == 0) {
        return (totalSize /8)/1024; // Convertir en kilooctets
    } else if (strcmp(unit, "mo") == 0) {
        return ((totalSize /8)/1024)/1024; // Convertir en mégaoctets
    } else if (strcmp(unit, "go") == 0) {
        return (((totalSize /8) /1024)/ 1024)/1024; // Convertir en gigaoctes
    }else 
    return totalSize;
   // YOUR CODE HERE - END
   return 0;
}