/****************************************************************************************************************************************************
 *  File Name   		: inordersuccessorbst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page07\inordersuccessorbst.h
 *  Created on			: May 1, 2014 :: 7:43:06 PM
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

#ifndef INORDERSUCCESSORBST_H_
#define INORDERSUCCESSORBST_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *inOrderSuccessorBST(itNode *ptr,int key){
	if(ptr == null){
		return null;
	}
	static itNode *probableSuccessor = null;
	if(ptr->value == key){
		if(ptr->right == null){
			return probableSuccessor;
		}
		ptr = ptr->right;
		while(ptr->left != null){
			ptr = ptr->left;
		}
		return ptr;
	}
	probableSuccessor = ptr;
	if(ptr->value > key){
		return inOrderSuccessorBST(ptr->left,key);
	}else{
		return inOrderSuccessorBST(ptr->right,key);
	}
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *inOrderSuccessor(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	static itNode *inorderSuccessorNode = null;
	if(ptr->value == value){
		return inorderSuccessorNode;
	}
	itNode *leftSubTreeNode = inOrderSuccessor(ptr->left,value);
	if(leftSubTreeNode != null){
		return leftSubTreeNode;
	}
	inorderSuccessorNode = ptr;
	return inOrderSuccessor(ptr->right,value);
}


/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int inOrderSuccessorONLOGN(itNode *ptr,int value){
	if(ptr == null){
		return INT_MAX;
	}
	treeutils *utils = new treeutils();
	vector<int> inorderValues;
	utils->setVectorWithInOrderValues(ptr,inorderValues);
	upper_bound(inorderValues.begin(),inorderValues.end(),value);
	//produce the output
}

#endif /* INORDERSUCCESSORBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
