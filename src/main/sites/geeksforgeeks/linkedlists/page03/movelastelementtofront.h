/****************************************************************************************************************************************************
 *  File Name   		: movelastelementtofront.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page03\movelastelementtofront.h
 *  Created on			: May 1, 2014 :: 7:45:24 PM
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

#ifndef MOVELASTELEMENTTOFRONT_H_
#define MOVELASTELEMENTTOFRONT_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void moveLastElementToFront(sillNode **head,sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return;
	}
	if(ptr->next->next == null){
		ptr->next->next = *head;
		(*head) = ptr->next;
		ptr->next = null;
		return;
	}
	moveLastElementToFront(head,ptr->next);
}

void moveLastElementToFrontIterative(sillNode **head){
	if(*head == null || (*head)->next == null){
		return;
	}
	sillNode *traversalNode = *head;
	while(traversalNode->next->next != null){
		traversalNode = traversalNode->next;
	}
	traversalNode->next->next = *head;
	(*head) = traversalNode->next;
	traversalNode->next = null;
}

#endif /* MOVELASTELEMENTTOFRONT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
