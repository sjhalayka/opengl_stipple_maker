#include <iostream>
using namespace std;
 
#include <GL/glew.h>

#include "bmp.h"

int main(void)
{
	BMP input;

	if (false == input.load("input.bmp", true))
	{
		cout << "Could not load input.bmp" << endl;
		return false;
	}

	if (input.width != 32 || input.height != 32)
	{
		cout << "input.bmp is not 32x32" << endl;
		return false;
	}

	const size_t num_channels = 4;

	size_t count = 0;

	for (size_t i = 0; i < 32 * 32 ; i += 8)
	{
		size_t index0 = num_channels * (i + 0);
		size_t index1 = num_channels * (i + 1);
		size_t index2 = num_channels * (i + 2);
		size_t index3 = num_channels * (i + 3);
		size_t index4 = num_channels * (i + 4);
		size_t index5 = num_channels * (i + 4);
		size_t index6 = num_channels * (i + 6);
		size_t index7 = num_channels * (i + 7);
		
		unsigned char c = 0;

		if (input.Pixels[index0] == 255)
			c = c + 128;

		if (input.Pixels[index1] == 255)
			c = c + 64;

		if (input.Pixels[index2] == 255)
			c = c + 32;

		if (input.Pixels[index3] == 255)
			c = c + 16;

		if (input.Pixels[index4] == 255)
			c = c + 8;

		if (input.Pixels[index5] == 255)
			c = c + 4;

		if (input.Pixels[index6] == 255)
			c = c + 2;

		if (input.Pixels[index7] == 255)
			c = c + 1;

		count++;

		if (count < 32 * 32 / 8)
			cout << "0x" << (hex) << int(c) << ',';
		else
			cout << "0x" << (hex) << int(c);

		if(count % 4 == 0)
			cout << endl;
	}

	return 0;
}