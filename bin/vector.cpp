#include <node.h>
#include <v8.h>

#include "vector.h"

using namespace v8;

Persistent<Function> Vector::constructor;

Vector::Vector(double value) : value_(value) {

}

Vector::~Vector() {
	
}

void Vector::Init(Handle<Object> exports) {
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::NewSymbol("Vector"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// tpl->PrototypeTemplate()->Set(String::NewSymbol("plusOne"),
	// 	FunctionTemplate::New(PlusOne)->GetFunction());

	constructor = Persistent<Function>::New(tpl->GetFunction());

	exports->Set(String::NewSymbol("Vector"), constructor);
}

Handle<Value> Vector::New(const Arguments& args) {
	HandleScope scope;

	if (args.IsConstructCall()) {
		Vector* vector_instance = new Vector();
		vector_instance->Wrap(args.This());
		return args.This();
	}
	else {
		const int argc = 1;

		Local<Value> argv[argc] = { args[0] };
		return scope.Close(constructor->NewInstance(argc, argv));
	}
}