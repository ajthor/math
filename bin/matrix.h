#ifndef MATRIX_H
#define MATRIX_H

#include <node.h>

class Matrix : public node::ObjectWrap {
public:
	static void Init(v8::Handle<v8::Object> exports);

private:
	explicit Matrix(double value = 0);
	~Matrix();

	static v8::Handle<v8::Value> New(const v8::Arguments& args);
	static v8::Persistent<v8::Function> constructor;

	double value_;
};

#endif