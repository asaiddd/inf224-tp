#include "dft.h"

float *dft(float *signal, int len)
{
    float realDFT[N];
    float imDFT[N];
    float powerDFT[N];

    for (int k = 0; k < len; k++)
    {
        realDFT[k] = 0;
        imDFT[k] = 0;

        for (int n = 0; n < len; n++)
        {
            realDFT[k] += signal[n] * cos(n * k * PI2 / len);
            imDFT[k] -= signal[n] * sin(n * k * PI2 / N);
            powerDFT[k] = realDFT[k] * realDFT[k] + imDFT[k] * imDFT[k];
        }
    }

    generateScript(signal, realDFT, imDFT, powerDFT, len);
}

void generateScript(float *signal, float *realDFT, float *imDFT, float *powerDFT, int len)
{
    FILE *f = fopen("dftplots.m", "w");
    fprintf(f, "n = [0:%d];\n", len-1);
    fprintf(f, "x = [ ");
    for (int n=0 ; n<len ; ++n) fprintf(f, "%f ", signal[n]);
    fprintf(f, "];\n");
    fprintf(f, "Xre = [ ");
    for (int k=0 ; k<len ; ++k) fprintf(f, "%f ", realDFT[k]);
    fprintf(f, "];\n");
    fprintf(f, "Xim = [ ");
    for (int k=0 ; k<len ; ++k) fprintf(f, "%f ", imDFT[k]);
    fprintf(f, "];\n");
    fprintf(f, "P = [ ");
    for (int k=0 ; k<len ; ++k) fprintf(f, "%f ", powerDFT[k]);
    fprintf(f, "];\n");
    fprintf(f, "subplot(3,1,1)\nplot(n,x)\n");
    fprintf(f, "xlim([0 %d])\n", len-1);
    fprintf(f, "subplot(3,1,2)\nplot(n,Xre,n,Xim)\n");
    fprintf(f, "xlim([0 %d])\n", len-1);
    fprintf(f, "subplot(3,1,3)\nstem(n,P)\n");
    fprintf(f, "xlim([0 %d])\n", len-1);
    fclose(f);
}
