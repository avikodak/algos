/****************************************************************************************************************************************************
 *  File Name   		: tree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\utils\common\tree\tree.h
 *  Created on			: Apr 10, 2014 :: 3:42:40 AM
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
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TREE_H_
#define TREE_H_

class treeutils{

private:
	//Tested
	itNode *getITreeFromVectorMain(vector<int> userInput,unsigned int currentIndex){
		if(userInput.size() == 0 || currentIndex >= userInput.size()){
			return null;
		}
		itNode *node = getNewITreeNode(userInput[currentIndex]);
		node->left = getITreeFromVectorMain(userInput,2*currentIndex + 1);
		node->right = getITreeFromVectorMain(userInput,2*currentIndex + 2);
		return node;
	}

	//Tested
	itNode *getITreeFromVectorAuxSpaceMain(vector<int> userInput,queue<itNode *> &levelOrderAuxSpace,unsigned int counter){
		if(userInput.size() == 0 || counter >= userInput.size()){
			return null;
		}
		itNode *newNode = getNewITreeNode(userInput[counter]);
		if(counter != 0){
			if(levelOrderAuxSpace.empty()){
				throw "Queue is empty";
			}
			itNode *currentFNodeInQueue = levelOrderAuxSpace.front();
			if(currentFNodeInQueue->left == NULL){
				currentFNodeInQueue->left = newNode;
			}else if(currentFNodeInQueue->right == NULL){
				currentFNodeInQueue->right = newNode;
				levelOrderAuxSpace.pop();
			}else{
				throw "Illegal node in queue";
			}
		}
		levelOrderAuxSpace.push(newNode);
		getITreeFromVectorAuxSpaceMain(userInput,levelOrderAuxSpace,counter+1);
		return newNode;
	}

	void getBSTFromVectorMain(itNode **ptr,itNode *currentNode,vector<int> userInput,unsigned int currentIndex){
		if(userInput.size() == 0 || currentIndex >= userInput.size()){
			return;
		}
		if(*ptr == NULL){
			(*ptr) = new itNode(userInput[currentIndex]);
			getBSTFromVectorMain(ptr,*ptr,userInput,currentIndex+1);
		}else{
			if(currentNode->value >= userInput[currentIndex]){
				if(currentNode->left == null){
					currentNode->left = new itNode(userInput[currentIndex]);
					getBSTFromVectorMain(ptr,*ptr,userInput,currentIndex+1);
				}else{
					getBSTFromVectorMain(ptr,currentNode->left,userInput,currentIndex);
				}
			}else{
				if(currentNode->right == null){
					currentNode->right = new itNode(userInput[currentIndex]);
					getBSTFromVectorMain(ptr,*ptr,userInput,currentIndex+1);
				}else{
					getBSTFromVectorMain(ptr,currentNode->right,userInput,currentIndex);
				}
			}
		}
	}

	itNode *getParentNodeForInsertionBST(itNode *ptr,int value){
		if(ptr == null){
			return null;
		}
		if(ptr->value >= value){
			if(ptr->left == NULL){
				return ptr;
			}else{
				return getParentNodeForInsertionBST(ptr->left,value);
			}
		}else{
			if(ptr->right == NULL){
				return ptr;
			}else{
				return getParentNodeForInsertionBST(ptr->right,value);
			}
		}
	}
public:
	//Tested
	itNode *getNewITreeNodePtrMethod(int userInput){
		itNode *newNode = (itNode *)malloc(sizeof(itNode *));
		newNode->value = userInput;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	//Tested
	itNode *getNewITreeNode(int userInput){
		return new itNode(userInput);
	}

	//Tested
	itNode *getITreeFromVector(vector<int> userInput){
		if(userInput.size() == 0){
			return NULL;
		}
		return getITreeFromVectorMain(userInput,0);
	}

	//Tested
	itNode *getITreeFromVectorAuxSpaceRecursive(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		queue<itNode *> auxSpace;
		return getITreeFromVectorAuxSpaceMain(userInput,auxSpace,0);
	}

	//Tested
	itNode *getITreeFromVectorAuxSpaceIterative(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		itNode *root = getNewITreeNode(userInput[0]),*currentFNodeInQueue;
		queue<itNode *> levelOrderAuxSpace;
		levelOrderAuxSpace.push(root);
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			if(levelOrderAuxSpace.empty()){
				throw "Queue is empty";
			}
			currentFNodeInQueue = levelOrderAuxSpace.front();
			if(currentFNodeInQueue->left == NULL){
				currentFNodeInQueue->left = getNewITreeNode(userInput[counter]);
				levelOrderAuxSpace.push(currentFNodeInQueue->left);
			}else if(currentFNodeInQueue->right == NULL){
				currentFNodeInQueue->right = getNewITreeNode(userInput[counter]);
				levelOrderAuxSpace.push(currentFNodeInQueue->right);
				levelOrderAuxSpace.pop();
			}else{
				throw "Illegal node in queue";
			}
		}
		return root;
	}

	itNode *getBSTTreeFromVectorIterative(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		itNode *rootBST = new itNode(userInput[0]),*nodeForInsertion;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			nodeForInsertion = getParentNodeForInsertionBST(rootBST,userInput[counter]);
			if(nodeForInsertion->value >= userInput[counter]){
				nodeForInsertion->left = new itNode(userInput[counter]);
			}else{
				nodeForInsertion->right = new itNode(userInput[counter]);
			}
		}
		return rootBST;
	}

	itNode *getBSTTreeFromVector(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		itNode *rootBST = null;
		getBSTFromVectorMain(&rootBST,rootBST,userInput,0);
		return rootBST;
	}

	itNode *searchForNodeBST(itNode *ptr,int value){
		if(ptr == null){
			return null;
		}
		if(ptr->value == value){
			return ptr;
		}
		if(ptr->value > value){
			return searchForNodeBST(ptr->left,value);
		}else{
			return searchForNodeBST(ptr->right,value);
		}
	}

	itNode *searchForNodeBSTIterative(itNode *ptr,int value){
		if(ptr == null){
			return null;
		}
		itNode *traversalNode = ptr;
		while(traversalNode != null){
			if(traversalNode->value == value){
				return traversalNode;
			}
			if(traversalNode->value > value){
				traversalNode = traversalNode->left;
			}else{
				traversalNode = traversalNode->right;
			}
		}
		return null;
	}

	//Tested
	unsigned int heightOfTree(itNode *ptr){
		if(ptr == null){
			return 0;
		}
		return 1 + max(heightOfTree(ptr->left),heightOfTree(ptr->right));
	}

	//Tested
	void preOrderTraversal(itNode *ptr){
		if(ptr == null){
			return;
		}
		printf("%d\t",ptr->value);
		preOrderTraversal(ptr->left);
		preOrderTraversal(ptr->right);
	}

	//Tested
	void postOrderTraversal(itNode *ptr){
		if(ptr == NULL){
			return;
		}
		postOrderTraversal(ptr->left);
		postOrderTraversal(ptr->right);
		printf("%d\t",ptr->value);
	}

	//Tested
	void inOrderTraversal(itNode *ptr){
		if(ptr == NULL){
			return;
		}
		inOrderTraversal(ptr->left);
		printf("%d\t",ptr->value);
		inOrderTraversal(ptr->right);
	}
};

#endif /* TREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
