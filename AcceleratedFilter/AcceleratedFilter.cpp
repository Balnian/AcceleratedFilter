// AcceleratedFilter.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include "AcceleratedFilter.h"
#include <amp.h>
#include <amp_graphics.h>

using namespace concurrency;
using namespace concurrency::graphics;


// Il s'agit d'un exemple de variable exportée
//ACCELERATEDFILTER_API int nAcceleratedFilter = 0;

EXTERN_C
{
	ACCELERATEDFILTER_API void GrayScaleAverage(int * Src, int * Copy, int width, int height)
   {
		extent<2> image_extent(height, width);

		/*vector<unsigned int> image_src(Src, Src + sizeof(Src) / sizeof(Src[0]));
		vector<unsigned int> image_cpy(Copy, Copy + sizeof(Copy) / sizeof(Copy[0]));*/

		texture<uint_4, 2> t_src{ image_extent, Src, image_extent.size() * 4U, 8U };
		texture<uint_4, 2> t_cpy{ image_extent, Copy, image_extent.size() * 4U, 8U };

		texture_view<const uint_4, 2> tv_src{ t_src };
		texture_view<uint_4, 2> tv_cpy{ t_cpy };

		parallel_for_each(image_extent, [=](index<2> idx)restrict(amp){
			uint_4 color = tv_src.get(idx);
			//color.r = color.g = color.b = (color.r + color.g + color.b) / 3;
			//color.r = ((color.r + color.g + color.b) / 3);
			tv_cpy.set(idx, color);
		});

		//array_view<const uint_4, 2> texture_src{ image_extent, Src };
	 //  array_view<uint_4, 2> texture_cpy(image_extent, Copy);
	 //  texture_cpy.discard_data();

	 //  parallel_for_each(image_extent, [=](index<2> idx)restrict(amp){
		//   //uint_4 color = texture_src[idx];
		//   //color.r = color.g = color.b = (color.r + color.g + color.b) / 3;
		//   //color.r = ((color.r + color.g + color.b) / 3);
		//   texture_cpy[idx].r = texture_cpy[idx].g = texture_cpy[idx].b = (texture_src[idx].r + texture_src[idx].g + texture_src[idx].b) / 3;
	 //  });

	 //  texture_cpy.synchronize();

	   /*texture<uint_4, 2> texture_src(image_extent, Src, image_extent.size() * 4U, 8U);
	   texture<uint_4, 2> texture_cpy(image_extent, Copy, image_extent.size() * 4U, 8U);
	   texture_src.copy_to(texture_cpy);*/
      /*array_view<const Color, 1> ImgSource(Stride*height, Src);
      array_view<Color, 1> ImgOut(Stride*height, Copy);
      parallel_for_each(ImgOut.extent,
         [=](index<1> idx) restrict(amp)
      {
         ImgOut[idx].R = ImgOut[idx].G = ImgOut[idx].B = ((ImgSource[idx].R + ImgSource[idx].G + ImgSource[idx].B) / 3);
      });*/
   }
}

//// Il s'agit d'un exemple de fonction exportée.
//ACCELERATEDFILTER_API int fnAcceleratedFilter(void)
//{
//	return 42;
//}
//
//// Il s'agit du constructeur d'une classe qui a été exportée.
//// consultez AcceleratedFilter.h pour la définition de la classe
//AcceleratedFilter::AcceleratedFilter()
//{
//	return;
//}
