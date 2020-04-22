/*
Given a string containing only three types of characters: '(', ')' and '*', 
write a function to check whether this string is valid. We define the validity
 of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left
parenthesis '(' or an empty string.
An empty string is also valid.*/

class Solution {
public:
   bool checkValidString(string s) {
      stack<int> open,ast;
      for(int i=0;i<s.length();i++)
      {
          if(s[i] == ')')
          {
              if(!open.empty()) open.pop();
              else if(!ast.empty()) ast.pop();
              else return false;
          }
          else if(s[i] == '(')   open.push(i);
          else ast.push(i);
      }
      while(!open.empty() && !ast.empty())
      {
         if(open.top() > ast.top()) return false;
         open.pop();
          ast.pop();
      }
        return open.empty();
    } 
};