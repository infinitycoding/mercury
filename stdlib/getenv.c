
#include <string.h>

extern char **environ;


char * getenv( const char * name )
{
    size_t len = strlen( name );
    size_t index = 0;
    while ( environ[ index ] != NULL )
    {
        if ( strncmp( environ[ index ], name, len ) == 0 )
        {
            return environ[ index ] + len + 1;
        }
        index++;
    }
    return NULL;
}
