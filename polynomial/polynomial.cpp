//
//  polynomial.cpp
//  polynomial
//
//  Created by Dawit Abera on 4/1/17.
//  Copyright © 2017 University of Washington. All rights reserved.
//

#include "polynomial.h"

/**
 Operator <<
 Output operator for class polynomial, print data, resposibility for output is
 left to object stored in the polynomial

 @param output        used to overload the cout object
 @param p passed by reference to print its data content

 @return an overload print statement
 */
ostream& operator <<(ostream &output, const Polynomial& p){
   
    bool minus=false;//will determine if a minus sign is printed
    bool constant=false;//to handle constant term printing (to print at the end)
    double constCoeff=0.0;//will save the value of the constant term
    int constPower=0;//the power of the constant term
    if (p.head==NULL||p.size==0){//if there are no terms or if there are problems with the param
        output<<"0"<<endl;//print 0 and stop
        return output;
    }
    Polynomial:: Term *traverse;
    traverse=p.head->next;//otherwise create a temp term
    if(traverse->power==0){//if the first term is a constant term (this means negative power terms follow it)
        constant=true;//remember it
        constCoeff=traverse->coeff;//save the value so we can print at the end
    }
    else if(traverse->power==1){//if the first term has a 1 power then print coeffx
        if(traverse->coeff==1){//if the coefficient is 1
            output<<"x";//just print x
        }
        else{
            output<<traverse->coeff<<"x";//otheriwse print coeffx
        }
    }
    else if(traverse->power==-1){//if the first term has a -1 power
        output<<traverse->coeff<<"/x";//print coeff/x
    }
    else if(traverse->power<1){//if the first term has a negative power
        output<<traverse->coeff<<"/x^"<<(traverse->power)*(-1);//print coeff/x^power
    }
    else{//for powers>1
        if(traverse->coeff==1){//if the coeff is 1
            output<<"x^"<<traverse->power;//just print x
   	    }
        else{//coeff is not 1
            output<<traverse->coeff<<"x^"<<traverse->power;//print coeffx^power
        }
    }
    if(traverse->next==p.head){//if theres only one term then stop
        output<<endl;
        traverse=NULL;//for memory leaks
        delete traverse;//for memory leaks
        return output;
    }
    if(traverse->next->coeff<0 && traverse->next->power!=0){//if the first term wasn't constant and the next term's coeff is negative
        output<<" - ";//print a -
        minus=true;
    }
    else if(traverse->next->coeff>0 && traverse->next->power!=0){//if the first term wasn't a constant and the next terms' coeff is positive
        output<<" + ";//othwerise print a +
    }
    traverse=traverse->next;//move on to the next term
    
    
    while(traverse!=p.head){//while we haven't reached the end of the polynomial
        if(traverse->power==0){//if the term is constant
            constant=true;//remember it
            constCoeff=traverse->coeff;//save the value so we can print it at the end
        }
        else if(traverse->power==1){//if the power is 1
            if(traverse->coeff==1){//if the coeff is 1
                output<<"x";//just print x
            }
            else{
                output<<traverse->coeff<<"x";//print coeffx
            }
        }
        else if(traverse->power==-1){//if the power is -1
            if(minus==false){//if we didn't print a minus the term before this
                output<<traverse->coeff<<"/x";//print coeff/x
            }
            else{//if we did print a minus sign the term before this
                output<<(traverse->coeff)*(-1)<<"/x";//print coeff/x but flip the sign of coeff
            }
        }
        
        else if(traverse->power<1){//if the power<1
            if(minus==false){//if we didn't print a minus the term before this
                output<<traverse->coeff<<"/x^"<<(traverse->power)*(-1);//print coeff/x^power
            }
            else{//if we did print a minus sign the term before this
                output<<(traverse->coeff)*(-1)<<"/x^"<<(traverse->power)*(-1);//print coeff/x^power but flip the sign of coeff
            }
        }
        else{//if the power>1
            if(traverse->coeff==1){//if coeff is 1
                output<<"x^"<<traverse->power;//just print x^power
            }
            else{//coeff is not 1
                if(minus==false){//if we didn't print a minus sign the term before this
                    output<<traverse->coeff<<"x^"<<traverse->power;//print coeffx^power
                }
                else{//if we did print a minus sign the term before this
                    output<<(traverse->coeff)*(-1)<<"x^"<<traverse->power;//print coeffx^power but flip the sign of coeff
                }
            }
        }
        
        if(traverse->next==p.head){//if that term was the last one
            if(constant==true){//if we ran into a constant term along the way
                if(constCoeff<0){//if the coeff was negative
                    output<<" - "<<(constCoeff)*(-1);//print a minus sign and coeff(sign is flipped)
                }
                else{//if the coeff was positive
                    output<<" + "<<constCoeff;//print the value
                }
            }
            //now we return after taking care of memory leaks
            output<<endl;
            traverse=NULL;//for memory leaks
            delete traverse;//for memory leaks
            return output;
            
        }
        //at this point the previous term was not the last
        if(traverse->next->coeff>0 && traverse->next->power!=0){//if the next term isn't constant and the coeff is positive 
            output<<" + ";//print a +
            minus=false;//remember that we printed a plus sign
        }
        else if(traverse->next->coeff<0 && traverse->next->power!=0){//if the next term isn't constant and the coeff is negative
            output<<" - ";//print a -
            minus=true;//remember that we printed a minus sign
        }
        traverse=traverse->next;//go on to the next term
    }
    traverse=NULL;//for memory leaks
    delete traverse;//for memory leaks
    return output;
    
}
//--------------------------------CONSTRUCTORS----------------------------------
/*
 * Default Constructor 
 * The default constructor creates and initializes the object
 *
 * Precondtion: N/A
 *
 * Postcondtion: A polynomial object with circular linked list is created
 */
