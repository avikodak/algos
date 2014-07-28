/****************************************************************************************************************************************************
 *  File Name   		: searchinbst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture08\searchinbst.h
 *  Created on			: Jun 4, 2014 :: 1:45:12 AM
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

#ifndef SEARCHINBST_H_
#define SEARCHINBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

itNode *searchForNodeInBST(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	if(ptr->value == value){
		return ptr;
	}
	if(ptr->value > value){
		return searchForNodeInBST(ptr->left,value);
	}else{
		return searchForNodeInBST(ptr->right,value);
	}
}

itNode *searchForNodeInBSTIterative(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	itNode *traversingNode = ptr;
	while(traversingNode != null){
		if(traversingNode->value == value){
			return traversingNode;
		}
		traversingNode = traversingNode->value > value?traversingNode->left:traversingNode->right;
	}
	return traversingNode;
}

itNode *searchForNodePreOrder(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	if(ptr->value == value){
		return ptr;
	}
	itNode *leftResult = searchForNodePreOrder(ptr->left,value);
	if(leftResult != null){
		return leftResult;
	}
	return searchForNodePreOrder(ptr->right,value);
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

itNode *searchInBSTBinarySearch(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	vector<itNode *> preOrderNodes;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderNodes(ptr,preOrderNodes);
	//return (lower_bound(preOrderNodes.begin(),preOrderNodes.end(),searchFunc) - preOrderNodes.begin());
}

#endif /* SEARCHINBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
