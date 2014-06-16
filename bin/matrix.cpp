#include <iostream>
#include <new>
#include <cstddef>

#include <node.h>
#include <v8.h>

#include "matrix.h"

using namespace v8;

Persistent<Function> Matrix::constructor;

Matrix::Matrix(double rows, double cols) {
	this->rows_ = &rows;
	this->cols_ = &cols;

	this->dimensions_ = new double[2];
	this->dimensions_[0] = rows;
	this->dimensions_[1] = cols;
}

Matrix::~Matrix() {
	delete[] this->dimensions_;
}

Handle<Value> Matrix::Add(const Arguments& args) {
	HandleScope scope;
	// unsigned i = 0;

	// Matrix m1 = node::ObjectWrap::Unwrap<Matrix>(args[0]->ToObject());
	// Matrix m2 = node::ObjectWrap::Unwrap<Matrix>(args[1]->ToObject());

	// for (i = 0; i < args->Length(); i++) {
	// 	// Add each individual element of the matrix.
	// }

	return scope.Close(Number::New(0));
}

Handle<Value> Matrix::Sub(const Arguments& args) {
	HandleScope scope;
	// unsigned i = 0;

	// Matrix m1 = node::ObjectWrap::Unwrap<Matrix>(args[0]->ToObject());
	// Matrix m2 = node::ObjectWrap::Unwrap<Matrix>(args[1]->ToObject());

	// for (i = 0; i < args->Length(); i++) {
	// 	// Add each individual element of the matrix.
	// }

	return scope.Close(Number::New(0));
}

Handle<Value> Matrix::Mult(const Arguments& args) {
	HandleScope scope;
	return scope.Close(Number::New(0));
}

Handle<Value> Matrix::Prod(const Arguments& args) {
	HandleScope scope;
	return scope.Close(Number::New(0));
}

Handle<Value> GetDimensions(Local<String> property, const AccessorInfo& info) {
	Matrix* instance = node::ObjectWrap::Unwrap<Matrix>(info.Holder());
	
	int i, len = sizeof(instance->dimensions_) / sizeof(instance->dimensions_[0]);
	Handle<Array> array = Array::New(len);

	for (i = 0; i < 2; i++) {
		array->Set(Number::New(i), Number::New(instance->dimensions_[i]));
	}

	return array;
}

// Initialization Function
// =======================
// This function defines the complete API of the JavaScript object by 
// wrapping specific C++ class functions.
void Matrix::Init(Handle<Object> exports) {
	Local<FunctionTemplate> t = FunctionTemplate::New(New);
	t->SetClassName(String::NewSymbol("Matrix"));
	t->InstanceTemplate()->SetInternalFieldCount(1);

	t->InstanceTemplate()->SetAccessor(String::New("dimensions"), GetDimensions);

	t->PrototypeTemplate()->Set(String::NewSymbol("add"),
		FunctionTemplate::New(Add)->GetFunction());

	t->PrototypeTemplate()->Set(String::NewSymbol("sub"),
		FunctionTemplate::New(Sub)->GetFunction());

	t->PrototypeTemplate()->Set(String::NewSymbol("mult"),
		FunctionTemplate::New(Mult)->GetFunction());

	t->PrototypeTemplate()->Set(String::NewSymbol("prod"),
		FunctionTemplate::New(Prod)->GetFunction());

	constructor = Persistent<Function>::New(t->GetFunction());

	exports->Set(String::NewSymbol("Matrix"), constructor);
}

Handle<Value> Matrix::New(const Arguments& args) {
	HandleScope scope;

	if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
		ThrowException(Exception::TypeError(String::New("Must provide dimensions to Matrix constructor.")));
		return scope.Close(Undefined());
	}

	if (args.IsConstructCall()) {
		Matrix* matrix_instance = new Matrix(
			args[0]->NumberValue(), 
			args[1]->NumberValue() );

		matrix_instance->Wrap(args.This());
		return args.This();
	}
	else {
		const int argc = 1;

		Local<Value> argv[argc] = { args[0] };
		return scope.Close(constructor->NewInstance(argc, argv));
	}
}


