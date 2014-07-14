#include <node.h>
#include <v8.h>

#include "matrix/matrix.h"

using namespace v8;

void Init(Handle<Object> exports) {
	Matrix::Init(exports);
}

NODE_MODULE(math, Init)