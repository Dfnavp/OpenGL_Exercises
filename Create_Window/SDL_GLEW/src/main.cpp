#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>

bool init_resources(void)
{
  //Initialization resources go here
  return true;
}

void render(SDL_Window* window)
{
 
}

void free_resources()
{

}

void mainLoop(SDL_Window* window)
{
	while (true) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT)
				return;
		}
		render(window);
	}
}

int main(int argc, char* argv[])
{
	// SDL initialization and window definition
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("My_SDL_Window",
		SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
		640, 480,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	SDL_GL_CreateContext(window);

	// GLEW initialization
	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK)
  {
    std::cerr << "Error: glewInit: " << glewGetErrorString(glew_status) << std::endl;
		return EXIT_FAILURE;
	}

	// When all init functions run without errors, the program can initialise the resources.
	if (!init_resources())
		return EXIT_FAILURE;

	// Execute the mainLoop in the SDL window.
	mainLoop(window);

	// If the program exits in the usual way, free resources and exit with a success.
	free_resources();
	return EXIT_SUCCESS;
}
