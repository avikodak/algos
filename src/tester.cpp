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
#include "main/utils/ds/tree/treeds.h"
#include "main/utils/common/tree/avltree.h"
#include "main/utils/common/tree/twofourtree.h"

#include "main/sites/geeksforgeeks/trees/page09/treetraversals.h"
#include "main/sites/geeksforgeeks/trees/page09/sizeoftree.h"
#include "main/sites/geeksforgeeks/trees/page09/treeidentical.h"
#include "main/sites/geeksforgeeks/trees/page09/heightoftree.h"
#include "main/sites/geeksforgeeks/trees/page09/roottoleafpaths.h"
#include "main/sites/geeksforgeeks/trees/page09/treetomirrorimage.h"
#include "main/sites/geeksforgeeks/trees/page08/minvaluebst.h"
#include "main/sites/geeksforgeeks/trees/page08/lowestcommonancestorsbst.h"
#include "main/sites/geeksforgeeks/trees/page08/greattreerecursion.h"
#include "main/sites/geeksforgeeks/trees/page08/levelordertraversal.h"
#include "main/sites/geeksforgeeks/trees/page08/levelspiralorder.h"
#include "main/sites/geeksforgeeks/trees/page08/inorderwithoutrecursionspace.h"
#include "main/sites/geeksforgeeks/trees/page08/inorderwithoutrecursion.h"
#include "main/sites/geeksforgeeks/trees/page08/countleafnodes.h"
#include "main/sites/geeksforgeeks/trees/page08/roottoleafsum.h"
#include "main/sites/geeksforgeeks/trees/page08/checkchildrensumproperty.h"
#include "main/sites/geeksforgeeks/trees/page08/heightbalanced.h"
#include "main/sites/geeksforgeeks/trees/page08/istreebst.h"
#include "main/sites/geeksforgeeks/linkedlists/page05/nthnodeinsll.h"
#include "main/sites/geeksforgeeks/linkedlists/page05/printmiddlesill.h"
#include "main/sites/geeksforgeeks/linkedlists/page05/nthnodefromend.h"
#include "main/sites/geeksforgeeks/linkedlists/page04/reversesill.h"
#include "main/sites/geeksforgeeks/linkedlists/page04/issillpalindrome.h"
#include "main/sites/geeksforgeeks/arrays/page09/checkforpairforsum.h"
#include "main/sites/geeksforgeeks/arrays/page09/majorityelement.h"
#include "main/sites/geeksforgeeks/arrays/page09/oddnumberoftimes.h"
#include "main/sites/geeksforgeeks/arrays/page09/findmissingnumber.h"
#include "main/sites/geeksforgeeks/arrays/page09/largestsumcontigoussubarray.h"
#include "main/sites/geeksforgeeks/arrays/page09/searchinsortedpivoted.h"
#include "main/sites/geeksforgeeks/arrays/page09/mergesortedarray.h"
#include "main/sites/geeksforgeeks/arrays/page08/reversearray.h"
#include "main/sites/geeksforgeeks/arrays/page08/medianofsequalortedarrays.h"
#include "main/sites/geeksforgeeks/arrays/page08/twoelementsclosetozero.h"
#include "main/sites/geeksforgeeks/arrays/page08/sortelementsbyfrequency.h"
#include "main/sites/geeksforgeeks/arrays/page08/segregate0s1sarray.h"
#include "main/sites/geeksforgeeks/arrays/page08/rotatearrayreversalalgo.h"
#include "main/sites/geeksforgeeks/arrays/page08/rotatearray.h"
#include "main/sites/geeksforgeeks/arrays/page08/leadersinarray.h"
#include "main/sites/geeksforgeeks/arrays/page08/firstsecondsmallest.h"
#include "main/sites/geeksforgeeks/arrays/page08/majoritysortedarray.h"
#include "main/sites/geeksforgeeks/arrays/page08/blockswaprotate.h"


