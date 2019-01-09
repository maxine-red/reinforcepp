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

#include <criterion/criterion.h>
#include <iostream>
#include "../include/graph.hpp"

extern unsigned int r;
extern unsigned int c;

Matrix mat1(r, c);
Matrix mat2(c, r);
Matrix mat3(r, r);
Matrix mat4(r, r);

Test(Graph, construct) {
	Graph g1(true);
	cr_expect(g1.needs_backprop,
		   	"Expected 'needs_backprop' to be true, when true was given as parameter");
	Graph g2;
	cr_expect_not(g2.needs_backprop,
		   	"Expected 'needs_backprop' to be false, when no parameter is given");
}

Test(Graph, weighted_sums) {
	Graph g;
	unsigned int i;
	for (i = 1; i <= mat1.content.size(); i++) {
		mat1.content[i-1] = i;
	}
	for (i = 1; i <= mat2.content.size(); i++) {
		mat2.content[i-1] = i;
	}
	mat3.content[0] = 1;
	g.weighted_sums(mat1, mat2, mat3, &mat4);
	cr_expect(mat4.content[0] == 5227,
		   	"Expect output matrix to be a weighted sum of all input matrices");
}
