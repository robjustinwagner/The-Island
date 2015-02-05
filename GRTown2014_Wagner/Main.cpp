/* CS559 FINAL PROJECT
	framework written by Michael Gleicher
	adapted by: Bob (Robert) Wagner
*/

#include "Main.H"
#include "GrTown_PCH.H"
#include "GraphicsTownUI.H"
#include "FlyCamera.H"
#include "GrWorld.H"
#include "DrawUtils.H"

// for setting up shader paths and textures
#include "Utilities/ShaderTools.H"
#include "Utilities/Texture.H"

//Objects and Behaviors
#include "Examples/Suburbs.H"
#include "Examples/Objects.H"
#include "Examples/SimpleBehaviors.H"
#include "Examples/Cars.H"
#include "Roads/Roads.H"
#include "Roads/Drive.H"

// define this to get 2 cars that always turn
// #define TESTCARS
const int numCars = 100;
const int nGrids = 5;

int main(int /*argc*/, char** /*argv*/)
{ 

  // put in some texture paths - look all over the place
	texturePaths.push_back(".");
	texturePaths.push_back("..");
	texturePaths.push_back("Textures/Textures");
	texturePaths.push_back("../Textures/Textures");
	texturePaths.push_back("Textures/Objects");
	texturePaths.push_back("../Textures/Objects");

	shaderPaths.push_back("Shaders");
	shaderPaths.push_back("../Shaders");

	constructWorld();

	//Camera & UI
	FlyCamera* fc = new FlyCamera;
	Map* m = new Map;

	add(fc);
	add(m);

	GraphicsTownUI grTown;
	grTown.make_window();
	grTown.townView->defaultCamera = fc;
	grTown.window->show();

	Fl::run();

	return 1;
}

void constructWorld()
{

	makeWorldElements();
	makeObjects();

	//add skybox last, for performance reasons
	
	//glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	GrObject* skybox = new Skybox();
	add(skybox);
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
}

