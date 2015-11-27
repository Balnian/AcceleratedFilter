// AcceleratedFilter.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include "AcceleratedFilter.h"


// Il s'agit d'un exemple de variable exportée
ACCELERATEDFILTER_API int nAcceleratedFilter=0;

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
