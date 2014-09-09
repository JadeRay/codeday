//相对路径转绝对路径
#include <iostream>
#include <vector>		// for vector
#include <string>		// for string , find, substr
using namespace std;

typedef vector < string > StrVec;
string
cp2ap (const string & cp_str)
{
  StrVec vec;
  vec.resize (100);		//这个地方必须用resize，因为resize有初始化，而reserve没有
  int front = 0;
  char ifs = '/';
  int pos1 = 0;
  int pos2 = 0;
  int len = cp_str.length ();
  string back ("/.."); //退回上一级
  string now ("/."); //当前目录
  while (pos1 < len && pos1 != cp_str.npos)
    {
      pos2 = cp_str.find (ifs, pos1 + 1);
      string tmp;
      if (pos2 == cp_str.npos)
	{
	  tmp = cp_str.substr (pos1, len - pos1);
	}
      else
	{
	  tmp = cp_str.substr (pos1, pos2 - pos1);
	}
      //cout<<tmp<<endl;
      if (tmp == back)
	{
		--front;
	}
      else if (tmp != now)
	{
	  vec[front++] = tmp;	// only if front < vec.size()
	}
      else;
      pos1 = pos2;
    }
  string ab_dir;
  for (int i = 0; i < front; ++i)
    ab_dir.append (vec[i]);
  return ab_dir;
}


int
main ()
{
  string input_str;
  cout << "input a contraversy path >>";
  while (cin >> input_str)
    {
      cout << "absolute path is :" << cp2ap (input_str) << endl;
      cout << "input a contraversy path >>";
    }
  return 0;
}
