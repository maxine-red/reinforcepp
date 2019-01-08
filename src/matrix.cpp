/*
 *  Copyright 2019 Maxine Michalski <maxine@furfind.net>
 *
 *  This file is part of reinforce++.
 *
 *  reinforce++ is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  reinforce++ is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with reinforce++.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../include/matrix.hpp"

/**
 * Constructor for Matrices.
 * @author Maxine Michalski
 */
Matrix::Matrix(unsigned int r, unsigned int c) : rows(r), columns(c) {
	content.reserve(rows * columns);
	deltas.reserve(rows * columns);
	content.insert(content.begin(), rows * columns, 0.0);
	deltas.insert(deltas.begin(), rows * columns, 0.0);
}

void Matrix::randomize(double mu, double std) {
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(mu, std);
	double r;
	for (unsigned int i =  0; i < content.size(); i++) {
		do {
			r = distribution(generator);
		} while (r == 0.0);
		content[i] = r;
	}
}

double Matrix::get(int row, int col) {
	return content[row * columns + col];
}

void Matrix::set(int row, int col, double val) {
	content[row * columns + col] = val;
}

void Matrix::update(double alpha) {
	for (unsigned int i = 0; content.size(); i++) {
		if (deltas[i] != 0.0) {
			content[i] -= alpha * deltas[i];
			deltas[i] = 0.0;
		}
	}
}
