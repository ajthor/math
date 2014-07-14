#ifndef MATH_OBJECT_H
#define MATH_OBJECT_H

#include <node.h>

namespace Math {

	class Object : public node::ObjectWrap {
	public:
		virtual ~Object() = 0;

		static void Init(v8::Handle<v8::Object> exports);

	protected:

		static v8::Handle<v8::Value> New(const v8::Arguments& args);
		static v8::Persistent<v8::Function> constructor;

	};

}

#endif