/****************************************************************************************************************************************************
 *  File Name   		: insertintocircularsill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page03\insertintocircularsill.h
 *  Created on			: May 1, 2014 :: 7:48:32 PM
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

#ifndef INSERTINTOCIRCULARSILL_H_
#define INSERTINTOCIRCULARSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void insertIntoSortedCircularSill(sillNode **ptr,int value){
	if(*ptr == null){
		return;
	}
	if(*ptr == null){
		(*ptr) = new sillNode(key);
		(*ptr)->next = *ptr;
	}else{
		sillNode *traversalNode = *ptr,*head = *ptr;
		sillNode *newNode = new sillNode(value);
		if(traversalNode->value > value){
			newNode->next = *ptr;
			*ptr = newNode;
			return;
		}
		while(traversalNode->next != head && traversalNode->value < value){
			traversalNode = traversalNode->next;
		}
	}
}

#endif /* INSERTINTOCIRCULARSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
