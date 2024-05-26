#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include <openssl/evp.h>

#define OPENSSL_ENGINE NULL

 std::string sha256(const std::string reference);