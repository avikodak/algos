/****************************************************************************************************************************************************
 *  File Name   		: twofourtree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\utils\common\tree\twofourtree.h
 *  Created on			: Jul 3, 2014 :: 11:39:26 PM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL
#define NO_NODE_KEYS 3
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TWOFOURTREE_H_
#define TWOFOURTREE_H_

i24Node *getNodeForInsertion(i24Node *ptr,int value){
	if(ptr == null){
		return null;
	}
	if(ptr->values[0] > value){
		if(ptr->children[0] == null){
			return ptr;
		}else{
			return getNodeForInsertion(ptr->children[0],value);
		}
	}
	if(ptr->values[ptr->fillCount - 1] < value){
		if(ptr->children[ptr->fillCount] == null){
			return ptr;
		}else{
			return getNodeForInsertion(ptr->children[ptr->fillCount],value);
		}
	}
	for(unsigned int counter = 1;counter < NO_NODE_KEYS;counter++){
		if(ptr->values[counter] > value){
			if(ptr->children[counter] == null){
				return ptr;
			}else{
				return getNodeForInsertion(ptr->children[counter],value);
			}
		}
	}
	return null;
}

void insertIntoTwoFourTreeDriver(i24Node **root,i24Node *ptr,int value,i24Node *prevLeftSplitNode = null ,i24Node *prevRightSplitNode = null,i24Node *prevSplitNode = null){
	if(*root == null){
		*root = new i24Node(value);
		return;
	}
	if(ptr == null){
		*root = new i24Node(value);
		if(prevSplitNode != null){
			(*root)->children[0] = prevLeftSplitNode;
			(*root)->children[1] = prevRightSplitNode;
			prevLeftSplitNode->parent = (*root);
			prevRightSplitNode->parent = (*root);
			free(prevSplitNode);
		}
		return;
	}
	if(ptr->fillCount < NO_NODE_KEYS){
		ptr->values[ptr->fillCount] = value;
		int counter = ptr->fillCount - 1;
		while(ptr->values[counter] > value && counter >= 0){
			ptr->values[counter+1] = ptr->values[counter];
			counter--;
		}
		ptr->values[counter+1] = value;
		ptr->fillCount += 1;
		if(prevSplitNode != null){
			unsigned int childrenSetCounter = 0;
			i24Node *temp = null,*temp2;
			for(unsigned int counter = 0;counter <= ptr->fillCount;){
				if(ptr->children[counter] == prevSplitNode){
					ptr->children[childrenSetCounter++] = prevLeftSplitNode;
					ptr->children[childrenSetCounter++] = prevRightSplitNode;
					prevLeftSplitNode->parent = ptr;
					prevRightSplitNode->parent = ptr;
					counter += 2;
				}else{
					if(temp != null){
						temp2 = temp;
						temp = ptr->children[counter];
						ptr->children[childrenSetCounter++] = temp2;
					}else{
						ptr->children[childrenSetCounter++] = ptr->children[counter];
					}
					counter++;
				}
			}
			free(prevSplitNode);
		}
		return;
	}else{
		i24Node *leftSplitNode = new i24Node();
		i24Node *rightSplitNode = new i24Node();
		unsigned int fillCount = 0;
		bool valueFilled = false;
		for(unsigned int counter = 0;counter < NO_NODE_KEYS;counter++){
			if(value < ptr->values[counter] && !valueFilled){
				if(fillCount < ((NO_NODE_KEYS+1)/2)){
					leftSplitNode->values[leftSplitNode->fillCount] = value;
					leftSplitNode->fillCount += 1;
				}else{
					rightSplitNode->values[rightSplitNode->fillCount] = value;
					rightSplitNode->fillCount += 1;
				}
				counter -= 1;
				valueFilled = true;
			}else{
				if(fillCount < ((NO_NODE_KEYS+1)/2)){
					leftSplitNode->values[leftSplitNode->fillCount] = ptr->values[counter];
					leftSplitNode->fillCount += 1;
				}else{
					rightSplitNode->values[rightSplitNode->fillCount] = ptr->values[counter];
					rightSplitNode->fillCount += 1;
				}
			}
			fillCount++;
		}
		if(!valueFilled){
			rightSplitNode->values[rightSplitNode->fillCount] = value;
			rightSplitNode->fillCount += 1;
		}
		if(prevSplitNode != null){
			unsigned int leftChildrenSetCounter = 0,rightChildrenSetCounter = 0,fillCounter = 0;
			bool prevLeftSet = false,prevRightSet = false;
			for(unsigned int counter = 0;counter <= ptr->fillCount;){
				if(ptr->children[counter] == prevSplitNode){
					counter++;
					continue;
				}
				if(fillCounter < (ptr->fillCount+1)/2){
					if(ptr->children[counter]->values[0] > prevLeftSplitNode->values[0] && !prevLeftSet){
						leftSplitNode->children[leftChildrenSetCounter] = prevLeftSplitNode;
						prevLeftSet = true;
						prevLeftSplitNode->parent = leftSplitNode;
					}else if(ptr->children[counter]->values[0] > prevRightSplitNode->values[0] && !prevRightSet){
						leftSplitNode->children[leftChildrenSetCounter] = prevRightSplitNode;
						prevRightSet = true;
						prevRightSplitNode->parent = leftSplitNode;
					}else{
						leftSplitNode->children[leftChildrenSetCounter] = ptr->children[counter];
						leftSplitNode->children[leftChildrenSetCounter]->parent = leftSplitNode;
						counter += 1;
					}
					leftChildrenSetCounter += 1;
				}else{
					if(ptr->children[counter]->values[0] > prevLeftSplitNode->values[0] && !prevLeftSet){
						rightSplitNode->children[rightChildrenSetCounter] = prevLeftSplitNode;
						prevLeftSet = true;
						prevLeftSplitNode->parent = rightSplitNode;
					}else if(ptr->children[counter]->values[0] > prevRightSplitNode->values[0] && !prevRightSet){
						rightSplitNode->children[rightChildrenSetCounter] = prevRightSplitNode;
						prevRightSet = true;
						prevRightSplitNode->parent = rightSplitNode;
					}else{
						rightSplitNode->children[rightChildrenSetCounter] = ptr->children[counter];
						rightSplitNode->children[rightChildrenSetCounter]->parent = rightSplitNode;
						counter += 1;
					}
					rightChildrenSetCounter += 1;
				}
				fillCounter += 1;
			}
			if(!prevLeftSet){
				rightSplitNode->children[rightChildrenSetCounter] = prevLeftSplitNode;
				rightChildrenSetCounter += 1;
			}
			if(!prevRightSet){
				rightSplitNode->children[rightChildrenSetCounter] = prevRightSplitNode;
				rightChildrenSetCounter += 1;
			}
			prevLeftSplitNode = leftSplitNode;
			prevRightSplitNode = rightSplitNode;
			free(prevSplitNode);
		}
		value = leftSplitNode->values[leftSplitNode->fillCount-1];
		leftSplitNode->values[leftSplitNode->fillCount-1] = INT_MAX;
		leftSplitNode->fillCount -= 1;
		insertIntoTwoFourTreeDriver(root,ptr->parent,value,leftSplitNode,rightSplitNode,ptr);
	}
}

void inorderTraversalTwoFourTree(i24Node *ptr){
	if(ptr == null){
		return;
	}
	for(unsigned int childrenCounter = 0;childrenCounter < ptr->fillCount;childrenCounter++){
		inorderTraversalTwoFourTree(ptr->children[childrenCounter]);
		printf("%d\n",ptr->values[childrenCounter]);
	}
	inorderTraversalTwoFourTree(ptr->children[ptr->fillCount]);
}

void insertValueIntoTwoFourTree(i24Node **root,vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		i24Node *ptrForInsertion = getNodeForInsertion(*root,userInput[counter]);
		insertIntoTwoFourTreeDriver(root,ptrForInsertion,userInput[counter]);
	}
}

struct i24Node{
	int values[3];
	unsigned int fillCount;
	i24Node *parent;
	i24Node *children[4];

	i24Node(){
		fillCount = 0;
	}

	i24Node(int value){
		this->values[0] = value;
		fillCount = 1;
		parent = null;
	}
};

i24Node *searchForNodeTwoFourTree(i24Node *ptr,int value){
	if(ptr == null){
		return null;
	}
	if(ptr->values[0] > value){
		return searchForNodeTwoFourTree(ptr->children[0],value);
	}
	if(ptr->values[ptr->fillCount - 1] < value){
		return ptr->values[ptr->fillCount];
	}
	for(unsigned int counter = 1;counter < ptr->fillCount;counter++){
		if(ptr->values[counter] == value){
			return ptr;
		}else if(ptr->values[counter] > value){
			return searchForNodeTwoFourTree(ptr->children[counter],value);
		}
	}
	return null;
}

unsigned int getChildIndex(i24Node *parent,i24Node *children){
	if(parent == null || children == null){
		return UINT_MAX;
	}
	for(unsigned int counter = 0;counter <= parent->fillCount;counter++){
		if(parent->children[counter] == children){
			return counter;
		}
	}
	return UINT_MAX;
}

void deleteValueIfAvailable(i24Node *ptr,int value){
	unsigned int counter = 0;
	while(ptr->values[counter] != value && counter < ptr->fillCount){
		counter++;
	}
	if(ptr->values[counter] != value){
		throw "Value not found";
	}
	while(counter < ptr->fillCount - 1){
		ptr->values[counter] = ptr->values[counter+1];
	}
	ptr->values[ptr->fillCount - 1] = INT_MAX;
	ptr->fillCount -= 1;
}

void deleteValueTwoFourTreeDriver(i24Node **root,i24Node *ptr,int value,i24Node *prevLeftCombinedNode,i24Node *prevRightCombinedNode,i24Node *combinedNode){
	if(*root == null){
		return null;
	}
	if(ptr->fillCount > 1){
		deleteValueIfAvailable(ptr,value);
		if(combinedNode != null){

		}
		return;
	}else{
		i24Node *parent = ptr->parent;
		if(parent == null){
			if(ptr->fillCount > 1){
				deleteValueIfAvailable(ptr,value);

			}else{
				if(combinedNode != null){
					throw "Invalid";
				}

			}
			return;
		}else{
			unsigned int index = getChildIndex(parent,ptr);
			int valueToBeDeleted;
			i24Node *leftNode,*rightNode;
			unsigned int indexToKey = UINT_MAX;
			for(unsigned int counter = 0;counter < ptr->fillCount;counter++){
				if(ptr->values[counter] == value){
					indexToKey = counter;
					break;
				}
			}
			if(index == UINT_MAX || indexToKey == UINT_MAX){
				throw "Invalid";
			}
			if(index != 0 && parent->children[index-1]->fillCount > 1){
				ptr->values[indexToKey] = parent->values[index];
				parent->values[index] = ptr->children[index-1]->values[ptr->children[index-1]->fillCount-1];
				ptr->children[index-1]->values[ptr->children[index-1]->fillCount-1] = UINT_MAX;
				ptr->children[index-1]->fillCount -= 1;
				parent->fillCount -= 1;
				if(combinedNode != null){

				}
				return;
			}else if(index+1 >= parent->fillCount && parent->children[index+1]->fillCount > 1){
				ptr->values[indexToKey] = parent->values[index];
				parent->values[index] = ptr->children[index+1]->values[ptr->children[index+1]->fillCount-1];
				ptr->children[index+1]->values[ptr->children[index+1]->fillCount-1] = UINT_MAX;
				ptr->children[index+1]->fillCount -= 1;
				parent->fillCount -= 1;
				if(combinedNode != null){

				}
				return;
			}else if(index != 0){
				i24Node *mergedNode = new i24Node();
				mergedNode->values[0] = parent->children[index-1]->values[0];
				mergedNode->values[1] = parent->values[index];
				leftNode = parent->children[index-1];
				rightNode = ptr;
				if(combinedNode != null){

				}
				deleteValueTwoFourTreeDriver(root,parent,ptr->values[index],leftNode,rightNode,mergedNode);
			}else{
				i24Node *mergedNode = new i24Node();
				mergedNode->values[0] = parent->values[index];
				mergedNode->values[1] = parent->children[index+1]->values[0];
				leftNode = ptr;
				rightNode = parent->children[index+1];
				if(combinedNode != null){

				}
				deleteValueTwoFourTreeDriver(root,parent,ptr->values[index],leftNode,rightNode,mergedNode);
			}
		}
	}
}

void deleteValueFromTree(i24Node **root,int value){
	if(*root == null){
		return;
	}
	i24Node *ptr = searchForNodeTwoFourTree(*root,value);
	if(ptr == null){
		return;
	}
	if(ptr->children[0] == null){

	}else{

	}
}

#endif /* TWOFOURTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