void makeWorldElements()
{
	Road* rr1 = new RoundRoad(-50, -575, 75);
	add(rr1);

	Road* rr2 = new RoundRoad(-390, -15, 45);
	add(rr2);

	Road* rr3 = new RoundRoad(-245, -100, 100);
	add(rr3);

	Road* rr4 = new RoundRoad(275, 0, 165);
	add(rr4);

	Road* rr5 = new RoundRoad(-320, 10, 30);
	add(rr5);

	Road* t1 = new StraightRoad(-50, 475, 110, 0);
	add(t1);

	Road* t = new StraightRoad(-50, -500, -50, 800);
	add(t);
	t->name = "The \"Path\"";
	t->interesting = true;
	t->laX = -50; t->laY = 75; t->laZ = 800;
	t->lfX = -50; t->lfY = 15; t->lfZ = -550;

	//add volcano/glowing lava mountain
	GrObject* o1 = new Volcano();
	o1->name = "Volcano";
	o1->interesting = true;
	o1->laX = -50; o1->laY = 300; o1->laZ = 1200;
	o1->lfX = -200; o1->lfY = 975; o1->lfZ = 405;
	add(o1);

	//showcase volcano doors
	GrObject* vd = new VolcanoDoors();
	vd->name = "Volcano Doors (HINT: adjust time of day!)";
	vd->interesting = true;
	vd->laX = -50; vd->laY = 75; vd->laZ = 675;
	vd->lfX = -150; vd->lfY = 120; vd->lfZ = 550;
	add(vd);

	//add glowing lava
	GrObject* lava = new Lava();
	lava->name = "Lava";
	lava->interesting = false;
	add(lava,-225,17,1100,0);

	//add castle
	/*
	GrObject* castle = new Castle;
	castle->interesting = true;
	castle->laX = 0; castle->laY = 0; castle->laZ = 0;
	castle->lfX = -50; castle->lfY = 100; castle->lfZ = 300;
	add(castle, -100, 0, 100, pi / 2.f);
	*/

	//add church
	/*
	GrObject* church = new Church;
	church->interesting = true;
	church->laX = 0; church->laY = 0; church->laZ = 0;
	church->lfX = -50; church->lfY = 100; church->lfZ = 300;
	add(church, -100, 0, 100, pi / 2.f);
	*/
	/*
	Lawn* l = new Lawn(-100, -100, 100, 100);
	add(l);
	*/
	/*
	//beaten road surrounding house
	Road* t = new RoundRoad(0, 0, 300);
	add(t);
	t->name = "Main Market";
	t->interesting = true;
	t->laX = 0; t->laY = 70; t->laZ = 500;
	t->lfX = 0; t->lfY = 15; t->lfZ = -150;
	*/

	
	/*
	Car* h = new HatchBack(1);
	h->name = "Car";		// warning! we can only do this since we don't delete
	add(h);
	Drive* d = new SimpleDrive(h, t, 0, 0);
	d->speed *= (float)0.15;
	*/
	//add trees
	TreeCluster* tc1 = new TreeCluster();
	add(tc1,110,0,460,20);
	tc1->name = "Tree Cluster 1";
	tc1->interesting = false;
	TreeCluster* tc2 = new TreeCluster();
	add(tc2,250, 0, -350, -40);
	tc2->name = "Tree Cluster 2";
	tc2->interesting = false;
	TreeCluster* tc4 = new TreeCluster();
	add(tc4,-350,0, 275,0);
	tc4->name = "Tree Cluster 3";
	tc4->interesting = false;
	TreeCluster* tc5 = new TreeCluster();
	add(tc5, -225, 0, -300, 45);
	tc5->name = "Tree Cluster 4";
	tc5->interesting = false;
	TreeCluster* tc6 = new TreeCluster();
	add(tc6, 600, 0, 0, 90);
	tc6->name = "Tree Cluster 5";
	tc6->interesting = false;
	TreeCluster* tc7 = new TreeCluster();
	add(tc7, 600, 0, -60, 150);
	tc7->name = "Tree Cluster 6";
	tc7->interesting = false;
	/*
	SimpleHouse1* sh = new SimpleHouse1();
	add(sh, 50, 0, 50);
	sh->name = "Mysterious House";
	sh->interesting = true;
	sh->laX = 0; sh->laY = 70; sh->laZ = 500;
	sh->lfX = 0; sh->lfY = 15; sh->lfZ = -150;
	*/
	/*
	int r, c;
	// make a 5x5 grid of town blocks - 5 houses per
	for (r = 0; r<1; r++) {
		for (c = 0; c<1; c++) {
			add(new SimpleSubdivision(5), static_cast<float>(r * 530), 0, static_cast<float>(c * 230));
			add(new StraightRoad(static_cast<float>(r * 530), static_cast<float>(c * 230), static_cast<float>(r * 530 + 500), static_cast<float>(c * 230)));
		}
	}
	// make cross streets
	for (int r = 0; r <= 1; r++) {
		for (c = 0; c<0; c++) {
			add(new StraightRoad(static_cast<float>(r * 530 - 15), static_cast<float>(c * 230 + 15), static_cast<float>(r * 530 - 15), static_cast<float>(c * 230 + 215)));
		}
	}

	// make intersections
	// make an intersection intersesting so we can look at it
	for (int r = 0; r <= 1; r++) {
		for (c = 0; c<1; c++) {
			GrObject* g = new Intersection(static_cast<float>(r * 530 - 15), static_cast<float>(c * 230));
			if ((r == 2) && (c == 3)) {
				g->interesting = 1;
				g->name = "Intersection(2,3)";
				g->laX = static_cast<float>(r * 530 - 15);    g->laY = 0;    g->laZ = static_cast<float>(c * 230);
				g->lfX = static_cast<float>(r * 530 + 25);   g->lfY = 100;   g->lfZ = static_cast<float>(c * 230 + 150);
			}
			add(g);
		}
	}
	*/
}

