#ifndef MATH_VALUE_H
#define MATH_VALUE_H

#include <node.h>

#include "binary.h"

namespace Math {

	template <typename T>
	class Value : public Binary {
	public:

		virtual T GetValue() {
			return this->value;
		}
		
		virtual void SetValue(T value) {
			this->value = value;
		}

	protected:

		static v8::Handle<v8::Value> GetValue(v8::Local<v8::String> property, const v8::AccessorInfo& info);

		T value;
	
	};

}

#endif