/**
* Author: Chris Dieter
* Date: 2/18/2015
* Sources: All code written by me,
* used some tree traversals from 
* old BST assignment. 
*/

#ifndef __EXPRESSION__
#define __EXPRESSION__

#include <string>
#include <iostream>
using namespace std;

// Self-defined node class borrowed from a previous BST assignment from CSE 274
class Node {
public:
  Node* left;
  Node* right;
  Node* prev;
  int num;
  string op;
};

class Expression{
public:
	Expression(); // check
	Expression(string str); // check
	Expression(const Expression &other);// check
	~Expression(); // check

	string randomStats(int n);

	Expression &operator = (const Expression &other); // check
	double evaluate(double x) const; // check
	//static Expression randomExpression(int height); // check
	static void randomExpression(int height, Expression &other);
	string toString() const; // check
	void mutate(); // check
	int getHieght () const; // check

	
private:
	Node* root;
	string expr; // just a string to store the original string passed to the constructor
	void removeAllNodes(Node* r); // recursive helper to remove all nodes
	Node* doWork(string x); // recursive helper to construct tree off of given string
	string inOrder(Node* r) const; // in order tree traversal for toString function
	static string pickOp(); // randomly picks an operator
	int heightHelper(Node* r) const; // recursive helper to calculate height
	void findX(Node* r, double z, bool changeToXorNum) const; // finds all the x's to change, then changes them back to original number
	double compute(Node* r) const; // recursive helper to compute trees
	static Node* randoHelper(Node* r, int h, int c); // recursive helper to help random function generator
};
#endif