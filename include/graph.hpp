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

#include <exception>
#include "matrix.hpp"

#ifndef GRAPH_H
#define GRAPH_H

/** A class to hold Matrix information and allow saving/loading matrices. */
class Graph {
	public:
		bool needs_backprop;
		Graph(bool back);
		Graph();
		//backward();
		void weighted_sums(Matrix m1, Matrix m2, Matrix m3, Matrix *m4);
		void sigmoid(Matrix m1);
		void tanh(Matrix m1);
 		void relu(Matrix m1);
	private:
		/* backprop, array of function calls */
};

#endif // GRAPH_H
