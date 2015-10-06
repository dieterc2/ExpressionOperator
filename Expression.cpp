#include "Expression.h"
#include <stdlib.h>
#include <ctime>
#include <math.h>

Expression::Expression(){
	root = new Node();
	root->right = NULL;
	root->left = NULL;
	root->op = "";
	root->num = 0;
}

void Expression::randomExpression(int height, Expression &other){
	int count = 0;
	other.root = randoHelper(other.root, height, count);
}

Node* Expression::randoHelper(Node* r, int h, int c){
	
	if(c == h){
		int number = rand() % 9 + 1;
		if(number < 10){
			r->num = number;
			r->op = "";
			r->left = NULL;
			r->right = NULL;
		}
		else{
			r->op="x";
			r->num=0;
			r->left = NULL;
			r->right = NULL;
		}
		return r;
	}
	if(c < h){
		string result = pickOp();
		r->op = result;
		r->num = NULL;
		c++;
		Node* lefty = new Node();
		lefty = randoHelper(lefty, h, c);
		r->left = lefty;
		Node* righty = new Node();
		righty = randoHelper(righty, h, c);
		r->right = righty;
	}
	return r;
}

string Expression::pickOp(){
	int v1 = rand() % 3;
	string result = "";
	switch(v1){
		case 0:
			result += "+";
			break;
		case 1:
			result += "*";
			break;
		case 2:
			result += "-";
			break;
		case 3:
			result += "^";
			break;
	}
	return result;
}

string Expression::toString() const{
	string result = "";
	result = inOrder(root);
	return result;
}

string Expression::inOrder(Node* r) const{
	string l = "";
	if(r->num != NULL || r->op.compare("x")==0){
		if(r->num != NULL){
			char c = r->num + '0';
			string y(1, c);
			string leaf = "(" + y + ")";
			return leaf;
		} else
			return "(" + r->op + ")";
	}
	if(r->op != ""){
		string lside = inOrder(r->left);
		string rside = inOrder(r->right);
		if(r->op.compare("+") == 0){
			l += "(" + lside + "+" + rside + ")";
		} else if(r->op.compare("-")==0){
			l += "(" + lside + "-" + rside + ")";
		} else if(r->op.compare("^")==0){
			l += "(" + lside + "^" + rside + ")";
		} else if(r->op.compare("*")==0){
			l += "(" + lside + "*" + rside + ")";
		}
	}
	return l;
}

int main(){
	srand(time(NULL));
	std::cout << "Test random expression generator" << std::endl;
	Expression* q1 = new Expression();
	Expression::randomExpression(3, *q1);
	std::cout << "Random function is: " << q1->toString() << std::endl;
	std::cout << "eval rando: " << q1->evaluate(1) << std::endl;
	return 0;
}