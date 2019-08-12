#include <stdio.h>
#include <stdlib.h>
//#include "mymalloc.h"
#include "mymalloc.c"
#include <time.h>

//void *mymalloc(size_t size);
//void myfree(void *ptr);
int ran(int min, int max);

int main(int argc, char **argv){

	srand( time(NULL));
	
	clock_t t = clock();
	
	int z = 0;
	while(z < 100){	
		//printf("RUN %d\n------------------------------------------------------------------",z);
		//printf("\n\n-----------------------TEST A----------------------\n\n");
		int i = 0;
		while(i < 150){
			char *ptr = malloc(1);
			free(ptr);
			i++;
		}

		//TEST 2:
		//printf("\n\n-----------------------TEST B----------------------\n\n");
		i = 0;
		int j;
		char *ptrs[150];
		
		while(i < 150){
			ptrs[i] = malloc(1);
			if(i == 49){
				for(j = 0; j < 50; j++){
					//printf("freeing ptrs[%d]\n",j);
					free(ptrs[j]);
				}
				break;
	
			}
			if(i == 99){
				for(j = 50; j < 100; j++){
					free(ptrs[j]);
				}
			}
			if(i == 149){
			//	printf("i == %d\n", i);
				for(j = 100; j < 150; j++){
					free(ptrs[j]);
				}
			}
			i++;
		
			free(ptrs[i]);
	
		}
		//printf("\n\n-----------------------TEST C----------------------\n\n");
		int numberOfMallocs = 0;
		//struct node *ptr = NULL;
			
		char *ptrs2[50];
		i = 0;
		while(numberOfMallocs < 50){
			int num = (rand() % 2 ) + 1;
			//printf("%d\n",num);
			if(num == 1){
			//printf("allocating\n",num);
				ptrs2[i] = malloc(1);
				numberOfMallocs++;
				i++;
			} else {
			//printf("freeing\n",num);
				if(ptrs2[i] != NULL){
					free(ptrs2[i]);
				}
				i++;
			}
		}
		for(i = 0; i < 50; i++){
			if(ptrs2[i] != NULL){
				free(ptrs2[i]);
			}
		}
		//printf("\n\n-----------------------TEST D----------------------\n\n");
	
		numberOfMallocs = 0;
	
	//char *ptrsD[50];
		i = 0;
	
		while(numberOfMallocs < 50){
			int num = (rand() % 2 ) + 1;
			int num2 = (rand() % 64 ) + 1;
			if(num == 1){
				ptrs2[i] = malloc(num2);
				numberOfMallocs++;
			} else {
				if(ptrs2[i] != NULL){
					free(ptrs2[i]);
				}//continue;
			}
			i++;
		}
		//printf("Freeing...\n");
		for(i = 0; i < 50; i++){
			if(ptrs2[i] != NULL){
				free(ptrs2[i]);
			}
		}
	
		


		//printf("\n\n-----------------------TEST E----------------------\n\n");
		
		char *pt = (char *) malloc(sizeof(int) * 10);
		/*free(pt);
		pt = (char *) malloc(sizeof(int) * 10);
		free(pt);
		*/
		i = 0;
		while(i < 1000){
			free(pt);
			i++;
		}

	//	printf("\n\n-----------------------TEST F----------------------\n\n");
		
		char *ptr = (char *) malloc(5000);
		free(ptr);
		ptr = (char *) malloc(5000);
		free(ptr);
	        //i++;
		


		//printf("starting new run...\n");	
		z++;
	
		//t = clock()-t;
		//double time_taken = ((double)t)/CLOCKS_PER_SEC;
		// printf("%f seconds to execute \n", time_taken);	
	}
		t = clock()-t;
		double time_taken = ((double)t)/CLOCKS_PER_SEC;
		printf("%f seconds to execute \n", time_taken);	

	return 0;
}


