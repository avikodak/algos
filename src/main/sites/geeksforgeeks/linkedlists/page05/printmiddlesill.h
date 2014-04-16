/****************************************************************************************************************************************************
 *  File Name   		: printmiddlesill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page05\printmiddlesill.h
 *  Created on			: Apr 15, 2014 :: 2:19:10 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <algos/utils/ds/tree/treeds.h>
#include <algos/utils/common/tree/tree.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PRINTMIDDLESILL_H_
#define PRINTMIDDLESILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printMiddleLinkedList(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *slowPtr = ptr,*fastPtr = ptr;
	while(slowPtr != null && fastPtr != null && fastPtr->next != null){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	printf("%d\n",slowPtr->value);
}

//This is same as the first method
//Tested
void printMiddleLinkedListByCounter(sillNode *ptr){
	if(ptr == null){
		return;
	}
	unsigned int counter = 0;
	sillNode *traversalNode = ptr,*followingPtr = ptr;
	while(traversalNode != null){
		if(counter&1){
			followingPtr = followingPtr->next;
		}
		counter++;
		traversalNode = traversalNode->next;
	}
	printf("%d\n",followingPtr->value);
}

//Tested
void printMiddleLinkedListByFindingLengthIterative(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *nodeForTraversal = ptr;
	unsigned int lengthOfSill = 0;
	while(nodeForTraversal != null){
		nodeForTraversal = nodeForTraversal->next;
		lengthOfSill += 1;
	}
	lengthOfSill /= 2;
	nodeForTraversal = ptr;
	while(lengthOfSill--){
		nodeForTraversal = nodeForTraversal->next;
	}
	printf("%d\n",nodeForTraversal->value);
}

//Tested
void printMiddleLinkedListByFindingLength(sillNode *ptr,unsigned int &middleIndex){
	if(ptr == null){
		return;
	}
	static unsigned int lengthOfLinkedList = 0;
	static bool isPrinted = false;
	if(ptr->next == null){
		middleIndex = lengthOfLinkedList/2 - 1;
		return;
	}
	lengthOfLinkedList++;
	printMiddleLinkedListByFindingLength(ptr->next,middleIndex);
	if(middleIndex == 0){
		if(!isPrinted){
			printf("%d\t",ptr->value);
			isPrinted = true;
		}
	}
	if(!isPrinted){
		middleIndex--;
	}
}

//Tested
void printMiddleLinkedListByHashmap(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	sillHashmap *hashmap = utils->getHashmapOfSILL(ptr);
	unsigned int sizeOfMap = (hashmap->indexNodeMap).size();
	hash_map<unsigned int,sillNode *> indexNodeMap = hashmap->indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	itToIndexNodeMap = indexNodeMap.find(sizeOfMap/2);
	printf("%d\n",itToIndexNodeMap->second->value);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printMiddleLinkedListON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	unsigned int frontCounter = 0,backCounter = 0;
	sillNode *temp,*traversalNode = ptr;
	while(traversalNode != null){
		frontCounter = 0;
		temp = ptr;
		while(temp != null && temp != traversalNode){
			frontCounter++;
			temp = temp->next;
		}
		backCounter = 0;
		temp = traversalNode->next;
		while(temp != null){
			backCounter++;
			temp = temp->next;
		}
		if(abs(frontCounter-backCounter) <= 1){
			printf("%d",traversalNode->value);
		}
		traversalNode = traversalNode->next;
	}
}

#endif /* PRINTMIDDLESILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
