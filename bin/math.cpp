#include <node.h>
#include <v8.h>

#include "vector.h"
#include "matrix.h"

using namespace v8;

void Init(Handle<Object> exports) {
	Vector::Init(exports);
	Matrix::Init(exports);
}

NODE_MODULE(math, Init)