/****************************************************************************************************************************************************
 *  File Name   		: deletionfromtrie.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture18\deletionfromtrie.h
 *  Created on			: Jun 25, 2014 :: 8:38:37 PM
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

#ifndef DELETIONFROMTRIE_H_
#define DELETIONFROMTRIE_H_



bool isFreeNode(ctrieNode *ptr){
	if(ptr == null){
		return true;
	}
	for(unsigned int counter = 0;counter < ALPHABET_SIZE;counter++){
		if(ptr->children[counter] != null){
			return false;
		}
	}
	return true;
}

ctrieNode *getWordLeaf(ctrieNode *ptr,string userInput,unsigned int index){

}

void deleteWordFromTrie(ctrieNode **root,string userInput){
	ctrieNode *startLeafNode;
}

#endif /* DELETIONFROMTRIE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
