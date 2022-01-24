#pragma once

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K00a, K00b, K00c,	\
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K10a, K10b, K10c, 	\
	K200, K201, K202, K203, K204, K205, K206,       K208,       K20a, K20b, K20c	\
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K00a, K00b, K00c }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K10a, K10b, K10c }, \
	{ K200, K201, K202, K203, K204, K205, K206, KC_NO, K208, KC_NO, K20a, K20b, K20c }  \
}

