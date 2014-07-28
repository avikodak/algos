/****************************************************************************************************************************************************
 *  File Name   		: detectloopinsill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\detectloopinsill.h
 *  Created on			: Apr 23, 2014 :: 11:40:15 PM
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

#ifndef DETECTLOOPINSILL_H_
#define DETECTLOOPINSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool detectALoopInSill(sillNode *ptr){
	if(ptr == null){
		return false;
	}
	sillNode *slowPtr = ptr,*fastPtr = ptr;
	while(slowPtr != null && fastPtr != null && fastPtr->next != null && fastPtr != slowPtr){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return fastPtr == slowPtr?true:false;
}

bool detectALoopInSill(sillfNode *ptr){
	if(ptr == null){
		return false;
	}
	sillfNode *traversalNode =ptr;
	while(traversalNode != null && !traversalNode->flag){
		traversalNode->flag = true;
		traversalNode = traversalNode->next;
	}
	return traversalNode == null?false:true;
}

bool detectALoopInSillHashMap(sillNode *ptr){
	if(ptr == null){
		return false;
	}
	hash_map<uint32_t,bool>  nodeVisitedFlags;
	sillNode *traversalPtr = ptr;
	while(traversalPtr != null){
		if(traversalPtr->next == null){
			return false;
		}
		if(nodeVisitedFlags.find((uint32_t)traversalPtr) != nodeVisitedFlags.end()){
			return true;
		}
		nodeVisitedFlags.insert(pair<uint32_t,bool>((uint32_t)traversalPtr,true));
	}
	return false;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* DETECTLOOPINSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
