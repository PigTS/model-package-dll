#define _CRT_SECURE_NO_WARNINGS
#include "interface.h"

void initModel()
{
	net.load_param(mobilenet_v2_param_bin);
	net.load_model(mobilenet_v2_bin);
}

const char* identify(const char* img_base64)
{
	std::string img_binary = base64_decode(img_base64);
	const unsigned char* img = (const unsigned char*)(img_binary.c_str());
	int width(0), height(0), channel(0), length(img_binary.size());
	unsigned char* input_img = stbi_load_from_memory(img, length, &width, &height, &channel, 0);

	ncnn::Mat in = ncnn::Mat::from_pixels_resize(input_img, ncnn::Mat::PIXEL_RGB2BGR, width, height, 224, 224);
	ncnn::Mat out;

	ncnn::Extractor ex = net.create_extractor();
	ex.set_light_mode(true);
	ex.set_num_threads(4);

	ex.input(mobilenet_v2_param_id::BLOB_x, in);
	ex.extract(mobilenet_v2_param_id::BLOB_y, out);

	ncnn::Mat out_flattened = out.reshape(out.w * out.h * out.c);
	std::vector<float> score;
	score.resize(out_flattened.w);
	for (int i = 0; i < out_flattened.w; ++i) {
		score[i] = out_flattened[i];
	}
	std::vector<float>::iterator max_id = max_element(score.begin(), score.end());

	//res ---> predicted class + predicted value
	char res[20];
	sprintf(res, "%d %.6f", max_id - score.begin(), score[max_id - score.begin()]);

	free(input_img);
	return res;
}

void freeModel()
{
	net.clear();
}

