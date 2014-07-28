/****************************************************************************************************************************************************
 *  File Name   		: converttreetodll.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page03\converttreetodll.h
 *  Created on			: May 25, 2014 :: 7:03:54 PM
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

#ifndef CONVERTTREETODLL_H_
#define CONVERTTREETODLL_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *convertTreeToDLLMain(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left == null){
		itNode *leftSubTree = convertTreeToDLLMain(ptr->left);
		while(leftSubTree->right != null){
			leftSubTree = leftSubTree->right;
		}
		ptr->left = leftSubTree;
		leftSubTree->right = ptr;
	}
	if(ptr->right == null){
		itNode *rightSubTree = convertTreeToDLLMain(ptr->right);
		while(rightSubTree->left != null){
			rightSubTree = rightSubTree->left;
		}
		ptr->right = rightSubTree;
		rightSubTree->left= ptr;
	}
	return ptr;
}

void convertTreeToDLLON2(itNode **ptr){
	if(ptr == null){
		return;
	}
	convertTreeToDLLMain(*ptr);
	itNode *currentNode = *ptr;
	while(currentNode->left != null){
		currentNode = currentNode->left;
	}
	*ptr = currentNode;
}

#endif /* CONVERTTREETODLL_H_ */


/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
