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
   
    // needs to be tested
    
    Polynomial::Term *current = thePolynomial.head;
    while (current != NULL) {
        output << current->coeff;
        output << "x^" << current->power<<endl;
        current = current ->next;
    }
    
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
    head = nullptr;
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

Polynomial::Polynomial(const Polynomial& polyObj){
    
 //   return *this =
    
}

//------------------------------------------------------------------------------
/*
 * Destructor 
 * The default constructor creates and initializes the object
 *
 * Precondtion:
 *
 * Postcondtion:
 */
Polynomial::~Polynomial(){
    
}