#include "main/tuts/nptel/naveengarg/lecture01/insertionsort.h"
#include "main/tuts/nptel/naveengarg/lecture01/maxarray.h"
#include "main/utils/printingutil.h"

#include "main/quant/school/class06/chapter03/sieveoferathosthenes.h"
#include "main/quant/school/class06/chapter03/primenumbers.h"
#include "main/quant/school/class06/chapter03/polyndromenumber.h"
#include "main/quant/school/class06/chapter03/twinprimes.h"
#include "main/quant/school/class06/chapter03/commonfactors.h"
#include "main/quant/school/class06/chapter03/factors.h"
#include "main/quant/school/class06/chapter03/hcf.h"
#include "main/quant/school/class06/chapter03/lcm.h"
#include "main/quant/school/class06/chapter03/primefactorization.h"
#include "main/quant/school/class06/chapter03/coprimes.h"
#include "main/quant/school/class06/chapter03/divisibilityby10.h"
#include "main/quant/school/class06/chapter03/divisibilityby2.h"
#include "main/quant/school/class06/chapter03/divisibilityby3.h"
#include "main/quant/school/class06/chapter03/divisibilityby4.h"
#include "main/quant/school/class06/chapter03/divisibilityby5.h"
#include "main/quant/school/class06/chapter03/divisibilityby8.h"
#include "main/quant/school/class06/chapter03/divisibilityby9.h"
#include "main/quant/school/class06/chapter03/divisibilityby6.h"
#include "main/quant/school/class06/chapter03/divisibilityby11.h"

#define PRINT_NEW_LINE printf("\n")
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

void testCaseArrayUserinput(){
	vector<int> userInput;
	int noOfTestCase,testCaseSize,temp;
	cin >> noOfTestCase;
	while(noOfTestCase--){
		cin >> testCaseSize;
		for(int counter = 0;counter < testCaseSize;counter++){
			scanf("%d",&temp);
			userInput.push_back(temp);
		}
		scanf("%d",&temp);
		PRINT_NEW_LINE;
		printf("%d",isGivenValueMajorityElementONLONGBST(userInput,temp));
		userInput.clear();
	}
}

void testCaseArray(){
	vector<int> randomVector = generateIVector(10,0,50);
	//sort(randomVector.begin(),randomVector.end());
	printIVector(randomVector,false);
	PRINT_NEW_LINE;
	//printf("%d\n",medianOfTwoSortedEqualArrayON(randomVector,randomVector2));
	//for(unsigned int counter = 1;counter < 9;counter++){
	//rotateArrayBlockSwap(randomVector,2);
	//printIVector(randomVector,false);
	//PRINT_NEW_LINE;
	//}
	printf("%d\t",getMaxFromArrayON2(randomVector));
}

void linkedListTest(){
	vector<int> randomVector = generateIVector(6,0,50);
	printIVector(randomVector);
	sillutils *utils = new sillutils();
	sillNode *head = utils->createSILLFromVector(randomVector);
	utils->printSILL(head);
	PRINT_NEW_LINE;
	reverseSillIterative(&head);
	PRINT_NEW_LINE;
	utils->printSILL(head);
}

void testCaseUserinputLinkedList(){
	vector<int> randomVector;
	unsigned int testCases,noOfTestInputs;
	scanf("%d",&testCases);
	unsigned int userInput;
	sillutils *utils = new sillutils();
	sillNode *head = null;
	while(testCases--){
		scanf("%d",&noOfTestInputs);
		while(noOfTestInputs--){
			scanf("%d",&userInput);
			randomVector.push_back(userInput);
		}
		head = utils->createSILLFromVector(randomVector);
		printf("%d\n",isSillPalindromeReverseIdenticalCheck(head));
		randomVector.clear();
	}
}

void testCaseTree(){
	vector<int> randomVector = generateIVector(6,1,50);
	printIVector(randomVector);
	treeutils *utils = new treeutils();
	itNode *ptr = utils->getBSTTreeFromVector(randomVector);
	//itNode *ptr = utils->getITreeFromVector(randomVector);
	printf("%d\n",isTreeBSTInOrderMorrisTraversal(ptr));
}

