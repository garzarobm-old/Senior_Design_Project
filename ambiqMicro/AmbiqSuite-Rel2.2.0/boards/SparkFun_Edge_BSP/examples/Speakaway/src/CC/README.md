# calling C++ functions from C


##### start of C++ file
// C++ code:
    extern "C" void f(int);
    void f(int i)
    {
        // ...
    }



##### end of C++ file





##### start of C file 



   /* C code: */
    void f(int);
    void cc(int i)
    {
        f(i);
        /* ... */
    }


##### end of C file
