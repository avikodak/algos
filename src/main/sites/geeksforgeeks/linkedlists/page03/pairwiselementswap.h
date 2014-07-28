/****************************************************************************************************************************************************
 *  File Name   		: pairwiselementswap.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page03\pairwiselementswap.h
 *  Created on			: May 1, 2014 :: 7:45:41 PM
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

#ifndef PAIRWISELEMENTSWAP_H_
#define PAIRWISELEMENTSWAP_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void pairwiseElementValueSwap(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return;
	}
	int temp;
	temp = ptr->value;
	ptr->value = ptr->next->value;
	ptr->next->value = temp;
	pairwiseElementValueSwap(ptr->next->next);
}
void pairwiseElementSwapIterative(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return;
	}
	int temp;
	while(ptr != null && ptr->next != null){
		temp = ptr->value;
		ptr->value = ptr->next->value;
		ptr->next->value = temp;
		ptr = ptr->next->next;
	}
}

void pairwiseElementSwapMain(sillNode *ptr,sillNode *parent){

}

void pairwiseElementSwap(sillNode **ptr){

}

void pairwiseElementSwapIterative(sillNode **ptr){
	if(*ptr == null || (*ptr)->next == null){
		return;
	}
	sillNode *currentNode = *ptr;
	sillNode *tempForSwap,*traversalNode = currentNode->next->next;
	tempForSwap = currentNode->next;
	currentNode->next = tempForSwap->next;
	tempForSwap->next = currentNode;
	*ptr = tempForSwap;
	sillNode *prevNode = (*ptr)->next;
	while(traversalNode != null && traversalNode->next != null){
		prevNode->next = traversalNode->next;
		tempForSwap = traversalNode->next;
		traversalNode->next = tempForSwap->next;
		tempForSwap->next = traversalNode;
		traversalNode = traversalNode->next->next;
	}
}

void pairwiseElementSwapAuxspace(sillNode **ptr){
	if(*ptr == null || (*ptr)->next == null){
		return;
	}
	stack<sillNode *> auxSpace;
	sillNode *currentNode = *ptr;
	while(currentNode != null && currentNode->next != null){
		auxSpace.push(currentNode->next);
		auxSpace.push(currentNode);
	}
	sillNode *prevNode = currentNode;
	while(!auxSpace.empty()){
		auxSpace.top()->next = prevNode;
		prevNode = auxSpace.top();
		auxSpace.pop();
	}
	*ptr = prevNode;
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* PAIRWISELEMENTSWAP_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
