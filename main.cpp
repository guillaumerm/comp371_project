#define DEBUG
#include "Scene.h"


int main(int argc, const char* argvs[]) {
#ifndef DEBUG
	if (argc < 3) {
		std::fprintf(stdout, "Usage: \n\t raytrace.exe scene_file output_file");
		exit(1);
	}

	Scene scene(argvs[1]);
	scene.render(argvs[2]);
#else
	// TODO issue with loading mesh scene files
	Scene scene("./scenes/meshscene1.txt");
	scene.render("./debug.bmp");
#endif

	return 0;
}

