#include "config/grayScaleImage.h"

// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in byte)
float grayScaleImage(int w, int h) {
   // YOUR CODE HERE - BEGIN
   if (w <= 0 || h <= 0) {
       return 0; // Taille invalide si largeur ou hauteur est négative ou nulle
   }
   float size = (float)(w * h); // Calcul de la taille en bytes
   // YOUR CODE HERE - END
   return size;
}