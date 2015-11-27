// Le bloc ifdef suivant est la façon standard de créer des macros qui facilitent l'exportation 
// à partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compilés avec le symbole ACCELERATEDFILTER_EXPORTS
// défini sur la ligne de commande. Ce symbole ne doit pas être défini pour un projet
// qui utilisent cette DLL. De cette manière, les autres projets dont les fichiers sources comprennent ce fichier considèrent les fonctions 
// ACCELERATEDFILTER_API comme étant importées à partir d'une DLL, tandis que cette DLL considère les symboles
// définis avec cette macro comme étant exportés.
#ifdef ACCELERATEDFILTER_EXPORTS
#define ACCELERATEDFILTER_API __declspec(dllexport)
#else
#define ACCELERATEDFILTER_API __declspec(dllimport)
#endif

#include "Image.h"

// Cette classe est exportée de AcceleratedFilter.dll
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

      
	// TODO: ajoutez ici vos méthodes.
};

extern ACCELERATEDFILTER_API int nAcceleratedFilter;



EXTERN_C ACCELERATEDFILTER_API void GrayScaleAverage(int * Src, int * Copy, int Stride, int height);

ACCELERATEDFILTER_API int fnAcceleratedFilter(void);


