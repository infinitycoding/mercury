#ifndef __static_mem__
#define __static_mem__

//the number of files that can be opend simultaniusly
#define NO_OF_FILEDESC 64








//validity checks
#if NO_OF_FILEDESC < 2
    #error NO_OF_FILEDESC is to small to contain the 3 default file descriptors
#endif

#endif
