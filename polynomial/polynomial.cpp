//
//  polynomial.cpp
//  polynomial
//
//  Created by Dawit Abera on 4/1/17.
//  Copyright © 2017 University of Washington. All rights reserved.
//

#include "polynomial.h"
/*
 * Operator << 
 * Output operator for class polynomial, print data, resposibility for output is
 * left to object stored in the polynomial
 */

ostream& operator <<(ostream &output, const Polynomial& thePolynomial){
   
    if(thePolynomial.head == NULL){
        output <<"List is Empty!" << endl;
        return output;
    }
    int check = 0;
    Polynomial::Term *current = thePolynomial.head;
    while (current != NULL) {
        
        if(check !=0){
            
            if(current ->coeff > 0)
                output << " + ";
            else
                output << " " ;
        }if(current ->power != 0)
                output << current ->coeff << "x^" << current ->power;
            else
                output << current ->coeff;
        
        current = current ->next;
            check = 1;
    }
    output<<endl;
    return output;
}
//--------------------------------CONSTRUCTORS----------------------------------
/*
 * Default Constructor 
 * The default constructor creates and initializes the object
 *
 * Precondtion:
 *
 * Postcondtion:
 */
//------------------------------------------------------------------------------
Polynomial::Polynomial(){
    Term term;
    term.coeff = 0;
    term.power = 0; 
    head = NULL;
    size = 0;
}

//------------------------------------------------------------------------------
/*
 * Copy Constructor
 * The default constructor creates and initializes the object
 *
 * Precondtion:
 *
 * Postcondtion:
 */

Polynomial::Polynomial(const Polynomial& rightPoly){
    
    Term *last;                    // pointer to the last node
    if(rightPoly.head == NULL){
        
        head = NULL;
        last = NULL;
        size = 0;
        return;
        
    }else{
        // create a new node
        Term *newPtr = new Term;
 
        Term *current;                // to traverse the list
       
        current = rightPoly.head;    // current points to the list to be copied
        size = rightPoly.size;
        
        head ->coeff = current ->coeff;
        head ->power = current ->power;
        head ->next = current ->next;
        head ->prev = current ->prev;
      
        last = head;                    // make last point to head
        
        current = current ->next;
        while(current!=NULL){
            newPtr = new Term;
            newPtr ->coeff = current ->coeff;
            newPtr ->power = current ->power;
            newPtr ->prev = current ->prev;
            last ->next = newPtr;
            last = newPtr;
            current = current ->next;
        }
        current ->next = NULL; 
    }
    
    
    
}

//------------------------------------------------------------------------------
/*
 * Destructor 
 * The destructor deallocates memory, delete every node and points head to 
 * nullptr
 *
 * Precondtion:
 *
 * Postcondtion: Memory is deallocated
 */
Polynomial::~Polynomial(){
  
    if(head == NULL)
        return;
    
    else{

        Term *temp = head;
        
        // delete the head fist
        head = head ->next;
        temp = NULL;
        
        // delete the rest of the node next
        Term *current = head;
        while (current!=NULL) {
            current = current ->next;
            delete current;
            current = nullptr;
        }
    }
    
}

//------------------------------------------------------------------------------
/*
 * operator =
 * Make a deep copy of the right object into the left parameter object
 *
 * Precondtion:
 *
 * Postcondtion:
 */
 Polynomial& Polynomial::operator=(const Polynomial &rightpoly){
    
     // check for self assignment
     if(&rightpoly !=this){
         // clear this
         if(head !=NULL)
             delete this;
         if(rightpoly.head == NULL)
             return *this;
         // make new node for the head
         Term *ptr = new Term;
         
         head = ptr;
         Term *curRight = rightpoly.head ->next;
         Term *curLeft = ptr;
         
         // traverse the list, making a new node and copying data
         // until rightpoly is empty
         while (curRight !=NULL) {
             curLeft ->next = new Term;
             curLeft = curLeft ->next;
             curRight = curRight ->next;
         }
         curLeft ->next = NULL;
     }
     return *this;

}
//------------------------------------------------------------------------------
/*
 * operator ==
 * returns true if the list are identical
 *
 * Precondtion:
 *
 * Postcondtion:
 */
bool Polynomial::operator==(const Polynomial &rightpoly)const{
    
    Term *current = head;
    Term *currentRight = rightpoly.head;
    
    while (current != NULL && currentRight != NULL) {
        
        if(current ->coeff != currentRight ->coeff || current ->power !=
           currentRight ->power)
            return false;
        current = current ->next;
        currentRight = currentRight ->next;
        
    }
    // could have existed the loop because either list reached its end
    // check each condition explicitly
    if((current == NULL && currentRight != NULL) ||
       (current !=NULL && currentRight == NULL))
        return false;
    else
    
        return true;
    
}
//------------------------------------------------------------------------------
/*
 * operator !=
 * returns true if the list are not equal
 *
 * Precondtion:
 *
 * Postcondtion:
 */
bool Polynomial::operator!=(const Polynomial &rightpoly)const{
    
    return !(*this == rightpoly);
    
}

/**
 <#Description#>

 @param rightPoly <#rightPoly description#>

 @return <#return value description#>
 */
Polynomial Polynomial:: operator+( const Polynomial& rightPoly ) const{
    
  
    Polynomial *result = new Polynomial;
    *result = *this;
    *result +=rightPoly;
    return *result;
    
    
}
/**
 <#Description#>

 @param rightPoly <#rightPoly description#>

 @return <#return value description#>
 */
Polynomial Polynomial:: operator-( const Polynomial& rightPoly ) const{
    
    
    Polynomial *result = new Polynomial;
    *result = *this;
    *result -=rightPoly;
    return *result;
    
}
/**
 <#Description#>

 @param rightPoly <#rightPoly description#>

 @return <#return value description#>
 */
Polynomial& Polynomial:: operator+=( const Polynomial& rightPoly ){
    
    *this = *this + rightPoly;
    return *this;
}


/**
 <#Description#>

 @param rightPoly <#rightPoly description#>

 @return <#return value description#>
 */
Polynomial& Polynomial:: operator-=( const Polynomial& rightPoly ){
    
    *this = *this - rightPoly;
    return *this;
}

/**
 <#Description#>

 @return <#return value description#>
 */
int Polynomial::degree()const{
    
    re
}


