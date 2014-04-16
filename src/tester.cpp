/****************************************************************************************************************************************************
 *  File Name   		: tester.cpp 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\tester.cpp
 *  Created on			: Apr 10, 2014 :: 3:09:51 AM
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
#include "main/utils/testing/testutil.h"
#include "main/utils/ds/linkedlist/linkedlist.h"
#include "main/utils/common/linkedlist/sillUtil.h"
#include "main/utils/common/tree/tree.h"
#include "main/sites/geeksforgeeks/trees/page09/treetraversals.h"
#include "main/sites/geeksforgeeks/trees/page09/sizeoftree.h"
#include "main/sites/geeksforgeeks/trees/page09/treeidentical.h"
#include "main/sites/geeksforgeeks/linkedlists/page05/nthnodeinsll.h"
#include "main/sites/geeksforgeeks/linkedlists/page05/printmiddlesill.h"
#include "main/sites/geeksforgeeks/arrays/page09/checkforpairforsum.h"
#include "main/sites/geeksforgeeks/arrays/page09/majorityelement.h"
#include "main/sites/geeksforgeeks/arrays/page09/oddnumberoftimes.h"
#include "main/utils/printingutil.h"

#define PRINT_NEW_LINE printf("\n")
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

int main(){
	printf("------------------------------------------ Test Starting ----------------------------------\n");
	vector<int> randomVector = generateIVector(9,0,50);
	printIVector(randomVector);
	sillutils *utils = new sillutils();
	sillNode *head = utils->createSILLFromVector(randomVector);
	unsigned int middleIndex = 0;
	printMiddleLinkedListByFindingLength(head,middleIndex);

	printf("\n------------------------------------------- Test End -------------------------------------");
	return 0;
}

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/


