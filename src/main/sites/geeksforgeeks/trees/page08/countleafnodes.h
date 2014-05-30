/****************************************************************************************************************************************************
 *  File Name   		: countleafnodes.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\countleafnodes.h
 *  Created on			: Apr 28, 2014 :: 1:12:00 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/
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

#ifndef COUNTLEAFNODES_H_
#define COUNTLEAFNODES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int countLeafNodesPreOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	if(ptr->left == null && ptr->right == null){
		return 1;
	}
	return countLeafNodesPreOrder(ptr->left) + countLeafNodesPreOrder(ptr->right);
}

//Tested
unsigned int countLeafNodesInOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return countLeafNodesInOrder(ptr->left) + (ptr->left == null && ptr->right == null?1:0) + countLeafNodesInOrder(ptr->right);
}

//Tested
unsigned int countLeafNodesPostOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return countLeafNodesPostOrder(ptr->left) + countLeafNodesPostOrder(ptr->right) + (ptr->left == null && ptr->right == null?1:0);
}

//Tested
unsigned int countLeafNodesPreOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	unsigned int counterLeafNodes = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->left == null && currentNode->right == null){
			counterLeafNodes += 1;
		}else{
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
		}
	}
	return counterLeafNodes;
}

//Tested
unsigned int countLeafNodesMorrisPreOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	itNode *traversalNode = ptr,*temp,*lastNode;
	unsigned int counterLeafNode = 0;
	while(traversalNode != null){
		lastNode = traversalNode;
		if(traversalNode->left != null){
			temp = traversalNode->left;
			while(temp->right != null && temp->right != traversalNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = traversalNode;
				traversalNode = traversalNode->left;
			}else{
				temp->right = null;
				if(temp->left == null){
					counterLeafNode += 1;
				}
				traversalNode = traversalNode->right;
			}
		}else{
			traversalNode = traversalNode->right;
		}
	}
	return lastNode->left == null?counterLeafNode+1:counterLeafNode; // Adding one because of last node
}

//Tested
unsigned int countLeafNodesInOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	unsigned int counterLeafNodes = 0;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->left == null && currentNode->right == null){
				counterLeafNodes += 1;
			}
			currentNode = currentNode->right;
		}
	}
	return counterLeafNodes;
}

//Tested
unsigned int countLeafNodesInOrderMorrisOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	itNode *traversalNode = ptr,*temp,*lastNode;
	unsigned int leafNodesCounter = 0;
	while(traversalNode != null){
		lastNode = traversalNode;
		if(traversalNode->left != null){
			temp = traversalNode->left;
			while(temp->right != null && temp->right != traversalNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = traversalNode;
				traversalNode = traversalNode->left;
			}else{
				temp->right = null;
				if(temp->left == null){
					leafNodesCounter += 1;
				}
				traversalNode = traversalNode->right;
			}
		}else{
			traversalNode = traversalNode->right;
		}
	}
	return lastNode->left == null?leafNodesCounter+1:leafNodesCounter; // Adding one because of last node
}

//Tested
unsigned int countPostOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	primaryAuxspace.push(ptr);
	itNode *currentTopNode;
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
	unsigned int counterLeafNodes = 0;
	while(!secondaryAuxspace.empty()){
		currentTopNode = secondaryAuxspace.top();
		if(currentTopNode->left == null && currentTopNode->right == null){
			counterLeafNodes += 1;
		}
		secondaryAuxspace.pop();
	}
	return counterLeafNodes;
}

//Tested
unsigned int countPostOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	unsigned int counterLeafNode = 0;
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
			if(!auxSpace.empty() && auxSpace.top() ==  currentNode->right){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				if(currentNode->left == null && currentNode->right == null){
					counterLeafNode += 1;
				}
				currentNode = null;
			}
		}
	}
	return counterLeafNode;
}

//Tested
unsigned int countLeavesPostOrderIterativeV2(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	unsigned int leafCounter = 0;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->left == null && currentNode->right == null){
				leafCounter += 1;
			}
			while(!auxSpace.empty() && currentNode == auxSpace.top()->right){
				currentNode = auxSpace.top();
				if(currentNode->left == null && currentNode->right == null){
					leafCounter += 1;
				}
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	return leafCounter;
}

//Tested
unsigned int treeLeafCounterHashmap(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap,tempItToLeftSubTreeIndexNodeMap,tempItToRightSubTreeIndexNodeMap;
	unsigned int leafNodeCounter = 0,currentNodeIndex;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNodeIndex = itToIndexNodeMap->first;
		tempItToLeftSubTreeIndexNodeMap = indexNodeMap.find(2*currentNodeIndex);
		tempItToRightSubTreeIndexNodeMap = indexNodeMap.find(2*currentNodeIndex + 1);
		if(tempItToLeftSubTreeIndexNodeMap == indexNodeMap.end() && tempItToRightSubTreeIndexNodeMap == indexNodeMap.end()){
			leafNodeCounter += 1;
		}
	}
	return leafNodeCounter;
}

//Tested
unsigned int leafCounterLevelOrderTraversal(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	queue<itNode *> auxSpace;
	itNode *currentFrontNode;
	unsigned int leafCounter = 0;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentFrontNode = auxSpace.front();
		auxSpace.pop();
		if(currentFrontNode->left == null && currentFrontNode->right == null){
			leafCounter += 1;
		}else{
			if(currentFrontNode->left != null){
				auxSpace.push(currentFrontNode->left);
			}
			if(currentFrontNode->right != null){
				auxSpace.push(currentFrontNode->right);
			}
		}
	}
	return leafCounter;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int leafLevelCounter(itNode *ptr,unsigned int levelCounter){
	if(ptr == null){
		return 0;
	}
	if(levelCounter == 0){
		return ptr->left == null && ptr->right == null?1:0;
	}
	return leafLevelCounter(ptr->left,levelCounter-1) + leafLevelCounter(ptr->right,levelCounter-1);
}

//Tested
unsigned int countLeafCounterON2(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	unsigned int heightOfTree = utils->heightOfTree(ptr);
	unsigned int counterLeafNodes = 0;
	for(unsigned int counter = 0;counter < heightOfTree;counter++){
		counterLeafNodes += leafLevelCounter(ptr,counter);
	}
	return counterLeafNodes;
}

#endif /* COUNTLEAFNODES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
