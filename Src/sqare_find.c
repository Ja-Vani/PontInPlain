//
// Created by Ja_Vani on 11.12.2024.
//

#include "sqare_find.h"

#include <math.h>

const U = 1;

float sqare_find(float t2, float t3, float t4) {
    return U*(powf(t4, 2.f)-powf(t3, 2.f)-powf(t2, 2.f))/(2.f*(t2+t3-t4));
}
