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

Test(Matrix, construct) {
	Matrix mat(r, c);
	cr_expect(mat.rows == r, "Row count is supposed to be 9");
	cr_expect(mat.columns == c, "Column count is supposed to be 12");
}
