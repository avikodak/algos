/****************************************************************************************************************************************************
 *  File Name   		: checkchildrensumproperty.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\checkchildrensumproperty.h
 *  Created on			: Apr 29, 2014 :: 8:01:18 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/
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

#ifndef CHECKCHILDRENSUMPROPERTY_H_
#define CHECKCHILDRENSUMPROPERTY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool checkChildrenSumPropertyPreorder(itNode *ptr){
	if(ptr == null || (ptr->left == null && ptr->right == null)){
		return true;
	}
	return ptr->value == (ptr->left==null?0:ptr->left->value)+(ptr->right == null?0:ptr->right->value) && checkChildrenSumPropertyPreorder(ptr->left) && checkChildrenSumPropertyPreorder(ptr->right);
}

//Tested
bool checkChildrenSumPropertyPostOrder(itNode *ptr){
	if(ptr == null || (ptr->left == null && ptr->right == null)){
		return true;
	}
	return checkChildrenSumPropertyPostOrder(ptr->left) && checkChildrenSumPropertyPostOrder(ptr->right) && ptr->value == (ptr->left==null?0:ptr->left->value)+(ptr->right==null?0:ptr->right->value);
}

//Tested
bool checkChildrenSumPropertyInOrder(itNode *ptr){
	if(ptr == null || (ptr->left == null && ptr->right == null)){
		return true;
	}

	return checkChildrenSumPropertyInOrder(ptr->left) && ptr->value == (ptr->left==null?0:ptr->left->value)+(ptr->right==null?0:ptr->right->value) && checkChildrenSumPropertyInOrder(ptr->right);
}

//Tested
bool checkChildrenSumPropertyPreorderIterative(itNode *ptr){
	if(ptr == null){
		return true;
	}
	stack<itNode *> auxSpace;
	itNode *currentTopNode;
	auxSpace.push(ptr);
	int childrenSum = 0;
	while(!auxSpace.empty()){
		currentTopNode = auxSpace.top();
		auxSpace.pop();
		childrenSum = 0;
		if(currentTopNode->right != null){
			auxSpace.push(currentTopNode->right);
			childrenSum += currentTopNode->right->value;
		}
		if(currentTopNode->left != null){
			auxSpace.push(currentTopNode->left);
			childrenSum += currentTopNode->left->value;
		}
		if(!(currentTopNode->left == null && currentTopNode->right == null)){
			if(childrenSum != currentTopNode->value){
				return false;
			}
		}
	}
	return true;
}

//Tested
bool checkChildrenSumPropertyPostOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return true;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	primaryAuxspace.push(ptr);
	itNode *currentTopNode;
	int childrenSum;
	while(!primaryAuxspace.empty()){
		currentTopNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentTopNode);
		if(currentTopNode->left != null){
			primaryAuxspace.push(currentTopNode->left);
		}
		if(currentTopNode->right != null){
			primaryAuxspace.push(currentTopNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		currentTopNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		childrenSum = 0;
		childrenSum += currentTopNode->left == null?0:currentTopNode->left->value;
		childrenSum += currentTopNode->right == null?0:currentTopNode->right->value;
		if(!(currentTopNode->left == null && currentTopNode->right == null)){
			if(childrenSum != currentTopNode->value){
				return false;
			}
		}
	}
	return true;
}

//Tested
bool checkChildrenSumPropertyPostOrderIterative(itNode *ptr){
	if(ptr == null){
		return true;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	int childrenSum;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(!auxSpace.empty() && auxSpace.top() == currentNode->right){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				childrenSum = 0;
				childrenSum += currentNode->left == null?0:currentNode->left->value;
				childrenSum += currentNode->right == null?0:currentNode->right->value;
				if(!(currentNode->left == null && currentNode->right == null)){
					if(childrenSum != currentNode->value){
						return false;
					}
				}
				currentNode = null;
			}
		}
	}
	return true;
}

//Tested
bool checkPropertyForNode(itNode *ptr){
	if(ptr == null || (ptr->left == null && ptr->right == null)){
		return true;
	}
	int sumOfChildren = 0;
	if(ptr->left != null){
		sumOfChildren += ptr->left->value;
	}
	if(ptr->right != null){
		sumOfChildren += ptr->right->value;
	}
	return ptr->value == sumOfChildren;
}

//Tested
bool checkChildrenSumPropertyPostOrderIterativeV2(itNode *ptr){
	if(ptr == null){
		return true;
	}
	stack<itNode *> auxSpace;
	itNode *traversingNode = ptr;
	while(!auxSpace.empty() || traversingNode != null){
		while(traversingNode != null){
			auxSpace.push(traversingNode);
			traversingNode = traversingNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			traversingNode = auxSpace.top();
			auxSpace.pop();
			if(!checkPropertyForNode(traversingNode)){
				return false;
			}
			while(!auxSpace.empty() && auxSpace.top()->right == traversingNode){
				traversingNode = auxSpace.top();
				auxSpace.pop();
				if(!checkPropertyForNode(traversingNode)){
					return false;
				}
			}
		}
		traversingNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	return true;
}

//Tested
bool checkChildrenSumPropertyLevelOrder(itNode *ptr){
	if(ptr == null){
		return true;
	}
	queue<itNode *> auxSpace;
	auxSpace.push(ptr);
	itNode *currentFrontNode;
	int childrenSum;
	while(!auxSpace.empty()){
		currentFrontNode = auxSpace.front();
		auxSpace.pop();
		childrenSum = 0;
		if(currentFrontNode->left != null){
			childrenSum += currentFrontNode->left->value;
			auxSpace.push(currentFrontNode->left);
		}
		if(currentFrontNode->right != null){
			childrenSum += currentFrontNode->right->value;
			auxSpace.push(currentFrontNode->right);
		}
		if(!(currentFrontNode->left == null && currentFrontNode->right == null)){
			if(childrenSum != currentFrontNode->value){
				return false;
			}
		}
	}
	return true;
}

//Tested
bool checkChildrenSumPropertyHashmap(itNode *ptr){
	if(ptr == null){
		return true;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap,itToLeftIndexNodeMap,itToRightIndexNodeMap;
	int childrenSum;
	unsigned int currentNodeIndex;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNodeIndex = itToIndexNodeMap->first;
		itToLeftIndexNodeMap = indexNodeMap.find(2*currentNodeIndex);
		itToRightIndexNodeMap = indexNodeMap.find(2*currentNodeIndex+1);
		if(itToLeftIndexNodeMap != indexNodeMap.end() || itToRightIndexNodeMap != indexNodeMap.end()){
			childrenSum = 0;
			if(itToLeftIndexNodeMap != indexNodeMap.end()){
				childrenSum += itToLeftIndexNodeMap->second->value;
			}
			if(itToRightIndexNodeMap != indexNodeMap.end()){
				childrenSum += itToRightIndexNodeMap->second->value;
			}
			if(itToIndexNodeMap->second->value != childrenSum){
				return false;
			}
		}
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool checkChildrenSumPropertyAtLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return true;
	}
	if(level == 0){
		int childrenSum = 0;
		childrenSum += ptr->left == null?0:ptr->left->value;
		childrenSum += ptr->right == null?0:ptr->right->value;
		if(!(ptr->left == null && ptr->right == null)){
			return childrenSum != ptr->value?false:true;
		}else{
			return true;
		}
	}
	return checkChildrenSumPropertyAtLevel(ptr->left,level-1) && checkChildrenSumPropertyAtLevel(ptr->right,level-1);
}

//Tested
bool checkChildrenSumPropertyLevelOrderON2(itNode *ptr){
	if(ptr == null){
		return true;
	}
	treeutils *utils = new treeutils();
	unsigned int heightOfTree = utils->heightOfTree(ptr);
	for(unsigned int level = 0;level < heightOfTree;level++){
		if(!checkChildrenSumPropertyAtLevel(ptr,level)){
			return false;
		}
	}
	return true;
}

#endif /* CHECKCHILDRENSUMPROPERTY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
