//
//  polynomial.cpp
//  polynomial
//
//  Created by Dawit Abera on 4/1/17.
//  Copyright © 2017 University of Washington. All rights reserved.
//

#include "polynomial.h"
//------------------------------- OPERATOR << ----------------------------------
/**
 Operator <<
 Output operator for class polynomial, print data, resposibility for output is
 left to object stored in the polynomial

 @param output        used to overload the cout object
 @param printPoly passed by reference to print its data content

 @return an overload print statement
 */
//------------------------------------------------------------------------------
ostream& operator <<(ostream &output, const Polynomial& printPoly){
   
    // check empty list first
    // if the list is empty print 0 and stop.
    if (printPoly.head==NULL||printPoly.size==0){
     
        output << "0" <<endl;
        return output;
    }
    
    // Handel constant terms and keep tracking to print it at the end of the
    // polynomial list Coeff_const saves the value for the constant term
    bool check_const = false;
    double Coeff_const = 0.0;
    
    // If the term is not constant, creat a new Term object
    Polynomial:: Term *current = printPoly.head->next;
    
    // constant terms can be identifed by thier power, so check the power first
    if(current->power == 0){
        
        // the term is constant, remeber it and save the value so it can be
        // printed at the end
        check_const = true;
        Coeff_const = current ->coeff;
        
    }
    // if the term has power = 1, print x as coefficient and x becomes the term
    else if(current ->power== 1){
        
        if(current ->coeff == 1){
            output<<"x";
            
        }
        else{
            //otheriwse print x  as coefficient for each term
            output<<current ->coeff<<"x";
            
        }
    }
    
    // print one if the polynomial term has a power = 0
    else if(current ->power == 0){
        
        return output<< " 1 ";
        
    }
    // print 0 i the polynomial term has a power < 0. By definition a polynimial
    // can not have a negative power.
    else if(current ->power < 1){
        
       return  output<<"Not defined!!!";
        
    }
    else if (current ->coeff == 0){
        
        return output << "";
    }
    
    // At this point, the polynomial term is not constant or it has a power > 1
    else{
        
        // if we incounter a term with coefficient = 1, print
        // x
        if(current ->coeff == 1){
            
            output<<"x^"<<current ->power;
   	    }
        
        // otherwise print x^ before the coefficient
        else{
            
            output<<current ->coeff<<"x^"<<current ->power;
            
        }
    }
    
    // No need to traverse the list if we only have one polynomial term
    if(current ->next == printPoly.head){
        
        output << endl;
        current = NULL;
        delete current;
        return output;
        
    }
    
    // To handel a polynomial that has negative coeffiecint, just print space
    if(current ->next ->coeff < 0 && current ->next ->power != 0){
        
        output<<" ";
      
    }
    
    // But if we have a positive term, print " + "
     if(current ->next ->coeff >0 && current ->next ->power != 0){
         
        output<<" + ";
         
    }
    // advance
    current = current ->next;
    
    // Now start traversing the list
    while(current != printPoly.head){
        
        // do the same thing again, if we have a term with power = 0, save the
        // value and print it at last
        if(current ->power==0){
            
            check_const = true;
            Coeff_const = current ->coeff;
            return output << " + 1 " ; 
            
        }
        //test
        else if (current ->coeff == 0){
            
             break;
        }
        // again do the same thing, if the power = 1, print x as instead of term
        else if(current ->power==1){
            
            if(current ->coeff==1){
                
                output<<"x";
            }
            
            else{
                // otherwise print coefficient x
                output<<current ->coeff<<"x";
                
            }
            
        }
        // A polynomial with power less than zero is not a polynomial
        else if(current ->power < 0){
            
            // The polynomials a Laurent polynomial.
           return output << " '0' ";
            
        }
        else{
        
            // otherwise print print x and x^ depending on the terms power
            if(current ->coeff==1){
                
                output<<"x^"<<current ->power;
                
            }
            else{
                
                    output<<current ->coeff<<"x^"<<current ->power;
              
            }
        }
        
        // now we are the end
        if(current ->next == printPoly.head){
            if(check_const == true){
                
                    output<<" + "<< Coeff_const;
               
            }
          
            output << endl;
            current = NULL;
            delete current;
            return output;
            
        }
        // at this point prev is not at end keep going
        // if the next term is not constant and the coefficent is positive
        if(current ->next ->coeff > 0 && current ->next ->power != 0){
            
            output<<" + ";
           
        }
        // advace to the next term
        current = current ->next;
    
    }
    
    current = NULL;
    delete current;
    return output;
    
}

