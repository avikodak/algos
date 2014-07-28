/****************************************************************************************************************************************************
 *  File Name   		: treeutil.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture06\treeutil.h
 *  Created on			: Jun 2, 2014 :: 12:31:13 AM
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

#ifndef TREEUTIL_H_
#define TREEUTIL_H_

class tree{
private:
	itNode *getTreeFromVectorMain(vector<int> userInput,unsigned int index){
		if(userInput.size() == 0||index >= userInput.size()){
			return null;
		}
		itNode *root = new itNode(userInput[index]);
		root->left = getTreeFromVectorMain(userInput,2*index+1);
		root->right = getTreeFromVectorMain(userInput,2*index+2);
		return root;
	}

	itNode *getTreeFromHashMapMain(hash_map<unsigned int,int> userInput,unsigned int index){
		if(userInput.size() == 0){
			return null;
		}
		hash_map<unsigned int,int>::iterator itToUserInput = userInput.find(index);
		if(itToUserInput == userInput.end()){
			return null;
		}
		itNode *root = new itNode(itToUserInput->second);
		root->left = getTreeFromHashMapMain(userInput,2*index+1);
		root->right = getTreeFromHashMapMain(userInput,2*index+2);
		return root;
	}

	iptNode *getPTreeFromVectorMain(vector<int> userInput,unsigned int index){
		if(userInput.size() == 0 || index >= userInput.size()){
			return null;
		}
		iptNode *root = new iptNode(userInput[index]);
		root->left = getPTreeFromVectorMain(userInput,2*index+1);
		if(root->left != null){
			root->left->parent = root;
		}
		root->right = getPTreeFromVectorMain(userInput,2*index+2);
		if(root->right != null){
			root->right->parent = root;
		}
		return root;
	}

	iptNode *getPTreeFromHashmapMain(hash_map<unsigned int,int> userInput,unsigned int index){
		if(userInput.size() == 0){
			return null;
		}
		hash_map<unsigned int,int>::iterator itToUserInput = userInput.find(index);
		if(itToUserInput == userInput.end()){
			return null;
		}
		iptNode *root = new iptNode(itToUserInput->second);
		root->left = getPTreeFromHashmapMain(userInput,2*index+1);
		if(root->left != null){
			root->left->parent = root;
		}
		root->right = getPTreeFromHashmapMain(userInput,2*index+2);
		if(root->right != null){
			root->right->parent = root;
		}
		return root;
	}
public:
	itNode *getTreeFromVectorIterative(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		queue<itNode *> auxSpace;
		itNode *root = new itNode(userInput[0]),*currentNode;
		auxSpace.push(root);
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			currentNode = auxSpace.front();
			if(currentNode->left == null){
				currentNode->left = new itNode(userInput[counter]);
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right == null){
				currentNode->right = new itNode(userInput[counter]);
				auxSpace.pop(currentNode->right);
			}
		}
		return root;
	}

	iptNode *getPTreeFromHashmapIterative(hash_map<unsigned int,int> userInput){
		if(userInput.size() == 0){
			return null;
		}

	}

	unsigned int heightOfTree(itNode *ptr){
		if(ptr == null){
			return 0;
		}
		return 1 + max(heightOfTree(ptr->left),heightOfTree(ptr->right));
	}

	unsigned int sizeOfTree(itNode *ptr){
		if(ptr == null){
			return 0;
		}
		return 1 + sizeOfTree(ptr->left) + sizeOfTree(ptr->right);
	}

	bool isTreeEmpty(itNode *ptr){
		return ptr == null?true:false;
	}

	unsigned int getLeafCount(itNode  *ptr){
		if(ptr == null){
			return 0;
		}
		if(ptr->left == null && ptr->right == null){
			return 1;
		}
		return getLeafCount(ptr->left) + getLeafCount(ptr->right);
	}
};

#endif /* TREEUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
