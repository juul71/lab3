/* file: superprimes.c */
/* author: Jula Plaatje (email: j.l.plaatje@student.rug.nl) */
/* date: Wed October 2 2024 */
/* version 1.0 */
/* description: this program calculates if a number is a superprime */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Method to check if a number is a prime number
*/
int isPrime(int num) {
    long int i;

    if ((num == 2) || (num == 3) || (num == 5))
        return 1;

    if (!(num % 2))
        return 0;
    if (!(num % 3))
        return 0;
    if (!(num % 5))
        return 0;

    for (i = 7;i * i <= num;i = i + 2)
        if (!(num % i))
            return 0;
    return 1;

}

int main(int argc, char* argv[]) {
    int a, b;
    int isSuperPrime = 1;
    int superPrimeCount = 0;

    scanf("%d%d", &a, &b);

    //for (int i = b; i >= a; i--) {
    for (int i = a; i < b; i++) {
        int temp = i;

        int total = 0;
        if (i > 1) {
            while (1) {
                while (temp > 9) {
                    int remainder = temp % 10;
                    total = total + remainder;
                    temp = temp / 10;
                }
                temp = total + temp;
                total = 0;

                // break immediately if the number if not a prime
                if (!isPrime(temp)) {
                    isSuperPrime = 0;
                    break;
                }
                if (temp < 10) {
                    break;
                }
            }
        } else {
            isSuperPrime = 0;
        }
        // check for superprime
        if (isSuperPrime == 1 && isPrime(i)) {
            superPrimeCount++;
        }
        isSuperPrime = 1;
    }

    printf("%d\n", superPrimeCount);

    return 0;
}
