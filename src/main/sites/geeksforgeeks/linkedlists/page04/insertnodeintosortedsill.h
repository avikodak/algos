/****************************************************************************************************************************************************
 *  File Name   		: insertnodeintosortedsill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\insertnodeintosortedsill.h
 *  Created on			: Apr 29, 2014 :: 9:57:23 PM
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

#ifndef INSERTNODEINTOSORTEDSILL_H_
#define INSERTNODEINTOSORTEDSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void insertNodeIntoSortedSill(sillNode **ptr,unsigned int userInput){
	if(*ptr == null){
		(*ptr) = new sillNode(userInput);
	}else{
		sillNode *traversalNode = *ptr,*newNode;
		newNode = new sillNode(userInput);
		if((*ptr)->value > userInput){
			newNode->next = *ptr;
			*ptr = newNode;
		}else{
			while(traversalNode->next != null && traversalNode->next->value < userInput){
				traversalNode = traversalNode->next;
			}
			traversalNode->next = newNode;
		}
	}
}

#endif /* INSERTNODEINTOSORTEDSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
