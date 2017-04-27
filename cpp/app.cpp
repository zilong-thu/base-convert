# include <stack>
# include <string>

using namespace std;


string baseConvert(long int dec, int base)
{
  stack<int> myStack;

  string str;

  while (dec > 0) {
    int rem = dec % base;
    myStack.push(rem);
    dec = dec / base;
  }

  while(!myStack.empty()) {
    str += std::to_string(myStack.top());
    myStack.pop();
  }

  return str;
}

int main()
{
  for (int i = 0; i < 1000000; ++i)
  {
    string s = baseConvert(9007199254740991, 2);
  }
  return 0;
}

