/****************************************************************************************************************************************************
 *  File Name   		: nthnodeinsll.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page05\nthnodeinsll.h
 *  Created on			: Apr 13, 2014 :: 10:22:13 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef NTHNODEINSLL_H_
#define NTHNODEINSLL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

//Tested
sillNode *getNthNodeFromSll(sillNode *ptr,unsigned int nthValue){
	if(ptr == null || nthValue == 0){
		return null;
	}
	if(nthValue-1== 0){
		return ptr;
	}
	return getNthNodeFromSll(ptr->next,nthValue-1);
}

//Tested
sillNode *getNthNodeFromSllIterative(sillNode *ptr,unsigned int nthValue){
	if(ptr == null || nthValue == 0){
		return null;
	}
	if(nthValue == 1){
		return ptr;
	}
	sillNode *traversalNode = ptr;
	nthValue--;
	while(traversalNode != null && nthValue--){
		traversalNode = traversalNode->next;
	}
	return traversalNode;
}

#endif /* NTHNODEINSLL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
