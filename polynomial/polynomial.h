#ifndef polynomial_h
#define polynomial_h
//-----------------------------------------------------------------------------
// University of Washington
// CSS 343: Program-1
// polynomial.hpp
// Created by Dawit Abera on 1/11/17.
// Instructor: Professor Wooyoung Kim

// Assumption and Implementation Details:
//                    -- The header file was provided by the instructor
//                    -- Format of the input file is correct
//                    -- 
//------------------------------------------------------------------------------

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Polynomial {
    // Overloaded <<: prints Cn * x^n + Cn-1 * X^n-1 + ... C1 * X + C0
    friend ostream& operator<<( ostream &output, const Polynomial& p );
    // Constructor: the default is a 0-degree polynomial with 0.0 coefficient
public:
    //-------------------------------CONSTRUCTOR--------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    Polynomial( );
    
    //--------------------------------------------------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    Polynomial( const Polynomial& p );
    
    //--------------------------------------------------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    ~Polynomial( );
    
    //-----------------------------Member functions-----------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    int degree( ) const;                   // returns the degree of a polynomial
    
    //--------------------------------------------------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    double coefficient( const int power ) const;
    
    //--------------------------------------------------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    bool changeCoefficient( const double newCoefficient, const int power );
    
    //--------------------------------------------------------------------------
    
    //--------------------------Arithmetic operators----------------------------
    /*
     * Operator +
     * Addes two polynomial objects and returns a new polynomial
     *
     * Precondtion:
     *
     * Postcondtion: new polymonial objects is returned
     */
    
    /**
     Operator +

     @param rightPoly Addes two polynomial objects and returns a new polynomial

     @return A union of two polynomials objects is returned.
     */
    Polynomial operator+( const Polynomial& rightPoly ) const;
    
    //--------------------------------------------------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    Polynomial operator-( const Polynomial& p ) const;
    
    //--------------------------------------------------------------------------
    
    //-------------------------Boolean comparison operators---------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    bool operator==( const Polynomial& p ) const;
    
    //--------------------------------------------------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    bool operator!=( const Polynomial& p ) const;
    
    //--------------------------------------------------------------------------
    
    //-----------------------------Assignment operators-------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
     Polynomial& operator=( const Polynomial& p );
    
    //--------------------------------------------------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    Polynomial& operator+=( const Polynomial& p );
    
    //--------------------------------------------------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
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
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    bool insert( Term* prev, const double newCoefficient, const int power );
    
    //--------------------------------------------------------------------------
    /*
     * Default Constructor
     * The default constructor creates and initializes the object
     *
     * Precondtion:
     *
     * Postcondtion:
     */
    
    bool remove( Term* pos );
};



#endif /* polynomial_h */
