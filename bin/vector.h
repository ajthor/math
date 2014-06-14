#ifndef VECTOR_H
#define VECTOR_H

#include <node.h>

class Vector : public node::ObjectWrap {
public:
	static void Init(v8::Handle<v8::Object> exports);

private:
	explicit Vector(double value = 0);
	~Vector();

	static v8::Handle<v8::Value> New(const v8::Arguments& args);
	static v8::Persistent<v8::Function> constructor;

	double value_;
};

#endif