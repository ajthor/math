#include <new>
#include <cstddef>

#include <node.h>
#include <v8.h>

#include "value.h"

Handle<v8::Value> Math::Value::Add(const v8::Arguments& args) {
	v8::HandleScope scope;
	Math::Value* result = new Math::Value();

	Math::Value* a = node::ObjectWrap::Unwrap<Math::Value>(args.This());
	Math::Value* b = node::ObjectWrap::Unwrap<Math::Value>(args[0]);

	result->value = a->value + b->value;

	result->Wrap(args.This());
	return scope.Close(;
}

Handle<v8::Value> Math::Value::Sub(const v8::Arguments& args) {
	v8::HandleScope scope;
	Math::Value* result = new Math::Value();

	Math::Value* a = node::ObjectWrap::Unwrap<Math::Value>(args.This());
	Math::Value* b = node::ObjectWrap::Unwrap<Math::Value>(args[0]);

	result->value = a->value - b->value;

	result->Wrap(args.This());
	return scope.Close(;
}

Handle<v8::Value> Math::Value::Mult(const v8::Arguments& args) {
	v8::HandleScope scope;
	Math::Value* result = new Math::Value();

	Math::Value* a = node::ObjectWrap::Unwrap<Math::Value>(args.This());
	Math::Value* b = node::ObjectWrap::Unwrap<Math::Value>(args[0]);

	result->value = a->value * b->value;

	result->Wrap(args.This());
	return scope.Close(;
}

Handle<v8::Value> Math::Value::Prod(const v8::Arguments& args) {
	v8::HandleScope scope;
	Math::Value* result = new Math::Value();

	Math::Value* a = node::ObjectWrap::Unwrap<Math::Value>(args.This());
	Math::Value* b = node::ObjectWrap::Unwrap<Math::Value>(args[0]);

	result->value = a->value * b->value;

	result->Wrap(args.This());
	return scope.Close(;
}

Handle<v8::Value> Math::Value::Quot(const v8::Arguments& args) {
	v8::HandleScope scope;
	Math::Value* result = new Math::Value();

	Math::Value* a = node::ObjectWrap::Unwrap<Math::Value>(args.This());
	Math::Value* b = node::ObjectWrap::Unwrap<Math::Value>(args[0]);

	result->value = a->value / b->value;

	result->Wrap(args.This());
	return scope.Close(;
}

Handle<v8::Value> Math::Value::Pow(const v8::Arguments& args) {
	v8::HandleScope scope;
	Math::Value* result = new Math::Value();

	Math::Value* a = node::ObjectWrap::Unwrap<Math::Value>(args.This());
	Math::Value* b = node::ObjectWrap::Unwrap<Math::Value>(args[0]);

	result->value = a->value ^ b->value;

	result->Wrap(args.This());
	return scope.Close(;
}
