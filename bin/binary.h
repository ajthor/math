#ifndef BINARY_H
#define BINARY_H

#include <node.h>
#include "object.h"

namespace Math {

	class Binary : public Math::Object {
	public:
		virtual ~Binary();

		virtual Binary operator+(const Binary& b);
		virtual Binary operator-(const Binary& b);
		
		virtual Binary operator*(const Binary& b);
		virtual Binary operator/(const Binary& b);

		virtual Binary operator^(const Binary& b);

	protected:
		
		static v8::Handle<v8::Value> Add(const v8::Arguments& args);
		static v8::Handle<v8::Value> Sub(const v8::Arguments& args);

		static v8::Handle<v8::Value> Mult(const v8::Arguments& args);
		static v8::Handle<v8::Value> Prod(const v8::Arguments& args);
		static v8::Handle<v8::Value> Quot(const v8::Arguments& args);

		static v8::Handle<v8::Value> Pow(const v8::Arguments& args);

	};

}

#endif