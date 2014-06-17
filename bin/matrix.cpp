#include <iostream>
#include <new>
#include <cstddef>

#include <node.h>
#include <v8.h>

#include "matrix.h"

using namespace v8;

Persistent<Function> Matrix::constructor;

// Constructor
// -----------
// Performs all necessary initialization of the Matrix class (in C++)
Matrix::Matrix(double rows, double cols) {
	int i, j;

	this->rows_ = rows;
	this->cols_ = cols;

	this->rlen = &this->rows_;
	this->clen = &this->cols_;

	this->data_ = new double*[ (int)rows ];

	for (i = 0; i < rows; i++) {

		this->data_[i] = new double[ (int)cols ];

		// Initialize the values to 0
		for (j = 0; j < cols; j++) {
			this->data_[i][j] = 0;
		}
	}

}

// Handle<Value> Matrix::Zero(const Arguments& args) {
// 	Matrix* instance = node::ObjectWrap::Unwrap<Matrix>(info.Holder());

// 	HandleScope scope;
// 	int i = 0;
// 	int j = 0;

// 	for (i = instance->rows_; i--;) {
// 		for (j = instance->cols_; j--;) {
// 			instance->data_[i][j] = 0;
// 		}
// 	}

// 	return args.This();
// }

// Descructor
// ----------
// Clean up all allocated variables used in the class.
Matrix::~Matrix() {
	int i;
	for (i = 0; i < this->rows_; i++) {
		delete[] this->data_[i];
	}

	delete[] this->data_;
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

Handle<Value> Matrix::Get(const Arguments& args) {
	HandleScope scope;
	// unsigned i = 0;

	// Matrix m1 = node::ObjectWrap::Unwrap<Matrix>(args[0]->ToObject());
	// Matrix m2 = node::ObjectWrap::Unwrap<Matrix>(args[1]->ToObject());

	// for (i = 0; i < args->Length(); i++) {
	// 	// Add each individual element of the matrix.
	// }

	return scope.Close(Number::New(0));
}

Handle<Value> Matrix::Set(const Arguments& args) {
	HandleScope scope;
	// unsigned i = 0;

	// Matrix m1 = node::ObjectWrap::Unwrap<Matrix>(args[0]->ToObject());
	// Matrix m2 = node::ObjectWrap::Unwrap<Matrix>(args[1]->ToObject());

	// for (i = 0; i < args->Length(); i++) {
	// 	// Add each individual element of the matrix.
	// }

	return scope.Close(Number::New(0));
}

// Matrix Property: Size
// ---------------------
// Get the size of the matrix as a read-only property. In order to 
// resize the array, the user will need to call `resize`.
Handle<Value> GetSize(Local<String> property, const AccessorInfo& info) {
	Matrix* instance = node::ObjectWrap::Unwrap<Matrix>(info.Holder());
	
	Handle<Array> array = Array::New(2);

	array->Set(Number::New(0), Number::New(instance->rows_));
	array->Set(Number::New(1), Number::New(instance->cols_));

	return array;
}

// Matrix Property: Value
// ----------------------
// Get the matrix returned as a 2-D Array of values.
Handle<Value> GetValue(Local<String> property, const AccessorInfo& info) {
	Matrix* instance = node::ObjectWrap::Unwrap<Matrix>(info.Holder());

	int i, j;	
	Handle<Array> array = Array::New(instance->rows_);

	for (i = 0; i < instance->rows_; i++) {
		Local<Array> row = Array::New(instance->cols_);

		for (j = 0; j < instance->cols_; j++) {
			row->Set(Number::New(j), Number::New(instance->data_[i][j]));
		}

		array->Set(Number::New(i), row);
	}

	return array;
}

// Initialization Functions
// ========================
// This function defines the complete API of the JavaScript object by 
// wrapping specific C++ class functions.
void Matrix::Init(Handle<Object> exports) {
	Local<FunctionTemplate> t = FunctionTemplate::New(New);
	t->SetClassName(String::NewSymbol("Matrix"));
	t->InstanceTemplate()->SetInternalFieldCount(1);

	t->InstanceTemplate()->SetAccessor(String::New("size"), GetSize);
	t->InstanceTemplate()->SetAccessor(String::New("value"), GetValue);

	t->PrototypeTemplate()->Set(String::NewSymbol("add"),
		FunctionTemplate::New(Add)->GetFunction());

	// t->PrototypeTemplate()->Set(String::NewSymbol("zero"),
	// 	FunctionTemplate::New(Zero)->GetFunction());

	constructor = Persistent<Function>::New(t->GetFunction());

	exports->Set(String::NewSymbol("Matrix"), constructor);
}

// New Matrix
// ----------
// The `new` function interprets JavaScript input and parses it into 
// C++ compatible input to initialize the C++ class.
Handle<Value> Matrix::New(const Arguments& args) {
	HandleScope scope;

	Matrix* matrix_instance;
	Local<Object> dimensions;

	if (args.IsConstructCall()) {

		if (args[0]->IsArray()) {
			dimensions = args[0]->ToObject();
			matrix_instance = new Matrix(
				dimensions->Get(0)->NumberValue(),
				dimensions->Get(1)->NumberValue() );
		}
		else if (args[0]->IsNumber() && args[1]->IsNumber()) {
			matrix_instance = new Matrix(
				args[0]->NumberValue(), 
				args[1]->NumberValue() );
		}
		else {
			ThrowException(Exception::TypeError(String::New("Must provide dimensions to Matrix constructor.")));
			return scope.Close(Undefined());
		}

		matrix_instance->Wrap(args.This());
		return args.This();
	}
	else {
		const int argc = 1;

		Local<Value> argv[argc] = { args[0] };
		return scope.Close(constructor->NewInstance(argc, argv));
	}
}


