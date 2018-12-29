#include <iostream>
#include "NodeTypes.h"
#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"
#include "BinarySearchTree.h"
#include <fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
BTNode * bst , *new_bst;
int choise;
string word , out= ("Binary Search Tree (BST)\n---------------------------------------------\n\n1. Create BST from Dictionary\n2. Add Word to BST\n3. Delete Word from BST\n4. Search for Word in BST\n5. Traverse BST\n6. What Comes Before Word in BST? \n7. What Comes After Word in BST?\n8. Compare BSTs\n9. Statistics\nQ. Quit\n\nPlease enter an option: ");
string dic1 = "dictionary1" , dic2="dictionary2" , dic3 ="dictionary3";

int main () {
    bst = NULL ;
     new_bst = NULL ;

	while(1)
    {
        new_bst = NULL;
        cout<< out ;
        cin >>word ;
        cout<< '\n';
        if (word == "Q" || word == "q")
            return 0;
        choise = word[0]-'0';
        if (choise== 1)
        {
           cout<< "Please enter the name of the dictionary file or M (Menu): " ;


           cin >>word;
           cout << "\n";
           if (word == "M" || word == "m")
                continue ;
            ifstream myReadFile ;
            myReadFile.open(word + ".txt");
                while(myReadFile>> word)
                new_bst= insert(new_bst, word);
                //---------------------------
            myReadFile.clear();
            myReadFile.close();
            bst = new_bst ;
        }
        else if (choise == 2)
        {
            cout <<"Please enter the word to insert in the BST or M (Menu):";
            cin >>word ;
            cout << "\n";
           if (word == "M" || word == "m")
                continue ;
            bst= insert(bst, word) ;
        }
        else if(choise == 3)
        {
            cout << "Please enter the word to delete from the BST or M (Menu):\n";
            cin >>word ;
           cout << "\n";
           if (word == "M" || word == "m")
                continue ;
           bst= deleteNode(bst, word);

        }
        else if (choise == 4)
        {

            cout << "Please enter a word to search for or M (Menu):\n";
            cin >>word ;
           cout << "\n";
           if (word == "M" || word == "m")
                continue ;
            if (contains(bst, word))
                cout << "The word is in the dictionary\n";
            else cout << "The word is not in the dictionary \n";
        }
        else if (choise == 5)
        {
            cout << " pre-order traversal\n";
            preOrderIterative(bst);
            cout<<"\n\n";
            cout << "IN-order Traversal\n";
            inOrderIterative(bst);
            cout << "\n\n";
            cout << "Post-order Traversal\n";
            postOrderIterative(bst);
            cout<<"\n\n";
            cout<< "Level-order Traversal\n";
            levelOrder(bst);
            cout <<"\n\n";


        }
        else if(choise == 6)
        {
            cin >> word;
            string s = findPredecessor(bst, word);
            if (s.empty())
                cout << "NO Predecessor Found\n";
            else cout << "The Predecessor of " << word << " is " << s << endl;


            //inOrderPredecessor()
        }
        else if (choise == 7)
        {
            cin >> word;
            string s = findSuccessor(bst, word);
            if (s.empty())
                cout << "NO Successor Found\n";
            else cout << "The Successor of " << word << " is " << s << endl;




        }
        else if (choise == 8)
        {
            cout << "Please enter the name of the file to create the BST or M (Menu):\n";
            cin >>word ;
            cout << "\n";
            if (word == "M" || word == "m")
                continue ;
           ifstream myReadFile ;
            myReadFile.open(word + ".txt");
                while(myReadFile>> word)
                new_bst= insert(new_bst, word);
                //---------------------------
            myReadFile.clear();
            myReadFile.close();
            if (isEqual(new_bst , bst))
                cout << "Equal BSTs\n";
            else cout << "Not Equal\n";

        }
        else if (choise == 9)
        {
            cout << "Number of nodes = ";
            cout << moment(bst)<< "\n";
            cout<< "Tree Height = "<< height(bst) << "\n";
            cout << "Tree width = " << width(bst) << "\n";
           cout << "Tree Weight = " << weight(bst)<< "\n";
            cout << "Number of levels = " << numLevels(bst)<< "\n";
            cout << "Smallest word is " << (min(bst)->data) << "\n";
            cout << "Largest Word is " << (max(bst)->data) << "\n";
        }
        else cout << "-----------****INVALID INPUT\N****--------\n";
    }

	return 0;
}
