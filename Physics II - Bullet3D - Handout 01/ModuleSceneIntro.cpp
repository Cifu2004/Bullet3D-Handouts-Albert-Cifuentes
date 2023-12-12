#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center

	App->camera->Position.y += 1;
	App->camera->Position.x += 1;

	App->camera->LookAt(0);


	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference

	Plane plano = Plane();

	plano.axis = true;
	plano.Render();

	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe

	Sphere redonda = Sphere();
	redonda.radius = 0.5f;
	redonda.SetPos(0, 1, 0);
	redonda.Render();

	Cube cubo = Cube();
	cubo.SetPos(2, 1, 0);
	cubo.Render();

	Cylinder cilindro = Cylinder();
	cilindro.SetPos(-1, 0.5f, 1);
	cilindro.radius = 0.3f;
	cilindro.Render();


	return UPDATE_CONTINUE;
}

