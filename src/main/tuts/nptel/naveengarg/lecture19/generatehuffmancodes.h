/****************************************************************************************************************************************************
 *  File Name   		: generatehuffmancodes.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture19\generatehuffmancodes.h
 *  Created on			: Jun 25, 2014 :: 1:28:06 PM
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

#ifndef GENERATEHUFFMANCODES_H_
#define GENERATEHUFFMANCODES_H_

struct cftNode{
	char ch;
	unsigned int frequency;
	cftNode *left;
	cftNode *right;

	cftNode(){
		ch = '\0';
		left = null;
		right = null;
		frequency = 0;
	}

	cftNode(char userInput){
		ch = userInput;
		frequency = 1;
		left = null;
		right = null;
	}
};

hash_map<char,cftNode *> createLeavesAndSetFrequencies(vector<char> userInput){
	hash_map<char,cftNode *> charFrequencyMap;
	if(userInput.size() == 0){
		return charFrequencyMap;
	}
	hash_map<char,cftNode *>::iterator itToCharFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToCharFrequencyMap = charFrequencyMap.find(userInput[counter])) == charFrequencyMap.end()){
			charFrequencyMap[userInput[counter]] = new cftNode(userInput[counter]);
		}else{
			charFrequencyMap[userInput[counter]]->frequency++;
		}
	}
	return charFrequencyMap;
}

void setCodesFromHuffmanTrie(cftNode *ptr,string runningCode,hash_map<char,string> &huffmanCodes){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		huffmanCodes.insert(pair<char,string>(ptr->ch,runningCode));
		return;
	}
	setCodesFromHuffmanTrie(ptr->left,runningCode.append("0"),huffmanCodes);
	runningCode.erase(runningCode.size()-1);
	setCodesFromHuffmanTrie(ptr->right,runningCode.append("1"),huffmanCodes);
}

hash_map<char,string> generateHuffmanCodes(vector<char> userInput){
	hash_map<char,string> huffmanCodes;
	if(userInput.size() == 0){
		return huffmanCodes;
	}
	hash_map<char,cftNode *> mapCharactersFrequency = createLeavesAndSetFrequencies(userInput);
	if(mapCharactersFrequency.size() == 1){
		huffmanCodes.insert(pair<char,string>(mapCharactersFrequency.begin()->second->ch,new string("0")));
		return huffmanCodes;
	}
	hash_map<char,cftNode *>::iterator itToMapCharactersFrequency;
	vector<cftNode *> nodes;
	for(itToMapCharactersFrequency = mapCharactersFrequency.begin();itToMapCharactersFrequency != mapCharactersFrequency.end();itToMapCharactersFrequency++){
		nodes.push_back(itToMapCharactersFrequency->second);
	}
	cftNode *root = null;
	unsigned int firstMinimumIndex = UINT_MAX,secondMinimumIndex = UINT_MAX;
	while(true){
		if(nodes.size() == 1){
			root = nodes[0];
			break;
		}
		firstMinimumIndex = 0;
		for(unsigned int counter = 1;counter < nodes.size();counter++){
			if(nodes[counter]->frequency < nodes[firstMinimumIndex]->frequency){
				secondMinimumIndex = firstMinimumIndex;
				firstMinimumIndex = counter;
			}else{
				if(nodes[counter]->frequency < nodes[secondMinimumIndex]->frequency){
					secondMinimumIndex = counter;
				}
			}
		}
		cftNode *newNode = new cftNode();
		newNode->frequency = nodes[firstMinimumIndex]->frequency + nodes[secondMinimumIndex]->frequency;
		newNode->left = nodes[firstMinimumIndex];
		newNode->right = nodes[secondMinimumIndex];
		nodes.erase(firstMinimumIndex);
		nodes.erase(secondMinimumIndex);
		nodes.push_back(newNode);
	}
	setCodesFromHuffmanTrie(root,huffmanCodes);
	return huffmanCodes;
}


#endif /* GENERATEHUFFMANCODES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
