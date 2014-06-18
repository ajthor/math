#include <new>
#include <cstddef>

#include <node.h>
#include <v8.h>

#include "matrix.h"

using namespace v8;

Persistent<Function> Matrix::constructor;