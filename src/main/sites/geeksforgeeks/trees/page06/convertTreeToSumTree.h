/****************************************************************************************************************************************************
 *  File Name   		: convertTreeToSumTree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page06\convertTreeToSumTree.h
 *  Created on			: May 9, 2014 :: 10:21:01 PM
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

#ifndef CONVERTTREETOSUMTREE_H_
#define CONVERTTREETOSUMTREE_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int convertTreeToSumTreePostOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	int temp;
	if(ptr->left == null && ptr->right == null){
		temp = ptr->value;
		ptr->value = 0;
		return temp;
	}
	int leftSubTreeSum = convertTreeToSumTreePostOrder(ptr->left);
	int rightSubTreeSum = convertTreeToSumTreePostOrder(ptr->right);
	temp = ptr->value;
	ptr->value = leftSubTreeSum + rightSubTreeSum;
	return ptr->value + temp;
}

struct itNodeValueHashmap{
	hash_map<uint32_t,int> nodeValueMap;
	hash_map<int,vector<itNode *> > valueNodesMap;
};

void convertTreeToSumTreePostOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	itNodeValueHashmap *nodeValueHashmap = utils->getNodeValueHashMap(null);
	hash_map<uint32_t,int> nodeValueHashmap =  nodeValueHashmap->nodeValueMap;
	hash_map<uint32_t,int>::iterator itToNodeValueHashmap;
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentTopNode;
	while(!primaryAuxspace.empty()){
		currentTopNode = primaryAuxspace.top();
		primaryAuxspace.pop();

	}

}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* CONVERTTREETOSUMTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
