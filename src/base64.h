#pragma once

#ifndef __BASE64_H__
#define __BASE64_H__

#include <iostream>
#include <string>

/*
*base64 ±àÂë/½âÂë
*/

static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static inline bool is_base64(const char c);

std::string base64_encode(const char* bytes_to_encode, unsigned int in_len);

std::string base64_decode(std::string const& encoded_string);

#endif
