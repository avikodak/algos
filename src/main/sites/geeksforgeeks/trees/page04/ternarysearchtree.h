/****************************************************************************************************************************************************
 *  File Name   		: ternarysearchtree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page04\ternarysearchtree.h
 *  Created on			: May 26, 2014 :: 7:56:13 PM
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

#ifndef TERNARYSEARCHTREE_H_
#define TERNARYSEARCHTREE_H_

struct iTernaryTreeNode{
	char ch;
	bool isLeafNode;
	iTernaryTreeNode *left;
	iTernaryTreeNode *equal;
	iTernaryTreeNode *right;

	iTernaryTreeNode(){

	}

	iTernaryTreeNode(char inputCh){
		ch = inputCh;
		isLeafNode = false;
		left = null;
		equal = null;
		right = null;
	}
};

void insertNodeIntoTernaryTree(iTernaryTreeNode **ptr,char *ch){
	if(ch == null || *ch == '\0'){
		(*ptr)->isLeafNode = true;
		return;
	}
	if(*ptr == null){
		*ptr = 	new iTernaryTreeNode(*ch);
		insertNodeIntoTernaryTree(ptr,ch+1);
	}else{
		if((*ptr)->ch > *ch){
			insertNodeIntoTernaryTree(&((*ptr)->left),ch);
		}else if((*ptr)->ch < *ch){
			insertNodeIntoTernaryTree(&((*ptr)->right),ch);
		}else{
			insertNodeIntoTernaryTree(&((*ptr)->equal),ch+1);
		}
	}
}

bool searchForWordTernaryTree(iTernaryTreeNode *ptr,char *word){

}

iTernaryTreeNode *createTernaryTree(vector<char *> userInput){
	if(userInput.size() == 0){
		return null;
	}
	iTernaryTreeNode *root = null;
	char *temp;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		temp = userInput[counter];
		insertNodeIntoTernaryTree(&root,temp);
	}
}

#endif /* TERNARYSEARCHTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
