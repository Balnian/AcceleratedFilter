// AcceleratedFilter.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include "AcceleratedFilter.h"
#include <amp.h>
#include <amp_graphics.h>

using namespace concurrency;
using namespace concurrency::graphics;
using std::vector;

unsigned int rouge(unsigned int couleur)restrict(amp){ return 0x00ff0000 & couleur; }
unsigned int vert(unsigned int couleur)restrict(amp){ return  0x0000ff00 & couleur; }
unsigned int bleu(unsigned int couleur)restrict(amp){ return  0x000000ff & couleur; }
unsigned int alpha(unsigned int couleur)restrict(amp){ return 0xff000000 & couleur; }


// Il s'agit d'un exemple de variable exportée
//ACCELERATEDFILTER_API int nAcceleratedFilter = 0;

void pick_accelerator()
{
	// Get all accelerators known to the C++ AMP runtime
	vector<accelerator> accs = accelerator::get_all();

	// Empty ctor returns the one picked by the runtime by default
	accelerator chosen_one;

	// Choose one; one that isn't emulated, for example
	auto result =
		std::find_if(accs.begin(), accs.end(), [](accelerator acc)
	{
		return !acc.is_emulated; //.supports_double_precision
	});
	if (result != accs.end())
		chosen_one = *(result); // else not shown

	// Output its description (tip: explore the other properties)
	//std::wcout << chosen_one.description << std::endl;

	// Set it as default ... can only call this once per process
	accelerator::set_default(chosen_one.device_path);

	// ... or just return it
	//return chosen_one;
}

EXTERN_C
{
	ACCELERATEDFILTER_API void GrayScaleAverage(int * Src, int * Copy, int width, int height, int stride)
	{
		extent<2> image_extent(height, width);
		pick_accelerator();

		/*vector<unsigned int> image_src(Src, Src + sizeof(Src) / sizeof(Src[0]));
		vector<unsigned int> image_cpy(Copy, Copy + sizeof(Copy) / sizeof(Copy[0]));*/

		//texture<uint_4, 2> t_src{ image_extent, Src, image_extent.size() * 4U, 8U };
		//
		//texture<uint_4, 2> t_cpy{ image_extent, Copy, image_extent.size() * 4U, 8U };

		//texture_view<const uint_4, 2> tv_src{ t_src };
		//texture_view<uint_4, 2> tv_cpy{ t_cpy };

		//parallel_for_each(image_extent, [=](index<2> idx)restrict(amp){
		//	uint_4 color = tv_src.get(idx);
		//	//color.r = color.g = color.b = (color.r + color.g + color.b) / 3;
		//	//color.r = ((color.r + color.g + color.b) / 3);
		//	tv_cpy.set(idx, color);
		//});
		//copy(t_cpy, Copy, (unsigned int)sizeof(Copy));

		array_view<const int, 2> texture_src{ image_extent, Src };
		array_view<int, 2> texture_cpy(image_extent, Copy);
		texture_cpy.discard_data();

		parallel_for_each(image_extent, [=](index<2> idx)restrict(amp){
			//if (idx[1])
			int color = texture_src[idx];
			unsigned int gray = ((rouge(color) + vert(color) + bleu(color)) / 3);
			texture_cpy[idx] = alpha(color)| /*( gray << (4*8)) | (gray << (2*8)) |*/ gray;//0xff00ff00 & color;
			//uint_4 color = texture_src[idx];
			//color.r = color.g = color.b = (color.r + color.g + color.b) / 3;
			//color.r = ((color.r + color.g + color.b) / 3);
			//texture_cpy[idx]. = texture_cpy[idx].g = texture_cpy[idx].b = (texture_src[idx].r + texture_src[idx].g + texture_src[idx].b) / 3;
		});

		texture_cpy.synchronize();

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
