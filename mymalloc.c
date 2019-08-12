#ifndef __MYMALLOC_H__
#define __MYMALLOC_H__

#include <stdio.h>
#include <stdlib.h>
#include "blockfunctions.h"
#include "structfunctions.h"
#include "mymalloc.h"


#define malloc(x) mymalloc(x, __FILE__, __LINE__)
#define free(x) myfree(x, __FILE__, __LINE__)

typedef int bool;
#define true 1
#define false 0

// Structures ------------------
struct node{
	short index;
	short spaceAssigned;
	short isFree; //1 == true
	struct node *next;
};

// Function signatures -------------------

//void *mymalloc(size_t size);
//void myfree(void *ptr);
//void printInfo(char block[], int blockSize, int numberOfTimesCalled);

// Global Variables -------------------
static char block[4096];

// Main code -------------------
void *mymalloc(size_t size, char *filename, int line){
	int blockSize = 4096;
	static numberOfStructs = 0;
	static int numberOfTimesCalled = 0;
	
	struct node *head = NULL;	
	head = (struct node *) block;

	if(size > blockSize){
		printf("ERROR: Size requested is bigger than blocksize.\nFilename: %s, Line: %d\n\n", filename, line);
		return NULL;
	}

	if(numberOfTimesCalled == 0){		
		fillArray(block);
		head->index = 0;
		head->spaceAssigned = (short) size;
		head->isFree = false;
		head->next = NULL;
		numberOfTimesCalled++;
		numberOfStructs++;
		return (void *)head;
	}	
	
	struct node *p = (struct node *) block;
	int sum = 0;
	while(p != NULL){
		if(p->isFree == false){
			sum += p->spaceAssigned;
		}
			p = p->next;	
	}
		
	blockSize = 4096 - sum;

	if(size > blockSize){
		return NULL;
	}
	
	struct node *prev = head;
	struct node *ptr = head;
	while(ptr->next != NULL){
		
		if(ptr->isFree == true){
			if(ptr->spaceAssigned >= size){
				blockSize = (blockSize + ptr->spaceAssigned)-size;
				ptr->spaceAssigned = size;
				ptr->isFree = false;
				numberOfTimesCalled += 1;
				return (void *) ptr;
			}
		}

		prev->next = ptr++;
	}

	if(ptr->isFree == true){
		if(ptr->spaceAssigned >= size){
			blockSize = (blockSize + ptr->spaceAssigned)-size;
			ptr->spaceAssigned = size;
			ptr->isFree = false;
			numberOfTimesCalled += 1;
			return (void *) ptr;
		}
	}

	struct node *newNode = (struct node*) &block[sizeof(struct node)] + numberOfStructs;
	numberOfStructs++;
	newNode->index = prev->spaceAssigned;
	newNode->spaceAssigned = (short) size;
	newNode->next = NULL;
	if(head->next = NULL){
		head->next = newNode;
	}
	numberOfTimesCalled += 1;
	blockSize = blockSize - size;
	return (void *) newNode;

	return NULL;
}



void myfree(void *ptr, char *filename, int line){
	//printBlock(block);
	struct node *temp = (struct node*) ptr;

	//get blockSize:
	struct node *p = (struct node *) block;
	int sum = 0;
	while(p != NULL){
		if(p->isFree = false){
			sum += p->spaceAssigned;
		}
		p = p->next;
	}
		
	int blockSize = 4096 - sum;
	
	if(ptr == NULL){
		return;
	}
		
	if(temp->isFree == true){
		printf("ERROR: This ptr is already free.\nFilename: %s, Line: %d\n\n", filename, line);
	}

	temp->isFree = true;

}
#endif

