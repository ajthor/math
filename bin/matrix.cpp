#include <new>
#include <cstddef>

#include <node.h>
#include <v8.h>

#include "matrix.h"

using namespace v8;

Persistent<Function> Matrix::constructor;

// Constructor
// -----------
// Performs all necessary initialization of the Matrix class.
Matrix::Matrix(int rows, int cols) {
	int i, j;

	this->rows_ = rows;
	this->cols_ = cols;

	this->data_ = new double*[ rows ];

	for (i = 0; i < rows; i++) {

		this->data_[i] = new double[ cols ];

		// Initialize the values to 0
		for (j = 0; j < cols; j++) {
			this->data_[i][j] = 0;
		}
	}
}

Matrix::Matrix(double ** data) {
	int i, j;
	int rows, cols;

	// Count the number of rows and cols in the dataset given to the 
	// matrix constructor.
	for (rows = 0; data[rows]; rows++)
		;

	for (cols = 0; data[0][cols]; cols++)
		;

	this->data_ = new double*[ rows ];

	for (i = 0; i < rows; i++) {

		this->data_[i] = new double[ cols ];

		for (j = 0; j < cols; j++) {
			this->data_[i][j] = data[i][j];
		}
	}

	this->rows_ = rows;
	this->cols_ = cols;
}

Handle<Value> Matrix::Zero(const Arguments& args) {
	HandleScope scope;
	Matrix* instance = node::ObjectWrap::Unwrap<Matrix>(args.This());
	int i = 0;
	int j = 0;

	double value = args[0]->IsNumber() ? args[0]->NumberValue() : 0;

	for (i = instance->rows_; i--;) {
		for (j = instance->cols_; j--;) {
			instance->data_[i][j] = value;
		}
	}

	return args.This();
}

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

	int i, len;
	for (i = 0, len = args.Length(); i < len; i++) {
		if (args[0]->IsNumber()) {

		}
	}

	return scope.Close(Number::New(0));
}

Handle<Value> Matrix::Get(const Arguments& args) {
	HandleScope scope;

	Matrix* instance = node::ObjectWrap::Unwrap<Matrix>(args.This());

	if (!args[0]->IsArray() && !args[0]->IsNumber()) {
		ThrowException(Exception::TypeError(String::New("Must provide index to Matrix get function.")));
		return scope.Close(Undefined());
	}

	// If the user input only one number, it means we should return 
	// one entire row.
	if (args[0]->IsNumber() && !args[1]->IsNumber()) {

		Local<Array> array = Array::New(instance->rows_);
		int row = args[0]->Int32Value();

		if (row >= 0 && row < instance->rows_) {
			for (int i = 0; i < instance->cols_; i++) {
				array->Set(Number::New(i), Number::New(instance->data_[row][i]));
			}
			return scope.Close(array);
		}
		else {
			ThrowException(Exception::TypeError(String::New("Index is out of range.")));
			return scope.Close(Undefined());
		}

	}

	// Two numbers were passed to the `get` function, which means 
	// that the user wants just one value out of the matrix.
	if (args[0]->IsNumber() && args[1]->IsNumber()) {
		int row = args[0]->Int32Value();
		int col = args[1]->Int32Value();

		if (row >= 0 && row < instance->rows_) {
			if (col >= 0 && col < instance->cols_) {
				return scope.Close(Number::New(instance->data_[row][col]));
			}
		}
		
		ThrowException(Exception::TypeError(String::New("Index is out of range.")));
		return scope.Close(Undefined());
	}

	return scope.Close(Undefined());
}

Handle<Value> Matrix::Set(const Arguments& args) {
	HandleScope scope;

	Matrix* instance = node::ObjectWrap::Unwrap<Matrix>(args.This());
	// int row = args[0]->Int32Value();
	// int col = args[1]->Int32Value();

	if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
		ThrowException(Exception::TypeError(String::New("Must provide index to Matrix set function.")));
		return scope.Close(Undefined());
	}

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

Handle<Value> GetRows(Local<String> property, const AccessorInfo& info) {
	Matrix* instance = node::ObjectWrap::Unwrap<Matrix>(info.Holder());
	return Number::New(instance->rows_);
}

Handle<Value> GetCols(Local<String> property, const AccessorInfo& info) {
	Matrix* instance = node::ObjectWrap::Unwrap<Matrix>(info.Holder());
	return Number::New(instance->cols_);
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
	t->InstanceTemplate()->SetAccessor(String::New("rows"), GetRows);
	t->InstanceTemplate()->SetAccessor(String::New("cols"), GetCols);

	t->InstanceTemplate()->SetAccessor(String::New("value"), GetValue);

	t->PrototypeTemplate()->Set(String::NewSymbol("add"),
		FunctionTemplate::New(Add)->GetFunction());

	t->PrototypeTemplate()->Set(String::NewSymbol("zero"),
		FunctionTemplate::New(Zero)->GetFunction());

	t->PrototypeTemplate()->Set(String::NewSymbol("get"),
		FunctionTemplate::New(Get)->GetFunction());

	constructor = Persistent<Function>::New(t->GetFunction());

	exports->Set(String::NewSymbol("Matrix"), constructor);
}

// New Matrix
// ----------
// The `new` function interprets JavaScript input and parses it into 
// C++ compatible input to initialize the C++ class.
Handle<Value> Matrix::New(const Arguments& args) {
	HandleScope scope;

	int i;
	int j;

	int rows;
	int cols;

	Matrix* matrix_instance;
	Local<Array> array;
	Local<Array> row;

	if (args.IsConstructCall()) {

		// If the user passes an array, we assume the array contains 
		// the dimensions of the matrix.
		if (!args[0]->IsArray()) {
			ThrowException(Exception::TypeError(String::New("Must provide dimensions to Matrix constructor.")));
			return scope.Close(Undefined());
		}

		array = Array::Cast(*args[0]);

		// If the values passed are a 2-D array, we can assume 
		// that the arguments passed are the values of the 
		// matrix. In which case, we should set the values of the 
		// matrix to be the ones passed to the constructor.
		if (array->Get(0)->IsArray()) {
			rows = array->Length();
			cols = Array::Cast(*array->Get(0))->Length();

			matrix_instance = new Matrix(rows, cols);

			for (i = 0; i < rows; i++) {

				row = Array::Cast(*array->Get(i));

				for (j = 0; j < cols; j++) {
					matrix_instance->data_[i][j] = row->Get(j)->NumberValue();
				}
			}

		}

		// Otherwise, we know that the numbers are the dimensions of 
		// the array.
		else {
			matrix_instance = new Matrix(
				array->Get(0)->Int32Value(),
				array->Get(1)->Int32Value() );
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


