#pragma once

#include "pch.h"
#include <string>
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string.h>

#define MIN(x,y) ((x) < (y) ? (x) : (y)) //calculate minimum between two values

const int MAXSIZE = 64;

//--- A fixed string length implementation, calculating the distance between strings s1 and s2 until at most length MAXSIZE ---

INT16 levenshtein_distance_fixed(LPCSTR s1, INT16 l1, LPCSTR s2, INT16 l2);
