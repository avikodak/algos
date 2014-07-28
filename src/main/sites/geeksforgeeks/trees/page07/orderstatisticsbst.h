/****************************************************************************************************************************************************
 *  File Name   		: orderstatisticsbst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page07\orderstatisticsbst.h
 *  Created on			: May 8, 2014 :: 11:46:28 PM
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

#ifndef ORDERSTATISTICSBST_H_
#define ORDERSTATISTICSBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *getKthSmallestNodeBST(itNode *ptr,unsigned int &kValue){
	if(ptr == null){
		return null;
	}
	itNode *leftSubtree = getKthSmallestNodeBST(ptr->left,kValue);
	if(kValue == 0){
		return ptr;
	}
	kValue -= 1;
	return getKthSmallestNodeBST(ptr->right,kValue);
}

itNode *getKthSmallestNodeBSTIterative(itNode *ptr,unsigned int kValue){
	if(ptr == null){
		return null;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			if(kValue == 0){
				return currentNode;
			}
			kValue--;
			currentNode = currentNode->right;
		}
	}
	return null;
}

itNode *getKthSmallestNodeBSTMorris(itNode *ptr,unsigned int kValue){
	if(ptr == null){
		return null;
	}
	itNode *currentNode = ptr,*temp;
	while(currentNode != null){
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				if(kValue == 0){
					return currentNode;
				}
				kValue--;
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				currentNode = currentNode->right;
			}
		}else{
			if(kValue == 0){
				return currentNode;
			}
			kValue--;
			currentNode = currentNode->right;
		}
	}
	return null;
}

itNode *getKthSmallestNodeBSTDLLONMain(itNode **root,itNode *ptr){
	if(*root == null || ptr == null){
		return null;
	}
	static itNode *prevNode = null;
	getKthSmallestNodeBSTDLLONMain(root,ptr->left);
	if(prevNode == null){
		*root = ptr;
	}else{
		prevNode->right = ptr;
	}
	ptr->left = prevNode;
	prevNode = ptr;
	getKthSmallestNodeBSTDLLONMain(root,ptr->right);
}

itNode *getKthSmallestNodeBSTDLLON(itNode *ptr,int kthValue){
	if(ptr == null || kthValue == 0){
		return null;
	}
	getKthSmallestNodeBSTDLLONMain(&ptr,ptr);
	while(ptr != null && kthValue > 0){
		kthValue--;
		ptr = ptr->right;
	}
	return ptr;
}

void gknFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	gknFixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	gknFixLeftPtr(ptr->right);
}

void gknFixRightPtr(itNode **ptr){
	if(*ptr == null){
		return;
	}
	itNode *traversalNode = *ptr;
	while(traversalNode->right != null){
		traversalNode = traversalNode->right;
	}
	itNode *prevNode = ptr;
	while(traversalNode!= null){
		traversalNode->right = prevNode;
		prevNode = traversalNode;
		traversalNode = traversalNode->left;
	}
	(*ptr) = traversalNode;
}

itNode *getKthSmallestNodeBSTDLL(itNode *ptr,unsigned int kthValue){
	if(ptr == null || kthValue == 0){
		return null;
	}
	gknFixLeftPtr(ptr);
	gknFixRightPtr(&ptr);
	while(ptr != null && kthValue > 0){
		ptr = ptr->right;
		kthValue--;
	}
}

itNode *getKthSmallestNodeBSTHashmap(itNode *ptr,unsigned int kthValue){
	if(ptr == null || kthValue == 0){
		return null;
	}
	hash_map<unsigned int,itNode *> inorderindexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToInorderindexNodeMap;
	unsigned int inorderIndex = 0;
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			inorderindexNodeMap.insert(pair<unsigned int,itNode *>(inorderIndex++,currentNode));
			currentNode = currentNode->right;
		}
	}
	itToInorderindexNodeMap = inorderindexNodeMap.find(kthValue);
	return itToInorderindexNodeMap == inorderindexNodeMap.end()?null:itToInorderindexNodeMap->second;
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int getKthSmallestNodeBSTONLOGN(itNode *ptr,unsigned int kValue){
	if(ptr == null || kValue == 0){
		return INT_MIN;
	}
	vector<int> preOrderValues;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderValues(ptr,preOrderValues);
	sort(preOrderValues.begin(),preOrderValues.end());
	return preOrderValues.size() <= kValue?INT_MIN:preOrderValues[kValue];
}
struct iavltNode{
	int value;
	unsigned int height;
	iavltNode *left;
	iavltNode *parent;
	iavltNode *right;

	iavltNode(){

	}

	iavltNode(int value){
		this->value = value;
		height = 1;
		left = null;
		parent = null;
		right = null;
	}
};

void rotateNodes(iavltNode *parent,iavltNode *child){
	iavltNode *grandParent = parent->parent;
	if(grandParent != null){
		child->parent = grandParent;
		if(grandParent->left == parent){
			grandParent->left = child;
		}else{
			grandParent->right = child;
		}
	}else{
		child->parent = null;
	}
	parent->parent = child;
	iavltNode *temp;
	if(parent->left == child){
		temp = child->right;
		child->right = parent;
		parent->left = temp;
	}else{
		temp = child->left;
		child->left = parent;
		parent->right = temp;
	}
}

iavltNode *insertAtRightPlace(iavltNode **root,iavltNode *currentNode,int userInput){
	if(*root == null){
		(*root) = new iavltNode(userInput);
		return *root;
	}else{
		if(currentNode->value == userInput){
			return null;
		}
		if(currentNode->value > userInput){
			if(currentNode->left == null){
				currentNode->left = new iavltNode(userInput);
				currentNode->left->parent = currentNode;
				return currentNode->left;
			}else{
				return insertAtRightPlace(root,currentNode->left,userInput);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new iavltNode(userInput);
				currentNode->right->parent = currentNode;
				return currentNode->right;
			}else{
				return insertAtRightPlace(root,currentNode,userInput);
			}
		}
	}
}

void insertNodeIntoAvlTree(iavltNode **root,int userInput){
	iavltNode *ptrToInsertedNode = insertAtRightPlace(root,*root,userInput);
	if(ptrToInsertedNode == null){
		return;
	}
	iavltNode *z,*y,*x;
	z = ptrToInsertedNode->parent;
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			y = z->value > userInput?z->left:z->right;
			x = y->value > userInput?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y  && y->right == x)){
				if(z->parent == null){
					*root = y;
				}
				rotateNodes(z,y);
			}else{
				if(z->parent == null){
					*root = x;
				}
				rotateNodes(y,x);
				rotateNodes(z,x);
			}
			return;
		}
		z->height = max(leftHeight,rightHeight)+1;
		z = z->parent;
	}
}

int getKNodeInOrder(iavltNode *ptr,unsigned int *kValue){
	if(ptr == null){
		return INT_MIN;
	}
	int leftResult = getKNodeInOrder(ptr->left,kValue);
	if(kValue == 0){
		return ptr->value;
	}
	(*kValue) = (*kValue) + 1;
	return getKNodeInOrder(ptr->right,kValue);
}

int kthOrderStatistics(vector<int> userInput,unsigned int kValue){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	iavltNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		insertNodeIntoAvlTree(&root,userInput[counter]);
	}
	return getKNodeInOrder(root,&kValue);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

itNode *getKthSmallestNodeBSTON2Main(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left != null){
		itNode *leftSubTree = getKthSmallestNodeBSTON2Main(ptr->left);
		while(leftSubTree->right != null){
			leftSubTree = leftSubTree->right;
		}
		leftSubTree->right = ptr;
		ptr->left = leftSubTree;
	}
	if(ptr->right != null){
		itNode *rightSubTree = getKthSmallestNodeBSTDLLONMain(ptr->right);
		while(rightSubTree->left != null){
			rightSubTree = rightSubTree->left;
		}
		rightSubTree->left = ptr;
		ptr->right = rightSubTree;
	}
	return ptr;
}

itNode *getKthSmallNodeBSTON2(itNode *ptr,int kValue){
	if(ptr == null || kValue){
		return null;
	}
	getKthSmallestNodeBSTON2Main(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	while(ptr != null && kValue > 0){
		ptr = ptr->right;
		kValue -= 1;
	}
	return ptr;
}

#endif /* ORDERSTATISTICSBST_H_ */


/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
