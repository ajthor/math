#include <node.h>
#include <v8.h>

#include "matrix.h"

using namespace v8;

Persistent<Function> Matrix::constructor;

Matrix::Matrix(double value) : value_(value) {

}

Matrix::~Matrix() {

}

void Matrix::Init(Handle<Object> exports) {
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::NewSymbol("Matrix"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// tpl->PrototypeTemplate()->Set(String::NewSymbol("plusOne"),
	// 	FunctionTemplate::New(PlusOne)->GetFunction());

	constructor = Persistent<Function>::New(tpl->GetFunction());

	exports->Set(String::NewSymbol("Matrix"), constructor);
}

Handle<Value> Matrix::New(const Arguments& args) {
	HandleScope scope;

	if (args.IsConstructCall()) {
		Matrix* vector_instance = new Matrix();
		vector_instance->Wrap(args.This());
		return args.This();
	}
	else {
		const int argc = 1;

		Local<Value> argv[argc] = { args[0] };
		return scope.Close(constructor->NewInstance(argc, argv));
	}
}