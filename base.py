import base_ext

# no overrides of any kind
class B(base_ext.A):
    pass

# override f
class C(base_ext.A2):
    def f(self):
        return "C::f()"


b = B()
print 'b.f(): \t\t\t%s' % b.f()
print 'super(B, b).f(): \t%s ' % super(B, b).f()
print 'base_ext.call_f(b): \t%s' % base_ext.call_f(b)

c = C()
print 'c.f(): \t\t\t%s' % c.f()
print 'super(C, c).f(): \t%s ' % super(C, c).f()
print 'base_ext.call_f(c): \t%s' % base_ext.call_f(c)
