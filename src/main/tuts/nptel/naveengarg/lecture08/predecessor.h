/****************************************************************************************************************************************************
 *  File Name   		: predecessor.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture08\predecessor.h
 *  Created on			: Jun 4, 2014 :: 1:45:38 AM
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

#ifndef PREDECESSOR_H_
#define PREDECESSOR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *getPredecessorBST(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	itNode *probablePredecessor = ptr,*traversingNode = ptr;
	while(traversingNode != null){
		if(traversingNode->value == value){
			if(traversingNode->left == null){
				return probablePredecessor;
			}else{
				traversingNode = traversingNode->left;
				while(traversingNode->right != null){
					traversingNode = traversingNode->right;
				}
				return traversingNode;
			}
		}else{
			if(traversingNode->value > value){
				traversingNode = traversingNode->left;
			}else{
				probablePredecessor = traversingNode;
				traversingNode = traversingNode->right;
			}
		}
	}
	return null;
}

iptNode *getPredecessorPBST(iptNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	iptNode *traversingNode = ptr;
	while(traversingNode != null){
		if(traversingNode->value == value){
			if(traversingNode->left == null){
				while(traversingNode != null){
					if(traversingNode->value < value){
						return traversingNode;
					}
					traversingNode = traversingNode->parent;
				}
			}else{
				traversingNode = traversingNode->left;
				while(traversingNode->right != null){
					traversingNode = traversingNode->right;
				}
				return traversingNode;
			}
		}else{
			if(traversingNode->value > value){
				traversingNode = traversingNode->left;
			}else{
				traversingNode = traversingNode->right;
			}
		}
	}
	return null;
}

void getPredecessorON(itNode *ptr,itNode **predecessor,int value){
	if(ptr == null){
		return;
	}
	if(ptr->value < value){
		if(*predecessor == null){
			*predecessor = ptr;
		}else{
			*predecessor = (*predecessor)->value > ptr->value?*predecessor:ptr;
		}
	}
	getPredecessorON(ptr->left,predecessor,value);
	getPredecessorON(ptr->right,predecessor,value);
}

itNode *getPredecessorInorderON(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	static itNode *prevNode = null;
	itNode *leftResult = getPredecessorInorderON(ptr->left,value);
	if(leftResult != null){
		return leftResult;
	}
	if(ptr->value == value){
		return prevNode;
	}
	prevNode = ptr;
	return getPredecessorInorderON(ptr->right,value);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void sortFuncItNode(itNode *firstPtr,itNode *secondPtr){
	return firstPtr->value < secondPtr->value?true:false;
}

itNode *getPredecessorONLOGN(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	vector<itNode *> preOrderNodes;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderNodes(ptr,preOrderNodes);
	for(unsigned int counter = 0;counter < preOrderNodes.size();counter++){
		if(preOrderNodes[counter] == value){
			if(counter == 0){
				return null;
			}else{
				return preOrderNodes[counter-1];
			}
		}
	}
	return null;
}

#endif /* PREDECESSOR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
