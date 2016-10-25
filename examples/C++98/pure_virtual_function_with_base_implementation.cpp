/**
 * Illustrate that pure virtual functions *can* have an implementation in the
 * base class, but that this is not used often.
 *
 * Possible use cases (according to StackOverflow):
 *
 *   - There is a more-or-less reasonable default behavior, but the class
 *     designer wants that sort-of-default behavior be invoked only explicitly.
 *
 *   - It can also be the case what you want derived classes to always perform
 *     their own work but also be able to call a common set of functionality.
 * 
 * References:
 *
 *   [1] http://stackoverflow.com/questions/2089083/pure-virtual-function-with-implementation
 *   [2] http://stackoverflow.com/questions/25530108/implementing-pure-virtual-function-in-the-abstract-class-is-there-any-use-of-i
 *   [3] http://www.gotw.ca/gotw/031.htm
 */

#include <iostream>

class Base {
public:
    virtual void f() = 0;
    void g();
};

void Base::f()
{
    std::cout << "Base::f() called." << std::endl;
}

void Base::g()
{
    f();        // calls Derived::f()
    Base::f();  // calls Base::f()

    std::cout << "Base::g() called." << std::endl;
}


class Derived : public Base {
public:
    virtual void f()
    {
        //Base::f();  // Derived's implementation can call Base implementation (if access permissions allow it)... but this is not so often used?

        std::cout << "Derived::f() called." << std::endl;  // Derived's implementation.
    }
};


int main()
{
    //Base b;  // does not work, because cannot declare variable 'b' to be of abstract type 'Base'.
    //b.f();

    std::cout << "Non-pointer version:" << std::endl;
    Derived d;
    d.g();

    std::cout << "Pointer version:" << std::endl;
    Derived* dp = new Derived();
    dp->g();
}
