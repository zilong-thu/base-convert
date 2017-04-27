# include <string>

using namespace std;


class Stack {
private:
  /** 
   * 因为是与 JavaScript 作比较，
   * JS 的 Number 最多是 53 位二进制
   * 所以 53 位的数组肯定足够了
   */
  int items[53];
  int _size;
public:
  Stack() {
    _size = 0;
  };

  ~Stack(){};

  int size() {
    return _size;
  }

  void push(int item) {
    _size++;
    items[_size - 1] = item;
  };

  int pop() {
    _size--;
    return items[_size];
  };

  bool empty() {
    return _size ==  0;
  };

  int top() {
    return items[_size - 1];
  };
};

string baseConvert(long int dec, int base)
{
  Stack myStack;

  char str[53];

  while (dec > 0) {
    int rem = dec % base;
    myStack.push(rem);
    dec = dec / base;
  }

  int i = 0;
  while(!myStack.empty()) {
    str[i++] = (char) myStack.pop();
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

