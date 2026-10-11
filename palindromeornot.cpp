# palindrome or not
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to reverse string using stack
string reverseString(string str)
{
    stack<char> s;
    string reversed = "";

    // Push characters into stack
    for (char ch : str)
    {
        s.push(ch);
    }

    // Pop characters to get reversed string
    while (!s.empty())
    {
        reversed = reversed + s.top();
        s.pop();
    }

    return reversed;
}

// Function to check palindrome
bool isPalindrome(string str)
{
    string reversed = reverseString(str);

    if (str == reversed)
        return true;
    else
        return false;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    // a) Print original and reversed string
    cout << "\nOriginal String : " << str << endl;
    cout << "Reversed String : " << reverseString(str) << endl;

    // b) Check palindrome
    if (isPalindrome(str))
        cout << "The given string is a Palindrome." << endl;
    else
        cout << "The given string is NOT a Palindrome." << endl;

    return 0;
}