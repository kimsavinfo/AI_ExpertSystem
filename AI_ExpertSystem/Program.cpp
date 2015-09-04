#include <iostream>

#include <string>
using namespace std;


int main( int argc, const char* argv[] )
{
	cout << "Hello, 'Expert System : Polygon' at your service !\n\n\n";

	// ===========================================

	/*
	InferenceEngine* cubica = new InferenceEngine(); 

	// Rule for triangles
	cubica->addRule("R1 : IF (Edges=3(How many edges ?)) THEN Triangle");
	cubica->addRule("R2 : IF (Triangle AND Right angle(Has the polygon got at least one right angle ?)) THEN Right Triangle");
	cubica->addRule("R3 : IF (Triangle AND Equal Sides=2(How many sides of equal lenght has the polygon got ?)) THEN Isosceles Triangle");
	cubica->addRule("R4 : IF (Right Triangle AND Isosceles Triangle) THEN Right Isosceles Triangle");
	cubica->addRule("R5 : IF (Triangle AND Equal Sides=3(How many sides of equal lenght has the polygon got ?)) THEN Equilateral Triangle");

	// Rule for Quadrilaterals
	cubica->addRule("R6 : IF (Edges=4(How many edges ?)) THEN Quadrilateral");
	cubica->addRule("R7 : IF (Quadrilateral AND Parallel Sides=2(How many parallel sides has the polygon got ? - 0, 2 ou 4)) THEN Trapezoid");
	cubica->addRule("R8 : IF (Quadrilateral AND Parallel Sides=4(How many parallel sides has the polygon got ? - 0, 2 ou 4)) THEN Parallelogram");
	cubica->addRule("R9 : IF (Parallelogram AND Right angle(Has the polygon got at least one right angle ?)) THEN Rectangle");
	cubica->addRule("R10 : IF (Parallelogram AND Equal Sides=4(How many sides of equal lenght has the polygon got ?)) THEN Rhombus");
	cubica->addRule("R11 : IF (Rectangle AND Rhombus) THEN Square");

	cubica->solve();
	*/

	// ===========================================

	string exit = "\n\n\n> Goodbye, have a nice day :) ";
	cout << exit;
	cin >> exit;

	return 0;
}