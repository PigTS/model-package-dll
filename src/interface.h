#pragma once

#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <vector>
#include <algorithm>
#include "net.h"
#include "base64.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "mobilenet_v2.id.h"
#include "mobilenet_v2.mem.h"

//net
ncnn::Net net;
//init model
void initModel();
//identify
const char* identify(const char* img_base64);
//free model
void freeModel();

#endif