void makeObjects()
{
	//draw goblet1 
	glPushMatrix();
	GrObject* goblet1 = new Goblet();
	goblet1->name = "L Goblet";
	goblet1->interesting = true;
	goblet1->laX = 0; goblet1->laY = 70; goblet1->laZ = 300;
	goblet1->lfX = -450; goblet1->lfY = 2; goblet1->lfZ = -500;
	add(goblet1, -725, 151, 700, 0);
	glPopMatrix();
	glPushMatrix();
	GrObject* goblet2 = new Goblet();
	goblet2->name = "R Goblet";
	goblet2->interesting = true;
	goblet2->laX = 0; goblet2->laY = 70; goblet2->laZ = 300;
	goblet2->lfX = 450; goblet2->lfY = 2; goblet2->lfZ = -500;
	add(goblet2, 600, 151, 700, 0);
	glPopMatrix();
	glPushMatrix();
	GrObject* goblet_part1 = new goblet_particle();
	goblet_part1->interesting = false;
	add(goblet_part1, 600, 240, 3675, 0);
	glPopMatrix();
	glPushMatrix();
	GrObject* goblet_part2 = new goblet_particle();
	goblet_part2->interesting = false;
	add(goblet_part2, -725, 240, 3675, 0);
	glPopMatrix();
	/*
	glPushMatrix();
	GrObject* gobletp = new goblet_profile();
	gobletp->interesting = true;
	gobletp->laX = 0; gobletp->laY = 0; gobletp->laZ = 0;
	gobletp->lfX = -50; gobletp->lfY = 100; gobletp->lfZ = 300;
	add(gobletp, 50, 150, 400, 0);
	glPopMatrix();
	*/
	//add birds flying around/blimp
	/*
	GrObject* blimp = new Blimp;
	blimp->interesting = true;
	blimp->laX = 0; blimp->laY = 0; blimp->laZ = 0;
	blimp->lfX = -50; blimp->lfY = 100; blimp->lfZ = 300;
	add(blimp, -100, 0, 100, pi / 2.f);
	*/

	//add train
	/*
	TrainWindow tw;
	
	GrObject* train = new Train;
	train->interesting = true;
	train->laX = 0; train->laY = 0; train->laZ = 0;
	train->lfX = -50; train->lfY = 100; train->lfZ = 300;
	add(train, -100, 0, 100, pi / 2.f);
	*/















	// *****************************************************************
	//  Make your town here

	// first, some really simple things

	// cubes are particularly easy since they set their own position
	// we need to raise the cube since we're giving the position of the
	// center 
	/*

	GrObject* cube1 = new ShadedCube(-50, 5, -50, 10, .7f, .6f, .3f);
	add(cube1);
	cube1->name = "Cube1";
	// make it an interesting object (so its easy to look at)
	// and give a place to look at it from
	// this is a good object to look at since it won't move
	cube1->interesting = true;
	cube1->laX = 0; cube1->laY = 0; cube1->laZ = 0;
	cube1->lfX = 70; cube1->lfY = 50; cube1->lfZ = 0;

	// make another cube - make this one spin around
	GrObject* cube2 = new Cube(-50, 5, -25, 10, .3f, .6f, .7f);
	add(cube2);
	new Spin(cube2);
	*/

	GrObject* fb = new FloatingBall();
	add(fb, -245, 100, -100);
	fb->name = "Mysterious Ball 1";
	fb->interesting = true;
	fb->laX = 0; fb->laY = 55; fb->laZ = -50;
	fb->lfX = -100; fb->lfY = -25; fb->lfZ = -200;
	new Float(fb);
	GrObject* fb2 = new FloatingBall2();
	add(fb2, 300, 185, -20, 40);
	fb2->name = "Mysterious Ball 2";
	fb2->interesting = true;
	fb2->laX = 75; fb2->laY = 165; fb2->laZ = -300;
	fb2->lfX = 275; fb2->lfY = 300; fb2->lfZ = -600;
	new Orbit(fb2);
	/*

	// now to demonstrate hierarchy - make another cube that spins, and
	// put a smaller cube on top of it
	GrObject* cube3 = new Cube(-50, 5, -75, 10, .7f, .3f, .6f);
	add(cube3);
	new Spin(cube3, .001f);
	GrObject* cube4 = new Cube(0, 7.5, 0, 5, 1, 0, 1);
	cube3->add(cube4);

	// make cars go around the track
	#ifndef TESTCARS
	// add some cars
	for (int r = 0; r<50; r++) {
	Car* c;
	switch (rand() % 3) {
	case 0: c = new Van(rand()); break;
	case 1: c = new SUV(rand()); break;
	case 2: c = new HatchBack(rand()); break;
	}
	add(c);
	new RandomDrive(c, theRoads[rand() % theRoads.size()], .2f, rand() % 2);
	}
	#endif

	#ifdef TESTCARS
	// two cars - one always turns right, one always turns left
	Car* c1 = new HatchBack(1);
	Car* c2 = new HatchBack(2);
	add(c1);
	add(c2);
	new RandomDrive(c1, theRoads[7], .5, 0, -1);
	new RandomDrive(c2, theRoads[8], .5, 0, 1);

	#endif
	
	*/

}

// $Header: /p/course/cs559-gleicher/private/CVS/GrTown/Main.cpp,v 1.8 2009/11/10 22:40:03 gleicher Exp $