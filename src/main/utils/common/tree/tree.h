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

	//Tested
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

	//Tested
	void getFBSTFromVectorMain(iftNode **ptr,iftNode *currentNode,vector<int> userInput,unsigned int currentIndex){
		if(userInput.size() == 0 || currentIndex >= userInput.size()){
			return;
		}
		if(*ptr == null){
			(*ptr) = new iftNode(userInput[currentIndex]);
			getFBSTFromVectorMain(ptr,*ptr,userInput,currentIndex+1);
		}else{
			if(currentNode->value == userInput[currentIndex]){
				currentNode->frequency += 1;
				getFBSTFromVectorMain(ptr,*ptr,userInput,currentIndex+1);
			}else{
				if(currentNode->value > userInput[currentIndex]){
					if(currentNode->left == null){
						currentNode->left = new iftNode(userInput[currentIndex]);
						getFBSTFromVectorMain(ptr,*ptr,userInput,currentIndex+1);
					}else{
						getFBSTFromVectorMain(ptr,currentNode->left,userInput,currentIndex);
					}
				}else{
					if(currentNode->right == null){
						currentNode->right = new iftNode(userInput[currentIndex]);
						getFBSTFromVectorMain(ptr,*ptr,userInput,currentIndex+1);
					}else{
						getFBSTFromVectorMain(ptr,currentNode->right,userInput,currentIndex);
					}
				}
			}
		}
	}

	void getFBSTFromSillMain(iftNode **ptr,iftNode *currentNode,sillNode *ptr){
		if(ptr == null){
			return;
		}
	}

	//Tested
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

	//Tested
	iftNode *getNodeForInsertionInFBST(iftNode *ptr,int value){
		if(ptr == null){
			return null;
		}
		if(ptr->value == value){
			return ptr;
		}
		if(ptr->value > value){
			if(ptr->left == null){
				return ptr;
			}else{
				return getNodeForInsertionInFBST(ptr->left,value);
			}
		}else{
			if(ptr->right == null){
				return ptr;
			}else{
				return getNodeForInsertionInFBST(ptr->right,value);
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

	//Tested
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

	//Tested
	itNode *getBSTTreeFromVector(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		itNode *rootBST = null;
		getBSTFromVectorMain(&rootBST,rootBST,userInput,0);
		return rootBST;
	}

	//Tested
	iftNode *getFBSTreeFromVector(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		iftNode *rootFBST = null;
		getFBSTFromVectorMain(&rootFBST,rootFBST,userInput,0);
		return rootFBST;
	}

	//Tested
	iftNode *getFBSTreeFromVectorIterative(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		iftNode *rootFBST = new iftNode(userInput[0]),*nodeForInsertion;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			nodeForInsertion = getNodeForInsertionInFBST(rootFBST,userInput[counter]);
			if(nodeForInsertion->value == userInput[counter]){
				nodeForInsertion->frequency += 1;
			}else{
				if(nodeForInsertion->value > userInput[counter]){
					nodeForInsertion->left = new iftNode(userInput[counter]);
				}else{
					nodeForInsertion->right = new iftNode(userInput[counter]);
				}
			}
		}
		return rootFBST;
	}

	iftNode *getFBSTFromSill(sillNode *ptr){
		if(ptr == null){
			return null;
		}
		iftNode *rootFBST = null;
		getFBSTFromSillMain(&rootFBST,rootFBST,ptr);
		return rootFBST;
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

	//Tested
	void preOrderTraversalIFBST(iftNode *ptr){
		if(ptr == null){
			return;
		}
		printf("%d|%d\t",ptr->value,ptr->frequency);
		preOrderTraversalIFBST(ptr->left);
		preOrderTraversalIFBST(ptr->right);
	}

	//Tested
	void inOrderTraversalIFBST(iftNode *ptr){
		if(ptr == null){
			return;
		}
		inOrderTraversalIFBST(ptr->left);
		printf("%d|%d\t",ptr->value,ptr->frequency);
		inOrderTraversalIFBST(ptr->right);
	}

	//Tested
	void postOrderTraversalIFBST(iftNode *ptr){
		if(ptr == null){
			return;
		}
		postOrderTraversalIFBST(ptr->left);
		postOrderTraversalIFBST(ptr->right);
		printf("%d|%d\t",ptr->value,ptr->frequency);
	}

	//Tested
	void setVectorWithPreOrderNodes(itNode *ptr,vector<itNode *>  &preOrderNodes){
		if(ptr == null){
			return;
		}
		preOrderNodes.push_back(ptr);
		setVectorWithPreOrderNodes(ptr->left,preOrderNodes);
		setVectorWithPreOrderNodes(ptr->right,preOrderNodes);
	}

	//Tested
	void setVectorWithInOrderNodes(itNode *ptr,vector<itNode *> &inOrderNodes){
		if(ptr == null){
			return;
		}
		setVectorWithInOrderNodes(ptr->left,inOrderNodes);
		inOrderNodes.push_back(ptr);
		setVectorWithInOrderNodes(ptr->right,inOrderNodes);
	}

	//Tested
	void setVectorWithPostOrderNodes(itNode *ptr,vector<itNode *> &postOrderNodes){
		if(ptr == null){
			return;
		}
		setVectorWithPostOrderNodes(ptr->left,postOrderNodes);
		setVectorWithPostOrderNodes(ptr->right,postOrderNodes);
		postOrderNodes.push_back(ptr);
	}

	//Tested
	itHashmap *getHashmapFormITree(itNode *ptr,bool defaultIndex = true){
		if(ptr == null){
			return null;
		}
		hash_map<unsigned int,itNode *> indexNodeMap;
		hash_map<uint32_t,unsigned int> nodeIndexMap;
		hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
		hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
		queue<itNode *> auxSpace;
		itNode *currentFrontNodeInQueue;
		unsigned int currentNodeIndex;
		auxSpace.push(ptr);
		if(defaultIndex){
			indexNodeMap.insert(pair<unsigned int,itNode *>(0,ptr));
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,0));
		}else{
			indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
		}
		while(!auxSpace.empty()){
			currentFrontNodeInQueue = auxSpace.front();
			auxSpace.pop();
			currentNodeIndex = nodeIndexMap.find((uint32_t)currentFrontNodeInQueue)->second;
			if(currentFrontNodeInQueue->left != null){
				if(defaultIndex){
					indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentNodeIndex+1,currentFrontNodeInQueue->left));
					nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentFrontNodeInQueue->left,2*currentNodeIndex+1));
				}else{
					indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentNodeIndex,currentFrontNodeInQueue->left));
					nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentFrontNodeInQueue->left,2*currentNodeIndex));
				}
				auxSpace.push(currentFrontNodeInQueue->left);
			}
			if(currentFrontNodeInQueue->right != null){
				if(defaultIndex){
					indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentNodeIndex+2,currentFrontNodeInQueue->right));
					nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentFrontNodeInQueue->right,2*currentNodeIndex+2));
				}else{
					indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentNodeIndex+1,currentFrontNodeInQueue->right));
					nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentFrontNodeInQueue->right,2*currentNodeIndex+1));
				}
				auxSpace.push(currentFrontNodeInQueue->right);
			}
		}
		/*for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
			printf("%d - %d\n",itToIndexNodeMap->first,itToIndexNodeMap->second->value);
		}
		for(itToNodeIndexMap = nodeIndexMap.begin();itToNodeIndexMap != nodeIndexMap.end();itToNodeIndexMap++){
			printf("%d - %d\n",((itNode *)itToNodeIndexMap->first)->value,itToNodeIndexMap->second);
		}*/
		itHashmap *hashMap = new itHashmap();
		hashMap->indexNodeMap = indexNodeMap;
		hashMap->nodeIndexMap = nodeIndexMap;
		return hashMap;
	}
};

#endif /* TREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
