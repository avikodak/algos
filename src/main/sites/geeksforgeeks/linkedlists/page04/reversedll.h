/****************************************************************************************************************************************************
 *  File Name   		: reversedll.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\reversedll.h
 *  Created on			: May 1, 2014 :: 9:55:47 AM
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

#ifndef REVERSEDLL_H_
#define REVERSEDLL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void reverseDll(dillNode **head,dillNode *ptr){
	if(ptr == null){
		return;
	}
	dillNode *temp;
	temp = ptr->prev;
	ptr->prev = ptr->next;
	ptr->next = temp;
	if(ptr->next == null){
		*head = ptr;
		return;
	}
	reverseDll(head,ptr->next);
}

void reverseDllIterative(dillNode **head,dillNode *ptr){
	if(ptr == null){
		return;
	}
	dillNode *traversalNode = ptr,*tempForSwap;
	while(traversalNode != null){
		tempForSwap = traversalNode->prev;
		traversalNode->prev = traversalNode->next;
		traversalNode->next = tempForSwap;
		if(traversalNode->next == null){
			break;
		}
		traversalNode = traversalNode->next;
	}
	*head = traversalNode;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* REVERSEDLL_H_ */


/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
