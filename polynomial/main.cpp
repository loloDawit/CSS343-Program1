////
////  main.cpp
////  polynomial
////
////  Created by Dawit Abera on 4/1/17.
////  Copyright © 2017 University of Washington. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
//#include "polynomial.h"
//
//int main( )
//
//{
//    
//    Polynomial p1;
//    
//     Polynomial p2 = p1;
//    
////    p1.changeCoefficient( 1, 1 );
////    
////    p1.changeCoefficient( 4, 4 );
////    
////    p1.changeCoefficient( 2.2, 2 );
////    
////    p1.changeCoefficient( -3.8, 3 );
////    
////    cout << "p1 = " << p1 << endl;
////    
////    
////    
////    p1.changeCoefficient( 0, 2 );
//    
//    cout << "p2 = " << p2 << endl;
//    
//    
//    
//   
//    
////    p2.changeCoefficient( 9.5, 2 );
////    
////    cout << "p1 = " << p1 << endl;
////    
////    cout << "p2 = " << p2 << endl;
////    
////    
////    
////    Polynomial p3 = p1 + p2;
////    
////    cout << "p3 = " << p3 << endl;
////    polyType polyType::operator=(const polyType &rhs)
////    {
////        delete polyPtr;
////        
////        termNode * orig = rhs.polyPtr;
////        termNode * newP = NULL;
////        
////        polyPtr = NULL;
////        
////        while(orig != NULL)
////        {
////            if(newP == NULL)
////            {
////                polyPtr = new termNode;
////                polyPtr->exp  = orig->exp;
////                polyPtr->coef = orig->coef;
////                polyPtr->next = NULL;
////                newP = polyPtr;
////            }
////            else
////            {
////                newP->next = new termNode;
////                newP = newP->next;
////                newP->exp = orig->exp;
////                newP->coef = orig->coef;
////                newP->next = NULL;
////            }
////            orig = orig->next;
////        }
////        
////        return *this;
//}


#include <iostream>
using namespace std;

class polyll {
private:
    struct polynode {
        float coeff;
        int exp;
        polynode* link;
    }
    * head;
    
public:
    polyll();
    void poly_append(float c, int e);
    void display_poly();
    void poly_add(polyll& l1, polyll& l2);
    ~polyll();
};
polyll::polyll()
{
    head = NULL;
}
void polyll::poly_append(float c, int e)
{
    if(e < 0)
        return;
    if(e == 0)
        c=1;
    polynode* temp = head;
    if (temp == NULL) {
        temp = new polynode;
        head = temp;
    }
    else {
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = new polynode;
        temp = temp->link;
    }
    temp->coeff = c;
    temp->exp = e;
    temp->link = NULL;
}
void polyll::display_poly()
{
    polynode* temp = head;
    int f = 0;
    
    cout << endl;
    while (temp != NULL) {
        if (f != 0) {
            if (temp->coeff > 0)
        cout << " + ";
    else
        cout << " ";
        } if (temp->exp != 0)
            cout << temp->coeff << "x^" << temp->exp;
        else
            cout << temp->coeff;
        temp = temp->link;
        f = 1;
    }
    cout << endl; 
}
void polyll::poly_add(polyll& l1, polyll& l2)
{
    polynode* z = nullptr;
    if (l1.head == NULL && l2.head == NULL)
        return;
    polynode *temp1, *temp2;
    temp1 = l1.head;
    temp2 = l2.head;
    while (temp1 != NULL && temp2 != NULL) {
        if (head == NULL) {
            head = new polynode;
            z = head;
        }
        else {
            z->link = new polynode;
            z = z->link;
        }
        if (temp1->exp < temp2->exp) {
            z->coeff = temp2->coeff;
            z->exp = temp2->exp;
            temp2 = temp2->link;
        }
        else {
            if (temp1->exp > temp2->exp) {
                z->coeff = temp1->coeff;
                z->exp = temp1->exp;
                temp1 = temp1->link;
            }
            else {
                if (temp1->exp == temp2->exp) {
                    z->coeff = temp1->coeff + temp2->coeff;
                    z->exp = temp1->exp;
                    temp1 = temp1->link;
                    temp2 = temp2->link;
                }
            }
        }
    }
    while (temp1 != NULL) {
        if (head == NULL) {
            head = new polynode;
            z = head;
        }
        else {
            z->link = new polynode;
            z = z->link;
        }
        z->coeff = temp1->coeff;
        z->exp = temp1->exp;
        temp1 = temp1->link;
    }
    while (temp2 != NULL) {
        if (head == NULL) {
            head = new polynode;
            z = head;
        }
        else {
            z->link = new polynode;
            z = z->link;
        }
        z->coeff = temp2->coeff;
        z->exp = temp2->exp;
        temp2 = temp2->link;
    }
    z->link = NULL;
}
polyll::~polyll()
{
    polynode* q;
    while (head != NULL) {
        q = head->link;
        delete head;
        head = q;
    }
}
int main()
{
    polyll p1;
    p1.poly_append(1.4, 5);
    p1.poly_append(1.5, 4);
    p1.poly_append(1.7, 2);
    p1.poly_append(1.8, 1);
    p1.poly_append(1.9, 0);
    cout << "\nFirst polynomial:";
    p1.display_poly();
    polyll p2;
    p2.poly_append(1.5, 6);
    p2.poly_append(2.5, 5);
    p2.poly_append(-3.5, 4);
    p2.poly_append(4.5, 3);
    p2.poly_append(6.5, 0);
    cout << "\nSecond polynomial:";
    p2.display_poly();
    polyll p3;
    p3.poly_add(p1, p2);
    cout << "\nResultant polynomial: ";
    p3.display_poly();
  //  getch();
}
