/****************************************************************************************************************************************************
 *  File Name   		: deletelinkedlist.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page05\deletelinkedlist.h
 *  Created on			: Apr 17, 2014 :: 1:39:33 AM
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

#ifndef DELETELINKEDLIST_H_
#define DELETELINKEDLIST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void deleteLinkedFrontToRear(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *remainingList = ptr->next;
	free(ptr);
	deleteLinkedFrontToRear(remainingList);
}

void deleteLinkedListRearToFront(sillNode *ptr){
	if(ptr == null){
		return;
	}
	deleteLinkedListRearToFront(ptr->next);
	free(ptr);
}

void deleteLinkedFrontToRearIterative(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *traversalNode = ptr,*nodeToBeDeleted;
	while(traversalNode != null){
		nodeToBeDeleted = traversalNode;
		traversalNode = traversalNode->next;
		free(nodeToBeDeleted);
	}
}

void deleteLinkedListRearToFrontIterative(sillNode *ptr){
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
		free(auxSpace.top());
		auxSpace.pop();
	}
}

void deleteLinkedListHashmap(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	for(itToIndexNodeMap = indexNodeMap.end() - 1;itToIndexNodeMap != indexNodeMap.begin();itToIndexNodeMap--){
		free(itToIndexNodeMap->second);
	}
	free(itToIndexNodeMap->second);
}

#endif /* DELETELINKEDLIST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
