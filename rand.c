#include <math.h> // sqrt(), log(), cos()


static const double PI = 3.14159265358979323846;
const unsigned int RAND_MAX = 32767;
static unsigned int next = 1; // Only accessible from within this file

void srand(unsigned int seed) {
    next = seed;
}

unsigned int rand15(void) {
    // See https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf, page 347
    // Bits 30-0 from next are random, but 15-0 not that much. Only the 15 bits 
    // 30-16 will be returned. 
    // Note: although it seems like the modulus 2^32 is implicitly used, the modulus
    // is actually 2^31. The next variable is implicitly masked by 2^31-1, because
    // the highest bit is not used as output. The highest bit being nonzero doesn't 
    // influence the value of the output. 
    next = 1103515245*next + 12345;
    // a % b = (b-1) & a
    return ((unsigned int)32767) & (next>>16);
}

unsigned int rand16(void) {
    unsigned int x = rand15() << 1;
    x |= (rand15() & 1);
    return x;
}

unsigned int rand32(void) {
    unsigned int x = rand16() << 16;
    x |= rand16();
    return x;
}

unsigned int randrange(unsigned int max) {
    unsigned int end, r;
    end = 0xffffffff / max; 
    end *= max;
    while ((r = rand32()) >= end); // Should take only a few loops
    return r % max; 
}

double rand_uniform(void) {
    return (double)rand32()/(double)0xffffffff;
}

double rand_normal(double mu, double sigma) {
    // Box-Müller method, generates two normally distributed
    // samples, only one is calculated and returned. 
    double xi1 = rand_uniform();
    double xi2 = rand_uniform();
    return sqrt(sigma)*sqrt(-2.0*log(xi1))*cos(2.0*PI*xi2) + mu;
}