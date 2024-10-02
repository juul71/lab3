/* file: superprimes.c */
/* author: Jula Plaatje (email: j.l.plaatje@student.rug.nl) */
/* date: Wed October 2 2024 */
/* version 1.0 */
/* description: this program calculates the last N digits */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    int a, e, n;

    // get input numbers
    scanf("%d %d %d", &a, &e, &n);

    int mod = 1;
    for (int i = 0; i < n; i++) {
        mod *= 10;
    }

    int res = 1;
    for (int j = 0; j < e; j++) {
        res = (res * a) % mod;
    }

    printf("%0*d\n", n, res);

}
