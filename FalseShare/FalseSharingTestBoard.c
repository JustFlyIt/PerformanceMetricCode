//============================================================================
// Name        : FalseSharingTestBoard.C
// Author      : DRS
// Version     :
// Copyright   :
// Description :
//============================================================================


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define DIM 100
#define P 1

int result[P];

struct threadArgs {
	int *intMatrix;
	int p;
};

typedef struct threadArgs ThreadArgs;

int intMatrix[DIM][DIM];

void scalable() {

}

void*  matrixThread(void * args) {
	ThreadArgs *currentThreadArgs = (ThreadArgs *)args;

	int p = currentThreadArgs->p;

	result[p] = 0;
	int chunkSize = DIM/P + 1;
	int start = p * chunkSize;
	int end = min(start+chunkSize, DIM);
	for (int i=start; i<end; ++i) {
		for(int j=0; j<DIM; ++j) {
			if(intMatrix[i*DIM + j]%2 != 0)
				++result[p];
		}
	}
}

void nonScalable() {
	pthread_t threads[P];

	for (int p=0; p<P; p++) {
		threads[p] = 0;
	}

	// Each of P parallel workers processes 1/P-th of the data;
	// the p-th worker records its partial count in result[p]
	for (int p=0; p < P; p++) {

		ThreadArgs *currentThreadArgs = malloc(sizeof(ThreadArgs));

		pthread_create(&threads[p], NULL, matrixThread, (void *) currentThreadArgs);

	}

	for (int p=0; p < P; ++p) {
		pthread_join(threads[p], NULL);
	}

	int odds = 0;
	for (int p=0; p < P; ++p) {
		odds += result[p];
	}
}

void populateMatrix() {

}

int main(int argc, const char * argv[]) {
    printf("False Sharing Test Started...\n\n");

    populateMatrix();

    nonScalable();

    scalable();

    printf("False Sharing Test Ended.\n\n");

    return 0;
}
