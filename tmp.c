#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int    main(void)
{
	float	ran_x = (float)(arc4random_uniform(2000)) / 1000.f - 1;
	float	ran_y = (float)(arc4random_uniform(2000)) / 1000.f - 1;
	float	ran_z = (float)(arc4random_uniform(2000)) / 1000.f - 1;
	float	ran_x1 = (float)(arc4random_uniform(2000)) / 1000.f - 1;
	float	ran_y1 = (float)(arc4random_uniform(2000)) / 1000.f - 1;
	float	ran_z1 = (float)(arc4random_uniform(2000)) / 1000.f - 1;

	printf("POS: (%.3f, %.3f, %.3f)\n", ran_x, ran_y, ran_z);
	printf("AXI: (%.3f, %.3f, %.3f)\n", ran_x1, ran_y1, ran_z1);

	for (float i = (M_PI*4) / 5; i < (M_PI*4); i += (M_PI*4) / 10)
	{
		float w1 = 0.f;
		float x1 = ran_x;
		float y1 = ran_y;
		float z1 = ran_z;
		float w2 = cos(i/2);
		float x2 = ran_x1 * sin(i/2);
		float y2 = ran_y1 * sin(i/2);
		float z2 = ran_z1 * sin(i/2);

		float fw = (w1*w2 - x1*x2 - y1*y2 - z1*z2);
		float fx = (w1*x2 + x1*w2 + y1*z2 - z1*y2);
		float fy = (w1*y2 - x1*z2 + y1*w2 + z1*x2);
		float fz = (w1*z2 + x1*y2 - y1*x2 + z1*w2);

		float length = sqrtf(fw * fw + fx * fx + fy * fy + fz * fz);
		fw /= length;
		fx /= length;
		fy /= length;
		fz /= length;

		printf("(%.3f, %.3f, %.3f)\n", fx/2, fy/2, fz/2);
	}
    
    return 1;
}