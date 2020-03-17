#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main()
{
	double square, lenght, radius, squareofcircle, halfdiagonal;

	printf("Square and lenght: ");
	scanf_s("%lf%lf", &square, &lenght);

	if (square > 100 || lenght > 100)
	{
		printf("\nSquare or lenght is more than 100\n");
		exit(2);
	}

	radius = square / 2;
	halfdiagonal = (square * sqrt(2)) / 2;

	if (radius > lenght)
	{
		squareofcircle = M_PI * lenght * lenght;
	}
	else if (lenght >= halfdiagonal)
	{
		squareofcircle = pow(square, 2);
	}
	else if (lenght > halfdiagonal && lenght > radius);
	{
		squareofcircle = 4 * (square / 2) * (square / 2) * (0.8215654504123046508035 / 0.88622692545275801364);
	}


	printf("Answer: %.3lf\n", squareofcircle);

	system("pause");
	return 0;
}