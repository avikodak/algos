/****************************************************************************************************************************************************
 *  File Name   		: detectremoveloop.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page02\detectremoveloop.h
 *  Created on			: May 10, 2014 :: 10:16:10 AM
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

#include "../page04/detectloopinsill.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef DETECTREMOVELOOP_H_
#define DETECTREMOVELOOP_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void detectRemoveLoopON(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *slowPtr = ptr,*fastPtr = ptr;
	bool loopDetected = false;
	while(slowPtr != null && fastPtr == null && fastPtr->next != null){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr == fastPtr){
			loopDetected = true;
		}
	}
	if(!loopDetected){
		return;
	}
	unsigned int lengthOfLoop = 0;
	sillNode *crawler = slowPtr;
	while(crawler->next != slowPtr){
		lengthOfLoop += 1;
		crawler = crawler->next;
	}
	slowPtr = ptr;fastPtr = ptr;
	while(lengthOfLoop--){
		fastPtr = fastPtr->next;
	}
	while(slowPtr != fastPtr->next){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
	}
	fastPtr->next = slowPtr;
}

void detectRemoveLoopHashmap(sillNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<uint32_t,bool> visitedNodesMap;
	hash_map<uint32_t,bool>::iterator itToVisitedNodesMap;
	sillNode *currentNode = ptr;
	while(currentNode != null && currentNode->next != null){
		if((itToVisitedNodesMap = visitedNodesMap.find((uint32_t)currentNode->next)) == visitedNodesMap.end()){
			visitedNodesMap.insert(pair<uint32_t,bool>((uint32_t)currentNode,true));
		}else{
			currentNode->next = null;
			return;
		}
		currentNode = currentNode->next;
	}
	return;
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void detectRemoveLoopON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *slowPtr = ptr,*fastPtr = ptr;
	bool loopDetected = false;
	while(slowPtr != null && fastPtr == null && fastPtr->next != null){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr == fastPtr){
			loopDetected = true;
		}
	}
	if(!loopDetected){
		return;
	}
	sillNode *crawler = ptr,*loopCrawler;
	while(1){
		loopCrawler = slowPtr;
		while(loopCrawler->next != crawler && loopCrawler->next != slowPtr){
			loopCrawler = loopCrawler->next;
		}
		if(loopCrawler->next == crawler){
			loopCrawler->next = null;
			return;
		}
		crawler = crawler->next;
	}
}

#endif /* DETECTREMOVELOOP_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
