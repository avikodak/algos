/****************************************************************************************************************************************************
 *  File Name   		: converttreetodllset2.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page03\converttreetodllset2.h
 *  Created on			: May 25, 2014 :: 6:56:31 PM
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

#ifndef CONVERTTREETODLLSET2_H_
#define CONVERTTREETODLLSET2_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void fixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	fixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	fixLeftPtr(ptr->right);
}

void fixRightPtr(itNode **ptr){
	if(*ptr == null){
		return;
	}
	itNode *currentNode = *ptr;
	itNode *prevNode = null;
	while(currentNode->right != null){
		currentNode = currentNode->right;
	}
	while(currentNode != null){
		currentNode->right = prevNode;
		prevNode = currentNode;
		currentNode = currentNode->left;
	}
	(*ptr) = prevNode;
}

void convertTreeToDLL(itNode **ptr){
	if(*ptr == null){
		return;
	}
	fixLeftPtr(*ptr);
	fixRightPtr(ptr);
}

#endif /* CONVERTTREETODLLSET2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
