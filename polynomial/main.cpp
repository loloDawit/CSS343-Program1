//-----------------------------------------------------------------------------
// University of Washington
// CSS 343: Program-1
// main.cpp
// Created by Dawit Abera on 1/11/17.
// Instructor: Professor Wooyoung Kim
//  Created by Dawit Abera on 4/1/17.
//

//--------------------------  main.cpp  ----------------------------------------
// Main.cpp :Driver class for class polynomial the function initilizes objects
//           of the polynomial class and call functions.
//
// Assumption and Implementation Details:
//                    -- The header file was provided by the instructor
//                    -- a polynomial term with non-negative power
//                    --
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

#include "polynomial.h"

int main( ){
    
    Polynomial p1, test;
    
    p1.changeCoefficient( 1, 1 );
    
    p1.changeCoefficient( 5, 0 );
    
    p1.changeCoefficient( 7, 2 );
    
    p1.changeCoefficient( -2.8, 3 );
    
    cout << "p1 = " << p1 << endl;
    
    
    
    p1.changeCoefficient( 1, 2.2);
    p1+=test;
    
    cout << "p1 = " << p1 << endl;
    
    // test for -ve power
    test.changeCoefficient(4, -1);
    cout << test << endl;
    
    Polynomial testp2 = p1;
    
    testp2.changeCoefficient( 8.3, 2 );
    
    cout << "p1 = " << p1 << endl;
    
    cout << "p2 = " << testp2 << endl;
    
    
    
    Polynomial testp3 = p1 + testp2;
    
    cout << "p3 = " << testp3 << endl;
    
    cout << "-----------------------------------"<<endl;
    //Do more testing
    cout<<"-------CONSTRUCTOR TEST --------"<<endl;
    //Testing default constructor
    Polynomial p;
    cout<<"After the default constructor, p is:    "<<p<<endl;
    Polynomial pc(p);
    cout<<"After the copy constructor, pc is:    "<<pc<<endl;
    
    cout<<"-------MEMEBER FUNCTION TEST --------"<<endl;
         cout << endl; 
    
   // TEST FOR INSERT
    p.changeCoefficient(5,1);
    p.changeCoefficient(22,2);
    p.changeCoefficient(9,11);
    p.changeCoefficient(13,9);
    p.changeCoefficient(12,12);
 
    cout<<"After adding terms, p is:    "<<p<<endl;
    
    //Testing degree()
    cout<<"the degree of p1 is:    "<<p.degree()<<endl;
    
    //Testing coefficient()
    cout<<"The coefficient of the 1th power term is:\t"<<p.coefficient(1)<<endl;
    cout<<"The coefficient of the 2th power term is:\t"<<p.coefficient(2)<<endl;
    cout<<"The coefficient of the -11th power term is:\t"<<p.coefficient(-11)<<endl;
    cout<<"The coefficient of the 12th power term is:\t"<<p.coefficient(12)<<endl;
    cout<<endl;
    
    //Testing the copy constructor
    Polynomial p2(p);
    cout<<"After using the copy constructor, p2 is:    "<<p2<<endl;
    cout<<"the degree of p2 is:    "<<p2.degree()<<endl;
    cout << endl;
    
    cout<<"-------OPERATOR TEST --------"<<endl;
         cout << endl;
    //Testing ==
    cout<<"Test for == "<< "p==p2:    "<<(p==p2)<<endl;
    
    //Testing the = operator
    Polynomial p3 = p;
    cout<<"p1 is:    "<<p<<endl;
    cout<<"Polynomial p3 = p is:    "<<p3<<endl;
    
    //Testing changeCoefficient for removing(First term, middle term, last term)
    p2.changeCoefficient(4,12);
    p2.changeCoefficient(3,1);
    p2.changeCoefficient(2,3);
    p2.changeCoefficient(1,5);
    cout<<"After removing some terms, p2 is:    "<<p2<<endl;
    
    //Testing changeCoefficient for changing coefficients
    p2.changeCoefficient(120,2);
    cout<<"After changing a coefficient of the power 7 term, p2 is:    "<<p2<<endl;
    
 
    
    //Testing the != operator
    cout<<"p3!=p2:    "<<(p3!=p2)<<endl<<endl;
     cout << endl;
     cout<<"-------OPERATOR + - += -= TEST--------"<<endl;
         cout << endl;
   
    Polynomial p4;
    p4.changeCoefficient(10,10);
    p4.changeCoefficient(77,9);
    p4.changeCoefficient(6,12);
    p4.changeCoefficient(32,7);
    cout<<"p + p4 =\t "<<(p+p4)<<endl;
    cout<<"p - p4 =\t "<<(p-p4)<<endl;
   cout<<"p += p4 is:\t "<<(p+=p4)<<endl;
    p-=p4;
    cout<<"p -= p4 is:\t"<<(p-=p4)<<endl;
    cout<<endl;
    

    Polynomial p5;
    p5.changeCoefficient(4.5,10);
    p5.changeCoefficient(4.32,6);

    Polynomial p6;
    p6.changeCoefficient(4.5,10);
    p6.changeCoefficient(4.41,14);
    
    Polynomial p7;
    p7.changeCoefficient(1.11,20);
    p7.changeCoefficient(4.71,10);
    
    
    cout<<"p6 is:\t"<<p6<<endl;
    cout<<"p7 is:\t"<<p7<<endl;
    cout<<"p5 is:\t"<<p5<<endl;
    cout<<"p5 + p6 is:\t"<<(p5+p6)<<endl;
    cout<<"p5 + p7 is:\t"<<(p5+p7)<<endl;
    cout<<"p7 + p6 is:\t"<<(p7+p6)<<endl;
    cout<<"p5 - p7 is:\t"<<(p5-p7)<<endl;
    cout<<"p7 - p6 is:\t"<<(p7-p6)<<endl;
    cout<<"p6 - p5 is:\t"<<(p5-p6)<<endl;
    
    cout<<endl;

    return 0;
}



