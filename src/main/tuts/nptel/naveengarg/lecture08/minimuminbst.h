/****************************************************************************************************************************************************
 *  File Name   		: minimuminbst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture08\minimuminbst.h
 *  Created on			: Jun 4, 2014 :: 1:45:21 AM
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

#ifndef MINIMUMINBST_H_
#define MINIMUMINBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *getMinimumFromBST(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left == null){
		return ptr;
	}
	return getMinimumFromBST(ptr->left);
}

itNode *getMinimumFromBSTIterative(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *traversingNode = ptr;
	while(traversingNode->left != null){
		traversingNode = traversingNode->left;
	}
	return traversingNode;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
bool sortForItNodes(itNode *firstPtr,itNode *secondPtr){
	return firstPtr->value < secondPtr->value?true:false;
}

itNode *getMinimumFromBSTONLOGN(itNode *ptr){
	if(ptr == null){
		return null;
	}
	treeutils *utils = new treeutils();
	vector<itNode *> preOrderNodes;
	utils->setVectorWithPreOrderNodes(ptr,preOrderNodes);
	sort(preOrderNodes.begin(),preOrderNodes.end(),sortForItNodes);
	return preOrderNodes[0];
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isValueLesserThanEveryKey(itNode *ptr,int value){
	if(ptr == null){
		return true;
	}
	if(ptr->value < value){
		return false;
	}
	return isValueLesserThanEveryKey(ptr->left,value) && isValueLesserThanEveryKey(ptr->right,value);
}

itNode *getMinimumForBSTON2(itNode *ptr){
	if(ptr == null){
		return null;
	}
	treeutils *utils = new treeutils();
	vector<itNode *> preOrderNodes;
	utils->setVectorWithPreOrderNodes(ptr,preOrderNodes);
	for(unsigned int counter = 0;counter < preOrderNodes.size();counter++){
		if(isValueLesserThanEveryKey(ptr,preOrderNodes[counter]->value)){
			return preOrderNodes[counter];
		}
	}
	return null;
}
#endif /* MINIMUMINBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