//------------------------------- CONSTRUCTORS ---------------------------------
/*
 * Default Constructor 
 * The default constructor creates and initializes the object with a doubly-
 * linked circular list with a dummy header.
 *
 * Precondtion: N/A
 *
 * Postcondtion: A polynomial object with circular linked list is created
 */
//------------------------------------------------------------------------------

Polynomial::Polynomial():head(NULL){
   
   // creat a dummy header
    head = new Term;
    
    // create the circular linked list
    head->next=head;
    head->prev=head;
    
    // initialize the coefficient and power of the term object
    head->power=0;//initialize
    head->coeff=0.0;//initialize
    
    // finally set the size to zero
    size=0;//initialize

}

//------------------------------------------------------------------------------
/*
 * Copy Constructor
 * The copy constructor constructs and creates a deep copy of an object by 
   initializing it with an object of the same class, which has been created 
   previously.
 *
 * Precondtion: The list must not be empty and head is expected to be not NULL
 *
 * Postcondtion: The left and right part of the object must be identical. Each 
                 object in copied.
 */
//------------------------------------------------------------------------------

Polynomial::Polynomial(const Polynomial& rightPoly){
    
    // first initialize the head
    head = new Term;
    
    // create a circular linked list < -- >
    head ->next = head;
    head ->prev = head;
    
    // set and initialize the Term values
    head ->coeff = 0;
    head ->power = 0;
    
    // set size to 0
    size = 0;
    
    // now call the assigment operator to finialize the deep copying
    *this = rightPoly;
 
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
//------------------------------------------------------------------------------

Polynomial::~Polynomial(){
  
    // check for empty list first
    if(head == NULL || size == 0)
        return;
    
    // special case where the polynomial has one term
    if(size == 1){
        
        remove(head ->next);
        delete head;
        head = NULL;
        return;
        
    }
    
        // first term is already taken care off , move to the second polynomial
        // term
        Term *current = head ->next ->next;
        
        // delete the rest of the node next
        
        while (current!= head) {
            
            // delete the term before current and advance
            remove(current ->prev);
            current = current ->next;
            
        }
    
    // finally delete the last term
    remove(current ->next);
    delete head;
    head = NULL; 
    
}

//----------------------------OVERLOADED OPERATORS------------------------------
 /**
  Overloaded assignment operator  =
  Make a deep copy of the left object into the right parameter object
  
  Pre-condtion: The param is already initilized

  @param rightpoly object where term this is copied to

  @return the param this must have the same objects as the left
  */
//------------------------------------------------------------------------------

 Polynomial& Polynomial::operator = (const Polynomial &rightpoly){
     
     // check size first
     if(rightpoly.size == 0){
         
         return *this;
     }
     
     // travertse the list and copy everything
     Term *traverse = rightpoly.head ->next;
     
     while(traverse != rightpoly.head){
         
         // call function changeCoefficient to add the rightpoly
         changeCoefficient(traverse ->coeff,traverse ->power);
         traverse = traverse ->next;
         
     }
     
     traverse = NULL;
     delete traverse;
     return *this;
}

//------------------------------------------------------------------------------
/**
 checks if two polynomial terms are identical or not 
 
 Pre-condtion: head != nullptr

 @param rightpoly the object to be copied

 @return a boolean value if returned based on the condition
 */
//------------------------------------------------------------------------------

bool Polynomial::operator == (const Polynomial &rightpoly)const{
    
    Term *current = head ->next;
    Term *currentRight = rightpoly.head ->next;
    
    while (current != head && currentRight != head) {
        
        if(current ->coeff != currentRight ->coeff || current ->power !=
           currentRight ->power)
            return false;
        
        current = current ->next;
        currentRight = currentRight ->next;
        
    }
    // could have existed the loop because either list reached its end
    // check each condition explicitly
    if((current == head && currentRight != head) ||
       (current !=head && currentRight == head))
        
        return false;
    
    else
    
        return true;
    
}

//------------------------------------------------------------------------------

/**
 checks if two polynomial terms are identical or not

 @param rightpoly head != nullptr

 @return a boolean value if returned based on the condition
 */
//------------------------------------------------------------------------------

bool Polynomial::operator!=(const Polynomial &rightpoly)const{
    
    return !(*this == rightpoly);
    
}

//------------------------------------------------------------------------------
/**
 Overloaded arthimetic operator +
 Takes two non-zero polynomial objects and add like terms
 
 Pre-conditions: head != nullptr

 @param rightpoly the polynomial object to be added

 @return the left side object is returned if the param is 0. otherwise the sum 
         of the polynomial objects is retuened
 */
//------------------------------------------------------------------------------

Polynomial Polynomial:: operator + ( const Polynomial& rightpoly ) const{
    
    // create a polynomial object and it has 'this object' as it param
    Polynomial sum(*this);
    
    // crate another polynomial object and as copy of the param 'rightpoly'
    Polynomial polyadd(rightpoly);//create a copy of the param
    
    // to traverse the list
    Term *currentLeft;
    Term *currentRight = polyadd.head->next;
    
    // to keep track and add each like terms in the polynomial list
    bool like_terms = false;
    
    while(currentRight != polyadd.head){
        
        // assume no like term exists at the start
        like_terms = false;
        currentLeft = sum.head->next;
        
        while(currentLeft != sum.head){
            
            //if the current term has common powers in both sum and polyadd
            if(currentRight ->power == currentLeft ->power){
                
                //combine like terms
                sum.changeCoefficient(currentLeft ->coeff + currentRight->coeff,
                                      currentLeft ->power);
                like_terms = true;
                
            }
            
            // advance
            currentLeft = currentLeft ->next;
            
        }
        
        // move to the next loop, we already have all the like terms in the
        // polynomial list
        if(!like_terms){
            
            // add
            sum.changeCoefficient(currentRight ->coeff,currentRight ->power);
            
        }
        
        currentRight = currentRight ->next;//move on to the next term of p2
        
    }
    
    return sum;

}

//-----------------------------ARITHMETIC OPERATORS-----------------------------
/**
 Overloaded arthimetic operator -
 Takes two non-zero polynomial objects and substract like terms
 
 Pre-conditions: head != nullptr

 @param rightpoly the polynomial object to be substructed

 @return the left side object is returned if the param is 0. otherwise the 
         different of the polynomial objects is retuened
 */
//------------------------------------------------------------------------------

Polynomial Polynomial:: operator - ( const Polynomial& rightpoly ) const{
    
    //create a copy of the param object
    Polynomial negativeSum(rightpoly);
    
    Term *currentRight = negativeSum.head->next;
    
    while(currentRight!=negativeSum.head){
        
        negativeSum.changeCoefficient(currentRight->coeff*(-1),
                                                           currentRight->power);
        
        currentRight=currentRight->next;
        
    }
    // call the the + to finilize the result 
    return (*this+negativeSum);
}

//------------------------------------------------------------------------------
/**
 overloaded operator +=
 Takes two polynomials object and adds the like terms and save the result to this
 object

 Pre-conditions: head != nullptr
 
 @param rightPoly the polynomial object to be added

 @return the left side object is returned if the param is 0. otherwise the
        different of the polynomial objects is retuened
 */
//------------------------------------------------------------------------------

Polynomial& Polynomial:: operator+=( const Polynomial& rightPoly ){
    
    return (*this=(*this + rightPoly));
}

//------------------------------------------------------------------------------
/**
 overloaded operator -=
 Takes two polynomials object and substracts the like terms and save the result 
 to this object
 
 Pre-conditions: head != nullptr

 @param rightPoly the polynomial object to be substructed

 @return the left side object is returned if the param is 0. otherwise the
         different of the polynomial objects is retuened
 */
//------------------------------------------------------------------------------

Polynomial& Polynomial:: operator-=( const Polynomial& rightPoly ){
    
  return (*this=(*this - rightPoly));
}

//------------------------------------------------------------------------------
/**
 The maximum polynomial with the leading term's degree is returned  
 
 Pre-condition:a polynomial list with head not equal to null exist

 @return a value is returned based on the request
 */
//------------------------------------------------------------------------------

int Polynomial::degree()const{
    
    // check for empty list
    if(head == NULL || size == 0)
        return 0;
    
    // traverse the list and return the max power
    Term *currnet = head ->next;
    
    int maxDegree = 0;
    
    while (currnet!= head) {
        
        if(currnet ->power > maxDegree){
            
            maxDegree = currnet ->power;
            
        }
        
        currnet = currnet ->next;
        
    }
    // return the leadig terms degree
    return maxDegree;
}

//------------------------------------------------------------------------------
/**
 Function returns the cofficient of a polynomial based on param power.
 
 Pre-condition: a polynomial list with head not equal to null exist

 @param power An integer to represent the polynomial degree

 @return a value is returned based the param power.
 */
//------------------------------------------------------------------------------

double Polynomial::coefficient(const int power)const{
    
    // check for empty list
    if(head == NULL || size == 0){
        return 0;
    }
    
    // traverse the list and find the coeffienct
    Term *findCoeff = head ->next;
    
    while (findCoeff != head) {
        
        if(findCoeff ->power == power){
            
            return findCoeff ->coeff;
        }
        
        findCoeff = findCoeff ->next;
    }
    
    // the coeffienct with the power provided @param was not in the list
    // return 0;
    
    return 0;
}

//------------------------------------------------------------------------------
/**
 changes the polynomials coeffcient bases on the param or inserts new polynomial
 to the list based on the param. The function calls both private functions insert
 and remove to do the task.

 @param newCoefficient a value thats double in its type used as coefficient
 @param power          a value thats an int in its type used as the power

 @return a new polynomial is either inserted to an existing polyomial or the 
         existing polynomials coefficient is changed.
 */
//------------------------------------------------------------------------------

bool Polynomial::changeCoefficient(const double newCoefficient, const int power){
    
    // check all cases
    // CASE I: The new coefficient to be added is 0.
    //
    if(newCoefficient == 0 && power == 0){
        
        //create a temp term
        Term *temp = new Term;
        
        // set both the coefficient and power
        temp ->coeff = 0;
        temp ->power = 0;
        
        bool removeTemp = remove(temp);
        
        delete temp;
        temp=NULL;
        return removeTemp;
        
    }
    
    // traverse the polynomial list
    Term *current = head->next;
    
    while(current != head){
        
        //if the current term has the same power as the param object
       
        if(current ->power == power){
            
            //just change the coefficient and return true
            current ->coeff = newCoefficient;
            current = NULL;
            delete current;
            return true;
            
        }
        
        current = current->next;
        
    }
    
    // we reach this point either because current points to head which means
    // the term does not exist
    current = NULL;
    delete current;
    
    // CASE II:
    // The list is empty and we are adding new term to the list
    if(size == 0){
        
        //create a new term that is linked to head
        head ->next = new Term;
        
        //set the coefficient and power
        head ->next ->coeff = newCoefficient;
        head ->next ->power = power;
        
        //link the prev of head with the new term
        head->prev = head->next;
        
        // add and link the new term with head
        head ->next ->prev = head;
        head ->next ->next = head;
        
        
        // remeber to increment the size
        size++;
        return true;
        
    }
    
    // CASE III
    // The list has at least one polynomial term
    else if(size==1){
        
        //if prev has a higher power
        if(head ->next ->power > power ){
            
            //create a new term
            Term *newTerm=new Term;
            
            //set the coefficient and power
            newTerm->coeff=newCoefficient;
            newTerm->power=power;
            
            //place the new term to the right of prev
            newTerm ->next = head;
            newTerm ->prev = head ->next;
            
            // link back to back (circular)
            newTerm ->next ->prev = newTerm;
            newTerm ->prev ->next = newTerm;
            
            //increment the size
            size++;
            
            newTerm = NULL;
            delete newTerm;
            return true;
        }
        
        // we are at this point because the 'this' object power is less than
        // the param power
        else{
            
            //create a new term
            Term *newTerm=new Term;
            
            //set the coefficient and power
            newTerm ->coeff = newCoefficient;
            newTerm ->power = power;
            
            //place the new term to the left of prev
            newTerm ->next = head ->next;
            newTerm ->prev = head;
            
               // link back to back (circular)
            newTerm ->next ->prev = newTerm;
            newTerm ->prev ->next= newTerm;
            
            //increment the size
            size++;
            
            newTerm=NULL;
            delete newTerm;
            return true;
        }
        
    }
    // if we reahc this point it means we did not changed the coefficient based
    // on the param or we did not remove the polynomial term therefore call
    // insert function to add the param
    
    return insert(head ->next,newCoefficient,power);
    

}

//------------------------------------------------------------------------------
/**
 removes the polynomial term from the list based the function call
 
 Pre-condtion: head != nullptr

 @param pos head pointer to the term object

 @return removes the param object passed as argu
 */
//------------------------------------------------------------------------------

bool Polynomial::remove(Polynomial::Term *pos){
    
    // traverse the list and find the node that need to be deleted
       Term *current = head ->next;
    
    // check for empty list
    if(head == NULL || size == 0){
        current = NULL; 
        return false;
    }
 
    /**
     Check all cases

     @param size the polynomials list size.

     @return Case I: the polynomial has one term so delete the term and return 
             true.
     */
    
    else if (size == 1){
        
        if(pos ->power == current ->power){
            
            Term *temp = head ->next;
            
            // deattach the head from both link
            head ->next = head;
            head ->prev = head;
            
            head ->next ->prev = head;
            head ->prev ->next = head;
            delete temp;
            
            // size of the polynomial is decressed
            size--;
            
            current = NULL;
            return true;
        }
        else{
            
            // the current polynomial term is not the value to be deleted
            current = NULL;
            return false;
        }
    }
    
    // now the size is greater than one so traverse the list to find the right
    // term
    while (current ->power != pos ->power) {
        
        if(current == head){
            
            current = NULL;
            return false;
        }
        current = current ->next;
    }
    // we found the right spot, so delete the term
    
    current ->prev ->next = current ->next;
    current ->next ->prev = current ->prev;
    
    delete current;
    current = NULL;
    size--;
    return true;
}

//------------------------------------------------------------------------------
/**
 Inserts new polynomial to the list based on the param specification and returns
 boolean value. The function checks multiple stages before inserting an item to 
 the polynomial list. If param to be inserted is has a term power is greater than
 what already exist in the param as a leading term. The function checks to insure
 the final insert to be in the standard form a_0x^n+a_1x^(n-1)+...+a_(n-1)x+a_n=0

 @param prev           pointer to the next object
 @param newCoefficient new value to be inserted as a coefficient
 @param power          new int value to be inserted as power

 @return new item is insereted to the polynomial list
 */
//------------------------------------------------------------------------------

bool Polynomial::insert(Polynomial::Term *prev, const double newCoefficient,
                                                               const int power){
    
    // create two booleans to help track our movment < ----- > (left to right)
   	bool _prev = false;
    bool _next = false;
    
    // to know the last position in the list
    Term *last_position = prev;
    
    while(prev != head){
        
        //check the prev's power with the param power
        if(prev ->power > power){
            
            //and we have already moved left
            if(_prev == true){
                
                //add the a new term after prev
                
                Term *newTerm = new Term;
                
                //set the coefficient and power
                newTerm ->coeff = newCoefficient;
                newTerm ->power = power;
                
                //place the new term to the right of prev
                newTerm ->next = prev->next;
                newTerm ->prev = prev;
                
                // link back to back (circular)
                newTerm ->next ->prev = newTerm;
                newTerm ->prev ->next = newTerm;
                
                //increment the size
                size++;
                
                newTerm = NULL;
                delete newTerm;
                last_position = NULL;
                delete last_position;
                return true;
            }
            
            //save the last prev in case we reach the end after moving
            last_position = prev;
            //move right
            prev = prev->next;
            //remember that we moved right
            _next = true;
        }
        //at this point the prev's power is smaller
        else{
            
            //if we already moved forward
            if(_next == true){
                
                //place a new term before prev
                //create a new term
                Term *newTerm = new Term;
                
                //set the coefficient and power
                newTerm ->coeff = newCoefficient;
                newTerm ->power = power;
                
                //place the new term to the left of prev
                newTerm ->next = prev;
                newTerm ->prev = prev->prev;
                
                // link back to back (circular)
                newTerm ->next ->prev = newTerm;
                newTerm ->prev ->next = newTerm;
                
                //increment the size
                size++;
                newTerm = NULL;
                delete newTerm;
                last_position = NULL;
                delete last_position;
                return true;
            }
            
            last_position = prev;
            //move left
            prev = prev ->prev;
            //remember that we moved left
            _prev = true ;
            
        }
        
    }
    //if we reach this point, that means we are either at the first or last term
    if(last_position ->next == head ){
        
        //add a new last term
        //create a new term
        Term *newTerm = new Term;
        
        //set the coefficient and power
        newTerm ->coeff = newCoefficient;
        newTerm ->power = power;
        
        //place the new term to the left of head
        newTerm ->next = head;
        newTerm ->prev = head ->prev;
        
        newTerm ->next ->prev = newTerm;
        newTerm ->prev ->next = newTerm;
        
        //increment the size
        size++;
        
        newTerm = NULL;
        delete newTerm;
        last_position = NULL;
        delete last_position;
        return true;
        
        
    }
    // at this stage we art the first term in the polynomial list 
    else if(last_position ->prev == head){
        //place a new term before the first term 
        Term *newTerm = new Term;//create a new term
        
        //set the coefficient and power
        newTerm ->coeff = newCoefficient;
        newTerm ->power = power;
        
        //place the new term to the left of last prev
        newTerm ->next = head->next;
        newTerm ->prev = head;
        
        newTerm ->next ->prev = newTerm;
        newTerm ->prev ->next = newTerm;
        
        //increment the size
        size++;
        newTerm = NULL;
        delete newTerm;
        last_position = NULL;
        delete last_position;
        return true;
        
    }
    
    return true;
}


































