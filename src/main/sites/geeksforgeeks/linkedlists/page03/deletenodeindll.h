/****************************************************************************************************************************************************
 *  File Name   		: deletenodeindll.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page03\deletenodeindll.h
 *  Created on			: May 1, 2014 :: 7:45:55 PM
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

#ifndef DELETENODEINDLL_H_
#define DELETENODEINDLL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void deleteNodeInDllIterative(dillNode **head,dillNode *ptrToBeDeleted){
	if(*head == null || ptrToBeDeleted == null){
		return;
	}
	dillNode *nodeToBeDeleted;
	if(*head == ptrToBeDeleted){
		*head = (*head)->next;
		(*head)->prev = null;
		free(ptrToBeDeleted);
		return;
	}
	nodeToBeDeleted = *head;
	while(nodeToBeDeleted != null && nodeToBeDeleted != ptr){
		nodeToBeDeleted = nodeToBeDeleted->next;
	}
	if(nodeToBeDeleted == null){
		return;
	}
	nodeToBeDeleted->prev->next = nodeToBeDeleted->next;
	nodeToBeDeleted->next->prev = nodeToBeDeleted->prev;
	free(nodeToBeDeleted);
}

#endif /* DELETENODEINDLL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
