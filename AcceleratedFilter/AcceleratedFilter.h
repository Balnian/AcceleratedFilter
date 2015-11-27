// Le bloc ifdef suivant est la fa�on standard de cr�er des macros qui facilitent l'exportation 
// � partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compil�s avec le symbole ACCELERATEDFILTER_EXPORTS
// d�fini sur la ligne de commande. Ce symbole ne doit pas �tre d�fini pour un projet
// qui utilisent cette DLL. De cette mani�re, les autres projets dont les fichiers sources comprennent ce fichier consid�rent les fonctions 
// ACCELERATEDFILTER_API comme �tant import�es � partir d'une DLL, tandis que cette DLL consid�re les symboles
// d�finis avec cette macro comme �tant export�s.
#ifdef ACCELERATEDFILTER_EXPORTS
#define ACCELERATEDFILTER_API __declspec(dllexport)
#else
#define ACCELERATEDFILTER_API __declspec(dllimport)
#endif

#include "Image.h"

// Cette classe est export�e de AcceleratedFilter.dll
class ACCELERATEDFILTER_API AcceleratedFilter {
public:
   

   

	AcceleratedFilter(void);
   static class GrayScale
   {
   public:
      static int Average(Color Couleur);
      static int Average(int Image[], int width, int height)
      {
         Color s;
         s.
      }

   };

      
	// TODO: ajoutez ici vos m�thodes.
};

extern ACCELERATEDFILTER_API int nAcceleratedFilter;



EXTERN_C ACCELERATEDFILTER_API void GrayScaleAverage(int * Src, int * Copy, int Stride, int height);

ACCELERATEDFILTER_API int fnAcceleratedFilter(void);


