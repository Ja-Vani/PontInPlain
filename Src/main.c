#include <math.h>
#include <stdio.h>
#include <sqare_find.h>
#include <stdlib.h>
#include <time.h>

struct sqare {
    float r, l, t, b;
};

int comp_float(const void *a, const void *b) {
    return *(float *)a > *(float *)b;
}

int main(void) {
    srand(time(NULL));
    struct sqare s1;
    s1.r = (float)rand()/(float)(RAND_MAX/100) - (float)(RAND_MAX/200);
    s1.l = (float)rand()/(float)(RAND_MAX/100) - (float)(RAND_MAX/200);
    s1.t = (float)rand()/(float)(RAND_MAX/100) - (float)(RAND_MAX/200);
    s1.b = s1.t - (s1.r-s1.l);
    for(int i =0; i <100; i++) {
        float x = (float)rand()/(float)RAND_MAX * (s1.r-s1.l) + s1.l;
        float y = (float)rand()/(float)RAND_MAX * (s1.r-s1.l) + s1.b;
        float r[4];
        r[0] = sqrtf(powf(x-s1.l, 2.f) + powf(y-s1.t, 2.f));
        r[1] = sqrtf(powf(x-s1.r, 2.f) + powf(y-s1.t, 2.f));
        r[2] = sqrtf(powf(x-s1.l, 2.f) + powf(y-s1.b, 2.f));
        r[3] = sqrtf(powf(x-s1.r, 2.f) + powf(y-s1.b, 2.f));
        qsort(r, 4, sizeof(r[0]), comp_float);
        float r1 = sqare_find(r[1]-r[0], r[2]-r[0], r[3]-r[0]);
        printf("expected %f result %f\n", r[0], r1);
    }
    return 0;
}
