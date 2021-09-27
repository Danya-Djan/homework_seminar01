#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "complex.h"
using namespace std;

// В этой программе мы рисуем в картинку комплексную функцию,
// которая задаётся в функции func

struct Color {
	unsigned char r, g, b;
};

Complex func(Complex z, Complex c) {
	for (int i = 0; i < 20; i++) {
		z = z * z + c;
	}
	return z;
}


int main() {
	int width = 800, height = 800;
	float x0 = -2.0f, x1 = 2.0f;
	float y0 = -2.0f, y1 = 2.0f;
	
	// Выделяем память под пиксели
	Color* data = (Color*)malloc(sizeof(Color) * width * height);

	// data - это массив цветов размером width * height
	// Задаём значения этого массива так, чтобы
	// реальная часть функции func соответствовала зелёному цвету,
	// а мнимая часть -- синей компоненте цвета
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			Complex c = {x0 + (x1-x0) / width * i, y0 + (y1-y0) / width * j};
			Complex z = {.0f, .0f};
			Complex f = func(z, c);
			data[i + width * j].r = 255 - f.re;
			data[i + width * j].g = f.re;
			data[i + width * j].b = f.im;
		}
	}

	// Сохраняем массив цветов data как картинку в формате .ppm
	FILE* file = fopen("Mandelbrot.ppm", "wb");
	fprintf(file, "P6\n%d %d\n255\n", width, height);
	fwrite(data, sizeof(Color), height * width, file);
	fclose(file);

	// Освобождаем память
	free(data);
}