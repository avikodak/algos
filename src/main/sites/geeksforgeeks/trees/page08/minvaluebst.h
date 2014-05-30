/****************************************************************************************************************************************************
 *  File Name   		: minvaluebst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\minvaluebst.h
 *  Created on			: Apr 23, 2014 :: 11:40:30 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/find-the-minimum-element-in-a-binary-search-tree/
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

#ifndef MINVALUEBST_H_
#define MINVALUEBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int minValueBST(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->left == null){
		return ptr->value;
	}
	return minValueBST(ptr->left);
}

//Tested
int minValueBSTIterative(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	itNode *traversalNode = ptr;
	while(traversalNode->left != null){
		traversalNode = traversalNode->left;
	}
	return traversalNode->value;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int minValueBSTONLOGN(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	treeutils *utils = new treeutils();
	vector<int> preOrderValues;
	utils->setVectorWithPreOrderValues(ptr,preOrderValues);
	sort(preOrderValues.begin(),preOrderValues.end());
	return preOrderValues[0];
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isMinValueInTree(itNode *ptr,int value){
	if(ptr == null){
		return true;
	}
	if(ptr->value < value){
		return false;
	}
	return isMinValueInTree(ptr->left,value) && isMinValueInTree(ptr->right,value);
}

//Tested
int getMinValuePreOrderTraversal(itNode **root,itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	if(isMinValueInTree(*root,ptr->value)){
		return ptr->value;
	}
	int leftSubTreeMinValue = getMinValuePreOrderTraversal(root,ptr->left);
	if(leftSubTreeMinValue != INT_MIN){
		return leftSubTreeMinValue;
	}
	return getMinValuePreOrderTraversal(root,ptr->right);
}

#endif /* MINVALUEBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
