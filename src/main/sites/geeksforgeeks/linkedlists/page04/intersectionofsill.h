/****************************************************************************************************************************************************
 *  File Name   		: intersectionofsill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\intersectionofsill.h
 *  Created on			: Apr 28, 2014 :: 7:03:39 PM
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

#ifndef INTERSECTIONOFSILL_H_
#define INTERSECTIONOFSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillfNode *getIntersectionOfSill(sillfNode *firstSill,sillfNode *secondSill){
	if(firstSill == null || secondSill == null){
		return null;
	}
	sillfNode *traversalNode = firstSill;
	while(traversalNode != null){
		traversalNode->flag = true;
		traversalNode = traversalNode->next;
	}
	traversalNode = secondSill;
	while(traversalNode != null){
		if(traversalNode->flag){
			return traversalNode;
		}
		traversalNode = traversalNode->next;
	}
	return null;
}

sillNode *getIntersectionOfSillHashMap(sillNode *firstSill,sillNode *secondSill){
	if(firstSill == null || secondSill == null){
		return null;
	}
	hash_map<uint32_t,bool> nodeVisitMap;
	hash_map<uint32_t,bool>::iterator itToNodeVisitMap;
	sillNode *traversalNode = firstSill;
	while(traversalNode != null){
		nodeVisitMap.insert(pair<uint32_t,bool>((uint32_t)traversalNode,true));
		traversalNode = traversalNode->next;
	}
	traversalNode = secondSill;
	while(traversalNode != null){
		if((itToNodeVisitMap = nodeVisitMap.find(traversalNode)) != nodeVisitMap.end()){
			return traversalNode;
		}
		traversalNode = traversalNode->next;
	}
	return null;
}

sillNode *getIntersecionOfSillByLength(sillNode *firstSill,sillNode *secondSill){
	if(firstSill == null || secondSill == null){
		return null;
	}
	sillutils *utils = new sillutils();
	unsigned int firstSillLength,secondSillLength;
	firstSillLength = utils->lengthOfSILL(firstSill);
	secondSillLength = utils->lengthOfSILL(secondSill);
	sillNode *traversalNodeFirstSill = firstSill,*traversalNodeSecondSill = secondSill;
	if(firstSillLength > secondSillLength){
		while(firstSillLength != secondSillLength){
			firstSillLength--;
			traversalNodeFirstSill = traversalNodeFirstSill->next;
		}
	}else{
		while(firstSillLength != secondSillLength){
			secondSillLength--;
			traversalNodeSecondSill = traversalNodeSecondSill->next;
		}
	}
	while(traversalNodeFirstSill != null && traversalNodeSecondSill != null){
		if(traversalNodeFirstSill == traversalNodeSecondSill){
			return traversalNodeFirstSill;
		}
		traversalNodeFirstSill = traversalNodeFirstSill->next;
		traversalNodeSecondSill = traversalNodeSecondSill->next;
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *getIntersectionOfSillON2(sillNode *firstSill,sillNode *secondSill){
	if(firstSill == null || secondSill == null){
		return null;
	}
	sillNode *traversalNodeFirstSill = firstSill,*traversalNodeSecondSill = secondSill;
	while(traversalNodeFirstSill != null){
		while(traversalNodeSecondSill != null){
			if(traversalNodeFirstSill == traversalNodeSecondSill){
				return traversalNodeFirstSill;
			}
			traversalNodeSecondSill =  traversalNodeSecondSill->next;
		}
		traversalNodeFirstSill = traversalNodeFirstSill->next;
	}
	return null;
}

#endif /* INTERSECTIONOFSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
