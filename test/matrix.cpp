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
#include "../include/matrix.hpp"

unsigned int r = 9;
unsigned int c = 12;

Matrix mat(r,c);

Test(Matrix, construct) {
	cr_expect(mat.rows == r, "Row count is supposed to be 9");
	cr_expect(mat.columns == c, "Column count is supposed to be 12");
	cr_expect(mat.content.size() == (r * c),
		   	"Matrix content needs to be set to contain all elements");
	cr_expect(mat.content.size() == mat.deltas.size(),
		   	"Matrix content and deltas need to be of same size");
}

Test(Matrix, set) {
	mat.set(0, 1, 1);
	cr_expect(mat.content[1] == 1, "Element 0,1 is supposed to be set");
}

Test(Matrix, get) {
	mat.content[0] = 1;
	cr_expect(mat.get(0,0) == 1, "Element 0,1 is supposed to be fetched");
}

Test(Matrix, randomize) {
	mat.randomize(0, 0.01);
	cr_expect(mat.content[0] != 0, "Matrix content needs to be set randomly");
}

Test(Matrix, update) {
	mat.content[0] = 1;
	mat.deltas[0] = 1;
	mat.update(0.1);
	cr_expect(mat.content[0] == 0.9,
		   	"Matrix content needs to be multiplied by 0.9");
}
