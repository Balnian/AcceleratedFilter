// AcceleratedFilter.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include "AcceleratedFilter.h"
#include <amp.h>

using namespace concurrency;


// Il s'agit d'un exemple de variable exportée
ACCELERATEDFILTER_API int nAcceleratedFilter = 0;

EXTERN_C
{
   ACCELERATEDFILTER_API void GrayScaleAverage(int * Src, int * Copy, int Stride, int height)
   {
      array_view<const Color, 1> ImgSource(Stride*height, Src);
      array_view<Color, 1> ImgOut(Stride*height, Copy);
      parallel_for_each(ImgOut.extent,
         [=](index<1> idx) restrict(amp)
      {
         ImgOut[idx].R = ImgOut[idx].G = ImgOut[idx].B = ((ImgSource[idx].R + ImgSource[idx].G + ImgSource[idx].B) / 3);
      });
   }
}

// Il s'agit d'un exemple de fonction exportée.
ACCELERATEDFILTER_API int fnAcceleratedFilter(void)
{
	return 42;
}

// Il s'agit du constructeur d'une classe qui a été exportée.
// consultez AcceleratedFilter.h pour la définition de la classe
AcceleratedFilter::AcceleratedFilter()
{
	return;
}
