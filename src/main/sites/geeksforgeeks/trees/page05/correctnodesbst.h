/****************************************************************************************************************************************************
 *  File Name   		: correctnodesbst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page05\correctnodesbst.h
 *  Created on			: May 28, 2014 :: 5:28:40 PM
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

#ifndef CORRECTNODESBST_H_
#define CORRECTNODESBST_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void correctTwoNodesInBSTMain(itNode *ptr,itNode **firstPtr,itNode **secondPtr,itNode **thirdPtr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	correctTwoNodesInBST(ptr->left,firstPtr,secondPtr,thirdPtr);
	if(prevNode != null){
		if(prevNode->value > ptr->value){
			if(*firstPtr == null){
				*firstPtr = prevNode;
				*secondPtr = ptr;
			}else{
				*thirdPtr = ptr;
				return;
			}
		}
	}
	prevNode = ptr;
	correctTwoNodesInBST(ptr->right,firstPtr,secondPtr,thirdPtr);
}

void correctTwoNodesInBST(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *firstPtr = null,*secondPtr=null,*thirdPtr=null;
	correctTwoNodesInBST(ptr,&firstPtr,&secondPtr,&thirdPtr);
	if(firstPtr == null){
		return null;
	}
	if(thirdPtr == null){
		int temp = firstPtr->value;
		firstPtr->value = secondPtr->value;
		secondPtr->value = temp;
	}else{
		int temp = firstPtr->value;
		firstPtr->value = thirdPtr->value;
		thirdPtr->value = temp;
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void setInOrderValueInTree(itNode *ptr,vector<int> inOrderValues){
	static unsigned int counter = 0;
	if(ptr == null || counter < inOrderValues.size()){
		return;
	}
	setInOrderValueInTree(ptr->left,inOrderValues);
	ptr->value = inOrderValues[counter++];
	setInOrderValueInTree(ptr->right,inOrderValues);
}

void correctNodesInBSTONLOGN(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	vector<int> inorderValues;
	utils->setVectorWithInOrderValues(ptr,inorderValues);
	sort(inorderValues.begin(),inorderValues.end());
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* CORRECTNODESBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
