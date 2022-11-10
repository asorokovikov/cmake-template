#include "lib.h"
#include "../version.h"

namespace lib {

int version() {
    return PROJECT_VERSION_PATCH;
}

int multiply(int a, int b) {
    return a * b;
}

float multiply(float a, float b) {
    return a * b;
}

double multiply(double a, double b) {
    return a * b;
}

}