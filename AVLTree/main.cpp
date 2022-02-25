//
//  main.cpp
//  AVLTree
//
//  Created by Jose Saldivar on 4/11/19.
//  Copyright © 2019 Jose Javier Saldivar. All rights reserved.
//

#include <iostream>
#include "AVLTree.h"
using namespace std;


int main ()
{
    AVLTree a;
    
    try{
        a.print ();
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
    try {
        a.remove(5);
    }
    catch (const char *e)
    {
        cout << e << endl;
    }

    
    //cin.get();
    
    a.append(3);
    a.append(8);
    a.append(5);
    a.append(12);
    a.append(9);
    a.remove(3);
    a.remove(5);
    
    try {
    
        a.remove (20);
        a.remove (8);
        a.remove(9);
        a.remove (12);
        
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
    
    try {
    a.print ();
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
   
    cout << "yee \n";
    
    
    /*
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.remove(1);
    a.append(1);
    a.append(0);
    a.append(5);
    a.append(6);
    a.append(7);
    a.append(8);
//    a.append(5);
    */
    
    /*
    a.append(10);
    a.append(15);
    a.append(12);
    a.append(11);
    a.append(9);
    a.append(8);*/
    
  //  a.remove(8);
    //a.remove(9);
    
  //  a.append(16);

    
   /* a.append(10);
    a.append(2);
    a.append(20);
    a.append(1);
    a.append(3);
    a.append(0);
    a.append(30);
    a.append(40);
    a.append(50);
    a.append(60);
    
  //  a.remove(20);*/
   
    bool found = a.find (9);
    
    if (found == true)
        cout << "Found.\n";
    else
        cout << "Not found.\n";
    
    cout << "Yee.\n";
}

