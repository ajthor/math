#ifndef MATRIX_H
#define MATRIX_H

#include <node.h>

#include "../value.h"

class Matrix : public Math::Value<double **> {
public:
	static void Init(v8::Handle<v8::Object> exports);

	int rows_;
	int cols_;

private:
	explicit Matrix(int rows, int cols);
	explicit Matrix(double ** data);
	~Matrix();

	static v8::Handle<v8::Value> Zero(const v8::Arguments& args);

	static v8::Handle<v8::Value> Get(const v8::Arguments& args);
	static v8::Handle<v8::Value> Set(const v8::Arguments& args);

	static v8::Handle<v8::Value> New(const v8::Arguments& args);
	static v8::Persistent<v8::Function> constructor;

	double ** GetValue() {
		return this->value;
	}
	static v8::Handle<v8::Value> GetValue(v8::Local<v8::String> property, const v8::AccessorInfo& info);

	static v8::Handle<v8::Value> Copy(const v8::Arguments& args);
	static v8::Handle<v8::Value> Clone(const v8::Arguments& args);
	static v8::Handle<v8::Value> Map(const v8::Arguments& args);
	static v8::Handle<v8::Value> ForEach(const v8::Arguments& args);

	static v8::Handle<v8::Value> Join(const v8::Arguments& args);
	static v8::Handle<v8::Value> Concat(const v8::Arguments& args);

	static v8::Handle<v8::Value> Hadamard(const v8::Arguments& args);

	static v8::Handle<v8::Value> ForEachRow(const v8::Arguments& args);
	static v8::Handle<v8::Value> Sum();
	
};

#endif