#ifndef MATRIX_H
#define MATRIX_H

#include <node.h>

class Matrix : public node::ObjectWrap {
public:
	static void Init(v8::Handle<v8::Object> exports);

	double rows_;
	double cols_;

	const double * rlen;
	const double * clen;

	double ** data_;
private:

	explicit Matrix(double rows, double cols);
	~Matrix();

	static v8::Handle<v8::Value> Get(const v8::Arguments& args);
	static v8::Handle<v8::Value> Set(const v8::Arguments& args);

	static v8::Handle<v8::Value> Copy(const v8::Arguments& args);
	static v8::Handle<v8::Value> Clone(const v8::Arguments& args);
	static v8::Handle<v8::Value> Map(const v8::Arguments& args);
	static v8::Handle<v8::Value> ForEach(const v8::Arguments& args);

	static v8::Handle<v8::Value> Zero(const v8::Arguments& args);

	static v8::Handle<v8::Value> Join(const v8::Arguments& args);
	static v8::Handle<v8::Value> Concat(const v8::Arguments& args);

	static v8::Handle<v8::Value> Add(const v8::Arguments& args);
	static v8::Handle<v8::Value> Sub(const v8::Arguments& args);
	static v8::Handle<v8::Value> Mult(const v8::Arguments& args); // Scalar
	static v8::Handle<v8::Value> Prod(const v8::Arguments& args); // Matrix

	static v8::Handle<v8::Value> Hadamard(const v8::Arguments& args);

	static v8::Handle<v8::Value> Pow(const v8::Arguments& args);

	static v8::Handle<v8::Value> ForEachRow(const v8::Arguments& args);
	static v8::Handle<v8::Value> Sum();

	static v8::Handle<v8::Value> New(const v8::Arguments& args);
	static v8::Persistent<v8::Function> constructor;

};

#endif