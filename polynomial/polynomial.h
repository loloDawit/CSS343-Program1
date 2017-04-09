#ifndef polynomial_h
#define polynomial_h
//-----------------------------------------------------------------------------
// University of Washington
// CSS 343: Program-1
// polynomial.hpp
// Created by Dawit Abera on 1/11/17.
// Instructor: Professor Wooyoung Kim

//--------------------------  class Polynomial ---------------------------------
// ADT Polynomial:A polynomial is a mathematical expression involving a sum of
//                powers in one or more variables multiplied by coefficients.
//                A polynomial in one variable (i.e., a univariate polynomial)
//                with constant coefficients is given by
//
//                     a_nx^n+...+a_2x^2+a_1x+a_0.
//
// The specification of our ADT polynomial has the following public functions:
//                 -- int degree( ) const; // returns the degree of a polynomial
//                 -- double coefficient( const int power ) const; returns the
//                    coefficient of the x^power term.
//                 -- bool changeCoefficient( const double newCoefficient,
//                    const int power );
//                 -- overloaded operarors << + = - += -+ == !=
//
// Assumption and Implementation Details:
//                    -- The header file was provided by the instructor
//                    -- a polynomial term with non-negative power
//                    -- 
//------------------------------------------------------------------------------

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Polynomial {
    // Overloaded <<: prints Cn * x^n + Cn-1 * X^n-1 + ... C1 * X + C0
    /**
     Operator <<
     Output operator for class polynomial, print data, resposibility for output
     is left to object stored in the polynomial
     
     @param output        used to overload the cout object
     @param p passed by reference to print its data content
     
     @return an overload print statement
     */
    friend ostream& operator<<( ostream &output, const Polynomial& p );
    // Constructor: the default is a 0-degree polynomial with 0.0 coefficient
public:
    //-------------------------------CONSTRUCTOR--------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object with a doubly-
     * linked circular list with a dummy header.
     *
     * Precondtion: N/A
     *
     * Postcondtion: A polynomial object with circular linked list is created
     */
   
    Polynomial( );
    
    //--------------------------------------------------------------------------
    /*
     * Copy Constructor
     * The copy constructor constructs and creates a deep copy of an object by
     initializing it with an object of the same class, which has been created
     previously.
     *
     * Precondtion: The list must not be empty and head is expected to be not 
                    NULL
     *
     * Postcondtion: The left and right part of the object must be identical. 
                    Each
     object in copied.
     */
    
    Polynomial( const Polynomial& p );
    
    //--------------------------------------------------------------------------
    /*
     * Destructor
     * The destructor deallocates memory, delete every node and points head to
     * nullptr
     *
     * Precondtion:
     *
     * Postcondtion: Memory is deallocated
     */
    
    ~Polynomial( );
    
    //-----------------------------Member functions-----------------------------
    /**
     The maximum polynomial with the leading term's degree is returned
     
     Pre-condition:a polynomial list with head not equal to null exist
     
     @return a value is returned based on the request
     */
    
    int degree( ) const;                  
    
    //--------------------------------------------------------------------------
    /**
     Function returns the cofficient of a polynomial based on param power.
     
     Pre-condition: a polynomial list with head not equal to null exist
     
     @param power An integer to represent the polynomial degree
     
     @return a value is returned based the param power.
     */
    
    double coefficient( const int power ) const;
    
    //--------------------------------------------------------------------------
    /**
     changes the polynomials coeffcient bases on the param or inserts new 
     polynomial to the list based on the param. The function calls both private 
     functions insert and remove to do the task.
     
     @param newCoefficient a value thats double in its type used as coefficient
     @param power          a value thats an int in its type used as the power
     
     @return a new polynomial is either inserted to an existing polyomial or the
     existing polynomials coefficient is changed.
     */
    
    bool changeCoefficient( const double newCoefficient, const int power );
    
    //--------------------------------------------------------------------------
    
    //--------------------------Arithmetic operators----------------------------
    /**
     Overloaded arthimetic operator +
     Takes two non-zero polynomial objects and add like terms
     
     Pre-conditions: head != nullptr
     
     @param p the polynomial object to be added
     
     @return the left side object is returned if the param is 0. otherwise the 
     sum of the polynomial objects is retuened
     */
    Polynomial operator+( const Polynomial& p ) const;
    
    //--------------------------------------------------------------------------
    /**
     Overloaded arthimetic operator -
     Takes two non-zero polynomial objects and substract like terms
     
     Pre-conditions: head != nullptr
     
     @param p the polynomial object to be substructed
     
     @return the left side object is returned if the param is 0. otherwise the
     different of the polynomial objects is retuened
     */
    
    Polynomial operator-( const Polynomial& p ) const;
    
    //--------------------------------------------------------------------------
    
    //-------------------------Boolean comparison operators---------------------
    /**
     checks if two polynomial terms are identical or not
     
     Pre-condtion: head != nullptr
     
     @param p the object to be copied
     
     @return a boolean value if returned based on the condition
     */
    
    bool operator==( const Polynomial& p ) const;
    
    //--------------------------------------------------------------------------
    /**
     checks if two polynomial terms are identical or not
     
     @param p head != nullptr
     
     @return a boolean value if returned based on the condition
     */
    
    bool operator!=( const Polynomial& p ) const;
    
    //--------------------------------------------------------------------------
    
    //-----------------------------Assignment operators-------------------------
    /**
     Overloaded assignment operator  =
     Make a deep copy of the left object into the right parameter object
     
     Pre-condtion: The param is already initilized
     
     @param p object where term this is copied to
     
     @return the param this must have the same objects as the left
     */
    
     Polynomial& operator=( const Polynomial& p );
    
    //--------------------------------------------------------------------------
    /**
     overloaded operator +=
     Takes two polynomials object and adds the like terms and save the result to
     this object
     
     Pre-conditions: head != nullptr
     
     @param p the polynomial object to be added
     
     @return the left side object is returned if the param is 0. otherwise the
     different of the polynomial objects is retuened
     */
    Polynomial& operator+=( const Polynomial& p );
    
    //--------------------------------------------------------------------------
    /**
     overloaded operator -=
     Takes two polynomials object and substracts the like terms and save the 
     result to this object
     
     Pre-conditions: head != nullptr
     
     @param p the polynomial object to be substructed
     
     @return the left side object is returned if the param is 0. otherwise the
     different of the polynomial objects is retuened
     */
    
    Polynomial& operator-=( const Polynomial& p );
    
    //--------------------------------------------------------------------------
private:
    
    struct Term {                             // a term on the sparce polynomial
        
        double coeff;                         // the coefficient of each term
        
        int power;                                    // the degree of each term
        
        Term *prev;                     // a pointer to the previous higher term
        Term *next;                          // a pointer to the next lower term
    };
    int size;                               // # terms in the sparce polynomial
    Term *head;            // a pointer to the doubly-linked circular list of
    
    // sparce polynomial
    //--------------------------------------------------------------------------
    /**
     Inserts new polynomial to the list based on the param specification and 
     returns boolean value. The function checks multiple stages before inserting 
     an item to the polynomial list. If param to be inserted is has a term power 
     is greater than what already exist in the param as a leading term. 
     The function checks to insure the final insert to be in the standard 
     form a_0x^n+a_1x^(n-1)+...+a_(n-1)x+a_n=0
     
     @param prev           pointer to the next object
     @param newCoefficient new value to be inserted as a coefficient
     @param power          new int value to be inserted as power
     
     @return new item is insereted to the polynomial list
     */
    
    bool insert( Term* prev, const double newCoefficient, const int power );
    
    //--------------------------------------------------------------------------
    /**
     removes the polynomial term from the list based the function call
     
     Pre-condtion: head != nullptr
     
     @param pos head pointer to the term object
     
     @return removes the param object passed as argu
     */
    
    bool remove( Term* pos );
};



#endif /* polynomial_h */
