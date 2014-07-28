/****************************************************************************************************************************************************
 *  File Name   		: insertintostandardtrie.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture18\insertintostandardtrie.h
 *  Created on			: Jun 23, 2014 :: 1:24:29 AM
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
#define ALPHABET_SIZE 26
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef INSERTINTOSTANDARDTRIE_H_
#define INSERTINTOSTANDARDTRIE_H_

struct ctrieNode{
	char ch;
	unsigned int noOfChildren;
	ctrieNode *parent;
	ctrieNode *children[ALPHABET_SIZE] = {null};

	ctrieNode(){

	}

	ctrieNode(char userInput){
		ch = userInput;
		noOfChildren = 0;
		parent = null;
	}
};

unsigned int getIndexForCharacter(char ch){
	return ch - 'a';
}

void insertIntoTrie(ctrieNode **root,ctrieNode *currentNode,string userInput,unsigned int index){
	if(userInput.size() == 0 || userInput.size() >= index){
		return;
	}
	unsigned int currentIndexOfCharater = getIndexForCharacter(userInput[index]);
	if(*root == null){
		(*root) =new ctrieNode('\0');
		(*root)->children[currentIndexOfCharater] = new ctrieNode(userInput[index]);
		(*root)->children[currentIndexOfCharater]->parent = *root;
		(*root)->noOfChildren++;
		insertIntoTrie(root,(*root)->children[currentIndexOfCharater],userInput,index+1);
	}else{
		if(currentNode->children[currentIndexOfCharater] == null){
			currentNode->children[currentIndexOfCharater] = new ctrieNode(userInput[index]);
			currentNode->children[currentIndexOfCharater]->parent = currentNode;
			currentNode->noOfChildren += 1;
		}
		insertIntoTrie(root,currentNode->children[currentIndexOfCharater],userInput,index+1);
	}
}

void insertIntoTrieIterative(ctrieNode **root,string userInput){
	if(userInput.size() == 0){
		return;
	}
	if(*root == null){
		*root = new ctrieNode('\0');
	}
	ctrieNode *traversalNode = *root;
	unsigned int index = 0,currentCharIndex;
	while(index < userInput.size()){
		currentCharIndex = userInput[index] - 'a';
		if(traversalNode->children[currentCharIndex] == null){
			traversalNode->children[currentCharIndex] = new ctrieNode(userInput[currentCharIndex]);
			traversalNode->children[currentCharIndex]->parent = traversalNode;
			traversalNode->noOfChildren++;
		}
		index++;
		traversalNode = traversalNode->children[currentCharIndex];
	}
}

#endif /* INSERTINTOSTANDARDTRIE_H_ */
/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
