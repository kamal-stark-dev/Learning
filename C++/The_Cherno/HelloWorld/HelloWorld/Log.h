#pragma once // this prevents multiple inclusions of this header file in a transational unit
// (hence, prevent duplication errors which may occur when you create something like a `struct`).

void Log(const char* message);

struct Person {};