void testCaseUserinputTree(){
	/*vector<int> randomVector = generateIVector(10,1,50);
	printIVector(randomVector);*/
	vector<int> randomVector;
	unsigned int noOfInputs;
	int userInput;
	//int temp;
	int noOfTestCase;
	cin >> noOfTestCase;
	treeutils *utils = new treeutils();
	while(noOfTestCase--){
		scanf("%u",&noOfInputs);
		while(noOfInputs--){
			scanf("%d",&userInput);
			randomVector.push_back(userInput);
		}
		//scanf("%d %d",&low,&high);
		//itNode *ptr = utils->getBSTTreeFromVector(randomVector);
		itNode *ptr = utils->getITreeFromVector(randomVector);
		printf("%d",checkChildrenSumPropertyPostOrderIterativeV2(ptr));
	}

}

void testCaseAvlTree(){
	vector<int> randomVector = generateIVector(10,1,50);
	printIVector(randomVector);
	avltreeutils *utils = new avltreeutils();
	utils->createAvlTreeFromVector(randomVector);
	utils->inorder();
	utils->deleteValueFromAvlTree(randomVector[0]);
	//utils->deleteValueFromAvlTree(randomVector[5]);
	printf("\n==========================================================\n");
	//utils->inorder();
}

void testCaseUserinputAvlTree(){
	vector<int> randomVector;
	unsigned int noOfInputs;
	int userInput;
	//int temp;
	int noOfTestCase;
	cin >> noOfTestCase;
	avltreeutils *utils = new avltreeutils();
	while(noOfTestCase--){
		scanf("%u",&noOfInputs);
		while(noOfInputs--){
			scanf("%d",&userInput);
			randomVector.push_back(userInput);
		}
		//scanf("%d %d",&low,&high);
		//itNode *ptr = utils->getBSTTreeFromVector(randomVector);
		utils->createAvlTreeFromVector(randomVector);
		utils->inorder();
		utils->deleteValueFromAvlTree(randomVector[0]);
		utils->deleteValueFromAvlTree(randomVector[5]);
		printf("\n==========================================================\n");
		utils->inorder();
	}
}

void quant(){
	unsigned int firstNumber;//,secondNumber;
	unsigned int testcases;
	cin >> testcases;
	hash_map<unsigned int,unsigned int> primeFactors;
	//vector<unsigned int> userInputs;
	while(testcases--){
		cin >> firstNumber;
		//cin >> secondNumber;
		//userInputs.push_back(firstNumber);
		//userInputs.push_back(secondNumber);
		printf("%d",divisibilityBy11(firstNumber));
	}
}

void testCaseTwofourtrees(){

}

void testCaseUserInputTwoFourTrees(){
	vector<int> randomVector;
	unsigned int noOfInputs;
	int userInput;
	int noOfTestCase;
	cin >> noOfTestCase;
	i24Node *root = null;
	while(noOfTestCase--){
		scanf("%u",&noOfInputs);
		while(noOfInputs--){
			scanf("%d",&userInput);
			randomVector.push_back(userInput);
		}
		insertValueIntoTwoFourTree(&root,randomVector);
		inorderTraversalTwoFourTree(root);
	}
}

int main(){
	printf("------------------------------------------ Test Starting ----------------------------------\n");
	//testCaseArray();
	//testCaseUserinputTree();
	//testCaseTree();
	//testCaseUserinputAvlTree();
	//testCaseAvlTree();
	//itNodeValueHashmap *test = utils->getNodeValueHashMap(null);
	//iRedBlackNode *ptr = new iRedBlackNode(10);
	//printf("%d",ptr->value);
	//quant();
	testCaseUserInputTwoFourTrees();
	printf("\n------------------------------------------- Test End -------------------------------------");
	return 0;
}

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/


