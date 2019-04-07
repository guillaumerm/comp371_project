#include "Scene.h"


int main(int argc, const char* argvs[]) {
	if (argc < 3) {
		std::fprintf(stdout, "Usage: \n\t raytrace.exe scene_file output_file");
		exit(1);
	}

	Scene scene(argvs[1]);
	scene.render(argvs[2]);

	return 0;
}

