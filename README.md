cpp_calls_python_v2
----------------

To run

1. run build_and_call.sh


    ./build_and_call.sh

Output should look like

    b.f():                  A::f()
    super(B, b).f():        A::f() 
    base_ext.call_f(b):     A::f()
    c.f():                  C::f()
    super(C, c).f():        ACallback::default_f() 
    base_ext.call_f(c):     C::f()


# References

This code is an excerpt from \<boost\>/libs/python/test/polymorphism.{cpp,py}

For more info on virtual functions, see Boost's [Exposing Classes](http://www.boost.org/doc/libs/1_48_0/libs/python/doc/tutorial/doc/html/python/exposing.html#python.virtual_functions_with_default_implementations)

For more info on 'class', see wiki.python.org's [boost.python/class](https://wiki.python.org/moin/boost.python/class)
