/****************************************************************************************************************************************************
 *  File Name   		: printreverse.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\printreverse.h
 *  Created on			: Apr 28, 2014 :: 6:29:07 PM
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

#ifndef PRINTREVERSE_H_
#define PRINTREVERSE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printReverseSill(sillNode *ptr){
	if(ptr == null){
		return;
	}
	printReverseSill(ptr->next);
	printf("%d\t",ptr->value);
}

void printReverseSillAuxspace(sillNode *ptr){
	if(ptr == null){
		return;
	}
	stack<sillNode *> auxSpace;
	sillNode *traversalNode = ptr;
	while(traversalNode != null){
		auxSpace.push(traversalNode);
		traversalNode = traversalNode->next;
	}
	while(!auxSpace.empty()){
		printf("%d\t",auxSpace.top()->value);
		auxSpace.pop();
	}
}

void printReverseSillByReversing(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	sillNode *revHead = utils->reverseSillNewList(ptr);
	utils->printSILL(revHead);
}

void printReverseSillHashmap(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMap = utils->getHashmapOfSILL(ptr)->indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	for(itToIndexNodeMap = indexNodeMap.end();itToIndexNodeMap != indexNodeMap.begin();itToIndexNodeMap--){
		printf("%d\t",itToIndexNodeMap->second->value);
	}
	printf("%d\t",itToIndexNodeMap->second->value);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *getNodeAtIndex(sillNode *ptr,unsigned int index){
	if(ptr == null){
		return null;
	}
	if(index == 0){
		return ptr;
	}
	return getNodeAtIndex(ptr->next,index-1);
}

void printReverseSillON2(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillutils *utils = new sillutils();
	unsigned int lengthOfSill = utils->lengthOfSILL(ptr);
	for(unsigned int counter = lengthOfSill-1;counter >= 0;counter--){
		printf("%d\t",getNodeAtIndex(ptr,counter)->value);
	}
}

#endif /* PRINTREVERSE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
