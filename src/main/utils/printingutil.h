/****************************************************************************************************************************************************
 *  File Name   		: printingutil.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\Interviews\src\library\utils\printingutil.h
 *  Created on			: Feb 16, 2014 :: 12:08:56 PM
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
#define PRINT_NEW_LINE printf("\n")

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PRINTINGUTIL_H_
#define PRINTINGUTIL_H_

//Tested
void printIVector(vector<int> userInput,bool withHeadersAndFooters = true){
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING VECTOR START\n");
		printf("====================================================================================================================================\n");
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		printf("%d\t",userInput[counter]);
	}
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING VECTOR END\n");
		printf("====================================================================================================================================\n");
	}
}

//Tested
void printUIVector(vector<unsigned int> userInput,bool withHeadersAndFooters = true){
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING VECTOR START\n");
		printf("====================================================================================================================================\n");
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		printf("%u\t",userInput[counter]);
	}
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING VECTOR END\n");
		printf("====================================================================================================================================\n");
	}
}

void printITVector(vector<itNode *> userInput,bool withHeadersAndFooters = true){
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING VECTOR START\n");
		printf("====================================================================================================================================\n");
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		printf("%d\t",userInput[counter]->value);
	}
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING VECTOR END\n");
		printf("====================================================================================================================================\n");
	}
}

//Tested
void printITNodeStack(stack<itNode *> auxSpace,bool withHeadersAndFooters = true){
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING STACK START\n");
		printf("====================================================================================================================================\n");
	}
	while(!auxSpace.empty()){
		printf("%d\t",auxSpace.top()->value);
		auxSpace.pop();
	}
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING VECTOR END\n");
		printf("====================================================================================================================================\n");
	}else{
		printf("\n");
	}
}

//Tested
void printReverseITNodeStack(stack<itNode *> auxSpace,bool withHeadersAndFooters = true){
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING STACK START\n");
		printf("====================================================================================================================================\n");
	}
	queue<itNode *> reverseAuxSpace;
	while(!auxSpace.empty()){
		reverseAuxSpace.push(auxSpace.top());
		auxSpace.pop();
	}
	while(!reverseAuxSpace.empty()){
		printf("%d\t",reverseAuxSpace.front()->value);
		reverseAuxSpace.pop();
	}
	if(withHeadersAndFooters){
		printf("\n====================================================================================================================================\n");
		printf("PRINTING VECTOR END\n");
		printf("====================================================================================================================================\n");
	}else{
		printf("\n");
	}
}

//Tested
void printUIUIHashMap(hash_map<unsigned int,unsigned int> map,bool withHeadersAndFooters = true){
	if(withHeadersAndFooters){
			printf("\n====================================================================================================================================\n");
			printf("PRINTING HASH MAP START\n");
			printf("====================================================================================================================================\n");
		}
		hash_map<unsigned int,unsigned int>::iterator itToMap;
		for(itToMap = map.begin();itToMap != map.end();itToMap++){
			printf("%u\t%u\n",itToMap->first,itToMap->second);
		}
		if(withHeadersAndFooters){
			printf("\n====================================================================================================================================\n");
			printf("PRINTING HASH MAP END\n");
			printf("====================================================================================================================================\n");
		}else{
			printf("\n");
		}
}

#endif /* PRINTINGUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
