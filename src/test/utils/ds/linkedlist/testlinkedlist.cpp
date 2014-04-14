/****************************************************************************************************************************************************
 *  File Name   		: testlinkedlist.cpp 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\test\utils\ds\linkedlist\testlinkedlist.cpp
 *  Created on			: Apr 10, 2014 :: 3:39:11 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
****************************************************************************************************************************************************/

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

#include <algos/utils/ds/linkedlist/linkedlist.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TESTLINKEDLIST_CPP_
#define TESTLINKEDLIST_CPP_

void testSILLNode(){
	sillNode *newSLLNode = (sillNode *)malloc(sizeof(sillNode));
	newSLLNode->value = 10;
	newSLLNode->next = NULL;
	printf("%d",newSLLNode->value);
}

/*int main(){
	testSILLNode();
}*/

#endif /* TESTLINKEDLIST_CPP_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
