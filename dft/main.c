#include "dft.h"

int main(void)
{
    // float signal[N];

    // srand(time(NULL)); // initialize random number generator
    // for (int n = 0; n < N; n++)
    // {
    //     signal[n] = ((2.0 * rand()) / RAND_MAX) - 1.0; // construct the time signal
    //     // printf("n = %d is %f\n", n, signal[n]);
    // }

    float signal[64] = {-1.2246e-16, -0.2013, -0.3944, -0.5713, -0.7248, -0.8486, -0.9378, -0.9885, -0.9987, -0.9681, -1.2246e-16, -0.2013, -0.3944, -0.5713, -0.7248, -0.8486, -0.9378, -0.9885, -0.9987, -0.9681-1.2246e-16, -0.2013, -0.3944, -0.5713, -0.7248, -0.8486, -0.9378, -0.9885, -0.9987, -0.9681-1.2246e-16, -0.2013, -0.3944, -0.5713, -0.7248, -0.8486, -0.9378, -0.9885, -0.9987, -0.9681};
    
    dft(signal, 64);
}
