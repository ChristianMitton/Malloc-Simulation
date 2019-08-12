#ifndef __BLOCKFUNCTIONS__H__
#define __BLOCKFUNCTIONS__H__

typedef int bool;
#define true 1
#define false 0

#include <stdio.h>
#include <stdlib.h>

void fillArray(char block[]);
void printBlock(char block[]);

void fillArray(char block[]){
	int i = 0;
	for(i = 0; i < 4096; i++){
		block[i] = '~';
	}
}

void printBlock(char block[]){
	int i,count = 0;
	for(i = 0; i < 4096; i++){
		printf("%c",block[i]);
		
		if(count == (44)){
			printf("\n");
			count = 0;
			continue;
		}
		printf(" ");
		count++;
	}
	printf("\n");

}

#endif
