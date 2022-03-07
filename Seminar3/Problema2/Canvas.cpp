#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int width, int height) {
	matrice = new char* [height];
	for (int i = 0; i < height; i++)
		matrice[i] = new char[width];
	Canvas::height = height;
	Canvas::width = width;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray) Canvas::matrice[i][j] = ch;
			else Canvas::matrice[i][j] = ' ';
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray) Canvas::matrice[i][j] = ch;
			else Canvas::matrice[i][j] = ' ';
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((i == top && (j >= left && j <= right)) || (i == bottom && (j >= left && j <= right))
				|| (j == left && (i <= bottom && i >= top)) || (j == right && (i <= bottom && i >= top)))
					Canvas::matrice[i][j] = ch;
			else Canvas::matrice[i][j]=' ';
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((i<=bottom && i>=top) && (j>=left && j<=right)) Canvas::matrice[i][j] = ch;
			else Canvas::matrice[i][j] = ' ';
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch) {
	Canvas::Clear();
	Canvas::matrice[x][y] = ch;
}

void Canvas::Print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) std::cout << Canvas::matrice[i][j];
		std::cout << '\n';
	}
}

void Canvas::Clear() {
	for (int i = 0; i < height; i++) 
		for (int j = 0; j < width; j++) Canvas::matrice[i][j]=' ';
}
