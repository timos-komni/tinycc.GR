#include <tcclib.h>

ακεραιος fib(n)
{
    αν (n <= 2)
        επεστρεψε 1;
    αλλιως
        επεστρεψε fib(n-1) + fib(n-2);
}

ακεραιος main(ακεραιος argc, χαρακτηρας **argv)
{
    ακεραιος n;
    αν (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        επεστρεψε 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n, 2));
    επεστρεψε 0;
}