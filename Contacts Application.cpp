#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ALPHABET_SIZE 26

int getChildIndex(char c)
{
    return (int)c - 'a';
}

struct node
{
    char data;
    int suffixes;
    node *child[ALPHABET_SIZE];
    
    node(char d)
    {
        data = d;
        suffixes = 0;
        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            child[i] = NULL;    
        }
    }
};

void addWord(node *root, string word)
{
    node *temp = root;
    for(int i=0; i<word.length(); i++)
    {
        char c = word[i];
        int index = getChildIndex(c);
        if(temp->child[index] == NULL)
            temp->child[index] = new node(c);    
        temp = temp->child[index];
        temp->suffixes++;
    }
}

void countWords(node *root, string word)
{
    node *temp = root;
    for(int i=0; i<word.size(); i++)
    {
        char c = word[i];
        int index = getChildIndex(c);
        if(temp->child[index] == NULL)
        {
            cout << "0\n";
            return;
        }
        temp = temp->child[index];
    }
    
    cout << temp->suffixes << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    
    node *root = new node('0');
    
    for(int i=0; i<n; i++)
    {
        string op, word;
        cin >> op >> word;
        
        if(op == "add")
        {
            addWord(root, word);
        }
        else
        {
            countWords(root, word);    
        }
    }
    return 0;
}
