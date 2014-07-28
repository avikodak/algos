/****************************************************************************************************************************************************
 *  File Name   		: addnumbersill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page02\addnumbersill.h
 *  Created on			: May 9, 2014 :: 1:38:40 AM
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

#ifndef ADDNUMBERSILL_H_
#define ADDNUMBERSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *addnumbersSillIterative(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null && secondPtr == null){
		return null;
	}
	if(firstPtr == null || secondPtr == null){
		if(firstPtr != null){
			return firstPtr;
		}else{
			return secondPtr;
		}
	}
	sillNode *result=null,*traversalNode;
	unsigned int carry = 0;
	int sum;
	while(firstPtr != null && secondPtr != null){
		sum = firstPtr->value + secondPtr->value + carry;
		if(result == null){
			result = new sillNode(sum%10);
			traversalNode = result;
		}else{
			traversalNode->next = new sillNode(sum%10);
			traversalNode = traversalNode->next;
		}
		carry = sum/10;
		firstPtr = firstPtr->next;
		secondPtr = secondPtr->next;
	}
	while(firstPtr != null){
		sum = firstPtr->value + carry;
		traversalNode->next = new sillNode(sum%10);
		carry = sum/10;
		firstPtr = firstPtr->next;
	}
	while(secondPtr != null){
		sum = secondPtr->value + carry;
		traversalNode->next = new sillNode(sum%10);
		carry = sum/10;
		secondPtr = secondPtr->next;
	}
	return result;
}


#endif /* ADDNUMBERSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
