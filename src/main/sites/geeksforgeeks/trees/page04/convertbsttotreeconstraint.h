/****************************************************************************************************************************************************
 *  File Name   		: convertbsttotreeconstraint.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page04\convertbsttotreeconstraint.h
 *  Created on			: May 26, 2014 :: 12:32:19 PM
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

#ifndef CONVERTBSTTOTREECONSTRAINT_H_
#define CONVERTBSTTOTREECONSTRAINT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void convertBSTToTreeSumOfAllGreaterValues(itNode *ptr){
	if(ptr == null){
		return;
	}
	static int prevValue = 0;
	convertBSTToTreeSumOfAllGreaterValues(ptr->right);
	ptr->value = ptr->value + prevValue;
	prevValue = ptr->value;
	convertBSTToTreeSumOfAllGreaterValues(ptr->left);
}

void convertBSTToTreeSumOfAllGreaterValueIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	int prevValue = 0;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->right;
		}else{
			currentNode = auxSpace.top();
			currentNode->value += prevValue;
			prevValue = currentNode->value;
			auxSpace.pop();
			currentNode = currentNode->left;
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int getAllValuesGreaterThanGivenValueBST(itNode *ptr,int value){
	if(ptr == null){
		return 0;
	}
	return (ptr->value > value?ptr->value:0) + getAllValuesGreaterThanGivenValueBST(ptr->left,value) + getAllValuesGreaterThanGivenValueBST(ptr->right,value);
}

int getAllValuesGreaterThanGivenValueBSTOptimised(itNode *ptr,int value){
	if(ptr == null){
		return 0;
	}
	if(ptr->value > value){
		return ptr->value + getAllValuesGreaterThanGivenValueBST(ptr->left,value)+getAllValuesGreaterThanGivenValueBST(ptr->right,value);
	}else{
		return getAllValuesGreaterThanGivenValueBST(ptr->right,value);
	}
}


#endif /* CONVERTBSTTOTREECONSTRAINT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
