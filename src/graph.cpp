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

#include "../include/graph.hpp"

/**
 * Constructor for computation graphs.
 * @author Maxine Michalski
 */
Graph::Graph(bool back) : needs_backprop(back) {}
Graph::Graph() : needs_backprop(false) {}

void Graph::weighted_sums(Matrix m1, Matrix m2, Matrix m3, Matrix *m4) {
	unsigned int rows = m1.rows;
	unsigned int cols = m2.columns;
	unsigned int same = m1.columns;
	unsigned int i, j, k, n;
	double dot;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			dot = 0.0;
			for (k = 0; k < same; k++) {
				dot += m1.content[same * i + k] * m2.content[cols * k + j];
			}
			m4->content[cols * i + j] = dot;
		}
	}
	n = m3.content.size();
	for (i = 0; i < n; i++) {
		m4->content[i] = m3.content[i] + m4->content[i];
	}
}