//------------------------------------------------------------------------------
Polynomial::Polynomial(){
   
    size = 0;
    head = new Term;      // dummy head
    
    // set the circular linked list
    head ->next = head, head ->prev = head;
    
    head ->coeff = 0, head ->power = 0;
    
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

Polynomial::Polynomial(const Polynomial& rightPoly){
    
    // first initialize the head
    head = new Term;
    
    // create a circular linked list < -- >
    head ->next = head, head ->prev = head;
    
    // set and initialize the Term values
    head ->coeff = 0;
    head ->power = 0;
    
    // set size to 0
    size = 0;
    
    // now call the assigment operator to do finialize the deep copying
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
Polynomial::~Polynomial(){
  
    // check for empty list first
    if(head == NULL || size == 0)
        return;
    
    // special case where the polynomial has one term
    if(size == 1){
        
        remove(head ->next);
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

//------------------------------------------------------------------------------
/*
 * operator =
 * Make a deep copy of the right object into the left parameter object
 *
 * Precondtion:
 *
 * Postcondtion:
 */
 /**
  <#Description#>

  @param rightpoly <#rightpoly description#>

  @return <#return value description#>
  */
 Polynomial& Polynomial::operator=(const Polynomial &rightpoly){
     
     
     if(rightpoly.size==0){//we are done if there are no terms to add
         return *this;
     }
     Term *traverse=rightpoly.head->next;//otherwise create a traversal node
     while(traverse!=rightpoly.head){//while the end hasnt been reached
         changeCoefficient(traverse->coeff,traverse->power);//add p's term
         traverse=traverse->next;//move on to the next term
     }
     traverse=NULL;//for memory leaks
     delete traverse;//for memory leaks
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
//------------------------------------------------------------------------------
/**
 <#Description#>

 @param p <#rightPoly description#>

 @return <#return value description#>
 */
Polynomial Polynomial:: operator+( const Polynomial& p ) const{
    
  
    Polynomial sum(*this);//let this be the current sum
    Polynomial p2(p);//create a copy of the param
    
    Term *traverseSum;//create a traversal term for sum
    Term *traversep2=p2.head->next;//create a traverseal term for p2
    bool exists=false;//for terms with powers present both in sum and p2 (to combine like terms)
    
    while(traversep2!=p2.head){//for every term in p2
        exists=false;//assume the term doesn't exist in both poly's
        traverseSum=sum.head->next;//start at the first term of sum
        while(traverseSum!=sum.head){//for every term in sum
            if(traversep2->power == traverseSum->power){//if the current term has common powers in both sum and p2
                sum.changeCoefficient(traverseSum->coeff+traversep2->coeff,traverseSum->power);//combine like terms
                exists=true;//remember that we combined
            }
            traverseSum=traverseSum->next;//move on to the next term
        }
        //the inner loop finished
        if(!exists){//if we didn't combine like terms
            sum.changeCoefficient(traversep2->coeff,traversep2->power);//add p2's term
        }
        traversep2=traversep2->next;//move on to the next term of p2 
    }
    
    return sum;
    
    
    
}
//------------------------------------------------------------------------------
/**
 <#Description#>

 @param p <#rightPoly description#>

 @return <#return value description#>
 */
Polynomial Polynomial:: operator-( const Polynomial& p ) const{
    
    Polynomial negativeSum(p);//create a copy of p
    Term *traverse=negativeSum.head->next;//start at the first term
    while(traverse!=negativeSum.head){//for every term
        negativeSum.changeCoefficient(traverse->coeff*(-1),traverse->power);//flip the sign of coeff
        traverse=traverse->next;//move on to the next term
    }
    return (*this+negativeSum);//now call +
}
//------------------------------------------------------------------------------
/**
 <#Description#>

 @param rightPoly <#rightPoly description#>

 @return <#return value description#>
 */
Polynomial& Polynomial:: operator+=( const Polynomial& rightPoly ){
    
    return (*this=(*this + rightPoly));
}
//------------------------------------------------------------------------------
/**
 <#Description#>

 @param rightPoly <#rightPoly description#>

 @return <#return value description#>
 */
Polynomial& Polynomial:: operator-=( const Polynomial& rightPoly ){
    
  return (*this=(*this - rightPoly));
}
//------------------------------------------------------------------------------
/**
 The maximum polynomial with the leading term's degree is returned  
 
 Pre-condition:a polynomial list with head not equal to null exist

 @return a value is returned based on the request
 */
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
bool Polynomial::changeCoefficient(const double newCoefficient, const int power){
    
    if(newCoefficient==0){//if the coeff is changed to 0
        Term *pos=new Term;//create a temp term
        pos->coeff=0.0;//set the coeff value
        pos->power=power;//set the power value
        bool removeTerm=remove(pos);//attempt to remove the term that contains these values
        delete pos;//for memory leaks
        pos=NULL;//for memory leaks
        return removeTerm;
    }
    Term *traversal=head->next;//create a traversal term
    while(traversal!=head){//while the end hasn't been reached
        if(traversal->power==power){//if the current term has the same power as the param
            traversal->coeff=newCoefficient;//just change the coeff and return
            traversal=NULL;//for memory leaks
            delete traversal;//for memory leaks
            return true;
            
        }
        traversal=traversal->next;//otherwise advance to the next term
    }
    //at this point the term doesnt currently exist
    traversal=NULL;//for memory leaks
    delete traversal;//for memory leaks
    
    if(size==0){//adding the first term is a special case
        head->next=new Term;//create a new term that is linked to head
        head->next->coeff=newCoefficient;//set the coefficient
        head->next->power=power;//set the power
        head->prev=head->next;//link the prev of head with the new term
        
        head->next->prev=head;//link the new term with head
        head->next->next=head;//link the new term with head going the other way
        
        
        size++;//increment the size
        return true;
    }
    else if(size==1){//for a poly of 1 term
        if(head->next->power>power ){//if prev has a higher power
            Term *newTerm=new Term;//create a new term
            newTerm->coeff=newCoefficient;//set the value
            newTerm->power=power;//set the value
            
            newTerm->next=head;//place the new term to the right of prev
            newTerm->prev=head->next;//place the new term to the right of prev
            
            newTerm->next->prev=newTerm;//link back
            newTerm->prev->next=newTerm;//link back
            
            size++;//increment the size
            newTerm=NULL;//for memory leaks
            delete newTerm;//for memory leaks
            return true;
        }
        
        else{//if prev has a lower power
            Term *newTerm=new Term;//create a new term
            newTerm->coeff=newCoefficient;//set the value
            newTerm->power=power;//set the value
            
            newTerm->next=head->next;//place the new term to the left of prev
            newTerm->prev=head;//place the new term to the left of prev
            
            newTerm->next->prev=newTerm;//link back
            newTerm->prev->next=newTerm;//link back
            
            size++;//increment the size 
            newTerm=NULL;//for memory leaks 
            delete newTerm;//for memory leaks 
            return true;
        }
        
    }
    return insert(head->next,newCoefficient,power);//if we didnt remove or change a coeff then insert the term
    

}
//------------------------------------------------------------------------------
/**
 removes the polynomial term from the list based the function call

 @param pos <#pos description#>

 @return <#return value description#>
 */
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
 boolean value.

 @param prev           pointer to the next object
 @param newCoefficient new value to be inserted as a coefficient
 @param power          new int value to be inserted as power

 @return new item is insereted to the polynomial list
 */
bool Polynomial::insert(Polynomial::Term *prev, const double newCoefficient,
                        const int power){
   	bool wentBack=false;//will track if we moved left
    bool wentForward=false;//will track if we moved right
    Term *lastPrev=prev;//will remember the last term
    while(prev!=head){//while prev is not head
        if(prev->power>power){//if prev's power is bigger
            if(wentBack==true){//and we have already moved left
                //place a new term after prev
                Term *newTerm=new Term;//create a new term
                newTerm->coeff=newCoefficient;//set the value
                newTerm->power=power;//set the value
                
                newTerm->next=prev->next;//place the new term to the right of prev
                newTerm->prev=prev;//place the new term to the right of prev
                
                newTerm->next->prev=newTerm;//link back
                newTerm->prev->next=newTerm;//link back
                
                size++;//increment the size
                newTerm=NULL;//for memory leaks
                delete newTerm;//for memory leaks
                lastPrev=NULL;//for memory leaks
                delete lastPrev;//for memory leaks
                return true;
            }
            lastPrev=prev;//save the last prev in case we reach the end after moving
            prev=prev->next;//move right
            wentForward=true;//remember that we moved right
        }
        else{//if prev's power is smaller
            if(wentForward==true){//if we already moved forward
                //place a new term before prev
                Term *newTerm=new Term;//create a new term
                newTerm->coeff=newCoefficient;//set the value
                newTerm->power=power;//set the value
                
                newTerm->next=prev;//place the new term to the left of prev
                newTerm->prev=prev->prev;//place the new term to the left of prev
                
                newTerm->next->prev=newTerm;//link back
                newTerm->prev->next=newTerm;//link back
                
                size++;//increment the size
                newTerm=NULL;//for memory leaks
                delete newTerm;//for memory leaks
                lastPrev=NULL;//for memory leaks
                delete lastPrev;//for memory leaks
                return true;
            }
            lastPrev=prev;//save the last prev in case we reach the end after moving
            prev=prev->prev;//move left
            wentBack=true ;//remember that we moved left
            
        }
        
    }
    //if we reach this point, that means we are either at the first or last term
    if(lastPrev->next==head ){//if we're at the last term
        //add a new last term
        Term *newTerm = new Term;//create a new term
        newTerm->coeff=newCoefficient;//set the value
        newTerm->power=power;//set the value
        
        newTerm->next=head;//place the new term to the left of head
        newTerm->prev=head->prev;//place the new term to the left of head
        
        newTerm->next->prev=newTerm;//link back
        newTerm->prev->next=newTerm;//link back
        
        size++;//increment the size
        newTerm=NULL;//for memory leaks
        delete newTerm;//for memory leaks
        lastPrev=NULL;//for memory leaks
        delete lastPrev;//for memory leaks
        return true;
        
        
    }
    else if(lastPrev->prev==head){//if we're at the first term
        //place a new term before the first term 
        Term *newTerm=new Term;//create a new term
        newTerm->coeff=newCoefficient;//set the value 
        newTerm->power=power;//set the value 
        
        newTerm->next=head->next;//place the new term to the left of last prev 
        newTerm->prev=head;//place the new term to the left of last prev
        
        newTerm->next->prev=newTerm;//link back 
        newTerm->prev->next=newTerm;//link back 
        
        size++;//increment the size 
        newTerm=NULL;//for memory leaks 
        delete newTerm;//for memory leaks
        lastPrev=NULL;//for memory leaks 
        delete lastPrev;//for memory leaks
        return true;
        
    }
    
    return true;
}































