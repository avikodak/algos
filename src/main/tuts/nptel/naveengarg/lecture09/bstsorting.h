/****************************************************************************************************************************************************
 *  File Name   		: bstsorting.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture09\bstsorting.h
 *  Created on			: Jun 4, 2014 :: 7:39:11 PM
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

#ifndef BSTSORTING_H_
#define BSTSORTING_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void getBSTFromVector(iftNode **root,iftNode *currentNode,vector<int> userInput,unsigned int index){
	if(userInput.size() == 0||index >= userInput.size()){
		return;
	}
	if(*root == null){
		*root = new iftNode(userInput[index]);
		getBSTFromVector(root,*root,userInput,index+1);
	}else{
		if(currentNode->value == userInput[index]){
			currentNode->frequency += 1;
		}else{
			if(currentNode->value > userInput[index]){
				if(currentNode->left == null){
					currentNode->left = new iftNode(userInput[index]);
					getBSTFromVector(root,*root,userInput,index+1);
				}else{
					getBSTFromVector(root,currentNode->left,userInput,index);
				}
			}else{
				if(currentNode->right  == null){
					currentNode->right = new iftNode(userInput[index]);
					getBSTFromVector(root,*root,userInput,index+1);
				}else{
					getBSTFromVector(root,currentNode->right,userInput,index);
				}
			}
		}
	}
}

void setVectorWithInorderNodes(iftNode *ptr,vector<int> &userInput){
	if(ptr == null){
		return;
	}
	static unsigned int index = 0;
	setVectorWithInorderNodes(ptr->left,userInput);
	while(ptr->frequency--){
		userInput[index++] = ptr->value;
	}
	setVectorWithInorderNodes(ptr->right,userInput);
}

void bstSorting(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	iftNode *root = null;
	getBSTFromVector(&root,root,userInput,0);
	setVectorWithInorderNodes(ptr,userInput);
}

#endif /* BSTSORTING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
