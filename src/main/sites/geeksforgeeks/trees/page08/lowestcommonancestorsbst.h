/****************************************************************************************************************************************************
 *  File Name   		: lowestcommonancestorsbst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\lowestcommonancestorsbst.h
 *  Created on			: Apr 22, 2014 :: 11:50:36 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
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

#ifndef LOWESTCOMMONANCESTORSBST_H_
#define LOWESTCOMMONANCESTORSBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *lowestCommonAncestors(itNode *ptr,int lowValue,int highValue){
	if(ptr == null){
		return null;
	}
	if(ptr->value >= lowValue && ptr->value >= highValue){
		return lowestCommonAncestors(ptr->left,lowValue,highValue);
	}
	if(ptr->value <= lowValue && ptr->value <= highValue){
		return lowestCommonAncestors(ptr->right,lowValue,highValue);
	}
	return ptr;
}

//Tested
itNode *lowestCommonAncestorsIterative(itNode *ptr,int lowValue,int highValue){
	if(ptr == null){
		return null;
	}
	itNode *traversalNode = ptr;
	while(traversalNode != null){
		if(traversalNode->value >=lowValue && traversalNode->value <= highValue){
			return traversalNode;
		}
		if(traversalNode->value >= lowValue && traversalNode->value >= highValue){
			traversalNode = traversalNode->left;
		}else if(traversalNode->value <= lowValue && traversalNode->value <= highValue){
			traversalNode = traversalNode->right;
		}
	}
	return null;
}

//Tested
iptNode *getNodeAndSetHeightBST(iptNode *ptr,int key,unsigned int *heightOfNode){
	if(ptr == null){
		*heightOfNode = 0;
		return null;
	}
	if(ptr->value == key){
		return ptr;
	}
	*heightOfNode += 1;
	if(ptr->value > key){
		return getNodeAndSetHeightBST(ptr->left,key,heightOfNode);
	}else{
		return getNodeAndSetHeightBST(ptr->right,key,heightOfNode);
	}
}

//Tested
iptNode *lowestCommonAncestorsParent(iptNode *ptr,int lowValue,int highValue){
	if(ptr == null){
		return null;
	}
	iptNode *ptrToLowerValue,*ptrToHigherValue;
	unsigned int heightOfLowerValueKey = 0,heightOfUpperValueKey = 0;
	ptrToLowerValue = getNodeAndSetHeightBST(ptr,lowValue,&heightOfLowerValueKey);
	ptrToHigherValue = getNodeAndSetHeightBST(ptr,highValue,&heightOfUpperValueKey);
	if(ptrToLowerValue == null || ptrToHigherValue == null){
		throw "Nodes do not exists in tree";
	}
	if(heightOfLowerValueKey > heightOfUpperValueKey){
		while(heightOfLowerValueKey > heightOfUpperValueKey){
			ptrToLowerValue = ptrToLowerValue->parent;
			heightOfLowerValueKey--;
		}
	}else{
		while(heightOfUpperValueKey > heightOfLowerValueKey){
			ptrToHigherValue = ptrToHigherValue->parent;
			heightOfUpperValueKey--;
		}
	}
	while(ptrToLowerValue != ptrToHigherValue){
		ptrToLowerValue = ptrToLowerValue->parent;
		ptrToHigherValue = ptrToHigherValue->parent;
	}
	return ptrToLowerValue;
}

//Tested
void setAncestorsForKeyBST(itNode *ptr,int key,stack<itNode *> &ancestors){
	if(ptr == null){
		while(!ancestors.empty()){
			ancestors.pop();
		}
		return;
	}
	ancestors.push(ptr);
	if(ptr->value == key){
		return;
	}
	if(ptr->value > key){
		setAncestorsForKeyBST(ptr->left,key,ancestors);
	}else{
		setAncestorsForKeyBST(ptr->right,key,ancestors);
	}
}

//Tested
itNode *getAncestorsForValueBSTAuxspace(itNode *ptr,int lowerValue,int higherValue){
	if(ptr == null){
		return null;
	}
	stack<itNode *> lowerValueAncestors,higherValueAncestors;
	setAncestorsForKeyBST(ptr,lowerValue,lowerValueAncestors);
	setAncestorsForKeyBST(ptr,higherValue,higherValueAncestors);
	if(lowerValueAncestors.size() == 0 || higherValueAncestors.size() == 0){
		throw "Values are not present in the binary search tree";
	}
	if(lowerValueAncestors.size() > higherValueAncestors.size()){
		while(lowerValueAncestors.size() > higherValueAncestors.size()){
			lowerValueAncestors.pop();
		}
	}else{
		while(higherValueAncestors.size() > lowerValueAncestors.size()){
			higherValueAncestors.pop();
		}
	}
	while(lowerValueAncestors.top() != higherValueAncestors.top()){
		lowerValueAncestors.pop();
		higherValueAncestors.pop();
	}
	return lowerValueAncestors.top();
}

//Tested
void setQueueWithAncestors(stack<itNode *> auxSpace,queue<itNode *> &ancestors,itNode *currentNode){
	if(currentNode == null){
		throw "Invalid inputs";
	}
	ancestors.push(currentNode);
	while(!auxSpace.empty()){
		ancestors.push(auxSpace.top());
		auxSpace.pop();
	}
}

//Tested
itNode *getAncestorsForValuesBSTPostOrder(itNode *ptr,int lowerValue,int higherValue){
	if(ptr == null){
		return null;
	}
	stack<itNode *> auxSpace;
	queue<itNode *> ancestorsLowerValue,ancestorsHigherValue;
	itNode *currentNode = ptr;
	unsigned int noOfNodesFound;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			if(currentNode->value == lowerValue || currentNode->value == higherValue){
				if(currentNode->value == lowerValue){
					setQueueWithAncestors(auxSpace,ancestorsLowerValue,currentNode);
				}else{
					setQueueWithAncestors(auxSpace,ancestorsHigherValue,currentNode);
				}
				noOfNodesFound += 1;
				if(noOfNodesFound == 2){
					break;
				}
			}
			auxSpace.pop();
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				if(currentNode->value == lowerValue || currentNode->value == higherValue){
					if(currentNode->value == lowerValue){
						setQueueWithAncestors(auxSpace,ancestorsLowerValue,currentNode);
					}else{
						setQueueWithAncestors(auxSpace,ancestorsHigherValue,currentNode);
					}
					noOfNodesFound += 1;
					if(noOfNodesFound == 2){
						break;
					}
				}
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	if(ancestorsLowerValue.empty() || ancestorsHigherValue.empty()){
		return null;
	}
	if(ancestorsLowerValue.size() >ancestorsHigherValue.size()){
		while(ancestorsLowerValue.size() != ancestorsHigherValue.size()){
			ancestorsLowerValue.pop();
		}
	}else if(ancestorsLowerValue < ancestorsHigherValue){
		while(ancestorsLowerValue.size() != ancestorsHigherValue.size()){
			ancestorsHigherValue.pop();
		}
	}
	while(!ancestorsLowerValue.empty() && !ancestorsHigherValue.empty()){
		if(ancestorsLowerValue.front() == ancestorsHigherValue.front()){
			return ancestorsLowerValue.front();
		}
		ancestorsLowerValue.pop();
		ancestorsHigherValue.pop();
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool checkForValueInSubTree(itNode *ptr,int key){
	if(ptr == null){
		return false;
	}
	if(ptr->value == key){
		return true;
	}
	if(ptr->value > key){
		return checkForValueInSubTree(ptr->left,key);
	}else{
		return checkForValueInSubTree(ptr->right,key);
	}
}

//Tested
itNode *lowestCommonAncestorsON2(itNode *ptr,int lowerValue,int higherValue){
	if(ptr == null){
		return null;
	}
	if((ptr->value == lowerValue || checkForValueInSubTree(ptr->left,lowerValue)) && (ptr->value == higherValue||checkForValueInSubTree(ptr->right,higherValue))){
		return ptr;
	}
	if(ptr->value >= lowerValue && ptr->value >= higherValue){
		return lowestCommonAncestorsON2(ptr->left,lowerValue,higherValue);
	}
	if(ptr->value <= lowerValue && ptr->value <= higherValue){
		return lowestCommonAncestorsON2(ptr->right,lowerValue,higherValue);
	}
	return null;
}

#endif /* LOWESTCOMMONANCESTORSBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
