#include <iostream>
#include <string>
using namespace std;

// Base/Parent class with different access specifiers
class ParentClass {
    public:
        int a_public;
        
    protected:
        int b_protected;
        
    private:
        int c_private;
    
    // Constructor needs to be public to create objects
    public:
    ParentClass(int inta, int intb, int intc) {
        a_public = inta;
        b_protected = intb;
        c_private = intc;
    }
    
    void display() {
        cout << "Public: " << a_public << endl;
        cout << "Protected: " << b_protected << endl;
        cout << "Private: " << c_private << endl;
    }
};

// PRIVATE INHERITANCE
// All members become PRIVATE in Child1
class Child1 : private ParentClass {
    public:
    Child1(int a, int b, int c) : ParentClass(a, b, c) {}
    
    void accessInChild1() {
        a_public = 10;    // OK: becomes private in Child1, accessible here
        b_protected = 20; // OK: becomes private in Child1, accessible here
        // c_private = 30; // ERROR: Private in Parent, never accessible
    }
};

// PROTECTED INHERITANCE
// All members become PROTECTED in Child2
class Child2 : protected ParentClass {
    public:
    Child2(int a, int b, int c) : ParentClass(a, b, c) {}
    
    void accessInChild2() {
        a_public = 10;    // OK: becomes protected
        b_protected = 20; // OK: becomes protected
        // c_private = 30; // ERROR: Private in Parent
    }
};

// PUBLIC INHERITANCE
// Members maintain their access levels
class Child3 : public ParentClass {
    public:
    Child3(int a, int b, int c) : ParentClass(a, b, c) {}
    
    void accessInChild3() {
        a_public = 10;    // OK: remains public
        b_protected = 20; // OK: remains protected
        // c_private = 30; // ERROR: Private in Parent
    }
};

// MULTI-LEVEL INHERITANCE
class GrandChild : public Child3 {
    public:
    GrandChild(int a, int b, int c) : Child3(a, b, c) {}
    
    void accessInGrandChild() {
        a_public = 10;    // OK: still public through inheritance chain
        b_protected = 20; // OK: protected members accessible
        // c_private = 30; // ERROR: never accessible
    }
};

// HIERARCHICAL INHERITANCE (multiple classes from same parent)
class Child4 : public ParentClass {
    public:
    Child4(int a, int b, int c) : ParentClass(a, b, c) {}
};

int main() {
    ParentClass parent(1, 2, 3);
    parent.a_public = 10;    // OK: public
    // parent.b_protected = 20; // ERROR: protected
    // parent.c_private = 30;    // ERROR: private
    
    Child1 child1(1, 2, 3);
    // child1.a_public = 10;    // ERROR: became private in Child1
    
    Child2 child2(1, 2, 3);
    // child2.a_public = 10;    // ERROR: became protected in Child2
    
    Child3 child3(1, 2, 3);
    child3.a_public = 10;       // OK: remains public
    // child3.b_protected = 20; // ERROR: protected
    
    GrandChild grand(1, 2, 3);
    grand.a_public = 15;        // OK: still public
    
    return 0;
}