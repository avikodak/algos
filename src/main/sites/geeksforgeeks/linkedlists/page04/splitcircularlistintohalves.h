/****************************************************************************************************************************************************
 *  File Name   		: splitcircularlistintohalves.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\splitcircularlistintohalves.h
 *  Created on			: May 1, 2014 :: 9:43:19 AM
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

#ifndef SPLITCIRCULARLISTINTOHALVES_H_
#define SPLITCIRCULARLISTINTOHALVES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *splitSillIntoTwo(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *slowPtr = ptr,*fastPtr = ptr,*head = ptr;
	while(slowPtr != head && fastPtr != head && fastPtr->next != head){

	}
	sillNode *twoLists = (sillNode *)malloc(2*sizeof(sillNode));
	twoLists[0] = head;
	twoLists[1] = slowPtr->next;
	slowPtr->next = null;
	fastPtr->next = head;
	return twoLists;
}

unsigned int lengthOfCircularSill(sillNode *ptr){
	if(ptr == null){
		return 0;
	}
	sillNode *traversalNode = ptr,*head = ptr;
	unsigned int length = 0;
	while(traversalNode->next != head){
		length++;
		traversalNode = traversalNode->next;
	}
	return length;
}

sillNode *splitSillIntoTwoLength(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	unsigned int length = lengthOfCircularSill(ptr);
	sillNode *traversalNode = ptr,*head = ptr;
	sillNode *requiredList = (sillNode *)malloc(2*sizeof(sillNode));
	length /= 2;
	while(length--){
		traversalNode = traversalNode->next;
	}
	requiredList[0] = head;
	requiredList[1] = traversalNode->next;
	traversalNode->next = null;
	traversalNode = requiredList[1];
	while(traversalNode->next != head){
		traversalNode = traversalNode->next;
	}
	traversalNode->next = null;
	return requiredList;
}

sillNode *splitSillIntoTwoHashmap(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *traversalNode = ptr,*head = ptr;
	hash_map<unsigned int,sillNode *> indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	indexNodeMap.insert(pair<unsigned int,sillNode *>(1,ptr));
	unsigned int indexCounter = 1;
	while(traversalNode != head){
		indexNodeMap.insert(pair<unsigned int,sillNode *>(++indexCounter,traversalNode));
		traversalNode = traversalNode->next;
	}
	sillNode *requiredList = (sillNode *)malloc(2*sizeof(sillNode));
	itToIndexNodeMap = indexNodeMap.find(indexNodeMap.size()/2);
	requiredList[0] = ptr;
	requiredList[1] = itToIndexNodeMap->second->next;
	itToIndexNodeMap->second->next = null;
	itToIndexNodeMap = indexNodeMap.find(indexNodeMap.size()-1);
	itToIndexNodeMap->second->next = null;
	return requiredList;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* SPLITCIRCULARLISTINTOHALVES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

