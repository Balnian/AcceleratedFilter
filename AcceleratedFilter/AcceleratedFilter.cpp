// AcceleratedFilter.cpp�: d�finit les fonctions export�es pour l'application DLL.
//

#include "stdafx.h"
#include "AcceleratedFilter.h"


// Il s'agit d'un exemple de variable export�e
ACCELERATEDFILTER_API int nAcceleratedFilter=0;

// Il s'agit d'un exemple de fonction export�e.
ACCELERATEDFILTER_API int fnAcceleratedFilter(void)
{
	return 42;
}

// Il s'agit du constructeur d'une classe qui a �t� export�e.
// consultez AcceleratedFilter.h pour la d�finition de la classe
AcceleratedFilter::AcceleratedFilter()
{
	return;
}
