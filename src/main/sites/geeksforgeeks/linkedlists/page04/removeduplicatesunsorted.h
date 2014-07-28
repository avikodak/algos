/****************************************************************************************************************************************************
 *  File Name   		: removeduplicatesunsorted.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\removeduplicatesunsorted.h
 *  Created on			: Apr 29, 2014 :: 10:25:09 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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

#ifndef REMOVEDUPLICATESUNSORTED_H_
#define REMOVEDUPLICATESUNSORTED_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void removeDuplicatesUnsortedON(sillNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	sillNode *traversalNode = ptr,*nodeToBeDeleted;
	while(traversalNode != null){
		if((itToFrequencyMap = frequencyMap.find(traversalNode->value)) != frequencyMap.end()){
			frequencyMap[traversalNode->value] += 1;
		}else{
			frequencyMap[traversalNode->value] = 1;
		}
	}
	traversalNode = ptr;
	while(traversalNode != null){
		if((itToFrequencyMap = frequencyMap.find(traversalNode->value)) != frequencyMap.end()){
			if(itToFrequencyMap->second > 1){
				nodeToBeDeleted = traversalNode->next;
				traversalNode->value = traversalNode->next->value;
				traversalNode->next = traversalNode->next->next;
				free(nodeToBeDeleted);
				frequencyMap[traversalNode->value] -= 1;
			}
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void combineStep(sillNode *startFirstCrawler,sillNode *endFirstCrawler,sillNode *startSecondCrawler,sillNode *endSecondCrawler){
	if(startCrawler == null){
		return;
	}
}


void removeDuplicatesUnsortedMergeSortDriver(sillNode *ptr){

}
/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void removeDuplicatesUnsortedON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *outerCrawler = ptr,*innerCrawler,*nodeToBeDeleted;
	while(outerCrawler != null){
		innerCrawler = outerCrawler->next;
		while(innerCrawler != null && innerCrawler->value != outerCrawler->value){
			innerCrawler = innerCrawler->next;
		}
		if(innerCrawler != null){
			nodeToBeDeleted = outerCrawler->next;
			outerCrawler->value = outerCrawler->next->value;
			outerCrawler->next = outerCrawler->next->next;
			free(nodeToBeDeleted);
		}else{
			outerCrawler = outerCrawler->next;
		}
	}
}

void removeDuplicatesUnsortedBubbleSortON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *outerCrawler = ptr,*innerCrawler;
	int temp;
	while(outerCrawler->next != null){
		innerCrawler = outerCrawler->next;
		while(innerCrawler != null && innerCrawler->next != null){
			if(innerCrawler->value > innerCrawler->next->value){
				temp = innerCrawler->value;
				innerCrawler->value = innerCrawler->next->value;
				innerCrawler->next->value = temp;
			}
			innerCrawler = innerCrawler->next;
		}
		outerCrawler = outerCrawler->next;
	}
	removeDuplicatesSortedSill(ptr);
}

void removeDuplicatesUnsortedSelectionSortON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *outerCrawler,*innerCrawler,*ptrToMinValue;
	int temp;
	while(outerCrawler != null){
		ptrToMinValue = outerCrawler;
		innerCrawler = outerCrawler->next;
		while(innerCrawler != null){
			if(ptrToMinValue->value > innerCrawler->value){
				ptrToMinValue = innerCrawler;
			}
			innerCrawler = innerCrawler->next;
		}
		if(outerCrawler != ptrToMinValue){
			temp = outerCrawler->value;
			outerCrawler->value = innerCrawler->value;
			innerCrawler->value = temp;
		}
	}
	removeDuplicatesSortedSill(ptr);
}

sillNode *getTailOfSill(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->next == null){
		return ptr;
	}
	return getTailOfSill(ptr->next);
}

void quickSortDivideStep(sillNode *sillStartPtr,sillNode *sillEndPtr){
	if(sillStartPtr == sillEndPtr){
		return;
	}
	int keyValue = sillEndPtr->value;
	sillNode *traversalnode = sillStartPtr;

}

void removeDuplicatesUnsortedQuickSortON2(sillNode *ptr){

}

#endif /* REMOVEDUPLICATESUNSORTED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
