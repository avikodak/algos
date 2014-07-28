/****************************************************************************************************************************************************
 *  File Name   		: successorbst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture08\successorbst.h
 *  Created on			: Jun 4, 2014 :: 1:45:30 AM
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

#ifndef SUCCESSORBST_H_
#define SUCCESSORBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *getSuccessorBST(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	itNode *probableSuccessor = null,*traversingNode = ptr;
	while(traversingNode != null){
		if(traversingNode->value == value){
			if(traversingNode->right == null){
				return probableSuccessor;
			}else{
				traversingNode = traversingNode->right;
				while(traversingNode->left != null){
					traversingNode = traversingNode->left;
				}
				return traversingNode;
			}
		}else{
			if(traversingNode->value > value){
				probableSuccessor = traversingNode;
				traversingNode = traversingNode->left;
			}else{
				traversingNode = traversingNode->right;
			}
		}
	}
	return null;
}

iptNode *getSuccessorPBST(iptNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	iptNode *traversingNode = ptr;
	while(traversingNode != null){
		if(traversingNode->value == value){
			if(traversingNode->right == null){
				while(traversingNode != null){
					if(traversingNode->value > value){
						return traversingNode;
					}
					traversingNode = traversingNode->parent;
				}
			}else{
				traversingNode = traversingNode->right;
				while(traversingNode->left != null){
					traversingNode = traversingNode->left;
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

void getSuccessorBSTON(itNode *ptr,itNode **successor,int value){
	if(ptr == null){
		return;
	}
	if(ptr->value > value){
		if(*successor == null){
			*successor = ptr;
		}else{
			*successor = (*successor)->value < ptr->value?*successor:ptr;
		}
	}
	getSuccessorBSTON(ptr->left,successor,value);
	getSuccessorBSTON(ptr->right,successor,value);
}

itNode *getSuccessorBSTReverseInorder(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	static itNode *prevNode = ptr;
	itNode *leftResult = getSuccessorBSTReverseInorder(ptr->right,value);
	if(leftResult != null){
		return leftResult;
	}
	if(ptr->value == value){
		return prevNode;
	}
	prevNode = ptr;
	return getSuccessorBSTReverseInorder(ptr->left,value);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
bool sortFunctionITNode(itNode *firstPtr,itNode *secondPtr){
	return firstPtr->value < secondPtr->value?true:false;
}

itNode *getSuccessorONLOGN(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	vector<itNode *> preOrderNodes;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderValues(ptr,preOrderNodes);
	sort(preOrderNodes.begin(),preOrderNodes.end(),sortFunctionITNode);
	for(unsigned int counter = 0;counter < preOrderNodes.size()-1;counter++){
		if(preOrderNodes[counter]->value == value){
			return preOrderNodes[counter+1];
		}
	}
	return null;
}

#endif /* SUCCESSORBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
