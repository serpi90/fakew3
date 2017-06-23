#include <windows.h>
#include <stdio.h>

#define MAX_COMMAND_SIZE 1024

int launchGame( char commandLine[] ) {
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInformation;
	ZeroMemory( &startupInfo, sizeof( startupInfo ) );
	startupInfo.cb = sizeof( startupInfo );
	ZeroMemory( &processInformation, sizeof( processInformation ) );

	/* Start the child process. */
	if( CreateProcess( NULL, commandLine, NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInformation ) ) {
		printf( "Waiting for the process to finish ...\r\n" );
		/* Wait until child process exits. */
		WaitForSingleObject( processInformation.hProcess, INFINITE );
		/* Close process and thread handles. */
		CloseHandle( processInformation.hProcess );
		CloseHandle( processInformation.hThread );
		return EXIT_SUCCESS;
	} else {
		printf( "Failed to start the process (%d).\n", GetLastError() );
		return EXIT_FAILURE;
	}
}

int main( ) {
	const char configFileName[] = "fakew3.txt";
	char defaultCommandLine[] = "\"C:\\Program Files (x86)\\Warcraft III\\Frozen Throne.exe\" -window";
	char commandLine[MAX_COMMAND_SIZE];
	FILE * configFile = fopen( configFileName, "r" );

	if( configFile == NULL ) {
		return launchGame( defaultCommandLine );
	} else if( fgets( commandLine, MAX_COMMAND_SIZE, configFile ) == NULL ) {
		printf( "Error reading configuration file %s, using default %s\r\n", configFileName, defaultCommandLine );
		fclose( configFile );
		return launchGame( defaultCommandLine );
	} else {
		printf( "Starting %s\r\n", commandLine );
		fclose( configFile );
		return launchGame( commandLine );
	}
}
