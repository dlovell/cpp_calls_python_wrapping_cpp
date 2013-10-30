// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// 2013-10-29 excerpted with modification by Dan Lovell
// originally <boost>/libs/python/test/polymorphism.cpp
#include <boost/python/module.hpp>
#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/call_method.hpp>

using namespace boost::python;

struct Callback
{
    Callback(PyObject* o) : mSelf(o) {}
    PyObject* mSelf;
};

struct A
{
    virtual ~A(){}
    virtual std::string f() { return "A::f()"; }
};

struct ACallback :  A,  Callback
{
	ACallback (PyObject* self) : Callback(self) {}
	std::string f()
	{
		return call_method<std::string>(mSelf, "f");
	}
	std::string default_f()
	{
		return "ACallback::default_f()";
	}
};

std::string call_f(A& a) { return a.f(); }


BOOST_PYTHON_MODULE_INIT(base_ext)
{
    class_<A,boost::noncopyable>("A")
        .def("f", &A::f)
        ;
    class_<A,boost::noncopyable,ACallback>("A2")
        .def("f", &A::f, &ACallback::default_f)
        ;
    def("call_f", call_f);
}
