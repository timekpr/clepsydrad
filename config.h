// Copyright (c) 2016 Olli-Pekka Wallin <opwallin@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include    <stdio.h>
#include    <stdlib.h>
#include    <stdbool.h>

struct accounts_struct
{
    int val;
    char *username;
    struct accounts_struct *next;
};

struct accounts_struct *head = NULL;
struct accounts_struct *curr = NULL;

#endif
