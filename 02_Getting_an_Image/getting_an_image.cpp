//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen Dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts SDL and creates window
bool init();

//loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window to render to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on screen
SDL_Surface* gHelloWorld = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could now be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//load splash image
	gHelloWorld = SDL_LoadBMP("Skibidi.bmp" );
	if( gHelloWorld == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "02_Getting_an_Image/skibidi.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;

	//Destroy Window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL Subsystems
	SDL_Quit();
}

int main ( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load Media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
		//Apply the image
		SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL);

		//Update the surface
		SDL_UpdateWindowSurface( gWindow );

		//Hack to get the window to stay up
		SDL_Event e; bool quit = false; 
		while( quit == false ) { 
			while( SDL_PollEvent( &e ) )
				{ if( e.type == SDL_QUIT ) quit = true; } 
			}
		}
	}
	//Free resources and close SDL
	close();

	return 0;
}
