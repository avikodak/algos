/****************************************************************************************************************************************************
 *  File Name   		: printduplicates.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\strings\page04\printduplicates.h
 *  Created on			: Jun 26, 2014 :: 3:12:51 AM
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
#define CHARACTERS_SIZE 256
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PRINTDUPLICATES_H_
#define PRINTDUPLICATES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printDuplicates(string userInput){
	if(userInput.size() == 0){
		return;
	}
	hash_map<char,unsigned int> frequencyMap;
	hash_map<char,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
			if(frequencyMap[userInput[counter]] == 2){
				printf("%c\t",userInput[counter]);
			}
		}else{
			frequencyMap[userInput[counter]] = 1;
		}
	}
}


/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void createCBSTFromString(cftNode **root,cftNode *ptr,string userInput,unsigned int counter){
	if(userInput.size() == 0 || counter >= userInput.size()){
		return;
	}
	if(*root == null){
		(*root) = new cftNode(userInput[counter]);
		createCBSTFromString(root,*root,userInput,counter+1);
	}else{
		if(ptr->ch == userInput[counter]){
			ptr->frequency += 1;
			createCBSTFromString(root,*root,userInput,counter+1);
		}else{
			if(ptr->ch > userInput[counter]){
				if(ptr->left == null){
					ptr->left = new cftNode(userInput[counter]);
					createCBSTFromString(root,*root,userInput,counter+1);
				}else{
					createCBSTFromString(root,ptr->left,userInput,counter);
				}
			}else{
				if(ptr->right == null){
					ptr->right = new cftNode(userInput[counter]);
					createCBSTFromString(root,*root,userInput,counter+1);
				}else{
					createCBSTFromString(root,ptr->right,userInput,counter);
				}
			}
		}
	}
}

void printDuplicatesBST(string userInput){
	if(userInput.size() == 0){
		return;
	}
	cftNode *root = null;
	createCBSTFromString(&root,root,userInput,0);
	stack<cftNode *> auxSpace;
	auxSpace.push(root);
	cftNode *currentTopNode;
	while(!auxSpace.empty()){
		currentTopNode = auxSpace.top();
		auxSpace.pop();
		printf("%c\t",currentTopNode->ch);
		if(currentTopNode->right != null){
			auxSpace.push(currentTopNode->right);
		}
		if(currentTopNode->left != null){
			auxSpace.push(currentTopNode->left);
		}
	}
}

void printDuplicatesSortONLOGN(string userInput){
	if(userInput.size() == 0){
		return;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int counter = 0;
	while(counter < userInput.size()){
		while(counter+1 < userInput.size() && userInput[counter] == userInput[counter+1]){
			counter += 1;
		}
		printf("%c\t",userInput[counter]);
		counter++;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void printDuplicatesON2(string userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int outerCrawler = 0,innerCrawler;
	bool flagDuplicate;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		flagDuplicate = false;
		if(userInput[outerCrawler] == '$'){
			continue;
		}
		for(innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(innerCrawler == outerCrawler){
				continue;
			}
			if(userInput[innerCrawler] == userInput[outerCrawler]){
				flagDuplicate = true;
				userInput[innerCrawler] = '$';
			}
		}
		if(flagDuplicate){
			printf("%c\t",userInput[outerCrawler]);
		}
	}
}

#endif /* PRINTDUPLICATES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
