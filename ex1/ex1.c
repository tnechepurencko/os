#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    // input begins

    printf("enter the number of files:\n");
    int f;
    scanf("%d", &f);

    printf("enter the number of processes:\n");
    int p;
    scanf("%d", &p);

    printf("enter the vector E:\n");
    int E[f];
    for (int i = 0; i < f; i++) {
        scanf("%d", &E[i]);
    }

    printf("enter the vector A:\n");
    int A[f];
    for (int i = 0; i < f; i++) {
        scanf("%d", &A[i]);
    }

    printf("enter the matrix C:\n");
    int C[p][f];
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < f; j++) {
            scanf("%d", &C[i][j]);

        }
    }

    printf("enter the matrix R:\n");
    int R[p][f];
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < f; j++) {
            scanf("%d", &R[i][j]);

        }
    }

    // input ends

    int processes_marked[p];
    for (int i = 0; i < p; i++) {
        processes_marked[i] = 0;
    }

    int deadlock = 0;
    int number_processes_marked = 0;
    int new_marks;
    int ok;
    while (!deadlock && number_processes_marked != p) {
        new_marks = 0;
        for (int i = 0; i < p; i++) {
            if (processes_marked[i] != 1) {
                ok = 1;
                for (int j = 0; j < f; j++) {
                    if (R[i][j] > A[j]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    processes_marked[i] = 1;
                    new_marks++;
                    number_processes_marked++;
                    for (int j = 0; j < f; j++) {
                        A[j] += C[i][j];
                    }
                }
            }
        }

        if (new_marks == 0) {
            deadlock = 1;
        }
    }

    if (deadlock) {
        printf("numbers of processes that are deadlocked: ");
        for (int i = 0; i < p; ++i) {
            if (processes_marked[i] == 0) {
                printf("#%d ", i + 1);
            }
        }
    } else {
        printf("no deadlock is detected\n");
    }

    return 0;
}



