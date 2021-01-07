/*  Created by  : A.Sait Tekkurt
    Date        : 07/01/2021 dd/mm/yyyy
    Description : This program is a realization of 
        DFT algorithm for INF224 class in Galatasaray University.

    DFT algorithm takes an input array that represents a signal, than calculate its' 
    DFT coefficient and DFT elements. We will use simple O(N^2) algorithm.
*/

#ifndef __DFT_H__
#define __DFT_H__


#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <time.h>

#define N 1024
#define PI2 6.2832

float *dft(float *arr, int len);
void generateScript(float *signal, float *realDFT, float *imDFT, float *powerDFT, int len);

#endif /* __DFT_H__ */
