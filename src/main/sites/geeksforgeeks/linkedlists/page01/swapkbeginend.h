/****************************************************************************************************************************************************
 *  File Name   		: swapkbeginend.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page01\swapkbeginend.h
 *  Created on			: May 28, 2014 :: 11:14:46 PM
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

#ifndef SWAPKBEGINEND_H_
#define SWAPKBEGINEND_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
vpod swapKthNodeBeginEnd(sillNode *ptr,unsigned int kValue){
	if(ptr == null || key == 0){
		return;
	}
	sillNode *preKthNodeFromBegin,*preKthNodeFromEnd,*traversalNode = ptr;
	while(kValue-- != 1 && traversalNode != null){
		traversalNode = traversalNode->next;
	}
	if(traversalNode->next == null){
		throw "Invalid K value";
	}
	preKthNodeFromBegin = traversalNode;
	traversalNode = traversalNode->next;
	preKthNodeFromEnd = ptr;
	while(traversalNode->next != null){
		traversalNode = traversalNode->next;
		preKthNodeFromEnd = preKthNodeFromEnd->next;
	}
	sillNode *temp;
}

void swapKthNodeBeginEndValue(sillNode *ptr,unsigned int key){
	if(ptr == null || key == 0){
		return;
	}
	sillNode *kthNodeFromBegin,*traversalNode = ptr,*kthNodeFromEnd = ptr;
	while(key-- && traversalNode != null){
		traversalNode = traversalNode->next;
	}
	if(traversalNode == null){
		throw "Invalid K value";
	}
	kthNodeFromBegin = traversalNode;
	while(traversalNode != null){
		kthNodeFromEnd = kthNodeFromEnd->next;
		traversalNode = traversalNode->next;
	}
	int temp = kthNodeFromBegin->value;
	kthNodeFromBegin->value = kthNodeFromEnd->value;
	kthNodeFromEnd->value = temp;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* SWAPKBEGINEND_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
