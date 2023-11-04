#include <stdlib.h>
#include <stdio.h>

#define N 20

ακεραιος nb_num;
ακεραιος tab[N];
ακεραιος stack_ptr;
ακεραιος stack_op[N];
ακεραιος stack_res[60];
ακεραιος result;

ακεραιος find(ακεραιος n, ακεραιος i1, ακεραιος a, ακεραιος b, ακεραιος op)
{
    ακεραιος i, j;
    ακεραιος c;

    αν (stack_ptr >= 0) {
        stack_res[3*stack_ptr] = a;
        stack_op[stack_ptr] = op;
        stack_res[3*stack_ptr+1] = b;
        stack_res[3*stack_ptr+2] = n;
        αν (n == result)
            επεστρεψε 1;
        tab[i1] = n;
    }

    για(i=0;i<nb_num;i++) {
        για(j=i+1;j<nb_num;j++) {
            a = tab[i];
            b = tab[j];
            αν (a != 0 && b != 0) {

                tab[j] = 0;
                stack_ptr++;

                αν (find(a + b, i, a, b, '+'))
                    επεστρεψε 1;
                αν (find(a - b, i, a, b, '-'))
                    επεστρεψε 1;
                αν (find(b - a, i, b, a, '-'))
                    επεστρεψε 1;
                αν (find(a * b, i, a, b, '*'))
                    επεστρεψε 1;
                αν (b != 0) {
                    c = a / b;
                    αν (find(c, i, a, b, '/'))
                        επεστρεψε 1;
                }

                αν (a != 0) {
                    c = b / a;
                    αν (find(c, i, b, a, '/'))
                        επεστρεψε 1;
                }

                stack_ptr--;
                tab[i] = a;
                tab[j] = b;
            }
        }
    }

    επεστρεψε 0;
}

ακεραιος main(ακεραιος argc, χαρακτηρας **argv)
{
    ακεραιος i, res, p;

    αν (argc < 3) {
        printf("usage: %s: result numbers...\n"
               "Try to find result from numbers with the 4 basic operations.\n", argv[0]);
        exit(1);
    }

    p = 1;
    result = atoi(argv[p]);
    printf("result=%d\n", result);
    nb_num = 0;
    για(i=p+1;i<argc;i++) {
        tab[nb_num++] = atoi(argv[i]);
    }

    stack_ptr = -1;
    res = find(0, 0, 0, 0, ' ');
    αν (res) {
        για(i=0;i<=stack_ptr;i++) {
            printf("%d %c %d = %d\n",
                   stack_res[3*i], stack_op[i],
                   stack_res[3*i+1], stack_res[3*i+2]);
        }
        επεστρεψε 0;
    } αλλιως {
        printf("Impossible\n");
        επεστρεψε 1;
    }
}
