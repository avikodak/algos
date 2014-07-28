/****************************************************************************************************************************************************
 *  File Name   		: deletealternatenodes.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page03\deletealternatenodes.h
 *  Created on			: May 1, 2014 :: 7:46:25 PM
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

#ifndef DELETEALTERNATENODES_H_
#define DELETEALTERNATENODES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void deleteAlternateNodes(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return null;
	}
	sillNode *nodeToBeDeleted = ptr->next;
	ptr->next = ptr->next->next;
	free(nodeToBeDeleted);
	deleteAlternateNodes(ptr->next);
}

void deleteAlternateNodesIterative(sillNode *ptr){
	if(ptr == null || ptr->next == null){
		return;
	}
	sillNode *traversalNode = ptr,*nodeToBeDeleted;
	while(traversalNode != null || traversalNode->next != null){
		nodeToBeDeleted = traversalNode->next;
		traversalNode->next = traversalNode->next->next;
		free(nodeToBeDeleted);
	}
}
#endif /* DELETEALTERNATENODES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
