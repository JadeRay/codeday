#include <iostream>
#include <stack>
#include <cstdlib>		//for atoi
#include <string.h>		//for strlen
#include <memory>		//for memcpy
#include <cctype>		//for isdigit
using namespace std;

char
Precede (char &optr1, char &optr2)
{
  if (optr1 == '+')
    if (optr2 == '+' || optr2 == '-' || optr2 == ')' || optr2 == '#')
      return '>';
    else
      return '<';
  if (optr1 == '-')
    if (optr2 == '+' || optr2 == '-' || optr2 == ')' || optr2 == '#')
      return '>';
    else
      return '<';
  if (optr1 == '*')
    if (optr2 == '(')
      return '<';
    else
      return '>';
  if (optr1 == '/')
    if (optr2 == '(')
      return '<';
    else
      return '>';
  if (optr1 == '(')
    if (optr2 == ')')
      return '=';
    else
      return '<';
  if (optr1 == ')')
    return '>';
  if (optr1 == '#')
    if (optr2 == '#')
      return '=';
    else
      return '<';
}

int
operate (int a, char lambda, int b)
{
  switch (lambda)
    {
    case '+':
      return a + b;
      break;
    case '-':
      return a - b;
      break;
    case '*':
      return a * b;
      break;
    case '/':
      return a / b;
      break;
    }
}

int
compute (char *expr)
{
  int len = strlen (expr);
  char *new_expr = new char[len + 2];
  memcpy (new_expr, expr, len + 1);
  new_expr[len] = '#';
  new_expr[len + 1] = '\0';
  //cout << new_expr << endl;
  stack < int >opnd;
  stack < char >optr;
  optr.push ('#');
  char *p = new_expr;
  while (*p != '#' || optr.top () != '#')
    {
      if (isdigit (*p))
	{
	  //cout << "opnd in:" << *p << endl;
	  opnd.push (*p - '0');
	  ++p;
	}
      else
	{
	  switch (Precede (optr.top (), *p))
	    {
	    case '<':
	      {
		//cout << "now optr in:" << *p << endl;
		optr.push (*p);
		++p;
		break;
	      }
	    case '=':		//only (=)
	      {
		//cout << "now optr out:" << optr.top () << endl;
		optr.pop ();
		++p;
		break;
	      }
	    case '>':
	      {
		char lambda = optr.top ();
		optr.pop ();
		//cout << "now optr out for compute:" << lambda << endl;
		int a = opnd.top ();
		opnd.pop ();
		int b = opnd.top ();
		opnd.pop ();
		opnd.push (operate (b, lambda, a));
		break;
	      }
	    }
	}
    }
  delete[]new_expr;
  return opnd.top ();
}

int
main ()
{
  char str[1000];
  cout << "input expression>> ";
  while (cin >> str)
    {
      cout << str << "=" << compute (str) << endl;
      cout << "input expression>> ";
    }
  return 0;
}
