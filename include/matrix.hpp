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

#include <vector>
#include <random>

#ifndef MATRIX_H
#define MATRIX_H

/** A class to hold Matrix information and allow saving/loading matrices. */
class Matrix {
	public:
		unsigned int rows, columns;
		std::vector<double> content,  deltas;
		Matrix(unsigned int r, unsigned int c);
		void randomize(double mu, double std);
		double get(int row, int col);
		void set(int row, int col, double val);
		void update(double alpha);
	private:
};

#endif // MATRIX_H
