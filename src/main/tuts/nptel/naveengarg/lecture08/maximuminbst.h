/****************************************************************************************************************************************************
 *  File Name   		: maximuminbst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture08\maximuminbst.h
 *  Created on			: Jun 6, 2014 :: 12:13:20 PM
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

#ifndef MAXIMUMINBST_H_
#define MAXIMUMINBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *getMaximumFromBST(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->right == null){
		return ptr;
	}
	return getMaximumFromBST(ptr->right);
}

itNode *getMaximumFromBSTIterative(itNode *ptr){
	if(ptr == null){
		return null;
	}
	while(ptr->right != null ){
		ptr = ptr->right;
	}
	return ptr;
}

void getMaximumFromBSTPreorder(itNode *ptr,itNode **maxNode){
	if(ptr == null){
		return ptr;
	}
	if(*maxNode == null){
		*maxNode = ptr;
	}else{
		if((*maxNode)->value < ptr->value){
			*maxNode = ptr;
		}
	}
	getMaximumFromBSTPreorder(ptr->left,maxNode);
	getMaximumFromBSTPreorder(ptr->right,maxNode);
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
bool sortFunctionItNode(itNode *firstNode,itNode *secondNode){
	return firstNode->value > secondNode->value?true:false;
}

itNode *getMaximumFromBSTONLOGN(itNode *ptr){
	if(ptr == null){
		return null;
	}
	vector<itNode *> preOrderNodes;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderNodes(ptr,preOrderNodes);
	sort(preOrderNodes.begin(),preOrderNodes.end(),sortFunctionItNode);
	return preOrderNodes[0];
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isValueGreaterThanEveryNode(itNode *ptr,int value){
	if(ptr == null){
		return true;
	}
	if(ptr->value > value){
		return false;
	}
	return isValueGreaterThanEveryNode(ptr->left,value) && isValueGreaterThanEveryNode(ptr->right,value);
}
itNode *getMaximumFromBST(itNode *ptr){
	if(ptr == null){
		return null;
	}
	vector<itNode *> preOrderNodes;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderNodes(ptr,preOrderNodes);
	for(unsigned int counter = 0;counter < preOrderNodes.size();counter++){
		if(isValueGreaterThanEveryNode(ptr,preOrderNodes[counter]->value)){
			return preOrderNodes[counter];
		}
	}
	return null;
}
#endif /* MAXIMUMINBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
