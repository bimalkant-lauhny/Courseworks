#pragma once
/*
  pragma once preprocessor forces the compiler to include declarations only once
*/

/*
Old style enums
Names provided to constants (numbers) must be unique
*/
enum Status {
    Pending,
    Approved,
    Cancelled
};

/*
Scoped Enums are new style enums
Names can be same now (for ex. 'ok' below)
*/
enum class FileError {
    notfound,
    ok
};

enum class NetworkError {
    disconnected,
    ok
};