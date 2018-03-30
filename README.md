# What is swizzling?

Wikipedia [https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)]

* Common Operation in GPGPU applications
* A = {1,2,3,4} and components are called x, y, z, w
* B = A.wwxy
* B equals {4, 4, 1, 2}

# How to do it in C++?

* Union Trick
* Swizzle-Proxy Template
* CxxSwizzle (wc -l include/swizzle: 3230 lines)

In general by generating upfront all combinations.

# How to do it in D?

By simply overriding opDispatch.

Examples with tests: [vector.d](https://github.com/d-muc/swiz/blob/master/vector.d)
