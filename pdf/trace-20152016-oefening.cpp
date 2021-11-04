/**
 * @file
 * Example session of Gobelijn trace assignment.
 * @author Glenn Daneels  CoMP/UA
 */

#include <iostream>
#include <vector>
#include <exception>
#include "tracer/tracer.h"
#include "objtracer/demobj.h"
#include "demos.h"

using namespace ODemo;
using std::cout;
using std::endl;
using std::vector;
using std::exception;
using std::shared_ptr;
using std::function;
using std::string;

namespace {
	void func(const Vehicle* vehicle) {
		COMP_MISC_FUNCTION_TRACER;
		vehicle->get_info();
	}
}

int practsession()
{
	COMP_MISC_FUNCTION_TRACER;
	{
		COMP_MISC_BLOCK_TRACER("Block 1");

		COMP_MISC_LOG_TRACER(" statement: Bicycle m1(\"Honda\", \"red\");");
		Bicycle m1("Honda", "red");

		COMP_MISC_LOG_TRACER(" statement: Bicycle* m2 = new Bicycle(m1);");
		Bicycle* m2 = new Bicycle(m1);

		COMP_MISC_LOG_TRACER(" statement: func(m2);");
		func(m2);

		COMP_MISC_LOG_TRACER(" statement: delete m2;");
		delete m2;
	}

	{
		COMP_MISC_BLOCK_TRACER("Block 2");

		COMP_MISC_LOG_TRACER(" statement: Motorcycle yamaha(shared_ptr<Engine>(new Engine(80)));");
		Motorcycle yamaha(shared_ptr<Engine>(new Engine(80)));

		COMP_MISC_LOG_TRACER(" statement: shared_ptr<Motorcycle> suzuki(new Motorcycle(yamaha));");
		shared_ptr<Motorcycle> suzuki(new Motorcycle(yamaha));

		COMP_MISC_LOG_TRACER(" statement: suzuki->startEngine();");
		suzuki->startEngine();
	}

	{
		COMP_MISC_BLOCK_TRACER("Block 3");

		COMP_MISC_LOG_TRACER( " statement: Motorcycle m1;");
		Motorcycle m1;

		COMP_MISC_LOG_TRACER(" statement: Motorcycle m2 = m1;");
		Motorcycle m2 = m1;

		COMP_MISC_LOG_TRACER(" statement: m1 = std::move(m2);");
		m1 = std::move(m2);
	}
	
	COMP_MISC_LOG_TRACER(" statement: return 0;");
	return 0;
}