#include <windows.h>
#include <stdio.h>

#define MAX_SIZE 1024

/**
* Used to wrap around GameRanger restrictions, to run Warcraft III in windowed mode.
* Currently GameRanger requres a file named War3x.mpq to be present in the folder to allow it to be selected as Warcraft III: Frozen Throne
*
* Attempt to read configFile. If file is missing or there is an error reading it. Attempt to use default W3 location.
*
* The configuration file only has the command line to execute. Example:
* "D:\Warcraft III\Frozen Throne.exe" -window
*
* Remember to wrap the path with quotes.
*/

int launchGame( const char commandLine[] ) {
    switch( WinExec( commandLine, SW_SHOWDEFAULT ) ) {
        case 0:
            fprintf( stderr, "The system is out of memory or resources\r\n" );
            return -1;
        case ERROR_BAD_FORMAT:
            fprintf( stderr, "The .exe file is invalid\r\n" );
            return -1;
        case ERROR_FILE_NOT_FOUND:
            fprintf( stderr, "The specified file was not found\r\n" );
            return -1;
        case ERROR_PATH_NOT_FOUND:
            fprintf( stderr, "The specified path was not found\r\n" );
            return -1;
        default:
            return 0;
    }
}

int main ( ) {
    const char defaultCommandLine[] = "\"C:\\Program Files ( x86)\\Warcraft III\\Frozen Throne.exe\" -window";
    const char configFileName[] = "fakew3.txt";
    char commandLine[MAX_SIZE];
    FILE * configFile = fopen( configFileName, "r" );

    if( configFile == NULL ) {
        return launchGame( defaultCommandLine );
    } else if( fgets( commandLine, MAX_SIZE, configFile ) == NULL ) {
        printf( "Error reading configuration file %s, using default %s\r\n", configFileName, defaultCommandLine );
        fclose( configFile );
        return launchGame( defaultCommandLine );
    } else {
        printf( commandLine );
        printf( "\r\n" );
        fclose( configFile );
        return launchGame( commandLine );
    }
}
