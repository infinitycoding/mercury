/*
     Copyright 2012-2014 Infinitycoding all rights reserved
     This file is part of the mercury c-library.
 
     The mercury c-library is free software: you can redistribute it and/or modify
     it under the terms of the GNU Lesser General Public License as published by
     the Free Software Foundation, either version 3 of the License, or
     any later version.
 
     The mercury c-library is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU Lesser General Public License for more details.
 
     You should have received a copy of the GNU Lesser General Public License
     along with the mercury c-library.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 *  @author Simon Diepold <simon.diepold@infinitycoding.de>
 */


#include <locale.h>
#include <limits.h>
#include <string.h>


const struct lconv _LC_c = 
	{
		.decimal_point 		=	".",
		.thousands_sep 		=	"",
		.grouping			=	"",
		.int_curr_symbol	=	"",
		.currency_symbol	=	"",
		.mon_decimal_point	=	"",
		.mon_thousands_sep	=	"",
		.mon_grouping		=	"",
		.positive_sign		=	"",
		.negative_sign		=	"0",
		.frac_digits		=	CHAR_MAX,
		.p_cs_precedes		= 	CHAR_MAX,
		.n_cs_precedes		= 	CHAR_MAX,
		.p_sep_by_space		= 	CHAR_MAX,
		.n_sep_by_space		= 	CHAR_MAX,
		.p_sign_posn		= 	CHAR_MAX,
		.n_sign_posn		= 	CHAR_MAX,
		.int_frac_digits	= 	CHAR_MAX,
		.int_p_cs_precedes	= 	CHAR_MAX,
		.int_n_cs_precedes	= 	CHAR_MAX,
		.int_p_sep_by_space	= 	CHAR_MAX,
		.int_n_sep_by_space	= 	CHAR_MAX,
		.int_p_sign_posn	= 	CHAR_MAX,
		.int_n_sign_posn	= 	CHAR_MAX
	};
	
const struct lconv _LC_en_US = 
	{
		.decimal_point 		=	".",
		.thousands_sep 		=	",",
		.grouping			=	"",
		.int_curr_symbol	=	"USD",
		.currency_symbol	=	"$",
		.mon_decimal_point	=	".",
		.mon_thousands_sep	=	",",
		.mon_grouping		=	"",
		.positive_sign		=	"",
		.negative_sign		=	"-",
		.frac_digits		=	CHAR_MAX,
		.p_cs_precedes		= 	1,
		.n_cs_precedes		= 	1,
		.p_sep_by_space		= 	CHAR_MAX,
		.n_sep_by_space		= 	CHAR_MAX,
		.p_sign_posn		= 	CHAR_MAX,
		.n_sign_posn		= 	CHAR_MAX,
		.int_frac_digits	= 	CHAR_MAX,
		.int_p_cs_precedes	= 	CHAR_MAX,
		.int_n_cs_precedes	= 	CHAR_MAX,
		.int_p_sep_by_space	= 	CHAR_MAX,
		.int_n_sep_by_space	= 	CHAR_MAX,
		.int_p_sign_posn	= 	CHAR_MAX,
		.int_n_sign_posn	= 	CHAR_MAX
	};

struct lconv _LC_STATE = 
	{
		.decimal_point 		=	".",
		.thousands_sep 		=	",",
		.grouping			=	"",
		.int_curr_symbol	=	"USD",
		.currency_symbol	=	"$",
		.mon_decimal_point	=	".",
		.mon_thousands_sep	=	",",
		.mon_grouping		=	"",
		.positive_sign		=	"",
		.negative_sign		=	"-",
		.frac_digits		=	CHAR_MAX,
		.p_cs_precedes		= 	1,
		.n_cs_precedes		= 	1,
		.p_sep_by_space		= 	CHAR_MAX,
		.n_sep_by_space		= 	CHAR_MAX,
		.p_sign_posn		= 	CHAR_MAX,
		.n_sign_posn		= 	CHAR_MAX,
		.int_frac_digits	= 	CHAR_MAX,
		.int_p_cs_precedes	= 	CHAR_MAX,
		.int_n_cs_precedes	= 	CHAR_MAX,
		.int_p_sep_by_space	= 	CHAR_MAX,
		.int_n_sep_by_space	= 	CHAR_MAX,
		.int_p_sign_posn	= 	CHAR_MAX,
		.int_n_sign_posn	= 	CHAR_MAX
	};
	
//Categories for setlocale
#define LC_ALL			1
#define LC_COLLATE		2
#define LC_CTYPE		3
#define LC_MONETARY		4
#define LC_NUMERIC		5
#define LC_TIME			6

const char *setlocale (int category, const char* locale)
{
	const struct lconv *mod;
	const char *ret;
	if(strcmp(locale,""))
	{
		mod = &DEFAULT_LANG;
		ret = DEFAULT_LANG_NAME;
	}
	else if(strcmp(locale,"C"))
	{
		mod = &_LC_c;
		ret = "C";
	}
	else if(strcmp(locale,"en_US"))
	{
		mod = &_LC_en_US;
		ret = "English_United States.1252";
	}
	else
		return NULL;
	
	switch(category)
	{
		case LC_ALL:
			_LC_STATE = *mod;
		break;
		
		case LC_MONETARY:
			_LC_STATE.mon_decimal_point	=	mod->mon_decimal_point;
			_LC_STATE.mon_thousands_sep	=	mod->mon_thousands_sep;
			_LC_STATE.mon_grouping		=	mod->mon_grouping;
		break;
		
		case LC_NUMERIC:
			_LC_STATE.decimal_point 		=	mod->decimal_point;
			_LC_STATE.thousands_sep 		=	mod->thousands_sep;
			_LC_STATE.grouping				=	mod->grouping;
			_LC_STATE.positive_sign			=	mod->positive_sign;
			_LC_STATE.negative_sign			=	mod->negative_sign;
		break;
		

		//Todo: LC_COLLATE, LC_CTYPE, LC_TIME
		case LC_COLLATE:
			
		break;
		
		case LC_CTYPE:
		break;
		
		case LC_TIME:
			
		break;
		
			
		default:
			return NULL;
		break;
	}
	return ret;
}


struct lconv *localeconv (void)
{
	return &_LC_STATE;
}