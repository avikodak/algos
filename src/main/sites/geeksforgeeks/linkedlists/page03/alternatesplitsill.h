/****************************************************************************************************************************************************
 *  File Name   		: alternatesplitsill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page03\alternatesplitsill.h
 *  Created on			: May 1, 2014 :: 7:46:38 PM
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

#ifndef ALTERNATESPLITSILL_H_
#define ALTERNATESPLITSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *alternateSplitSill(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *alternateSills = (sillNode *)malloc(sizeof(sillNode));
	if(ptr->next == null){
		alternateSills[0] = ptr;
		alternateSills[1] = null;
		return alternateSills;
	}
	alternateSills[0] = ptr;
	alternateSills[1] = ptr->next;
	sillNode *traversalNode = ptr->next->next,*oddTraversal = alternateSills[0],*eventTraversal = alternateSills[1];
	oddTraversal->next = null;
	eventTraversal->next = null;
	bool isOdd = true;
	while(traversalNode != null){
		if(isOdd){
			oddTraversal->next = traversalNode;
			oddTraversal = oddTraversal->next;
		}else{
			eventTraversal->next = traversalNode;
			eventTraversal = eventTraversal->next;
		}
		traversalNode = traversalNode->next;
		isOdd = !isOdd;
	}
	return alternateSills;
}

sillNode *alternateSplitSillAuxspace(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *alternateSills = (sillNode *)malloc(sizeof(sillNode));
	if(ptr->next == null){
		alternateSills[0] = ptr;
		alternateSills[1] = null;
		return alternateSills;
	}
	queue<sillNode *> oddBucket,eventBucket;
	sillNode *traversalNode = ptr;
	bool isOdd = true;
	while(traversalNode != null){
		if(isOdd){
			oddBucket.push(traversalNode);
		}else{
			eventBucket.push(traversalNode);
		}
		isOdd = !isOdd;
		traversalNode = traversalNode->next;
	}
	alternateSills[0] = oddBucket.front();
	traversalNode = oddBucket.front();
	oddBucket.pop();
	while(!oddBucket.empty()){
		traversalNode->next = oddBucket.front();
		oddBucket.pop();
		traversalNode = traversalNode->next;
	}
	traversalNode->next = null;
	alternateSills[1] = eventBucket.front();
	traversalNode = eventBucket.front();
	eventBucket.pop();
	while(!eventBucket.empty()){
		traversalNode->next = eventBucket.front();
		eventBucket.pop();
		traversalNode = traversalNode->next;
	}
	traversalNode->next = null;
	return alternateSills;
}

sillNode *alternatesplitSillHashmap(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *alternateSills = (sillNode *)malloc(sizeof(sillNode));
	if(ptr->next == null){
		alternateSills[0] = ptr;
		alternateSills[1] = null;
		return alternateSills;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMap = utils->getHashmapOfSILL(ptr);
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	alternateSills[0] = indexNodeMap.find(0)->second;
	alternateSills[1] = indexNodeMap.find(1)->second;
	sillNode *evenTraversalNode = alternateSills[0],*oddTraversalNode = alternateSills[1];
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		if(itToIndexNodeMap->first&1){
			oddTraversalNode->next = itToIndexNodeMap->second;
			oddTraversalNode = oddTraversalNode->next;
		}else{
			evenTraversalNode->next = itToIndexNodeMap->second;
			evenTraversalNode = evenTraversalNode->next;
		}
	}
	oddTraversalNode->next = null;
	evenTraversalNode->next = null;
	return alternateSills;
}
/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* ALTERNATESPLITSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
