/****************************************************************************************************************************************************
 *  File Name   		: copysillnextarbitptr.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\copysillnextarbitptr.h
 *  Created on			: Apr 25, 2014 :: 12:21:20 AM
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

#ifndef COPYSILLNEXTARBITPTR_H_
#define COPYSILLNEXTARBITPTR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *copySillWithNextArbitPtrHashmap(sillArbitPtrNode *ptr){
	if(ptr == null){
		return null;
	}
	hash_map<uint32_t,sillArbitPtrNode *> oldNewNodeMap;
	sillArbitPtrNode *headNewList = new sillArbitPtrNode(ptr->value);
	sillArbitPtrNode *traversalNode = ptr->next,*traversalNewList = headNewList;
	oldNewNodeMap.insert(pair<uint32_t,sillArbitPtrNode *>((uint32_t)ptr,headNewList));
	while(traversalNode != null){
		traversalNewList->next = new sillArbitPtrNode(traversalNode->value);
		oldNewNodeMap.insert(pair<uint32_t,sillArbitPtrNode *>((uint32_t)traversalNode,traversalNewList->next));
		traversalNewList = traversalNewList->next;
		traversalNode = traversalNode->next;
	}
	traversalNode = ptr;
	traversalNewList = headNewList;
	while(traversalNode != null){
		traversalNewList->arbitrary = oldNewNodeMap.find((uint32_t)traversalNode->arbitrary)->second;
		traversalNode = traversalNode->next;
		traversalNewList = traversalNewList->next;
	}
	return headNewList;
}

sillNode *copySillWithNextArbitPtrON(sillArbitPtrNode *ptr){
	if(ptr == null){
		return null;
	}
	sillArbitPtrNode *headNewList = new sillArbitPtrNode(ptr->value);
	sillArbitPtrNode *traversalNode = ptr->next,*traversalNodeNewList = headNewList,*temp;
	while(traversalNode != null){
		traversalNodeNewList->next = new sillArbitPtrNode(traversalNode->value);
		traversalNode = traversalNode->next;
	}
	traversalNode = ptr;
	traversalNodeNewList = headNewList;
	while(traversalNode != null){
		temp = traversalNode->next;
		traversalNode->next = traversalNodeNewList;
		traversalNodeNewList->arbitrary = traversalNode;
		traversalNodeNewList = traversalNodeNewList->next;
		traversalNode = temp;
	}
	traversalNode = ptr;
	traversalNodeNewList = headNewList;
	sillArbitPtrNode *prevNode = null;
	while(traversalNodeNewList != null){
		traversalNodeNewList->arbitrary = traversalNode->arbitrary->next;
		traversalNodeNewList = traversalNodeNewList->next;
		traversalNode->next = traversalNodeNewList->arbitrary;
		traversalNode = traversalNode->next;
	}
	//check
	return headNewList;
}

sillArbitPtrNode *copySillWithNextArbitONInsertMiddle(sillArbitPtrNode *ptr){
	if(ptr == null){
		return null;
	}
	sillArbitPtrNode *temp,*traversalNode = ptr;
	while(traversalNode != null){
		temp = traversalNode->next;
		traversalNode->next = new sillArbitPtrNode(traversalNode->value);
		traversalNode->next->next = temp;
		traversalNode = temp;
	}

	traversalNode = ptr;
	while(traversalNode != null){
		traversalNode->next->arbitrary = traversalNode->arbitrary->next;
		traversalNode = traversalNode->next->next;
	}
	traversalNode = ptr;
	sillArbitPtrNode *headNode = traversalNode->next,*traversalNodeNewList = headNode;
	traversalNode->next = traversalNode->next->next;
	while(traversalNode != null){
		temp = headNode->next;
		traversalNodeNewList->next = traversalNode->next->next;
		traversalNode->next = temp;
		traversalNode = traversalNode->next;
	}
	return headNode;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *copySillWithNextArbitPtrON2(sillArbitPtrNode *ptr){
	if(ptr == null){
		return null;
	}
	sillArbitPtrNode *headNewList = new sillArbitPtrNode(ptr->value);
	sillArbitPtrNode *traversalNode = ptr->next,*temp;
	sillArbitPtrNode *newTraversalNode = headNewList;
	while(traversalNode != null){
		newTraversalNode->next = new sillArbitPtrNode(traversalNode->value);
		traversalNode = traversalNode->next;
		newTraversalNode = newTraversalNode->next;
	}
	unsigned int counter;
	traversalNode = ptr;
	newTraversalNode = headNewList;
	while(traversalNode != null){
		temp = ptr;
		if(traversalNode->arbitrary != null){
			counter = 1;
			while(traversalNode->arbitrary != temp){
				counter += 1;
			}
			temp = headNewList;
			while(--counter){
				temp = temp->next;
			}
			newTraversalNode->arbitrary = temp;
		}else{
			newTraversalNode->arbitrary = null;
		}
	}
	return newTraversalNode;
}


#endif /* COPYSILLNEXTARBITPTR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

