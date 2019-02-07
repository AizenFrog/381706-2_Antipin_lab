#include "Polish_record.h"
#include <cmath>

Calculator::Calculator(const char* string)
{
  str.WrightString(string);
  numbers = new Stack<int>(100);
  s_char = new Stack<char>(100);
}

int Calculator::Calculate()
{
  int a = 0, b = 0;
  bool priority_of_simbols = true;
  while (1)
  {
    Number tmp = str.GetNextChar();
    if (numbers->GetIndex() == 1 && tmp.len == 0)
      break;
    int type = AddToStacks(tmp);
    if (s_char->GetIndex() > 1)
      priority_of_simbols = WhatsMore();
    if ((s_char->GetIndex() > 0 && Priority() == 4) || (numbers->GetIndex() >= 2 && type > 0 && priority_of_simbols == true))
    {
      if (s_char->GetWithoutDelete() == '(')
      {
        char* inside_string = new char[100];
        int inside_char_count = 0;
        int inside_brecket_count = 0;
        while (1)
        {
          tmp = str.GetNextChar();
          if (tmp.number[0] == '(')
            inside_brecket_count++;
          if (tmp.number[0] == ')' && inside_brecket_count == 0)
            break;
          else if (tmp.number[0] == ')')
            inside_brecket_count--;
          int i;
          for (i = 0; i < tmp.len; i++)
            inside_string[i + inside_char_count] = tmp.number[i];
          inside_char_count += tmp.len;
        }
        inside_string[inside_char_count] = '=';
        Calculator calcul(inside_string);
        numbers->Put(calcul.Calculate());
        s_char->Get();
        continue;
      }
      char c = s_char->Get();
      if (s_char->GetWithoutDelete() == '+')
      {
        a = numbers->Get();
        b = numbers->Get();
        numbers->Put(a + b);
        s_char->Get();
      }
      else if (s_char->GetWithoutDelete() == '-')
      {
        a = numbers->Get();
        b = numbers->Get();
        numbers->Put(b - a);
        s_char->Get();
      }
      else if (s_char->GetWithoutDelete() == '*')
      {
        a = numbers->Get();
        b = numbers->Get();
        numbers->Put(a * b);
        s_char->Get();
      }
      else if (s_char->GetWithoutDelete() == '/')
      {
        a = numbers->Get();
        b = numbers->Get();
        numbers->Put(b / a);
        s_char->Get();
      }
      else if (s_char->GetWithoutDelete() == '^')
      {
        a = numbers->Get();
        b = numbers->Get();
        numbers->Put(pow(b, a));
        s_char->Get();
      }
      s_char->Put(c);
    }
  }
  return numbers->Get();
}

int Calculator::AddToStacks(Number n)
{
  if (n.number[0] == '+')
  {
    s_char->Put('+');
    return 1;
  }
  else if (n.number[0] == '-')
  {
    s_char->Put('-');
    return 1;
  }
  else if (n.number[0] == '*')
  {
    s_char->Put('*');
    return 1;
  }
  else if (n.number[0] == '/')
  {
    s_char->Put('/');
    return 1;
  }
  else if (n.number[0] == '^')
  {
    s_char->Put('^');
    return 1;
  }
  else if (n.number[0] == '(')
  {
    s_char->Put('(');
    return 1;
  }
  else if (n.number[0] == ')')
  {
    s_char->Put(')');
    return 1;
  }
  else if (n.number[0] == '=')
  {
    s_char->Put('=');
    return 2;
  }
  else
  {
    if (n.len != 0)
    {
      numbers->Put(CharToInt(n));
      return 0;
    }
    else
      return 3;
  }
}

int Calculator::CharToInt(Number st)
{
  int M = 0;
  int N = 0;
  for (int i = 0; i < st.len; i++)
  {
    M += (st.number[i] - '0') * pow(10, st.len - i - 1);
    N = st.number[i] - '0';
    if (N > 9 || N < 0)
      exception.except_throw(106);
  }
  return M;
}

int Calculator::Priority()
{
  if (s_char->GetWithoutDelete() == '=')
    return 0;
  if (s_char->GetWithoutDelete() == '+' || s_char->GetWithoutDelete() == '-')
    return 1;
  if (s_char->GetWithoutDelete() == '*' || s_char->GetWithoutDelete() == '/')
    return 2;
  if (s_char->GetWithoutDelete() == '^')
    return 3;
  if (s_char->GetWithoutDelete() == '(' || s_char->GetWithoutDelete() == ')')
    return 4;
}

bool Calculator::WhatsMore()
{
  char ch = s_char->Get();
  int prior = Priority();
  s_char->Put(ch);
  if (prior >= Priority())
    return true;
  else
    return false;
}