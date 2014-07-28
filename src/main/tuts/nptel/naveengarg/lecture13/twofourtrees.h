/****************************************************************************************************************************************************
 *  File Name   		: twofourtrees.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture13\twofourtrees.h
 *  Created on			: Jun 14, 2014 :: 1:08:01 PM
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
#define MAX_KEYS 3
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TWOFOURTREES_H_
#define TWOFOURTREES_H_

struct i24Node{
	int values[3];
	unsigned int fillCount;
	i24Node *children[4] = {null};i
	i24Node *parent = null;
	i24Node(){

	}

	i24Node(value){
		this->values[0] = value;
		fillCount += 1;
	}
};


class twofourtreeutils{
private:
	i24Node *root;

	i24Node *getNodeForInsertion(int value){
		i24Node *traversingNode = this->root;
		unsigned int counter = 0;
		while(traversingNode != null){
			if(traversingNode->values[0] > value){
				if(traversingNode->children[0] == null){
					return traversingNode;
				}else{
					traversingNode = traversingNode->children[0];
					continue;
				}
			}
			if(traversingNode->values[0] == value){
				return null;
			}
			if(traversingNode->values[traversingNode->fillCount - 1] < value){
				if(traversingNode->children[traversingNode->fillCount - 1] == null){
					return traversingNode;
				}else{
					traversingNode = traversingNode->children[traversingNode->fillCount - 1];
					continue;
				}
			}
			if(traversingNode->values[traversingNode->fillCount - 1] == value){
				return null;
			}
			counter = 1;
			while(counter < traversingNode->fillCount && traversingNode->values[counter] < value){
				if(traversingNode->values[counter] ==  value){
					return null;
				}
				counter++;
			}
			if(traversingNode->children[counter] == null){
				return traversingNode;
			}else{
				traversingNode = traversingNode->children[counter];
			}
		}
		return null;
	}

	i24Node *searchMain(i24Node *currentNode,int userInput){
		if(currentNode == null){
			return null;
		}
		if(currentNode->values[0] == userInput){
			return currentNode;
		}
		if(currentNode->values[0] < userInput){
			return searchMain(currentNode->children[0],userInput);
		}
		if(currentNode->values[currentNode->fillCount - 1] == userInput){
			return currentNode;
		}
		if(currentNode->values[currentNode->fillCount - 1] < userInput){
			return searchMain(currentNode->children[currentNode->fillCount - 1],userInput);
		}
		unsigned int counter = 1;
		while(counter < currentNode->fillCount && currentNode->values[counter] < counter){
			counter++;
		}
		return searchMain(currentNode->children[counter],userInput);
	}

	unsigned int getChildIndex(i24Node *parent,i24Node *child){
		if(parent == null || child == null){
			return UINT_MAX;
		}
		for(unsigned int counter = 0;counter <= MAX_KEYS;counter++){
			if(parent->children[counter] == child){
				return counter;
			}
		}
		return UINT_MAX;
	}



	void splitAndFill(i24Node *currentNode,int userInput){
		if(currentNode == null){
			return;
		}
		i24Node *parentNode;
		i24Node *leftSplitNode = null,*rightSplitNode = null,*prevLeftSplitNode,*prevRightSplitNode;
		unsigned int fillCounter;
		int valueToBeInserted;
		while(currentNode != null){
			if(currentNode->parent != null && currentNode->parent->fillCount == MAX_KEYS){
				parentNode = currentNode->parent;
			}else{
				leftSplitNode = new i24Node();
				rightSplitNode = new i24Node();
				fillCounter = 0;
				for(unsigned int counter = 0;counter < currentNode->fillCount;counter++){
					if(userInput < currentNode[counter]){
						valueToBeInserted = userInput;
						counter -= 1;
					}else{
						valueToBeInserted = currentNode[counter];
					}
					if(counter == currentNode->fillCount/2){
						fillCounter = 0;
					}
					if(counter < currentNode->fillCount){
						leftSplitNode[fillCounter++] = valueToBeInserted;
					}else{
						rightSplitNode[fillCounter++] = valueToBeInserted;
					}
				}
			}
		}
	}

	void insertMain(i24Node *traversingNode,int userInput,i24Node *prevChildPtr = null,i24Node *prevLeftSplitPtr = null,i24Node *prevRightSplitPtr){
		if(this->root == null ||traversingNode == null){
			this->root = new i24Node(userInput);
			this->root->children[0] = prevLeftSplitPtr;
			this->root->children[1] = prevRightSplitPtr;
			return;
		}
		if(traversingNode->fillCount < MAX_KEYS){
			traversingNode->values[traversingNode->fillCount] = userInput;
			int innerCounter = traversingNode->fillCount - 1;
			while(innerCounter > 0 && traversingNode->values[innerCounter] > userInput){
				traversingNode->values[innerCounter+1] = traversingNode->values[innerCounter];
				innerCounter -= 1;
			}
			traversingNode->values[innerCounter+1] = userInput;
			traversingNode->fillCount += 1;
			unsigned int fillCounter = 0;
			if(prevLeftSplitPtr != null && prevRightSplitPtr != null){
				for(unsigned int counter = 0;counter <= traversingNode->fillCount;counter++,fillCounter++){
					if(traversingNode->children[counter] == prevChildPtr){
						traversingNode->children[fillCounter] = prevLeftSplitPtr;
						traversingNode->children[fillCounter+1] = prevRightSplitPtr;
						counter -= 1;
						fillCounter += 1;
					}else{
						traversingNode->children[fillCounter]  = traversingNode->children[counter];
					}
				}
			}
			prevLeftSplitPtr->parent = traversingNode;
			prevRightSplitPtr->parent = traversingNode;
			free(prevChildPtr);
			return;
		}
		i24Node *leftSplitNode = new i24Node();
		i24Node *rightSplitNode = new i24Node();
		int fillCounter = -1;
		int value;
		for(unsigned int counter = 0;counter < traversingNode->fillCount;counter++){
			if(userInput < traversingNode->values[counter]){
				value = userInput;
			}else{
				value = traversingNode->values[counter];
			}
			if(counter < traversingNode->fillCount){
				leftSplitNode[++fillCounter] = value;
			}else{
				rightSplitNode[++fillCounter] = value;
			}
			if(counter == traversingNode->fillCount/2){
				fillCounter = -1;
			}
		}
		if(prevLeftSplitPtr != null && prevRightSplitPtr != null){

		}
		insertMain(traversingNode->parent,userInput,traversingNode,leftSplitNode,rightSplitNode);
	}
public:
	void insert(int userInput){
		i24Node *nodeToBeInserted = getNodeForInsertion(userInput);
		insertMain(nodeToBeInserted,userInput);
	}

	i24Node *searchIterative(int userInput){
		if(this->root == null){
			return null;
		}
		i24Node *traversingNode = this->root;
		unsigned int counter;
		while(traversingNode != null){
			if(traversingNode->values[0] == userInput){
				return traversingNode;
			}
			if(traversingNode->values[0] > userInput){
				traversingNode = traversingNode->children[0];
				continue;
			}
			if(traversingNode->values[traversingNode->fillCount - 1] < userInput){
				traversingNode = traversingNode->children[traversingNode->fillCount - 1];
				continue;
			}
			counter = 1;
			while(counter < traversingNode->fillCount && traversingNode->values[counter] <= userInput){
				if(traversingNode->values[counter] == userInput){
					return traversingNode;
				}
				traversingNode = traversingNode->children[counter];
			}
		}
		return null;
	}

	i24Node *search(int userInput){
		return searchMain(this->root,userInput);
	}
};

#endif /* TWOFOURTREES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
