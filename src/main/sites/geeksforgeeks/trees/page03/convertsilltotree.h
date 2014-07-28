/****************************************************************************************************************************************************
 *  File Name   		: convertsilltotree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page03\convertsilltotree.h
 *  Created on			: May 25, 2014 :: 10:34:09 PM
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

#ifndef CONVERTSILLTOTREE_H_
#define CONVERTSILLTOTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *convertSillToTreeIterative(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	sillNode *traversalNode = ptr;
	while(traversalNode !=  null){
		if(auxSpace.empty()){
			currentNode = new itNode(traversalNode->value);
			auxSpace.push(currentNode);
		}else{
			currentNode = auxSpace.front();
			if(currentNode->left == null){
				currentNode->left = new itNode(traversalNode->value);
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right == null){
				currentNode->right = new itNode(traversalNode->value);
				auxSpace.push(currentNode->right);
				auxSpace.pop();
			}
		}
		traversalNode = traversalNode->next;
	}
}


/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* CONVERTSILLTOTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
