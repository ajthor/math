#ifndef UNARY_H
#define UNARY_H

#include <node.h>
#include "object.h"

namespace Math {

	class Unary : public Math::Object {
	public:
		virtual ~Unary();

		virtual Unary operator()(const Unary& b);

	protected:
		
	};

}

#endif