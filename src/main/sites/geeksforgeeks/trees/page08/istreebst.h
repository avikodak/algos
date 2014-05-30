/****************************************************************************************************************************************************
 *  File Name   		: istreebst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\istreebst.h
 *  Created on			: May 1, 2014 :: 9:15:29 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
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

#ifndef ISTREEBST_H_
#define ISTREEBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isTreeBSTON(itNode *ptr,int minValue = INT_MIN,int maxValue = INT_MAX){
	if(ptr == null){
		return true;
	}
	if(ptr->value < minValue || ptr->value > maxValue){
		return false;
	}
	return isTreeBSTON(ptr->left,minValue,ptr->value) && isTreeBSTON(ptr->right,ptr->value,maxValue);
}

//Tested
bool isTreeBSTInOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return true;
	}
	stack<itNode *> auxSpace;
	itNode *traversingNode = ptr;
	itNode *prevNode = null;
	while(!auxSpace.empty() || traversingNode != null){
		if(traversingNode != null){
			auxSpace.push(traversingNode);
			traversingNode = traversingNode->left;
		}else{
			traversingNode = auxSpace.top();
			auxSpace.pop();
			if(prevNode != null){
				if(prevNode->value > traversingNode->value){
					return false;
				}
			}
			prevNode = traversingNode;
			traversingNode = traversingNode->right;
		}
	}
	return true;
}

//Tested
bool isTreeBSTInOrderMorrisTraversal(itNode *ptr){
	if(ptr == null){
		return true;
	}
	itNode *traversingNode = ptr,*temp,*prevInOrderNode = null;
	while(traversingNode != null){
		if(traversingNode->left != null){
			temp = traversingNode->left;
			while(temp->right != null && temp->right != traversingNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = traversingNode;
				traversingNode = traversingNode->left;
			}else{
				temp->right = null;
				if(prevInOrderNode != null){
					if(prevInOrderNode->value > traversingNode->value){
						return false;
					}
				}
				prevInOrderNode = traversingNode;
				traversingNode = traversingNode->right;
			}
		}else{
			if(prevInOrderNode != null){
				if(prevInOrderNode->value > traversingNode->value){
					return false;
				}
			}
			prevInOrderNode = traversingNode;
			traversingNode = traversingNode->right;
		}
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isVectorSorted(vector<int> userInput){
	if(userInput.size() == 0){
		return true;
	}
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] < userInput[counter-1]){
			return false;
		}
	}
	return true;
}

//Tested
bool isTreeBSTONLOGN(itNode *ptr){
	if(ptr == null){
		return true;
	}
	vector<int> inOrderValues;
	treeutils *utils = new treeutils();
	utils->setVectorWithInOrderValues(ptr,inOrderValues);
	return isVectorSorted(inOrderValues);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool checkValuesInTreeForConstraint(itNode *ptr,int key,bool lessThanConstraint = true){
	if(ptr == null){
		return true;
	}
	if(lessThanConstraint){
		if(ptr->value > key){
			return false;
		}
	}else{
		if(ptr->value < key){
			return false;
		}
	}
	return checkValuesInTreeForConstraint(ptr->left,key,lessThanConstraint) && checkValuesInTreeForConstraint(ptr->right,key,lessThanConstraint);
}

//Tested
bool isTreeBSTON2(itNode *ptr){
	if(ptr == null){
		return true;
	}
	if(!checkValuesInTreeForConstraint(ptr->left,ptr->value,true) || !checkValuesInTreeForConstraint(ptr->right,ptr->value,false)){
		return false;
	}
	return isTreeBSTON2(ptr->left) && isTreeBSTON2(ptr->right);
}

#endif /* ISTREEBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
