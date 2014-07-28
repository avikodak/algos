/****************************************************************************************************************************************************
 *  File Name   		: searchinstandardtrie.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture18\searchinstandardtrie.h
 *  Created on			: Jun 25, 2014 :: 8:25:54 PM
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

#ifndef SEARCHINSTANDARDTRIE_H_
#define SEARCHINSTANDARDTRIE_H_

bool searchForWordTrie(ctrieNode *ptr,string userInput,unsigned int index){
	if(ptr == null && index < userInput.size()){
		return false;
	}
	if(userInput.size() == 0 || index >= userInput.size()){
		return true;
	}
	unsigned int currentCharIndex = getIndexForCharacter(userInput[index]);
	if(ptr->children[currentCharIndex] == null){
		return false;
	}
	return searchForWordTrie(ptr->children[currentCharIndex],userInput,index+1);
}

bool searchForWordTrieIterative(ctrieNode *ptr,string userInput){
	if(userInput.size() == 0){
		return true;
	}
	if(ptr == null){
		return false;
	}
	ctrieNode *crawler = ptr;
	unsigned int index = 0,currentCharIndex;
	while(crawler != null && index < userInput.size()){
		currentCharIndex = userInput[index] - 'a';
		if(crawler->children[currentCharIndex] == null){
			return false;
		}
		crawler = crawler->children[currentCharIndex];
		index++;
	}
	return index == userInput.size();
}

#endif /* SEARCHINSTANDARDTRIE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
