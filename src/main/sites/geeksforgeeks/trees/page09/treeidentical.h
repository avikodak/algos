/****************************************************************************************************************************************************
 *  File Name   		: treeidentical.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page09\treeidentical.h
 *  Created on			: Apr 15, 2014 :: 2:11:30 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
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

#ifndef TREEIDENTICAL_H_
#define TREEIDENTICAL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool areTreesIdenticalTopToBottom(itNode *ptrToFirstTree,itNode *ptrToSecondTree){
	if(ptrToFirstTree == null && ptrToSecondTree == null){
		return true;
	}
	if(ptrToFirstTree == null || ptrToSecondTree == null){
		return false;
	}
	if(ptrToFirstTree->value != ptrToSecondTree->value){
		return false;
	}
	return areTreesIdenticalTopToBottom(ptrToFirstTree->left,ptrToSecondTree->left) && areTreesIdenticalTopToBottom(ptrToFirstTree->right,ptrToSecondTree->right);
}

//Tested
bool areTreesIdenticalBottomUp(itNode *ptrToFirstTree,itNode *ptrToSecondTree){
	if(ptrToFirstTree == null && ptrToSecondTree == null){
		return true;
	}
	if(ptrToFirstTree == null || ptrToSecondTree == null){
		return false;
	}
	bool areSubTreesIdentical = areTreesIdenticalBottomUp(ptrToFirstTree->left,ptrToSecondTree->left) && areTreesIdenticalBottomUp(ptrToFirstTree->right,ptrToSecondTree->right);
	return areSubTreesIdentical?(ptrToFirstTree->value == ptrToSecondTree->value?true:false):false;
}

//Tested
bool areTreesIdenticalHashmap(itNode *ptrToFirstTree,itNode *ptrToSecondTree){
	if(ptrToFirstTree == null && ptrToSecondTree == null){
		return true;
	}
	if(ptrToFirstTree == null || ptrToSecondTree == null){
		return false;
	}
	treeutils *utils = new treeutils();
	itHashmap *hashmapFirstTree = utils->getHashmapFormITree(ptrToFirstTree);
	itHashmap *hashmapSecondTree = utils->getHashmapFormITree(ptrToSecondTree);
	hash_map<unsigned int,itNode *> indexNodeMapFirstTree = hashmapFirstTree->indexNodeMap,indexNodeMapSecondTree = hashmapSecondTree->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMapFirstTree,itToIndexNodeMapSecondTree;

	for(itToIndexNodeMapFirstTree = indexNodeMapFirstTree.begin();itToIndexNodeMapFirstTree != indexNodeMapFirstTree.end();itToIndexNodeMapFirstTree++){
		if((itToIndexNodeMapSecondTree = indexNodeMapSecondTree.find(itToIndexNodeMapFirstTree->first)) == indexNodeMapSecondTree.end()){
			return false;
		}
		if(itToIndexNodeMapSecondTree->second->value != itToIndexNodeMapFirstTree->second->value){
			return false;
		}
	}
	return true;
}

//Tested
bool areTreesIdenticalPreInOrderNodes(itNode *ptrToFirstTree,itNode *ptrToSecondTree){
	if(ptrToFirstTree == null && ptrToSecondTree == null){
		return true;
	}
	if(ptrToFirstTree == null || ptrToSecondTree == null){
		return false;
	}
	vector<itNode *> preOrderNodesFirstTree,preOrderNodesSecondTree,inOrderNodesFirstTree,inOrderNodesSecondTree;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderNodes(ptrToFirstTree,preOrderNodesFirstTree);
	utils->setVectorWithPreOrderNodes(ptrToSecondTree,preOrderNodesSecondTree);
	utils->setVectorWithInOrderNodes(ptrToFirstTree,inOrderNodesFirstTree);
	utils->setVectorWithInOrderNodes(ptrToSecondTree,inOrderNodesSecondTree);
	if(preOrderNodesFirstTree.size() != preOrderNodesSecondTree.size()){
		return false;
	}
	for(unsigned int counter = 0;counter < preOrderNodesFirstTree.size();counter++){
		if(preOrderNodesFirstTree[counter]->value != preOrderNodesSecondTree[counter]->value){
			return false;
		}
	}
	for(unsigned int counter = 0;counter < inOrderNodesFirstTree.size();counter++){
		if(inOrderNodesFirstTree[counter]->value != inOrderNodesSecondTree[counter]->value){
			return false;
		}
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* TREEIDENTICAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
