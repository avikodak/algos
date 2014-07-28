/****************************************************************************************************************************************************
 *  File Name   		: deletenodesgreatervaluerightside.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page02\deletenodesgreatervaluerightside.h
 *  Created on			: May 10, 2014 :: 12:53:16 AM
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

#ifndef DELETENODESGREATERVALUERIGHTSIDE_H_
#define DELETENODESGREATERVALUERIGHTSIDE_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

int deleteNodesGreaterValueRightSide(sillNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	int result = deleteNodesGreaterValueRightSide(ptr->next);
	if(result > ptr->value){
		ptr->value = ptr->next->value;
		sillNode *nodeToBeDeleted = ptr->next;
		ptr->next = ptr->next->next;
		free(nodeToBeDeleted);
		return result;
	}else{
		return ptr->value;
	}
}

void deleteNodesGreaterValueRightSideIterative(sillNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	int maxTillNow = INT_MIN;
	stack<sillNode *> auxSpace;
	sillNode *currentNode = ptr;
	while(ptr != null){
		auxSpace.push(currentNode);
		currentNode = currentNode->next;
	}
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->value < maxTillNow){
			currentNode->value = currentNode->next->value;
			sillNode *nodeToBeDeleted = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(nodeToBeDeleted);
		}else{
			maxTillNow = currentNode->value;
		}
	}
}

void deleteNodesGreaterValueRightSideReversing(sillNode *ptr){
	if(ptr == null){
		return;
	}
	reverseSillDriver(&ptr);
	sillNode *traversalNode = ptr,*nodeToBeDeleted;
	int maxTillNow = INT_MIN;
	while(traversalNode->next != null){
		if(traversalNode->next->value < maxTillNow){
			nodeToBeDeleted = traversalNode->next;
			traversalNode->next = traversalNode->next->next;
			free(nodeToBeDeleted);
		}else{
			maxTillNow = traversalNode->next->value;
			traversalNode = traversalNode->next;
		}
	}
	reverseSillDriver(&ptr);
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool hasGreaterValueRightSide(sillNode *ptr,int key){
	if(ptr == null){
		return false;
	}
	if(key < ptr->value){
		return true;
	}
	return hasGreaterValueRightSide(ptr->next,key);
}

void deleteNodesGreaterValueRightSideON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	if(hasGreaterValueRightSide(ptr->next)){
		ptr->value = ptr->next->value;
		sillNode *nodeToBeDeleted = ptr->next;
		ptr->next = ptr->next->next;
		free(nodeToBeDeleted);
		deleteNodesGreaterValueRightSideON2(ptr);
	}else{
		deleteNodesGreaterValueRightSideON2(ptr->next);
	}
}

#endif /* DELETENODESGREATERVALUERIGHTSIDE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
