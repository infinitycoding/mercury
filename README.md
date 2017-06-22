Mercury
=======

A small standard c library which is easy to port and supports a lot of embedded compiletime features.


Dependecies:
========
* gcc/clang     (only for compilation)
* make          (only for compilation)
* nasm          (only for compilation for x86)


Currently supported operating systems:
=======
* universe
* linux

Currently supported architectures:
=======
* X86

Features:
=======

* noos=true
Disables any kind of function that does use a operating system ABI

* noheap=true
Disables dynamic memory allocation

Planed features:
=======
* vfs=true
Adds a virtual filesystem which overides the usual file API. The VFS requres a heap so it is not compatible with noheap=true.
The virtual Filesystem can mount your operating sytems file system.


How to configure/compile:
=======

````
    make TARGET={the operating system you are compiling for} <any other flag from above>
````

Project structure:
========
The folders are named after the include file which contains the prototypes.
In each of these folders is a subfolder which contains the functionalities that need a operating system.
/test contains unittests for each library function.
/system contains the operating system specific files
/system/< arch > contains the operating system specific files dependend on the processor architecture
