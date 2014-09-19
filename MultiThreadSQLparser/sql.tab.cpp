
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison GLR parsers in C
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0




/* Copy the first part of user declarations.  */

/* Line 172 of glr.c  */
#line 23 "sql.ypp"

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <pthread.h>
#include "sql_node_struct.h"
using namespace std;

Node * parsetreeroot;
char globalInputText[10000];
extern int numToRead;
extern pthread_mutex_t mutex;


/* Line 172 of glr.c  */
#line 77 "sql.tab.cpp"



#include "sql.tab.hpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template,
   here we set the default value of $$ to a zeroed-out value.
   Since the default value is undefined, this behavior is
   technically correct.  */
static YYSTYPE yyval_default;

/* Copy the second part of user declarations.  */


/* Line 243 of glr.c  */
#line 112 "sql.tab.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(env) setjmp (env)
# define YYLONGJMP(env, val) longjmp (env, val)
#endif

/*-----------------.
| GCC extensions.  |
`-----------------*/

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__)
#  define __attribute__(Spec) /* empty */
# endif
#endif


#ifdef __cplusplus
# define YYOPTIONAL_LOC(Name) /* empty */
#else
# define YYOPTIONAL_LOC(Name) Name __attribute__ ((__unused__))
#endif

#ifndef YYASSERT
# define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  231
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2490

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  328
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  168
/* YYNRULES -- Number of rules.  */
#define YYNRULES  585
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1165
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 11
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   567

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short int yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,     2,     2,    28,    22,     2,
     325,   326,    26,    24,   323,    25,   324,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   322,
       2,     2,     2,   327,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    21,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    18,    19,    20,    23,    29,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     6,    10,    12,    16,    28,    29,    32,
      33,    38,    41,    46,    47,    49,    51,    52,    55,    56,
      59,    60,    64,    65,    68,    73,    74,    77,    79,    83,
      84,    87,    90,    93,    96,    99,   102,   105,   108,   110,
     114,   116,   119,   121,   125,   127,   129,   132,   137,   141,
     145,   146,   148,   151,   153,   154,   160,   164,   170,   177,
     183,   184,   186,   188,   189,   191,   193,   195,   198,   201,
     202,   203,   205,   208,   213,   215,   219,   223,   225,   233,
     236,   239,   242,   243,   250,   253,   258,   259,   262,   270,
     272,   281,   282,   288,   289,   292,   295,   298,   301,   303,
     304,   305,   309,   313,   319,   321,   323,   327,   331,   339,
     347,   351,   355,   361,   367,   369,   378,   386,   394,   396,
     405,   406,   409,   412,   416,   422,   428,   436,   438,   443,
     448,   449,   453,   455,   464,   475,   485,   492,   504,   513,
     517,   518,   520,   522,   523,   525,   527,   531,   535,   541,
     546,   551,   557,   563,   564,   568,   571,   575,   579,   583,
     587,   590,   594,   598,   601,   605,   611,   614,   616,   619,
     623,   625,   630,   635,   637,   643,   649,   651,   655,   659,
     666,   670,   674,   678,   683,   684,   686,   687,   690,   694,
     698,   699,   701,   703,   714,   715,   717,   719,   721,   722,
     725,   727,   729,   731,   735,   739,   741,   747,   749,   754,
     759,   760,   763,   765,   772,   774,   778,   782,   788,   789,
     791,   793,   795,   799,   800,   804,   812,   818,   828,   830,
     833,   836,   838,   841,   843,   845,   847,   850,   853,   854,
     856,   861,   862,   866,   869,   870,   873,   875,   880,   882,
     887,   889,   891,   893,   896,   902,   906,   908,   912,   914,
     918,   922,   924,   927,   930,   932,   934,   937,   939,   946,
     947,   949,   951,   954,   957,   960,   962,   964,   968,   970,
     974,   976,   981,   987,   989,   993,   995,   999,  1001,  1011,
    1013,  1017,  1019,  1022,  1024,  1026,  1028,  1030,  1032,  1034,
    1036,  1038,  1041,  1043,  1044,  1047,  1050,  1053,  1056,  1059,
    1062,  1064,  1074,  1076,  1086,  1088,  1092,  1095,  1098,  1101,
    1103,  1105,  1107,  1109,  1111,  1114,  1116,  1125,  1127,  1137,
    1139,  1149,  1151,  1155,  1159,  1165,  1167,  1176,  1177,  1180,
    1182,  1187,  1188,  1190,  1192,  1194,  1200,  1202,  1207,  1208,
    1210,  1212,  1214,  1216,  1218,  1220,  1225,  1226,  1228,  1230,
    1232,  1237,  1239,  1245,  1246,  1249,  1252,  1255,  1257,  1263,
    1265,  1270,  1274,  1282,  1287,  1292,  1297,  1301,  1305,  1310,
    1315,  1319,  1323,  1327,  1332,  1338,  1342,  1346,  1352,  1355,
    1359,  1364,  1370,  1376,  1381,  1386,  1390,  1394,  1395,  1397,
    1398,  1401,  1402,  1405,  1406,  1409,  1410,  1412,  1414,  1420,
    1422,  1426,  1428,  1432,  1433,  1435,  1437,  1439,  1443,  1445,
    1449,  1451,  1453,  1455,  1457,  1460,  1462,  1465,  1468,  1473,
    1475,  1477,  1481,  1482,  1484,  1486,  1488,  1494,  1498,  1503,
    1504,  1507,  1509,  1512,  1514,  1518,  1520,  1523,  1525,  1527,
    1532,  1536,  1540,  1544,  1545,  1548,  1550,  1552,  1555,  1557,
    1561,  1565,  1569,  1570,  1574,  1580,  1581,  1583,  1584,  1587,
    1590,  1591,  1596,  1600,  1603,  1607,  1611,  1615,  1619,  1623,
    1627,  1631,  1635,  1639,  1643,  1645,  1647,  1649,  1651,  1653,
    1657,  1663,  1666,  1671,  1673,  1675,  1677,  1679,  1683,  1687,
    1691,  1695,  1701,  1707,  1709,  1713,  1715,  1717,  1721,  1723,
    1725,  1727,  1729,  1733,  1737,  1741,  1745,  1749,  1753,  1756,
    1760,  1764,  1768,  1772,  1778,  1785,  1792,  1799,  1803,  1807,
    1811,  1815,  1818,  1821,  1825,  1829,  1833,  1838,  1842,  1847,
    1853,  1855,  1859,  1860,  1862,  1868,  1875,  1881,  1888,  1893,
    1899,  1904,  1909,  1914,  1919,  1926,  1935,  1940,  1948,  1950,
    1952,  1954,  1961,  1968,  1972,  1976,  1980,  1984,  1988,  1992,
    1996,  2000,  2004,  2009,  2016,  2020,  2026,  2031,  2037,  2041,
    2046,  2050,  2055,  2057,  2059,  2061
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const short int yyrhs[] =
{
     329,     0,    -1,   330,   322,    -1,   329,   330,   322,    -1,
     331,    -1,   187,   342,   343,    -1,   187,   342,   343,   105,
     345,   332,   333,   337,   338,   339,   340,    -1,    -1,   237,
     481,    -1,    -1,   108,    47,   334,   336,    -1,   481,   335,
      -1,   334,   323,   481,   335,    -1,    -1,    39,    -1,    81,
      -1,    -1,   239,   183,    -1,    -1,   109,   481,    -1,    -1,
     161,    47,   334,    -1,    -1,   134,   481,    -1,   134,   481,
     323,   481,    -1,    -1,   125,   341,    -1,     3,    -1,   341,
     323,     3,    -1,    -1,   342,    33,    -1,   342,    84,    -1,
     342,    85,    -1,   342,   110,    -1,   342,   206,    -1,   342,
     203,    -1,   342,   201,    -1,   342,   202,    -1,   344,    -1,
     343,   323,   344,    -1,    26,    -1,   481,   349,    -1,   346,
      -1,   345,   323,   346,    -1,   347,    -1,   350,    -1,     3,
     349,    -1,     3,   324,     3,   349,    -1,   358,   348,     3,
      -1,   325,   345,   326,    -1,    -1,    38,    -1,    38,     3,
      -1,     3,    -1,    -1,   346,   351,   127,   347,   355,    -1,
     346,   206,   347,    -1,   346,   206,   347,   156,   481,    -1,
     346,   353,   352,   127,   347,   356,    -1,   346,   152,   354,
     127,   347,    -1,    -1,   118,    -1,    62,    -1,    -1,   163,
      -1,   133,    -1,   182,    -1,   133,   352,    -1,   182,   352,
      -1,    -1,    -1,   356,    -1,   156,   481,    -1,   228,   325,
     341,   326,    -1,     3,    -1,   357,   323,     3,    -1,   325,
     331,   326,    -1,   359,    -1,    80,   360,   105,     3,   332,
     338,   339,    -1,   360,   144,    -1,   360,   169,    -1,   360,
     115,    -1,    -1,    80,   360,   361,   105,   345,   332,    -1,
       3,   362,    -1,   361,   323,     3,   362,    -1,    -1,   324,
      26,    -1,    80,   360,   105,   361,   228,   345,   332,    -1,
     363,    -1,   121,   365,   366,     3,   367,   232,   368,   364,
      -1,    -1,   156,   157,   128,   225,   370,    -1,    -1,   365,
     144,    -1,   365,    79,    -1,   365,   110,    -1,   365,   115,
      -1,   125,    -1,    -1,    -1,   325,   341,   326,    -1,   325,
     369,   326,    -1,   368,   323,   325,   369,   326,    -1,   481,
      -1,    78,    -1,   369,   323,   481,    -1,   369,   323,    78,
      -1,   121,   365,   366,     3,   190,   370,   364,    -1,   121,
     365,   366,     3,   367,   331,   364,    -1,     3,    20,   481,
      -1,     3,    20,    78,    -1,   370,   323,     3,    20,   481,
      -1,   370,   323,     3,    20,    78,    -1,   371,    -1,   177,
     365,   366,     3,   367,   232,   368,   364,    -1,   177,   365,
     366,     3,   190,   370,   364,    -1,   177,   365,   366,     3,
     367,   331,   364,    -1,   372,    -1,   225,   373,   345,   190,
     374,   332,   338,   339,    -1,    -1,   365,   144,    -1,   365,
     115,    -1,     3,    20,   481,    -1,     3,   324,     3,    20,
     481,    -1,   374,   323,     3,    20,   481,    -1,   374,   323,
       3,   324,     3,    20,   481,    -1,   375,    -1,    61,    68,
     376,     3,    -1,    61,   184,   376,     3,    -1,    -1,   114,
      18,    97,    -1,   377,    -1,    61,   380,   207,   376,     3,
     325,   381,   326,    -1,    61,   380,   207,   376,     3,   324,
       3,   325,   381,   326,    -1,    61,   380,   207,   376,     3,
     325,   381,   326,   378,    -1,    61,   380,   207,   376,     3,
     378,    -1,    61,   380,   207,   376,     3,   324,     3,   325,
     381,   326,   378,    -1,    61,   380,   207,   376,     3,   324,
       3,   378,    -1,   379,   348,   331,    -1,    -1,   115,    -1,
     177,    -1,    -1,   208,    -1,   382,    -1,   381,   323,   382,
      -1,     3,   489,   383,    -1,   166,   128,   325,   341,   326,
      -1,   128,   325,   341,   326,    -1,   116,   325,   341,   326,
      -1,   106,   116,   325,   341,   326,    -1,   106,   128,   325,
     341,   326,    -1,    -1,   383,    18,   154,    -1,   383,   154,
      -1,   383,    78,     4,    -1,   383,    78,     5,    -1,   383,
      78,     7,    -1,   383,    78,     6,    -1,   383,    40,    -1,
     383,   222,   128,    -1,   383,   166,   128,    -1,   383,   128,
      -1,   383,    56,     4,    -1,   383,   222,   325,   341,   326,
      -1,   244,   491,    -1,   384,    -1,   250,     3,    -1,   250,
     207,     3,    -1,   385,    -1,    34,    68,     3,   488,    -1,
      34,   184,     3,   488,    -1,   386,    -1,    34,   391,   207,
       3,   387,    -1,    34,   391,   207,     3,   390,    -1,   388,
      -1,   387,   323,   388,    -1,    32,   389,   381,    -1,    51,
     389,     3,     3,   489,   383,    -1,    88,   389,     3,    -1,
      88,   166,   128,    -1,    88,   116,   341,    -1,    88,   104,
     128,   341,    -1,    -1,    55,    -1,    -1,   175,     3,    -1,
     175,   217,     3,    -1,   161,    47,     3,    -1,    -1,   115,
      -1,   392,    -1,    61,   393,   116,     3,   394,   156,     3,
     325,   396,   326,    -1,    -1,   222,    -1,   106,    -1,   195,
      -1,    -1,   228,   395,    -1,   312,    -1,   313,    -1,   397,
      -1,   396,   323,   397,    -1,     3,   485,   335,    -1,   398,
      -1,    88,   116,     3,   156,     3,    -1,   399,    -1,    88,
      68,   400,     3,    -1,    88,   184,   400,     3,    -1,    -1,
     114,    97,    -1,   401,    -1,    88,   380,   207,   400,   402,
     403,    -1,     3,    -1,     3,   324,     3,    -1,   402,   323,
       3,    -1,   402,   323,     3,   324,     3,    -1,    -1,   179,
      -1,    49,    -1,   404,    -1,   175,   207,   405,    -1,    -1,
       3,   217,     3,    -1,     3,   324,     3,   217,     3,   324,
       3,    -1,   405,   323,     3,   217,     3,    -1,   405,   323,
       3,   324,     3,   217,     3,   324,     3,    -1,   406,    -1,
      82,     3,    -1,    81,     3,    -1,   407,    -1,   227,     3,
      -1,   408,    -1,   410,    -1,   413,    -1,   262,   263,    -1,
     260,   409,    -1,    -1,   311,    -1,   261,   409,   411,   412,
      -1,    -1,    36,   264,   265,    -1,    36,   265,    -1,    -1,
     264,   174,    -1,   174,    -1,   268,   409,   411,   412,    -1,
     414,    -1,   190,   266,    20,   481,    -1,   415,    -1,   416,
      -1,   417,    -1,   267,     3,    -1,   268,   409,   217,   267,
       3,    -1,   174,   267,     3,    -1,   418,    -1,   139,   270,
     419,    -1,   420,    -1,   419,   323,   420,    -1,     3,   349,
     421,    -1,   170,    -1,   170,   269,    -1,   144,   240,    -1,
     240,    -1,   422,    -1,   223,   270,    -1,   423,    -1,   190,
     424,   263,   271,   272,   425,    -1,    -1,   273,    -1,   274,
      -1,   170,   275,    -1,   170,   276,    -1,   277,   170,    -1,
     278,    -1,   426,    -1,    61,   249,   427,    -1,   428,    -1,
     427,   323,   428,    -1,     8,    -1,     8,   279,    47,     4,
      -1,     8,   279,    47,   280,     4,    -1,   429,    -1,    88,
     249,   430,    -1,     8,    -1,   430,   323,     8,    -1,   431,
      -1,   107,   432,   156,    26,   324,    26,   217,   427,   434,
      -1,   433,    -1,   432,   323,   433,    -1,    33,    -1,    33,
     281,    -1,   187,    -1,   225,    -1,   121,    -1,    80,    -1,
      61,    -1,    88,    -1,   116,    -1,    34,    -1,   107,   159,
      -1,   173,    -1,    -1,   239,   435,    -1,   107,   159,    -1,
     245,   481,    -1,   246,   481,    -1,   247,   481,    -1,   248,
     481,    -1,   436,    -1,   107,   432,   156,     3,   324,    26,
     217,   427,   434,    -1,   437,    -1,   107,   438,   156,     3,
     324,     3,   217,   427,   434,    -1,   439,    -1,   438,   323,
     439,    -1,   187,   367,    -1,   225,   367,    -1,   121,   367,
      -1,    80,    -1,    61,    -1,    88,    -1,   116,    -1,    34,
      -1,   107,   159,    -1,   440,    -1,   181,   432,   156,    26,
     324,    26,   105,   430,    -1,   441,    -1,   181,   432,   156,
       3,   324,    26,   105,   430,   434,    -1,   442,    -1,   181,
     438,   156,     3,   324,     3,   105,   430,   434,    -1,   443,
      -1,   175,   249,   444,    -1,     8,   217,     8,    -1,   444,
     323,     8,   217,     8,    -1,   445,    -1,   190,   280,   446,
      20,   280,   325,     4,   326,    -1,    -1,   102,     8,    -1,
     447,    -1,    35,   448,   207,   402,    -1,    -1,   269,    -1,
     153,    -1,   449,    -1,   282,   207,   402,   217,     4,    -1,
     450,    -1,    53,   207,   402,   451,    -1,    -1,   169,    -1,
     251,    -1,   252,    -1,   253,    -1,   254,    -1,   452,    -1,
     283,   207,   402,   453,    -1,    -1,   169,    -1,   253,    -1,
     454,    -1,   158,   448,   207,   402,    -1,   455,    -1,   284,
     448,   207,   402,   456,    -1,    -1,   456,   169,    -1,   456,
     253,    -1,   456,   285,    -1,   457,    -1,   286,   207,   402,
     105,     4,    -1,   458,    -1,   191,   287,   190,   461,    -1,
     191,   288,   461,    -1,   191,   459,   289,   105,     3,   460,
     461,    -1,   191,    61,    68,     3,    -1,   191,    61,   184,
       3,    -1,   191,    61,   207,     3,    -1,   191,    68,     3,
      -1,   191,   184,     3,    -1,   191,   290,     3,   291,    -1,
     191,   290,     3,   292,    -1,   191,   293,   294,    -1,   191,
     295,   339,    -1,   191,   481,   295,    -1,   191,   296,   102,
       8,    -1,   191,   116,   105,     3,   460,    -1,   191,   297,
     292,    -1,   191,   463,   291,    -1,   191,   315,   270,   460,
     461,    -1,   191,   281,    -1,   191,   459,   298,    -1,   191,
     424,   292,   461,    -1,   191,   207,   292,   460,   461,    -1,
     191,   459,   270,   460,   461,    -1,   191,   299,   460,   462,
      -1,   191,   424,   300,   461,    -1,   191,   301,   339,    -1,
     191,   481,   301,    -1,    -1,   316,    -1,    -1,   105,     3,
      -1,    -1,    14,     4,    -1,    -1,    14,   481,    -1,    -1,
     314,    -1,   464,    -1,   258,   116,   465,    16,     3,    -1,
     466,    -1,   465,   323,   466,    -1,     3,    -1,     3,   467,
     357,    -1,    -1,   116,    -1,   128,    -1,   468,    -1,   302,
     448,   469,    -1,   470,    -1,   469,   323,   470,    -1,   303,
      -1,   304,    -1,   291,    -1,   281,    -1,   257,   258,    -1,
     292,    -1,   207,     3,    -1,   270,   402,    -1,   270,   239,
     170,   139,    -1,   305,    -1,   471,    -1,   130,   472,   481,
      -1,    -1,   306,    -1,   257,    -1,   473,    -1,   136,   116,
     125,   258,   465,    -1,     3,   474,   475,    -1,   467,   325,
     357,   326,    -1,    -1,   115,   255,    -1,   476,    -1,   307,
     477,    -1,   478,    -1,   477,   323,   478,    -1,   256,    -1,
     257,   258,    -1,   259,    -1,   479,    -1,   308,     3,   105,
     330,    -1,   310,     3,   480,    -1,   309,   308,     3,    -1,
      88,   308,     3,    -1,    -1,   228,   430,    -1,   327,    -1,
     482,    -1,   190,   483,    -1,   484,    -1,   483,   323,   484,
      -1,     8,    20,   481,    -1,     8,     9,   481,    -1,    -1,
     325,     5,   326,    -1,   325,     5,   323,     5,   326,    -1,
      -1,    43,    -1,    -1,   487,   224,    -1,   487,   243,    -1,
      -1,   488,    52,   190,     3,    -1,   488,    54,     3,    -1,
      44,   485,    -1,   215,   485,   487,    -1,   192,   485,   487,
      -1,   147,   485,   487,    -1,   122,   485,   487,    -1,   123,
     485,   487,    -1,    42,   485,   487,    -1,   172,   485,   487,
      -1,    87,   485,   487,    -1,   101,   485,   487,    -1,    76,
     485,   487,    -1,    70,    -1,   212,    -1,   213,    -1,    71,
      -1,   241,    -1,    52,   485,   488,    -1,   234,   325,     5,
     326,   488,    -1,    43,   485,    -1,   233,   325,     5,   326,
      -1,   214,    -1,    45,    -1,   146,    -1,   141,    -1,   216,
     486,   488,    -1,   209,   486,   488,    -1,   148,   486,   488,
      -1,   142,   486,   488,    -1,    95,   325,   490,   326,   488,
      -1,   190,   325,   490,   326,   488,    -1,     4,    -1,   490,
     323,     4,    -1,     3,    -1,     8,    -1,     3,   324,     3,
      -1,     4,    -1,     5,    -1,     7,    -1,     6,    -1,   481,
      24,   481,    -1,   481,    25,   481,    -1,   481,    26,   481,
      -1,   481,    27,   481,    -1,   481,    28,   481,    -1,   481,
      29,   481,    -1,    25,   481,    -1,   481,    12,   481,    -1,
     481,    10,   481,    -1,   481,    11,   481,    -1,   481,    20,
     481,    -1,   481,    20,   325,   331,   326,    -1,   481,    20,
      37,   325,   331,   326,    -1,   481,    20,   193,   325,   331,
     326,    -1,   481,    20,    33,   325,   331,   326,    -1,   481,
      21,   481,    -1,   481,    22,   481,    -1,   481,    30,   481,
      -1,   481,    23,   481,    -1,    18,   481,    -1,    17,   481,
      -1,     8,     9,   481,    -1,   325,   481,   326,    -1,   481,
      15,   154,    -1,   481,    15,    18,   154,    -1,   481,    15,
       6,    -1,   481,    15,    18,     6,    -1,   481,    19,   481,
      36,   481,    -1,   481,    -1,   481,   323,   491,    -1,    -1,
     491,    -1,   481,    16,   325,   491,   326,    -1,   481,    18,
      16,   325,   491,   326,    -1,   481,    16,   325,   331,   326,
      -1,   481,    18,    16,   325,   331,   326,    -1,    97,   325,
     331,   326,    -1,    18,    97,   325,   331,   326,    -1,     3,
     325,   492,   326,    -1,   321,   325,    26,   326,    -1,   321,
     325,   481,   326,    -1,   317,   325,   491,   326,    -1,   317,
     325,   481,   105,   481,   326,    -1,   317,   325,   481,   105,
     481,   102,   481,   326,    -1,   318,   325,   491,   326,    -1,
     318,   325,   493,   481,   105,   491,   326,    -1,   131,    -1,
     218,    -1,    46,    -1,   319,   325,   481,   323,   494,   326,
      -1,   320,   325,   481,   323,   494,   326,    -1,   124,   481,
      72,    -1,   124,   481,    73,    -1,   124,   481,    74,    -1,
     124,   481,    75,    -1,   124,   481,   242,    -1,   124,   481,
     241,    -1,   124,   481,   111,    -1,   124,   481,   112,    -1,
     124,   481,   113,    -1,    50,   481,   495,    94,    -1,    50,
     481,   495,    91,   481,    94,    -1,    50,   495,    94,    -1,
      50,   495,    91,   481,    94,    -1,   236,   481,   211,   481,
      -1,   495,   236,   481,   211,   481,    -1,   481,    14,   481,
      -1,   481,    18,    14,   481,    -1,   481,    13,   481,    -1,
     481,    18,    13,   481,    -1,    65,    -1,    63,    -1,    64,
      -1,    43,   481,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   417,   417,   418,   423,   427,   432,   440,   441,   443,
     444,   451,   456,   463,   464,   465,   468,   469,   472,   473,
     480,   481,   488,   489,   494,   504,   505,   508,   509,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   523,   524,
     525,   528,   531,   532,   535,   536,   540,   545,   549,   554,
     557,   558,   561,   562,   563,   578,   582,   586,   591,   595,
     601,   602,   603,   606,   607,   610,   611,   614,   615,   616,
     619,   620,   627,   631,   651,   652,   655,   660,   663,   668,
     669,   670,   671,   674,   679,   680,   683,   684,   687,   693,
     696,   702,   703,   706,   707,   708,   709,   710,   713,   713,
     716,   717,   720,   721,   724,   725,   726,   727,   730,   736,
     742,   745,   748,   751,   757,   760,   766,   772,   778,   781,
     788,   789,   790,   794,   804,   815,   817,   826,   830,   832,
     836,   837,   842,   845,   849,   853,   858,   862,   867,   873,
     877,   878,   879,   882,   883,   886,   887,   891,   892,   893,
     894,   895,   896,   899,   900,   901,   902,   903,   904,   905,
     906,   907,   908,   909,   910,   911,   920,   924,   927,   928,
     932,   936,   937,   941,   946,   947,   951,   952,   956,   957,
     958,   959,   960,   961,   964,   965,   968,   969,   970,   971,
     974,   975,   979,   983,   986,   987,   988,   989,   992,   993,
     996,   997,  1000,  1001,  1004,  1008,  1011,  1015,  1019,  1020,
    1023,  1024,  1028,  1031,  1034,  1035,  1036,  1037,  1040,  1041,
    1042,  1047,  1050,  1053,  1054,  1055,  1056,  1057,  1061,  1064,
    1065,  1069,  1072,  1076,  1077,  1078,  1081,  1082,  1085,  1086,
    1089,  1092,  1093,  1094,  1097,  1098,  1099,  1102,  1106,  1109,
    1113,  1114,  1115,  1119,  1122,  1125,  1129,  1132,  1135,  1136,
    1139,  1142,  1143,  1144,  1145,  1149,  1152,  1156,  1160,  1163,
    1164,  1165,  1169,  1170,  1171,  1172,  1176,  1179,  1182,  1183,
    1186,  1187,  1188,  1192,  1195,  1198,  1199,  1203,  1206,  1209,
    1210,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,
    1223,  1224,  1225,  1228,  1229,  1233,  1234,  1235,  1236,  1237,
    1241,  1244,  1248,  1251,  1254,  1255,  1259,  1260,  1261,  1262,
    1263,  1264,  1265,  1266,  1267,  1277,  1280,  1283,  1286,  1289,
    1292,  1296,  1299,  1303,  1304,  1308,  1311,  1314,  1315,  1319,
    1322,  1325,  1326,  1327,  1331,  1334,  1338,  1341,  1344,  1345,
    1346,  1347,  1348,  1349,  1353,  1356,  1359,  1360,  1361,  1365,
    1368,  1372,  1375,  1378,  1379,  1380,  1381,  1385,  1388,  1392,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1406,  1407,  1408,  1409,  1410,  1411,  1412,  1413,  1414,
    1415,  1416,  1417,  1418,  1419,  1420,  1421,  1424,  1425,  1428,
    1429,  1432,  1433,  1436,  1437,  1440,  1441,  1445,  1448,  1451,
    1452,  1455,  1456,  1459,  1460,  1461,  1465,  1468,  1471,  1472,
    1475,  1476,  1477,  1478,  1479,  1480,  1481,  1482,  1483,  1484,
    1488,  1491,  1494,  1495,  1496,  1500,  1503,  1506,  1509,  1512,
    1513,  1517,  1520,  1523,  1524,  1527,  1528,  1529,  1533,  1536,
    1537,  1538,  1539,  1542,  1543,  1546,  1554,  1557,  1559,  1559,
    1562,  1566,  1574,  1575,  1576,  1579,  1580,  1583,  1584,  1585,
    1588,  1589,  1591,  1596,  1597,  1598,  1599,  1600,  1601,  1602,
    1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,
    1613,  1615,  1616,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1630,  1631,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1671,  1672,  1673,  1674,  1677,
    1681,  1682,  1685,  1686,  1689,  1690,  1691,  1692,  1693,  1694,
    1697,  1701,  1702,  1705,  1706,  1707,  1708,  1709,  1712,  1713,
    1714,  1717,  1718,  1721,  1722,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1732,  1733,  1734,  1735,  1738,  1739,  1742,  1743,
    1746,  1747,  1750,  1751,  1752,  1755
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "BOOL",
  "APPROXNUM", "USERVAR", "ASSIGN", "OR", "XOR", "ANDOP", "REGEXP", "LIKE",
  "IS", "IN", "'!'", "NOT", "BETWEEN", "COMPARISON", "'|'", "'&'", "SHIFT",
  "'+'", "'-'", "'*'", "'/'", "'%'", "MOD", "'^'", "UMINUS", "ADD", "ALL",
  "ALTER", "ANALYZE", "AND", "ANY", "AS", "ASC", "AUTO_INCREMENT",
  "BEFORE", "BIGINT", "BINARY", "BIT", "BLOB", "BOTH", "BY", "CALL",
  "CASCADE", "CASE", "CHANGE", "CHAR", "CHECK", "COLLATE", "COLUMN",
  "COMMENT", "CONDITION", "CONSTRAINT", "CONTINUE", "CONVERT", "CREATE",
  "CROSS", "CURRENT_DATE", "CURRENT_TIME", "CURRENT_TIMESTAMP",
  "CURRENT_USER", "CURSOR", "DATABASE", "DATABASES", "DATE", "DATETIME",
  "DAY_HOUR", "DAY_MICROSECOND", "DAY_MINUTE", "DAY_SECOND", "DECIMAL",
  "DECLARE", "DEFAULT", "DELAYED", "DELETE", "DESC", "DESCRIBE",
  "DETERMINISTIC", "DISTINCT", "DISTINCTROW", "DIV", "DOUBLE", "DROP",
  "DUAL", "EACH", "ELSE", "ELSEIF", "ENCLOSED", "END", "ENUM", "ESCAPED",
  "EXISTS", "EXIT", "EXPLAIN", "FETCH", "FLOAT", "FOR", "FORCE", "FOREIGN",
  "FROM", "FULLTEXT", "GRANT", "GROUP", "HAVING", "HIGH_PRIORITY",
  "HOUR_MICROSECOND", "HOUR_MINUTE", "HOUR_SECOND", "IF", "IGNORE",
  "INDEX", "INFILE", "INNER", "INOUT", "INSENSITIVE", "INSERT", "INT",
  "INTEGER", "INTERVAL", "INTO", "ITERATE", "JOIN", "KEY", "KEYS", "KILL",
  "LEADING", "LEAVE", "LEFT", "LIMIT", "LINES", "LOAD", "LOCALTIME",
  "LOCALTIMESTAMP", "LOCK", "LONG", "LONGBLOB", "LONGTEXT", "LOOP",
  "LOW_PRIORITY", "MATCH", "MEDIUMBLOB", "MEDIUMINT", "MEDIUMTEXT",
  "MINUTE_MICROSECOND", "MINUTE_SECOND", "MODIFIES", "NATURAL",
  "NO_WRITE_TO_BINLOG", "NULLX", "NUMBER", "ON", "DUPLICATE", "OPTIMIZE",
  "OPTION", "OPTIONALLY", "ORDER", "OUT", "OUTER", "OUTFILE", "PRECISION",
  "PRIMARY", "PROCEDURE", "PURGE", "QUICK", "READ", "READS", "REAL",
  "REFERENCES", "RELEASE", "RENAME", "REPEAT", "REPLACE", "REQUIRE",
  "RESTRICT", "RETURN", "REVOKE", "RIGHT", "ROLLUP", "SCHEMA", "SCHEMAS",
  "SECOND_MICROSECOND", "SELECT", "SENSITIVE", "SEPARATOR", "SET", "SHOW",
  "SMALLINT", "SOME", "SONAME", "SPATIAL", "SPECIFIC", "SQL",
  "SQLEXCEPTION", "SQLSTATE", "SQLWARNING", "SQL_BIG_RESULT",
  "SQL_CALC_FOUND_ROWS", "SQL_SMALL_RESULT", "SSL", "STARTING",
  "STRAIGHT_JOIN", "TABLE", "TEMPORARY", "TEXT", "TERMINATED", "THEN",
  "TIME", "TIMESTAMP", "TINYBLOB", "TINYINT", "TINYTEXT", "TO", "TRAILING",
  "TRIGGER", "UNDO", "UNION", "UNIQUE", "UNLOCK", "UNSIGNED", "UPDATE",
  "USAGE", "USE", "USING", "UTC_DATE", "UTC_TIME", "UTC_TIMESTAMP",
  "VALUES", "VARBINARY", "VARCHAR", "VARYING", "WHEN", "WHERE", "WHILE",
  "WITH", "WRITE", "YEAR", "YEAR_MONTH", "ZEROFILL", "DO",
  "MAX_QUERIES_PER_HOUR", "MAX_UPDATES_PER_HOUR",
  "MAX_CONNECTIONS_PER_HOUR", "MAX_USER_CONNECTIONS", "USER", "TRUNCATE",
  "FAST", "MEDIUM", "EXTENDED", "CHANGED", "LEAVES", "MASTER", "QUERY",
  "CACHE", "SLAVE", "BEGINT", "COMMIT", "START", "TRANSACTION", "NO",
  "CHAIN", "AUTOCOMMIT", "SAVEPOINT", "ROLLBACK", "LOCAL", "TABLES",
  "ISOLATION", "LEVEL", "GLOBAL", "SESSION", "UNCOMMITTED", "COMMITTED",
  "REPEATABLE", "SERIALIZABLE", "IDENTIFIED", "PASSWORD", "PRIVILEGES",
  "BACKUP", "CHECKSUM", "REPAIR", "USE_FRM", "RESTORE", "CHARACTER",
  "COLLATION", "COLUMNS", "ENGINE", "LOGS", "STATUS", "STORAGE", "ENGINES",
  "ERRORS", "GRANTS", "INNODB", "PROCESSLIST", "TRIGGERS", "VARIABLES",
  "WARNINGS", "FLUSH", "HOSTS", "DES_KEY_FILE", "USER_RESOURCES",
  "CONNECTION", "RESET", "PREPARE", "DEALLOCATE", "EXECUTE", "WORK",
  "BTREE", "HASH", "BDB", "OPEN", "FULL", "FSUBSTRING", "FTRIM",
  "FDATE_ADD", "FDATE_SUB", "FCOUNT", "';'", "','", "'.'", "'('", "')'",
  "'?'", "$accept", "stmt_list", "stmt", "select_stmt", "opt_where",
  "opt_groupby", "groupby_list", "opt_asc_desc", "opt_with_rollup",
  "opt_having", "opt_orderby", "opt_limit", "opt_into_list", "column_list",
  "select_opts", "select_expr_list", "select_expr", "table_references",
  "table_reference", "table_factor", "opt_as", "opt_as_alias",
  "join_table", "opt_inner_cross", "opt_outer", "left_or_right",
  "opt_left_or_right_outer", "opt_join_condition", "join_condition",
  "index_list", "table_subquery", "delete_stmt", "delete_opts",
  "delete_list", "opt_dot_star", "insert_stmt", "opt_ondupupdate",
  "insert_opts", "opt_into", "opt_col_names", "insert_vals_list",
  "insert_vals", "insert_asgn_list", "replace_stmt", "update_stmt",
  "update_opts", "update_asgn_list", "create_database_stmt",
  "opt_if_not_exists", "create_table_stmt", "create_select_statement",
  "opt_ignore_replace", "opt_temporary", "create_col_list",
  "create_definition", "column_atts", "truncate_stmt",
  "alter_database_stmt", "alter_table_stmt", "alter_definition",
  "alter_duplicate_definition", "opt_col", "alter_noduplicate_definition",
  "opt_ignore", "create_index_stmt", "index_att", "opt_using_type",
  "index_type", "index_col_list", "index_col_name", "drop_index_stmt",
  "drop_database_stmt", "opt_if_exists", "drop_table_stmt", "table_list",
  "opt_rc", "rename_table_stmt", "rename_list", "describe_stmt",
  "use_stmt", "start_transaction_stmt", "opt_work", "commit_stmt",
  "opt_chain", "opt_release", "rollback_stmt", "set_autocommit_stmt",
  "savepoint_stmt", "rollback_to_savepoint_stmt", "release_savepoint",
  "lock_table_stmt", "lock_table_list", "lock_table", "opt_read_write",
  "unlock_tables", "set_transaction_stmt", "opt_trans_level", "trans_att",
  "create_user_stmt", "create_user_list", "create_user", "drop_user_stmt",
  "user_list", "grant_all_stmt", "priv_database_list",
  "priv_database_type", "opt_with_opt", "with_opt", "grant_database_stmt",
  "grant_table_stmt", "priv_table_list", "priv_table_type",
  "revoke_all_stmt", "revoke_database_stmt", "revoke_table_stmt",
  "rename_user_stmt", "utou_list", "set_password_stmt", "opt_for_user",
  "analyze_table_stmt", "analyze_opt", "backup_table_stmt",
  "check_table_stmt", "check_opts", "checksum_table_stmt", "checksum_opt",
  "optimize_table_stmt", "repair_table_stmt", "repair_opts",
  "restore_table_stmt", "show_stmt", "opt_full", "opt_from",
  "opt_like_string", "opt_like_expr", "opt_bdb", "cache_index_stmt",
  "table_index_list", "table_index", "opt_index_key", "flush_stmt",
  "flush_opt_list", "flush_opt", "kill_stmt", "opt_connection_query",
  "load_index_stmt", "opt_index_key_list", "opt_ignore_leaves",
  "reset_stmt", "reset_opt_list", "reset_opt", "prepare_stmt",
  "opt_use_name", "expr", "set_stmt", "set_list", "set_expr", "opt_length",
  "opt_binary", "opt_uz", "opt_csc", "data_type", "enum_list", "expr_list",
  "opt_expr_list", "trim_ltb", "interval_exp", "case_list", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   328,   329,   329,   330,   331,   331,   332,   332,   333,
     333,   334,   334,   335,   335,   335,   336,   336,   337,   337,
     338,   338,   339,   339,   339,   340,   340,   341,   341,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   343,   343,
     343,   344,   345,   345,   346,   346,   347,   347,   347,   347,
     348,   348,   349,   349,   349,   350,   350,   350,   350,   350,
     351,   351,   351,   352,   352,   353,   353,   354,   354,   354,
     355,   355,   356,   356,   357,   357,   358,   330,   359,   360,
     360,   360,   360,   359,   361,   361,   362,   362,   359,   330,
     363,   364,   364,   365,   365,   365,   365,   365,   366,   366,
     367,   367,   368,   368,   369,   369,   369,   369,   363,   363,
     370,   370,   370,   370,   330,   371,   371,   371,   330,   372,
     373,   373,   373,   374,   374,   374,   374,   330,   375,   375,
     376,   376,   330,   377,   377,   377,   377,   377,   377,   378,
     379,   379,   379,   380,   380,   381,   381,   382,   382,   382,
     382,   382,   382,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   330,   330,   384,   384,
     330,   385,   385,   330,   386,   386,   387,   387,   388,   388,
     388,   388,   388,   388,   389,   389,   390,   390,   390,   390,
     391,   391,   330,   392,   393,   393,   393,   393,   394,   394,
     395,   395,   396,   396,   397,   330,   398,   330,   399,   399,
     400,   400,   330,   401,   402,   402,   402,   402,   403,   403,
     403,   330,   404,   405,   405,   405,   405,   405,   330,   406,
     406,   330,   407,   330,   330,   330,   408,   408,   409,   409,
     410,   411,   411,   411,   412,   412,   412,   413,   330,   414,
     330,   330,   330,   415,   416,   417,   330,   418,   419,   419,
     420,   421,   421,   421,   421,   330,   422,   330,   423,   424,
     424,   424,   425,   425,   425,   425,   330,   426,   427,   427,
     428,   428,   428,   330,   429,   430,   430,   330,   431,   432,
     432,   433,   433,   433,   433,   433,   433,   433,   433,   433,
     433,   433,   433,   434,   434,   435,   435,   435,   435,   435,
     330,   436,   330,   437,   438,   438,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   330,   440,   330,   441,   330,
     442,   330,   443,   444,   444,   330,   445,   446,   446,   330,
     447,   448,   448,   448,   330,   449,   330,   450,   451,   451,
     451,   451,   451,   451,   330,   452,   453,   453,   453,   330,
     454,   330,   455,   456,   456,   456,   456,   330,   457,   330,
     458,   458,   458,   458,   458,   458,   458,   458,   458,   458,
     458,   458,   458,   458,   458,   458,   458,   458,   458,   458,
     458,   458,   458,   458,   458,   458,   458,   459,   459,   460,
     460,   461,   461,   462,   462,   463,   463,   330,   464,   465,
     465,   466,   466,   467,   467,   467,   330,   468,   469,   469,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     330,   471,   472,   472,   472,   330,   473,   465,   474,   475,
     475,   330,   476,   477,   477,   478,   478,   478,   330,   479,
     479,   479,   479,   480,   480,   481,   330,   482,   483,   483,
     484,   484,   485,   485,   485,   486,   486,   487,   487,   487,
     488,   488,   488,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   490,   490,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     491,   491,   492,   492,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   493,   493,
     493,   481,   481,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   481,   481,   481,   481,   495,   495,   481,   481,
     481,   481,   481,   481,   481,   481
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     3,     1,     3,    11,     0,     2,     0,
       4,     2,     4,     0,     1,     1,     0,     2,     0,     2,
       0,     3,     0,     2,     4,     0,     2,     1,     3,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     2,     1,     3,     1,     1,     2,     4,     3,     3,
       0,     1,     2,     1,     0,     5,     3,     5,     6,     5,
       0,     1,     1,     0,     1,     1,     1,     2,     2,     0,
       0,     1,     2,     4,     1,     3,     3,     1,     7,     2,
       2,     2,     0,     6,     2,     4,     0,     2,     7,     1,
       8,     0,     5,     0,     2,     2,     2,     2,     1,     0,
       0,     3,     3,     5,     1,     1,     3,     3,     7,     7,
       3,     3,     5,     5,     1,     8,     7,     7,     1,     8,
       0,     2,     2,     3,     5,     5,     7,     1,     4,     4,
       0,     3,     1,     8,    10,     9,     6,    11,     8,     3,
       0,     1,     1,     0,     1,     1,     3,     3,     5,     4,
       4,     5,     5,     0,     3,     2,     3,     3,     3,     3,
       2,     3,     3,     2,     3,     5,     2,     1,     2,     3,
       1,     4,     4,     1,     5,     5,     1,     3,     3,     6,
       3,     3,     3,     4,     0,     1,     0,     2,     3,     3,
       0,     1,     1,    10,     0,     1,     1,     1,     0,     2,
       1,     1,     1,     3,     3,     1,     5,     1,     4,     4,
       0,     2,     1,     6,     1,     3,     3,     5,     0,     1,
       1,     1,     3,     0,     3,     7,     5,     9,     1,     2,
       2,     1,     2,     1,     1,     1,     2,     2,     0,     1,
       4,     0,     3,     2,     0,     2,     1,     4,     1,     4,
       1,     1,     1,     2,     5,     3,     1,     3,     1,     3,
       3,     1,     2,     2,     1,     1,     2,     1,     6,     0,
       1,     1,     2,     2,     2,     1,     1,     3,     1,     3,
       1,     4,     5,     1,     3,     1,     3,     1,     9,     1,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     2,     2,     2,     2,     2,     2,
       1,     9,     1,     9,     1,     3,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     1,     8,     1,     9,     1,
       9,     1,     3,     3,     5,     1,     8,     0,     2,     1,
       4,     0,     1,     1,     1,     5,     1,     4,     0,     1,
       1,     1,     1,     1,     1,     4,     0,     1,     1,     1,
       4,     1,     5,     0,     2,     2,     2,     1,     5,     1,
       4,     3,     7,     4,     4,     4,     3,     3,     4,     4,
       3,     3,     3,     4,     5,     3,     3,     5,     2,     3,
       4,     5,     5,     4,     4,     3,     3,     0,     1,     0,
       2,     0,     2,     0,     2,     0,     1,     1,     5,     1,
       3,     1,     3,     0,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     2,     2,     4,     1,
       1,     3,     0,     1,     1,     1,     5,     3,     4,     0,
       2,     1,     2,     1,     3,     1,     2,     1,     1,     4,
       3,     3,     3,     0,     2,     1,     1,     2,     1,     3,
       3,     3,     0,     3,     5,     0,     1,     0,     2,     2,
       0,     4,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     3,
       5,     2,     4,     1,     1,     1,     1,     3,     3,     3,
       3,     5,     5,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     5,     6,     6,     6,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     4,     3,     4,     5,
       1,     3,     0,     1,     5,     6,     5,     6,     4,     5,
       4,     4,     4,     4,     6,     8,     4,     7,     1,     1,
       1,     6,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     6,     3,     5,     4,     5,     3,     4,
       3,     4,     1,     1,     1,     2
};

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error.  */
static const unsigned short int yydefact[] =
{
       0,   190,   341,     0,   143,    82,     0,     0,   143,     0,
      93,   432,     0,     0,   341,     0,     0,    93,     0,    29,
     269,   397,     0,    93,     0,     0,     0,     0,   238,   238,
       0,     0,   238,     0,     0,   341,     0,   341,     0,     0,
       0,     0,     0,     0,     4,    77,    89,   114,   118,   127,
     132,   167,   170,   173,   192,   205,   207,   212,   221,   228,
     231,   233,   234,   235,   248,   250,   251,   252,   256,   265,
     267,   276,   283,   287,   310,   312,   325,   327,   329,   331,
     335,   339,   344,   346,   354,   359,   361,   367,   369,   407,
     416,   430,   435,   441,   448,   456,     0,   191,     0,     0,
     343,   342,     0,     0,   130,   196,   130,   197,   144,   195,
       0,     0,     0,     0,   230,   229,   210,     0,   210,     0,
       0,     0,   291,   300,   297,   296,   298,     0,   299,   100,
     302,   100,   100,     0,   289,     0,   314,    99,   434,   433,
       0,     0,     0,     0,     0,   223,     0,    99,     0,     0,
       0,     0,     0,   270,   271,   337,     0,   457,   458,   505,
     508,   509,   511,   510,   506,     0,     0,     0,     0,     0,
       0,   583,   584,   582,     0,     0,     0,     0,     0,   388,
       0,   401,     0,     0,    22,     0,     0,   399,    22,   406,
       0,   398,     0,     0,     0,     0,     0,     0,   455,     0,
       0,     0,     0,   266,     0,     0,   232,   540,   166,   168,
       0,     0,   239,   237,   241,   236,   253,   241,     0,     0,
       0,     0,     0,   445,     0,   447,   442,   443,     0,     0,
     453,     1,     0,     2,   470,   470,     0,     0,   214,   348,
       0,     0,     0,   280,   277,   278,   130,     0,    86,     0,
      81,    79,    80,     0,     0,     0,     0,     0,   285,   284,
     452,   210,   292,   301,     0,   318,   316,   317,     0,     0,
       0,     0,    95,    96,    97,    98,    94,     0,   431,     0,
      54,   257,   258,     0,   255,     0,   222,     0,   332,     0,
       0,     0,    40,    30,    31,    32,    33,    36,    37,    35,
      34,     5,    38,    54,     0,     0,     0,     0,     0,     0,
       0,     0,   542,     0,   532,     0,   531,   518,   585,     0,
       0,     0,     0,     0,     0,   376,     0,     0,   377,   399,
     401,     0,   371,     0,   380,     0,   381,     0,   385,     0,
     403,   395,   399,     0,     0,     0,     0,     0,     0,   401,
     401,   399,     0,   389,   386,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   382,   396,    97,    94,    54,
       0,     0,    42,    44,    45,    50,     0,   169,   411,     0,
     409,     0,   244,     0,   244,     0,   356,     0,     0,     0,
       0,     0,   423,   422,   425,   420,   421,   429,   417,   418,
     446,     0,     0,   451,     0,   450,     3,   171,   172,   186,
     340,     0,   349,   350,   351,   352,   353,     0,   347,     0,
     128,   129,     0,     0,     0,   198,     0,    84,     7,     0,
       0,     0,   211,   208,     0,   209,     0,     0,    27,     0,
       0,     0,   300,   297,   296,   298,     0,   299,   295,   293,
     294,   290,     0,   323,   320,   319,   321,     0,   322,   100,
     100,   100,   315,   100,     0,    53,     0,     0,     0,   360,
       0,     0,     0,     0,     0,   100,     0,     0,     0,     0,
       0,    41,   461,   460,   249,   338,     0,     0,   459,   507,
     543,     0,   533,     0,     0,     0,     0,   574,     0,   373,
     374,   375,     0,   399,   401,   370,   402,   378,   379,    23,
     383,   400,     0,   393,   401,   540,     0,   560,   558,   559,
       0,     0,     0,     0,     0,     0,   534,   390,   394,   401,
       0,   520,   521,   519,   580,   578,   537,     0,   535,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   522,   527,
     528,   530,   512,   513,   514,   515,   516,   517,   529,     0,
      46,     0,     0,     0,     0,    62,    61,    65,    69,    66,
       0,     0,    63,    51,     0,   541,   414,   415,     0,   439,
       0,     0,     0,   243,   246,     0,   240,     0,   247,     0,
     357,   358,   355,   363,     0,   426,   424,     0,   427,     0,
     444,   449,   454,     0,     0,   184,   184,   184,     0,     0,
     174,   176,   175,   215,   216,   131,     0,   279,   140,     0,
       0,    87,     0,    20,     0,     7,    86,   206,   286,   218,
       0,   101,     0,     0,   301,     0,   324,     0,     0,   436,
      52,     0,   261,   264,   260,   259,   224,     0,     0,   333,
       0,     0,     0,     0,     0,     0,     7,    39,     0,     0,
     550,     0,     0,     0,   572,     0,     0,   548,   384,   391,
       0,   404,   387,     0,   553,   556,     0,     0,     0,   551,
     552,   392,   399,   538,   536,     0,     0,   581,   579,     0,
       0,     0,     0,     0,     0,    54,    76,    49,     0,     7,
      43,    63,    63,     0,    56,     0,    64,     0,    48,    74,
       0,   412,     0,   437,   408,   411,   410,   242,   245,   254,
     345,   362,   368,     0,   419,     0,   472,   185,     0,     0,
       0,     0,     0,     0,     0,   187,     0,     0,     0,   281,
       0,   141,   142,     0,     0,   136,    50,   200,   201,   199,
       0,     8,     0,    22,     7,    83,    85,   220,   219,   213,
      28,     0,     0,     0,     0,    91,     0,    91,   263,   262,
       0,     0,     0,     0,    91,     0,    91,     0,     0,     0,
       9,     0,     0,     0,   275,   268,   548,   576,     0,   575,
       0,    24,     0,     0,     0,     0,     0,   401,   546,   544,
       0,     0,   539,     0,     0,     0,   523,    47,     0,     0,
       0,    20,    67,    68,     0,     0,    70,     0,     0,     0,
     440,     0,   364,   365,   366,   428,   471,     0,     0,     0,
       0,     0,   178,   145,     0,     0,   182,   181,   180,   189,
     188,   177,   217,   282,   140,     0,     0,     0,     0,    78,
      88,     0,     0,     0,     0,     0,     0,   108,     0,    91,
     109,     0,   226,     0,   334,   116,    91,   117,     0,     0,
       0,     0,    18,     0,   272,   273,   274,   573,   577,     0,
     554,     0,     0,   561,   562,   372,   547,   545,   526,   524,
     525,   123,     0,     0,    22,    59,    57,     0,     0,    55,
      71,     0,   438,    75,   462,   462,   462,   494,   462,   484,
     487,   462,   462,     0,   462,   462,   462,   496,   465,   495,
     462,   465,   462,     0,   462,   465,   485,   486,   493,   462,
     465,     0,     0,   488,   153,     0,     0,     0,     0,     0,
       0,     0,   183,     0,   138,   140,   139,     0,    21,    13,
     303,   303,   303,   111,   110,     0,     0,   105,     0,   104,
       0,    90,     0,     0,   115,   303,   326,   303,     0,     0,
      20,   336,     0,   557,   563,   564,   565,   566,   569,   570,
     571,   568,   567,     0,     0,     0,   119,    72,     0,    58,
       0,   467,   491,   473,   470,   467,   467,     0,   467,   467,
     467,   466,   470,   467,   470,   467,     0,   467,   470,   467,
     470,     0,     0,   147,     0,     0,     0,     0,     0,   146,
     153,     0,   135,   462,     0,   202,     0,    14,    15,    11,
       0,   311,   288,   313,     0,     0,     0,   102,     0,   225,
       0,   328,   330,    16,    19,    22,   555,   124,   125,     0,
       0,     0,   479,   489,   483,   481,   503,     0,   482,   477,
     478,   500,   476,   499,   480,     0,   475,   498,   474,   497,
       0,     0,     0,   160,     0,     0,   163,   155,     0,     0,
       0,     0,   150,   149,     0,   179,   140,    13,     0,   193,
      13,     0,     0,     0,     0,     0,   304,     0,   113,   112,
     107,   106,     0,     0,     0,    10,    25,     0,    73,     0,
     463,   468,   469,     0,   470,   470,   492,   470,   154,   164,
     156,   157,   159,   158,   162,   161,     0,   151,   152,   148,
     137,   204,   203,    12,   305,   306,   307,   308,   309,    92,
     103,   227,    17,     0,     6,   126,     0,   504,   501,   502,
     490,     0,    26,   464,   165
};

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,    42,    43,    44,   633,   882,   958,  1039,  1115,   980,
     763,   336,  1154,   449,   150,   301,   302,   381,   382,   383,
     584,   477,   384,   581,   717,   582,   713,   909,   910,   721,
     385,    45,   113,   253,   437,    46,   867,   137,   277,   265,
     869,   968,   775,    47,    48,   205,   709,    49,   241,    50,
     755,   756,   111,   842,   843,  1023,    51,    52,    53,   620,
     621,   738,   622,    99,    54,   112,   630,   759,  1034,  1035,
      55,    56,   255,    57,   239,   769,    58,   286,    59,    60,
      61,   213,    62,   392,   596,    63,    64,    65,    66,    67,
      68,   281,   282,   654,    69,    70,   156,   795,    71,   244,
     245,    72,   259,    73,   133,   134,  1041,  1106,    74,    75,
     135,   136,    76,    77,    78,    79,   288,    80,   308,    81,
     102,    82,    83,   428,    84,   602,    85,    86,   731,    87,
      88,   200,   340,   332,   523,   201,    89,   389,   390,   588,
      90,   408,   409,    91,   140,    92,   589,   723,    93,   226,
     227,    94,   415,   207,    95,   157,   158,  1001,  1012,  1062,
     417,   944,  1067,   208,   501,   531,   805,   321
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -836
static const short int yypact[] =
{
    1769,    10,   -80,  -100,   318,  -836,   131,   184,    -3,  1722,
    -836,     6,    88,    59,   -80,    89,   -65,  -836,  1722,  -836,
     166,   395,   125,    15,   301,  1098,    19,   295,    98,    98,
     168,   430,    98,   234,   236,   -80,   243,   -80,   336,   452,
     158,   474,  1610,   164,  -836,  -836,  -836,  -836,  -836,  -836,
    -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,
    -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,
    -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,
    -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,
    -836,  -836,  -836,  -836,  -836,  -836,   504,  -836,   520,   325,
    -836,  -836,   330,   538,   434,  -836,   434,  -836,  -836,  -836,
     542,   374,   439,   216,  -836,  -836,   469,   598,   469,   605,
     611,   412,   384,  -108,   -99,   -69,   -59,   497,   -58,  -123,
    -836,   -98,   -88,   -57,  -836,   -53,  -836,   424,  -836,  -836,
    1098,   541,   664,   466,   674,   681,   685,   424,   -52,   -48,
      46,   113,   684,  -836,  -836,   604,   445,   400,  -836,  -208,
    -836,  -836,  -836,  -836,   708,  1098,  1139,  1098,  1098,   226,
       1,  -836,  -836,  -836,   722,   402,   628,   746,   458,  -836,
     567,   744,   756,   467,   629,   660,   472,   662,   629,  -836,
     498,  -836,   444,   447,   450,   451,   460,  1098,  -836,    97,
     284,   486,  1700,  -836,   394,    33,  -836,  1312,  -836,  -836,
     784,   785,  -836,  -836,   753,  -836,  -836,    38,   538,   538,
     583,   538,   490,  -836,   534,  -836,   473,  -836,   694,   797,
     573,  -836,   480,  -836,  -836,  -836,   800,   538,   481,   268,
     789,   805,   806,   531,   512,  -836,   434,   818,   514,   833,
    -836,  -836,  -836,   -73,   742,   837,   686,   838,  -836,   523,
    -836,   469,  -836,   -44,   857,  -836,  -836,  -836,   269,  1781,
     864,   619,  -836,  -836,  -836,  -836,  -836,   874,  2442,   621,
      99,   558,  -836,   538,  -836,  -134,   559,   678,   574,   896,
     422,   897,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,
    -836,   -63,  -836,  2421,  1098,  1098,  1098,   901,   890,   640,
     904,   910,  1098,  1098,   829,   589,   829,  -836,  -836,  1098,
    1751,   -24,   912,   915,   916,  -836,   733,   922,  -836,   662,
     744,   923,  -836,   -14,  -836,  1098,  -836,   918,  -836,   925,
     921,  -836,   662,  1098,   411,  1098,  1098,   748,   612,   744,
     744,   662,   831,  -836,  -836,  1098,  1098,  1098,  1098,  1098,
     120,   614,   511,  1098,   553,  1098,  1098,  1098,  1098,  1098,
    1098,  1098,  1098,  1098,  1098,  -836,  -836,    34,    36,    52,
      14,  -109,   537,  -836,  -836,   902,  1098,  -836,     8,    -4,
    -836,   311,   -68,   670,   -68,  -124,    49,   538,   -61,   938,
     687,    18,  -836,  -836,  -836,  -836,  -836,  -836,   623,  -836,
    -836,   336,  1769,  -836,   605,  -836,  -836,   339,   339,   391,
     624,   945,  -836,  -836,  -836,  -836,  -836,   947,  -836,   855,
    -836,  -836,   906,   542,   951,   728,   933,  -836,   159,  -140,
      33,   957,  -836,  -836,   962,  -836,   953,   538,  -836,   141,
     642,   643,  -836,  -836,  -836,  -836,   809,  -836,  -836,  -836,
    -836,  -836,   646,  -836,  -836,  -836,  -836,   812,  -836,   649,
     649,   649,  -836,  -114,   785,  -836,   972,   -43,   664,   624,
     989,   990,   991,   987,   995,   -18,   682,   683,   689,    33,
    1098,  -836,  2442,  2442,  2442,  -836,   725,   736,  -836,  -836,
    -836,   688,  2442,   733,  2070,    84,  1098,  -836,  1098,  -836,
    -836,  -836,   690,   662,   744,  -836,  -836,  -836,  -836,  1533,
    -836,  -836,  1098,  -836,   744,  1272,   691,  -836,  -836,  -836,
     692,  1098,  1562,  1593,   695,   804,  -836,  -836,  -836,   744,
    1007,  1511,  1910,  2115,  2460,  2460,  -836,    69,  -836,   858,
    1098,  1098,   697,  2392,   701,   721,   723,   858,  1144,  1006,
    1110,   580,   617,   617,   979,   979,   979,   979,  -836,  1017,
    -836,   724,   173,  1044,    33,  -836,  -836,  -836,   195,  -836,
      33,   924,   886,  -836,  1051,  -836,  -836,  -836,    37,   940,
    1053,  1058,   798,  -836,  -836,   888,  -836,  1061,  -836,  1066,
    -836,  -836,  -836,   624,  1067,  -836,  -836,   907,   751,   490,
    -836,  -836,   523,   889,  1073,  1025,  1025,   396,  1039,    28,
     764,  -836,  -836,  -836,   765,  -836,    16,  -836,   -86,   178,
     932,  -836,  1098,   929,    33,  -143,   514,  -836,  -836,    -8,
    1089,  -836,  1068,  1069,  -836,  1090,  -836,  1094,   -92,   786,
    -836,   867,   839,  -836,  -836,  -836,  -836,   893,   -38,  -836,
     894,  1094,   -55,  1086,  1088,  1114,  -143,  -836,   793,   -85,
    -836,   794,  1098,  1098,  -836,  2315,  2091,  -836,  -836,  -836,
    1098,  2442,  -836,  1098,  -836,  -836,  2219,   997,   997,  -836,
    -836,  -836,   662,  -836,  -836,   796,   799,  2460,  2460,   858,
    1098,   733,   733,   733,   801,    99,  -836,  -836,    -7,  -137,
     537,   886,   886,   992,   968,    33,  -836,   999,  -836,  -836,
    1125,   808,   895,  -836,  -836,    79,  -836,  -836,  -836,  -836,
    -836,   199,  -836,  1010,  -836,  1126,  -836,  -836,   278,  1148,
    1024,   857,  1026,  1150,  1152,  -836,  1155,   417,  1156,  -836,
    1176,  -836,  -836,  1157,   278,  -836,   902,  -836,  -836,  -836,
    1178,  2442,  1137,   629,  -143,  -836,  -836,  -836,  -836,  -836,
    -836,   969,   970,   971,  1172,   -41,   869,  1042,  -836,  -836,
    1203,  1205,  1207,  1204,   -41,   869,  1042,  1106,  1108,  1116,
    1107,  1218,   313,  1055,  -836,  -836,  1360,  2442,  2336,  -836,
    1098,  2442,   139,  1098,  1098,   903,   905,   744,  -836,  -836,
     908,   909,   958,   911,   913,   914,  -836,  -836,  1098,  1220,
    1224,   929,  -836,  -836,    33,  1098,   102,    33,   205,  1225,
    -836,  1125,  -836,  -836,  -836,  -836,  -836,  2080,   185,   917,
     927,  1102,   952,  -836,  1229,   857,   954,  -836,  -836,  -836,
    -836,  -836,  -836,  -836,   -72,   246,   733,   936,  1098,  -836,
    -836,   542,   542,   542,   899,  1076,  1235,  -836,   926,   -35,
    -836,   955,  -836,  1031,  -836,  -836,   -35,  -836,   605,   605,
     605,  1194,  1140,   950,  -836,  -836,  -836,  -836,  2442,  1098,
    -836,   963,  1951,  -836,  -836,  -836,  -836,  -836,  -836,  -836,
    -836,  2442,  1230,    -6,   629,  -836,  2442,  1098,   956,  -836,
    -836,   219,  -836,  -836,   978,   978,   978,  -836,   978,  -836,
    -836,   978,   978,   980,   978,   978,   978,  -836,  1237,  -836,
     978,  1237,   978,   981,   978,  1237,  -836,  -836,  -836,   978,
    1237,   982,   984,  -836,  -836,   985,   993,   857,   857,  1004,
     278,  2080,  1020,   278,  -836,   -54,  -836,  1275,  1021,  2357,
     -36,   -36,   -36,  -836,  2442,  1188,  1284,  -836,   271,  2442,
    1022,  -836,  1314,  1317,  -836,   -17,   523,   -17,  1098,  1098,
     929,  -836,  1244,  -836,  -836,  -836,  -836,  -836,  -836,  -836,
    -836,  -836,  -836,  1098,  1098,  1342,  -836,  2442,   857,  -836,
    1341,  -836,  -836,  -836,  -836,  -836,  -836,  1344,  -836,  -836,
    -836,  -836,  -836,  -836,  -836,  -836,  1344,  -836,  -836,  -836,
    -836,  1345,  1346,   352,   857,   857,   289,   331,   857,  -836,
    -836,   335,  -836,   978,   337,  -836,  1098,  -836,  -836,  -836,
      63,  -836,  -836,  -836,  1124,   994,  1035,  -836,   926,  -836,
    1033,  -836,  -836,    60,  2442,   629,  -836,  2442,  2442,  1338,
     348,   349,   183,   339,   183,   183,  -836,   355,   183,   183,
     183,   339,   183,   339,   183,   375,   183,   339,   183,   339,
    1038,  1040,  1211,  -836,  1355,   510,  -836,  -836,  1233,   -83,
     377,   379,  -836,  -836,   398,   352,   -49,   293,  1275,  -836,
    2357,  1208,  1098,  1098,  1098,  1098,  -836,  1094,  -836,  2442,
    -836,  2442,   416,  1365,  1186,  -836,  1266,  1098,  -836,  1387,
    -836,  -836,  -836,  1389,  -836,  -836,  -836,  -836,  -836,  -836,
    -836,  -836,  -836,  -836,  -836,  -836,   857,  -836,  -836,  -836,
    -836,  -836,  -836,  -836,  -836,  2442,  2442,  2442,  2442,  1071,
    -836,  -836,  -836,   857,  -836,  2442,  1074,  -836,   339,   339,
     339,   418,  1072,  -836,  -836
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -836,  -836,   -33,  -321,  -231,  -836,   419,  -363,  -836,  -836,
    -759,  -186,  -836,  -731,  -836,  -836,   919,  -354,   827,  -524,
     647,  -295,  -836,  -836,   -91,  -836,  -836,  -836,   491,   693,
    -836,  -836,  -836,  1158,   768,  -836,  -289,   404,  1258,  -116,
     625,   358,  -654,  -836,  -836,  -836,  -836,  -836,   -26,  -836,
    -835,  -836,  1400,  -694,   461,   382,  -836,  -836,  -836,  -836,
     667,    32,  -836,  -836,  -836,  -836,  -836,  -836,  -836,   322,
    -836,  -836,    55,  -836,  -191,  -836,  -836,  -836,  -836,  -836,
    -836,   716,  -836,  1209,  1027,  -836,  -836,  -836,  -836,  -836,
    -836,  -836,   946,  -836,  -836,  -836,  1406,  -836,  -836,  -298,
     996,  -836,  -408,  -836,  1410,  1161,  -377,  -836,  -836,  -836,
    1413,  1165,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,
     104,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,  -836,
    -836,  -836,  -304,  -326,  -836,  -836,  -836,   964,   846,   714,
    -836,  -836,   834,  -836,  -836,  -836,  -836,  -836,  -836,  -836,
    1029,  -836,  -836,   -21,  -836,  -836,  1132,   275,  -442,  -121,
    -234,   493,   429,  -309,  -836,  -836,   758,  1127
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -549
static const short int yytable[] =
{
     202,   418,   341,   500,   515,   512,   612,   784,   491,   232,
     846,  -413,   590,   818,   994,   266,   267,   379,  -120,   954,
     749,   238,   209,   537,   538,   514,   572,   395,   396,   751,
     398,   745,   440,  -100,   526,   530,   379,  -122,   524,  -121,
     719,   767,   489,   751,   604,  1135,   420,   539,  -300,   159,
     160,   161,   162,   163,   164,   475,   714,  -297,  -100,   571,
     855,   751,   904,   165,   166,   116,   751,   506,  -100,   322,
     507,   167,   292,   100,   391,   693,   647,   585,    96,   293,
     242,   573,  -413,   480,   570,   792,   635,  -296,   634,   168,
     476,   752,   479,   599,   632,    19,   169,  -298,  -299,   268,
     632,   651,   475,   270,   290,   752,   594,   103,   291,   171,
     172,   173,  -301,   117,   952,   865,   311,   312,   143,   278,
    1032,   865,   304,   752,   586,    97,   546,   652,   752,   303,
     294,   295,    19,   305,   114,   666,   587,   476,   547,   220,
     776,   222,   145,   175,   314,   316,   317,   318,   320,   355,
     356,   357,   358,   359,   360,   361,   296,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
    1101,   768,   661,   257,   151,   673,   348,   785,   674,   781,
     574,   118,   671,   441,   146,   323,   820,   115,   679,   101,
     481,   826,   793,   794,    98,   586,   595,   653,   682,   427,
    -100,    19,   264,  1040,   141,   108,   603,   587,   324,   678,
     608,   264,   508,   691,   574,  -300,  1026,  1027,   600,   248,
     434,  1055,  1040,   694,  -297,  -100,   210,   264,   695,   159,
     160,   161,   162,   163,   164,  -100,   704,   264,   753,   754,
     696,   889,  1136,   165,   166,   746,   119,   297,   298,   299,
     441,   167,   300,   953,  -296,   393,   639,   607,   907,  1031,
     490,  1140,   427,   138,  -298,  -299,   269,  1060,  -133,   168,
     271,   269,   450,  -134,   548,   271,   169,   517,   518,  -301,
     764,   837,   866,   492,   493,   494,   782,   433,   970,   171,
     172,   173,   502,  1090,  1091,   451,   750,  1094,   504,  1114,
     905,   945,   601,   911,   206,   120,   446,   264,  1102,  1103,
    1104,  1105,   139,   946,   519,   427,   447,   819,   995,   591,
     508,   249,   525,   175,   532,   533,   535,   777,   711,   142,
     908,   250,  1037,  -413,   541,   542,   543,   544,   545,   380,
    -120,   786,   553,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   266,   267,   144,   648,   380,  -122,
     251,  -121,   720,   192,   193,   194,   195,   196,   832,   662,
    1082,   197,   427,   198,  1038,   907,   569,   712,   810,   611,
     813,   814,   815,  1036,   838,   252,   104,   -86,   807,   349,
     811,   613,  1083,   614,   839,   203,   632,   350,   159,   160,
     161,   162,   163,   164,   765,  1161,   840,  1121,  1084,   212,
     817,   211,   165,   166,   159,   160,   161,   162,   163,   164,
     167,   147,  1162,   615,   105,   486,  1122,   204,   165,   166,
    1085,   215,   152,   216,  -194,   790,   167,   422,   168,   153,
     154,   218,   616,   219,   841,   169,   155,   908,   487,   615,
     221,   737,   833,  1149,   168,   228,   170,   527,   171,   172,
     173,   169,   319,   174,   640,   890,   229,   641,   616,   303,
     975,   976,   977,   272,   171,   172,   173,   230,   821,   617,
    1086,   895,   -86,   436,   834,   675,   233,   676,   870,  1014,
     757,   758,   175,  1018,   891,   875,   574,   877,  1020,   707,
     740,   681,   106,   272,   273,   617,  1087,   234,   175,   377,
     686,   176,   741,   107,  1130,  1131,  1132,  1133,  1088,   423,
     424,   425,   426,   235,   550,   551,   108,   552,   829,   697,
     698,   912,   236,   860,   273,   956,   348,   237,   378,   274,
     109,   238,   528,   192,   193,   194,   195,   196,   240,   275,
     243,   197,   618,   198,   351,   247,   159,   160,   161,   162,
     163,   164,   742,   960,   961,   962,   619,   110,   276,   950,
     165,   166,   955,   352,  1089,   592,   593,   859,   167,   177,
     971,   246,   353,   254,  1042,  1043,   554,   974,   884,   885,
     555,   427,   223,   224,  1046,   225,   168,  1047,  1051,   575,
    1052,   256,   178,   169,   368,   369,   370,   371,   372,   373,
     374,   761,   640,   258,   260,  1092,   171,   172,   173,   261,
     822,   823,   355,   356,   357,   358,   359,   360,   361,   529,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   370,   371,   372,   373,   374,   739,   743,
     175,   797,   798,   463,   640,   576,   263,  1093,   950,   801,
    1098,  1096,   802,  1099,   -60,   262,   279,   280,   153,   154,
     577,   640,  1119,   283,  1118,  1120,   179,   284,  1123,   812,
     464,  1124,   180,   181,   285,   182,  -405,  -269,   183,   578,
     184,   185,   186,   287,   187,  -269,   188,   399,  1123,   465,
     640,  1125,   640,  1137,   306,  1138,   307,   466,   309,   189,
     190,   191,   192,   193,   194,   195,   196,   313,   996,   579,
     197,   640,   198,   310,  1139,   325,   467,   326,   192,   193,
     194,   195,   196,   327,  1141,   468,   197,  1143,   198,  1046,
     469,   640,  1150,   580,  1164,   214,   556,   400,   217,   328,
     329,   159,   160,   161,   162,   163,   164,   330,   331,   333,
     401,   334,   337,   335,   338,   165,   166,   339,   342,   343,
    1063,   402,   344,   167,   534,   345,   346,   354,  1071,   888,
    1073,   403,   404,   892,  1077,   347,  1079,   387,   388,   391,
     397,   168,   410,   405,   406,   407,   411,   901,   169,   412,
     413,   414,   416,   419,   906,   421,   470,   429,   430,   431,
     432,   171,   172,   173,   355,   356,   357,   358,   359,   360,
     361,   435,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   433,   438,   959,   436,   442,
     443,   445,   444,   964,   471,   175,   446,   969,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     448,   159,   160,   161,   162,   163,   164,   462,   982,  1116,
     192,   193,   194,   195,   196,   165,   166,   473,   557,   474,
     198,   478,   482,   167,  1064,  1065,   997,  1068,  1069,  1070,
    1158,  1159,  1072,  1160,  1074,   483,  1076,   484,  1078,   485,
     488,   168,   159,   160,   161,   162,   163,   164,   169,   495,
     496,   497,   151,   499,   503,   509,   165,   166,   510,   511,
      19,   171,   172,   173,   167,   513,   520,   516,   521,   159,
     160,   161,   162,   163,   164,   522,   540,   597,   536,   549,
     583,   605,   168,   165,   166,   606,   609,   427,   623,   169,
     624,   167,   625,   626,   628,   175,   629,   959,  1054,   631,
     636,   638,   171,   172,   173,   637,   642,   643,   644,   168,
     645,   646,  1057,  1058,   264,   650,   169,   963,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   171,
     172,   173,   656,   657,   658,   659,   175,   159,   160,   161,
     162,   163,   164,   660,   967,   668,   663,   664,   669,   374,
     692,   165,   166,   665,   670,  1100,   677,   684,   685,   167,
     705,   689,   699,   175,  1109,  1111,   701,   969,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   168,   159,   160,
     161,   162,   163,   164,   169,    19,   702,   708,   703,   716,
     706,   715,   165,   166,   718,   722,   724,   171,   172,   173,
     167,   725,   728,   727,   729,   192,   193,   194,   195,   196,
     730,   732,  1108,   197,   427,   198,   736,   733,   168,   735,
     737,  1145,  1146,  1147,  1148,   169,   744,   747,   760,   748,
     762,   175,   770,   773,   771,   772,  1155,   774,   171,   172,
     173,   159,   160,   161,   162,   163,   164,   778,   779,   591,
     780,   783,   787,  1110,   788,   165,   166,   789,   791,   824,
     796,   804,   808,   167,   825,   809,   827,   816,   719,   836,
     690,   829,   175,   367,   368,   369,   370,   371,   372,   373,
     374,   168,   159,   160,   161,   162,   163,   164,   169,   835,
     830,   844,   845,   848,   847,   849,   165,   166,   850,   852,
     854,   171,   172,   173,   167,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   192,   193,   194,   195,   196,
     853,   857,   168,   197,   858,   198,   861,   862,   863,   169,
    1002,  1003,   864,  1004,   868,   175,  1005,  1006,   865,  1008,
    1009,  1010,   171,   172,   173,  1013,   871,  1015,   872,  1017,
     873,   878,   874,   879,  1019,   881,   192,   193,   194,   195,
     196,   880,   883,   902,   197,   886,   198,   903,   913,   893,
     949,   894,   951,   965,   896,   897,   315,   898,   966,   899,
     900,   978,   947,   192,   193,   194,   195,   196,   973,   979,
     993,   197,   948,   198,   355,   356,   357,   358,   359,   360,
     361,   957,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   950,   981,   640,  1033,   972,
    1011,   998,   355,   356,   357,   358,   359,   360,   361,   983,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,  1000,  1045,  1007,  1016,  1021,  1097,  1022,
    1024,   192,   193,   194,   195,   196,  1044,  1049,  1025,   197,
    1050,   198,   355,   356,   357,   358,   359,   360,   361,  1028,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   640,  1036,  1059,  1061,  1048,  1066,  1107,
    1080,  1081,   192,   193,   194,   195,   196,  1113,  1117,  1129,
     197,  1134,   198,  -548,  1126,  1128,  1127,  1144,  1151,  1152,
    -548,  -548,  -548,  -548,  -548,  -548,  -548,   683,  -548,  -548,
    -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,
    -548,  1153,  1156,  1157,   866,   640,  -548,  1053,  -548,  -548,
    1163,   710,   999,   856,   766,   289,  1112,   439,   121,   667,
     876,  1029,  1095,   828,   851,   192,   193,   194,   195,   196,
    1142,   598,  -548,   197,   655,   198,   394,   199,   148,   627,
     461,   149,  -548,  -548,  -548,  -548,   472,   726,   649,   831,
     610,  -548,   498,   734,  1030,  1075,   806,   505,     0,     0,
       0,  -548,     0,     0,  -548,     0,   192,   193,   194,   195,
     196,     0,  -548,     0,   197,  -548,   198,     0,  -548,  -548,
       0,  -548,  -548,  -548,     0,     0,     0,     0,  -548,     0,
       0,     0,     0,     0,     0,  -548,     0,  -548,     0,     0,
       0,     0,     0,  -548,  -548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -548,     0,     0,     0,  -548,     0,     0,     0,
       0,  -548,   356,   357,   358,   359,   360,   361,     0,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,  -548,   355,   356,   357,   358,   359,   360,   361,
    -548,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,  -548,     0,     0,     0,
    1056,  -548,   355,   356,   357,   358,   359,   360,   361,     0,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     0,   386,  -548,  -548,     0,  -548,
       0,  -548,  -548,   355,   356,   357,   358,   359,   360,   361,
     231,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   386,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -548,     0,     0,     0,     0,
       0,  -548,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -548,  -548,     0,     0,  -548,     0,     0,     0,
       5,     6,     7,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     355,   356,   357,   358,   359,   360,   361,     9,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,    10,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,    12,     0,     0,    13,
       0,     0,     0,     0,     0,   122,   123,     0,     0,     0,
       0,   355,   356,   357,   358,   359,   360,   361,    14,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,   124,    15,    16,     0,    17,     0,     0,
       0,    18,     0,     0,     0,     0,     0,    19,     0,     0,
      20,    21,   125,     1,     2,     0,     0,     0,     0,     0,
     126,     0,     0,     0,   122,   452,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,   127,
       4,     0,     0,    22,     0,    23,     0,    24,   128,     0,
       0,     0,   453,   129,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     0,    25,     0,   680,     8,     0,     0,
      26,   454,     0,     0,     0,     0,     0,     0,    27,   455,
      28,    29,    30,     0,     0,     0,     9,    31,    32,     0,
       0,     0,     0,     0,     0,   687,     0,     0,   456,     0,
      10,     0,    33,    34,    35,   130,    36,   457,     0,    11,
       0,     0,   458,     0,     0,    12,     0,     0,    13,   131,
       0,     0,    37,     0,     0,     0,   688,    38,    39,    40,
      41,     0,   357,   358,   359,   360,   361,    14,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     0,    15,    16,     0,    17,   132,     0,     0,
      18,     0,     0,     0,   130,     0,    19,     0,     0,    20,
      21,   355,   356,   357,   358,   359,   360,   361,   459,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,     0,     0,     0,     0,     0,   319,     0,     0,
       0,     0,    22,     0,    23,   375,    24,     0,     0,     0,
       0,   376,     0,     0,     0,     0,   460,     0,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    26,
       0,     0,     0,   984,   985,   986,   987,    27,     0,    28,
      29,    30,     0,     0,     0,     0,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,     0,    36,     0,     0,     0,     0,
       0,     0,   988,   989,   990,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,    38,    39,    40,    41,
     355,   356,   357,   358,   359,   360,   361,     0,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   355,   356,   357,   358,   359,   360,   361,     0,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   914,   915,   916,   917,     0,     0,   358,   359,
     360,   361,   918,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,     0,     0,     0,     0,
     919,   920,     0,     0,     0,     0,   921,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   922,     0,     0,
       0,     0,     0,     0,     0,   923,     0,     0,     0,     0,
       0,   924,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   991,   992,     0,     0,     0,     0,     0,     0,
       0,     0,   925,   926,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   927,   928,     0,     0,     0,   929,   930,   931,   355,
     356,   357,   358,   359,   360,   361,     0,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
       0,     0,   932,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     933,     0,   934,     0,     0,     0,     0,     0,     0,     0,
       0,   672,     0,     0,     0,     0,     0,     0,     0,   935,
       0,     0,   936,   937,   938,   939,   940,     0,     0,     0,
       0,     0,   800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   941,   942,     0,     0,     0,     0,     0,
       0,   943,     0,     0,   803,   355,   356,   357,   358,   359,
     360,   361,     0,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   355,   356,   357,   358,
     359,   360,   361,     0,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   355,   356,   357,
     358,   359,   360,   361,     0,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,     0,     0,
       0,     0,     0,     0,     0,     0,  1037,     0,     0,     0,
       0,     0,   355,   356,   357,   358,   359,   360,   361,   799,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,   475,     0,     0,     0,   700,     0,
     887,   355,   356,   357,   358,   359,   360,   361,  1038,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   355,   356,   357,   358,   359,   360,   361,   476,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,  -549,  -549,  -549,  -549,     0,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     5,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     7,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,   165,     0,
       0,     0,     0,     0,    15,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,     0,   169,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
      45,    47,    49,    51,    53,    55,    57,     0,    59,    61,
      63,    65,    67,    69,    71,    73,    75,    77,    79,    81,
      83,     0,     0,     0,     0,     0,    85,     0,    87,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    95,    97,    99,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,   109,     0,     0,   111,   113,
       0,   115,   117,   119,     0,     0,     0,     0,   121,     0,
       0,     0,     0,     0,     0,   123,     0,   125,     0,     0,
       0,     0,     0,   127,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,     0,     0,     0,   133,     0,     0,     0,
       0,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   147,     0,   149,
       0,   151,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   155,     0,     0,     0,     0,
       0,   157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   161,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   323,     0,   323,     0,   320,     0,   320,     0,   319,
       0,   319,     0,   321,     0,   321,     0,   322,     0,   322,
       0,   295,     0,   295,     0,   293,     0,   293,     0,   294,
       0,   294,     0,   324,     0,   324,     0,   427,     0,    56,
       0,   412,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,   549,     0,   549,     0,   549,
       0,   549,     0,   549,     0,    70,     0,   178,     0,   182,
       0,   183,     0
};

static const short int yycheck[] =
{
      21,   235,   188,   312,   330,   326,   414,   661,   303,    42,
     741,     3,    16,    20,    20,   131,   132,     3,     3,   854,
       4,     3,     3,   349,   350,   329,   380,   218,   219,   115,
     221,     3,   105,   156,   343,   344,     3,     3,   342,     3,
       3,    49,   105,   115,   105,   128,   237,   351,   156,     3,
       4,     5,     6,     7,     8,     3,   580,   156,   156,   380,
     754,   115,   821,    17,    18,    68,   115,    91,   156,    68,
      94,    25,    26,   153,    36,     6,   190,   386,    68,    33,
     106,   190,     3,   217,   379,   170,   440,   156,   228,    43,
      38,   177,   283,   217,   237,   187,    50,   156,   156,   156,
     237,   144,     3,   156,   156,   177,   174,   207,   156,    63,
      64,    65,   156,   116,   845,   156,   324,   325,    14,   140,
     955,   156,     9,   177,   116,   115,     6,   170,   177,   150,
      84,    85,   187,    20,     3,   489,   128,    38,    18,    35,
     232,    37,   207,    97,   165,   166,   167,   168,   169,    10,
      11,    12,    13,    14,    15,    16,   110,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
     107,   179,   190,   118,     8,    91,   197,   232,    94,   217,
     323,   184,   503,   323,   249,   184,   323,     3,   514,   269,
     324,   715,   277,   278,   184,   116,   264,   240,   524,   323,
     323,   187,   325,   239,   116,   208,   397,   128,   207,   513,
     401,   325,   236,   539,   323,   323,   947,   948,   169,     3,
     246,   980,   239,   154,   323,   323,   207,   325,   549,     3,
       4,     5,     6,     7,     8,   323,   557,   325,   324,   325,
     549,   102,   325,    17,    18,   217,   249,   201,   202,   203,
     323,    25,   206,   325,   323,   217,   447,   239,   156,   953,
     323,  1096,   323,   257,   323,   323,   323,   998,   322,    43,
     323,   323,     3,   322,   154,   323,    50,   291,   292,   323,
     634,     3,   323,   304,   305,   306,   324,   323,   323,    63,
      64,    65,   313,  1024,  1025,    26,   280,  1028,   319,   239,
     824,   116,   253,   827,     3,   308,   323,   325,   245,   246,
     247,   248,   306,   128,   335,   323,   261,   324,   324,   323,
     236,   105,   343,    97,   345,   346,   347,   648,   133,   270,
     228,   115,    39,   325,   355,   356,   357,   358,   359,   325,
     325,   662,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   470,   471,   267,   473,   325,   325,
     144,   325,   325,   317,   318,   319,   320,   321,   169,   485,
      18,   325,   323,   327,    81,   156,   324,   182,   699,   412,
     701,   702,   703,   323,   106,   169,    68,   228,   692,   292,
     699,    52,    40,    54,   116,   270,   237,   300,     3,     4,
       5,     6,     7,     8,   635,  1136,   128,   224,    56,   311,
     705,   116,    17,    18,     3,     4,     5,     6,     7,     8,
      25,    17,  1153,    32,   106,     3,   243,    23,    17,    18,
      78,   263,   266,     3,   116,   666,    25,   169,    43,   273,
     274,   207,    51,   207,   166,    50,   280,   228,    26,    32,
     207,    55,   253,  1107,    43,     3,    61,    46,    63,    64,
      65,    50,   236,    68,   323,   326,   308,   326,    51,   490,
     878,   879,   880,    79,    63,    64,    65,     3,   709,    88,
     128,   807,   323,   324,   285,   506,   322,   508,   777,   931,
     312,   313,    97,   935,   803,   784,   323,   786,   940,   326,
     104,   522,   184,    79,   110,    88,   154,     3,    97,   115,
     531,   116,   116,   195,     4,     5,     6,     7,   166,   251,
     252,   253,   254,     3,    13,    14,   208,    16,   323,   550,
     551,   326,   207,   764,   110,   856,   557,   207,   144,   115,
     222,     3,   131,   317,   318,   319,   320,   321,   114,   125,
       8,   325,   161,   327,   270,   116,     3,     4,     5,     6,
       7,     8,   166,   861,   862,   863,   175,   249,   144,   323,
      17,    18,   326,   289,   222,   264,   265,   763,    25,   184,
     869,   207,   298,   114,   961,   962,    33,   876,   275,   276,
      37,   323,   256,   257,   323,   259,    43,   326,   975,    62,
     977,     3,   207,    50,    24,    25,    26,    27,    28,    29,
      30,   632,   323,     8,     3,   326,    63,    64,    65,   207,
     711,   712,    10,    11,    12,    13,    14,    15,    16,   218,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    26,    27,    28,    29,    30,   616,   617,
      97,   672,   673,    34,   323,   118,   159,   326,   323,   680,
     323,   326,   683,   326,   127,   281,   125,     3,   273,   274,
     133,   323,   323,   207,   326,   326,   281,     3,   323,   700,
      61,   326,   287,   288,     3,   290,   291,   292,   293,   152,
     295,   296,   297,     8,   299,   300,   301,   207,   323,    80,
     323,   326,   323,   326,    20,   326,   102,    88,   263,   314,
     315,   316,   317,   318,   319,   320,   321,     9,   904,   182,
     325,   323,   327,   323,   326,     3,   107,   325,   317,   318,
     319,   320,   321,   105,  1097,   116,   325,  1100,   327,   323,
     121,   323,   326,   206,   326,    29,   193,   257,    32,     3,
     292,     3,     4,     5,     6,     7,     8,   190,    14,     3,
     270,   294,   102,   134,   292,    17,    18,   105,   270,   325,
    1004,   281,   325,    25,    26,   325,   325,   291,  1012,   800,
    1014,   291,   292,   804,  1018,   325,  1020,     3,     3,    36,
     207,    43,   258,   303,   304,   305,   323,   818,    50,   105,
       3,   228,   322,     3,   825,   324,   187,    18,     3,     3,
     279,    63,    64,    65,    10,    11,    12,    13,    14,    15,
      16,     3,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   323,     3,   858,   324,    97,
       3,     3,   156,   864,   225,    97,   323,   868,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       3,     3,     4,     5,     6,     7,     8,     3,   889,  1055,
     317,   318,   319,   320,   321,    17,    18,     3,   325,   258,
     327,   323,   323,    25,  1005,  1006,   907,  1008,  1009,  1010,
    1124,  1125,  1013,  1127,  1015,   217,  1017,   323,  1019,     3,
       3,    43,     3,     4,     5,     6,     7,     8,    50,     8,
      20,   271,     8,     3,   325,     3,    17,    18,     3,     3,
     187,    63,    64,    65,    25,     3,     8,     4,     3,     3,
       4,     5,     6,     7,     8,    14,   105,   267,   326,   325,
      38,     3,    43,    17,    18,   258,   323,   323,     3,    50,
       3,    25,    97,    47,     3,    97,   228,   978,   979,    26,
       3,     8,    63,    64,    65,     3,   324,   324,   159,    43,
     324,   159,   993,   994,   325,     3,    50,    78,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    63,
      64,    65,     3,     3,     3,     8,    97,     3,     4,     5,
       6,     7,     8,     8,    78,   280,   324,   324,   272,    30,
       3,    17,    18,   324,   326,  1036,   326,   326,   326,    25,
       3,   326,   325,    97,  1045,  1046,   325,  1048,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    43,     3,     4,
       5,     6,     7,     8,    50,   187,   325,     3,   325,   163,
     326,   127,    17,    18,     3,   115,     3,    63,    64,    65,
      25,     3,   174,   265,     3,   317,   318,   319,   320,   321,
       4,     4,    78,   325,   323,   327,     3,   170,    43,   190,
      55,  1102,  1103,  1104,  1105,    50,    47,   323,   156,   324,
     161,    97,     3,     3,    26,    26,  1117,     3,    63,    64,
      65,     3,     4,     5,     6,     7,     8,   240,   269,   323,
     217,   217,    26,    78,    26,    17,    18,     3,   325,   127,
     326,   124,   326,    25,   156,   326,   127,   326,     3,     3,
     326,   323,    97,    23,    24,    25,    26,    27,    28,    29,
      30,    43,     3,     4,     5,     6,     7,     8,    50,   139,
     255,     3,   128,     3,   128,     3,    17,    18,     3,     3,
       3,    63,    64,    65,    25,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   317,   318,   319,   320,   321,
       4,     3,    43,   325,    47,   327,   217,   217,   217,    50,
     915,   916,    20,   918,   325,    97,   921,   922,   156,   924,
     925,   926,    63,    64,    65,   930,     3,   932,     3,   934,
       3,   105,     8,   105,   939,   108,   317,   318,   319,   320,
     321,   105,     4,     3,   325,   170,   327,     3,     3,   326,
     128,   326,     3,   157,   326,   326,    97,   326,     3,   326,
     326,    47,   325,   317,   318,   319,   320,   321,   217,   109,
      20,   325,   325,   327,    10,    11,    12,    13,    14,    15,
      16,   325,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   323,   326,   323,     3,   324,
      43,   325,    10,    11,    12,    13,    14,    15,    16,   326,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   325,    20,   325,   325,   325,  1033,   325,
     325,   317,   318,   319,   320,   321,   128,     3,   325,   325,
       3,   327,    10,    11,    12,    13,    14,    15,    16,   325,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   323,   323,     3,     5,   325,     4,   225,
       5,     5,   317,   318,   319,   320,   321,   324,    20,     4,
     325,   128,   327,     3,   326,   154,   326,   159,     3,   183,
      10,    11,    12,    13,    14,    15,    16,   105,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,   125,     5,     4,   323,   323,    36,   978,    38,    39,
     326,   574,   911,   756,   636,   147,  1048,   249,     8,   490,
     785,   950,  1030,   720,   747,   317,   318,   319,   320,   321,
    1098,   394,    62,   325,   478,   327,   217,    21,    18,   433,
     269,    18,    72,    73,    74,    75,   271,   591,   474,   725,
     411,    81,   310,   609,   951,  1016,   688,   320,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,   317,   318,   319,   320,
     321,    -1,   102,    -1,   325,   105,   327,    -1,   108,   109,
      -1,   111,   112,   113,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,   127,    -1,    -1,
      -1,    -1,    -1,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,   156,    -1,    -1,    -1,
      -1,   161,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   182,    10,    11,    12,    13,    14,    15,    16,
     190,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,   206,    -1,    -1,    -1,
     326,   211,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,   323,   236,   237,    -1,   239,
      -1,   241,   242,    10,    11,    12,    13,    14,    15,    16,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   323,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,
      -1,   301,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,    -1,    -1,   326,    -1,    -1,    -1,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,   107,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,   158,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    61,   174,   175,    -1,   177,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,
     190,   191,    80,    34,    35,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      61,    -1,    -1,   223,    -1,   225,    -1,   227,   116,    -1,
      -1,    -1,    61,   121,    -1,    -1,    -1,    -1,    -1,    80,
      81,    82,    -1,    -1,   244,    -1,   323,    88,    -1,    -1,
     250,    80,    -1,    -1,    -1,    -1,    -1,    -1,   258,    88,
     260,   261,   262,    -1,    -1,    -1,   107,   267,   268,    -1,
      -1,    -1,    -1,    -1,    -1,   323,    -1,    -1,   107,    -1,
     121,    -1,   282,   283,   284,   173,   286,   116,    -1,   130,
      -1,    -1,   121,    -1,    -1,   136,    -1,    -1,   139,   187,
      -1,    -1,   302,    -1,    -1,    -1,   323,   307,   308,   309,
     310,    -1,    12,    13,    14,    15,    16,   158,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,   174,   175,    -1,   177,   225,    -1,    -1,
     181,    -1,    -1,    -1,   173,    -1,   187,    -1,    -1,   190,
     191,    10,    11,    12,    13,    14,    15,    16,   187,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,   223,    -1,   225,   295,   227,    -1,    -1,    -1,
      -1,   301,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    72,    73,    74,    75,   258,    -1,   260,
     261,   262,    -1,    -1,    -1,    -1,   267,   268,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,   284,    -1,   286,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,   302,    -1,    -1,    -1,    -1,   307,   308,   309,   310,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    42,    43,    44,    45,    -1,    -1,    13,    14,
      15,    16,    52,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,    -1,    -1,    -1,   146,   147,   148,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
      -1,    -1,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   234,    -1,    -1,    -1,    -1,    -1,
      -1,   241,    -1,    -1,   105,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    16,    94,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,     3,    -1,    -1,    -1,    36,    -1,
      94,    10,    11,    12,    13,    14,    15,    16,    81,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    10,    11,    12,    13,    14,    15,    16,    38,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,    34,    35,    53,    61,    80,    81,    82,    88,   107,
     121,   130,   136,   139,   158,   174,   175,   177,   181,   187,
     190,   191,   223,   225,   227,   244,   250,   258,   260,   261,
     262,   267,   268,   282,   283,   284,   286,   302,   307,   308,
     309,   310,   329,   330,   331,   359,   363,   371,   372,   375,
     377,   384,   385,   386,   392,   398,   399,   401,   404,   406,
     407,   408,   410,   413,   414,   415,   416,   417,   418,   422,
     423,   426,   429,   431,   436,   437,   440,   441,   442,   443,
     445,   447,   449,   450,   452,   454,   455,   457,   458,   464,
     468,   471,   473,   476,   479,   482,    68,   115,   184,   391,
     153,   269,   448,   207,    68,   106,   184,   195,   208,   222,
     249,   380,   393,   360,     3,     3,    68,   116,   184,   249,
     308,   380,    33,    34,    61,    80,    88,   107,   116,   121,
     173,   187,   225,   432,   433,   438,   439,   365,   257,   306,
     472,   116,   270,   448,   267,   207,   249,   365,   432,   438,
     342,     8,   266,   273,   274,   280,   424,   483,   484,     3,
       4,     5,     6,     7,     8,    17,    18,    25,    43,    50,
      61,    63,    64,    65,    68,    97,   116,   184,   207,   281,
     287,   288,   290,   293,   295,   296,   297,   299,   301,   314,
     315,   316,   317,   318,   319,   320,   321,   325,   327,   424,
     459,   463,   481,   270,   365,   373,     3,   481,   491,     3,
     207,   116,   311,   409,   409,   263,     3,   409,   207,   207,
     448,   207,   448,   256,   257,   259,   477,   478,     3,   308,
       3,     0,   330,   322,     3,     3,   207,   207,     3,   402,
     114,   376,   376,     8,   427,   428,   207,   116,     3,   105,
     115,   144,   169,   361,   114,   400,     3,   400,     8,   430,
       3,   207,   281,   159,   325,   367,   367,   367,   156,   323,
     156,   323,    79,   110,   115,   125,   144,   366,   481,   125,
       3,   419,   420,   207,     3,     3,   405,     8,   444,   366,
     156,   156,    26,    33,    84,    85,   110,   201,   202,   203,
     206,   343,   344,   481,     9,    20,    20,   102,   446,   263,
     323,   324,   325,     9,   481,    97,   481,   481,   481,   236,
     481,   495,    68,   184,   207,     3,   325,   105,     3,   292,
     190,    14,   461,     3,   294,   134,   339,   102,   292,   105,
     460,   339,   270,   325,   325,   325,   325,   325,   481,   292,
     300,   270,   289,   298,   291,    10,    11,    12,    13,    14,
      15,    16,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   295,   301,   115,   144,     3,
     325,   345,   346,   347,   350,   358,   323,     3,     3,   465,
     466,    36,   411,   217,   411,   402,   402,   207,   402,   207,
     257,   270,   281,   291,   292,   303,   304,   305,   469,   470,
     258,   323,   105,     3,   228,   480,   322,   488,   488,     3,
     402,   324,   169,   251,   252,   253,   254,   323,   451,    18,
       3,     3,   279,   323,   376,     3,   324,   362,     3,   361,
     105,   323,    97,     3,   156,     3,   323,   400,     3,   341,
       3,    26,    34,    61,    80,    88,   107,   116,   121,   187,
     225,   433,     3,    34,    61,    80,    88,   107,   116,   121,
     187,   225,   439,     3,   258,     3,    38,   349,   323,   402,
     217,   324,   323,   217,   323,     3,     3,    26,     3,   105,
     323,   349,   481,   481,   481,     8,    20,   271,   484,     3,
     491,   492,   481,   325,   481,   495,    91,    94,   236,     3,
       3,     3,   331,     3,   460,   461,     4,   291,   292,   481,
       8,     3,    14,   462,   460,   481,   491,    46,   131,   218,
     491,   493,   481,   481,    26,   481,   326,   461,   461,   460,
     105,   481,   481,   481,   481,   481,     6,    18,   154,   325,
      13,    14,    16,   481,    33,    37,   193,   325,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   324,
     349,   331,   345,   190,   323,    62,   118,   133,   152,   182,
     206,   351,   353,    38,   348,   491,   116,   128,   467,   474,
      16,   323,   264,   265,   174,   264,   412,   267,   412,   217,
     169,   253,   453,   402,   105,     3,   258,   239,   402,   323,
     478,   330,   430,    52,    54,    32,    51,    88,   161,   175,
     387,   388,   390,     3,     3,    97,    47,   428,     3,   228,
     394,    26,   237,   332,   228,   345,     3,     3,     8,   402,
     323,   326,   324,   324,   159,   324,   159,   190,   367,   465,
       3,   144,   170,   240,   421,   420,     3,     3,     3,     8,
       8,   190,   367,   324,   324,   324,   345,   344,   280,   272,
     326,   331,   211,    91,    94,   481,   481,   326,   460,   461,
     323,   481,   461,   105,   326,   326,   481,   323,   323,   326,
     326,   461,     3,     6,   154,   331,   491,   481,   481,   325,
      36,   325,   325,   325,   331,     3,   326,   326,     3,   374,
     346,   133,   182,   354,   347,   127,   163,   352,     3,     3,
     325,   357,   115,   475,     3,     3,   466,   265,   174,     3,
       4,   456,     4,   170,   470,   190,     3,    55,   389,   389,
     104,   116,   166,   389,    47,     3,   217,   323,   324,     4,
     280,   115,   177,   324,   325,   378,   379,   312,   313,   395,
     156,   481,   161,   338,   345,   332,   362,    49,   179,   403,
       3,    26,    26,     3,     3,   370,   232,   331,   240,   269,
     217,   217,   324,   217,   370,   232,   331,    26,    26,     3,
     332,   325,   170,   277,   278,   425,   326,   481,   481,    94,
     211,   481,   481,   105,   124,   494,   494,   460,   326,   326,
     331,   491,   481,   331,   331,   331,   326,   349,    20,   324,
     323,   332,   352,   352,   127,   156,   347,   127,   357,   323,
     255,   467,   169,   253,   285,   139,     3,     3,   106,   116,
     128,   166,   381,   382,     3,   128,   341,   128,     3,     3,
       3,   388,     3,     4,     3,   381,   348,     3,    47,   339,
     332,   217,   217,   217,    20,   156,   323,   364,   325,   368,
     364,     3,     3,     3,     8,   364,   368,   364,   105,   105,
     105,   108,   333,     4,   275,   276,   170,    94,   481,   102,
     326,   491,   481,   326,   326,   461,   326,   326,   326,   326,
     326,   481,     3,     3,   338,   347,   481,   156,   228,   355,
     356,   347,   326,     3,    42,    43,    44,    45,    52,    70,
      71,    76,    87,    95,   101,   122,   123,   141,   142,   146,
     147,   148,   172,   190,   192,   209,   212,   213,   214,   215,
     216,   233,   234,   241,   489,   116,   128,   325,   325,   128,
     323,     3,   341,   325,   378,   326,   331,   325,   334,   481,
     427,   427,   427,    78,   481,   157,     3,    78,   369,   481,
     323,   364,   324,   217,   364,   430,   430,   430,    47,   109,
     337,   326,   481,   326,    72,    73,    74,    75,   111,   112,
     113,   241,   242,    20,    20,   324,   339,   481,   325,   356,
     325,   485,   485,   485,   485,   485,   485,   325,   485,   485,
     485,    43,   486,   485,   486,   485,   325,   485,   486,   485,
     486,   325,   325,   383,   325,   325,   341,   341,   325,   382,
     489,   381,   378,     3,   396,   397,   323,    39,    81,   335,
     239,   434,   434,   434,   128,    20,   323,   326,   325,     3,
       3,   434,   434,   334,   481,   338,   326,   481,   481,     3,
     341,     5,   487,   488,   487,   487,     4,   490,   487,   487,
     487,   488,   487,   488,   487,   490,   487,   488,   487,   488,
       5,     5,    18,    40,    56,    78,   128,   154,   166,   222,
     341,   341,   326,   326,   341,   383,   326,   485,   323,   326,
     481,   107,   245,   246,   247,   248,   435,   225,    78,   481,
      78,   481,   369,   324,   239,   336,   339,    20,   326,   323,
     326,   224,   243,   323,   326,   326,   326,   326,   154,     4,
       4,     5,     6,     7,   128,   128,   325,   326,   326,   326,
     378,   335,   397,   335,   159,   481,   481,   481,   481,   370,
     326,     3,   183,   125,   340,   481,     5,     4,   488,   488,
     488,   341,   341,   326,   326
};


/* Prevent warning if -Wmissing-prototypes.  */
int yyparse (void);

/* Error token number */
#define YYTERROR 1

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */


#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N) ((void) 0)
#endif


#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#define YYLEX yylex ()

YYSTYPE yylval;

YYLTYPE yylloc;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)							     \
   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }	     \
   while (YYID (0))

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			    \
do {									    \
  if (yydebug)								    \
    {									    \
      YYFPRINTF (stderr, "%s ", Title);					    \
      yy_symbol_print (stderr, Type,					    \
		       Value);  \
      YYFPRINTF (stderr, "\n");						    \
    }									    \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
# if (! defined __cplusplus \
      || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
#  define YYSTACKEXPANDABLE 1
# else
#  define YYSTACKEXPANDABLE 0
# endif
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)			\
  do {							\
    if (Yystack->yyspaceLeft < YYHEADROOM)		\
      yyexpandGLRStack (Yystack);			\
  } while (YYID (0))
#else
# define YY_RESERVE_GLRSTACK(Yystack)			\
  do {							\
    if (Yystack->yyspaceLeft < YYHEADROOM)		\
      yyMemoryExhausted (Yystack);			\
  } while (YYID (0))
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef short int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the first token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static void yyFail (yyGLRStack* yystackp, const char* yymsg)
  __attribute__ ((__noreturn__));
static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != NULL)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static void yyMemoryExhausted (yyGLRStack* yystackp)
  __attribute__ ((__noreturn__));
static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  yyGLRState* s;
  int i;
  s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
      YYASSERT (s->yyresolved);
      yyvsp[i].yystate.yyresolved = yytrue;
      yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     __attribute__ ((__unused__));
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
/*ARGSUSED*/ static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
	      YYSTYPE* yyvalp,
	      YYLTYPE* YYOPTIONAL_LOC (yylocp),
	      yyGLRStack* yystackp
	      )
{
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == NULL);
  int yylow;
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)						     \
  return yyerror (YY_("syntax error: cannot back up")),     \
	 yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);

  switch (yyn)
    {
        case 2:

/* Line 936 of glr.c  */
#line 417 "sql.ypp"
    { printf("> \n"); ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node); parsetreeroot = ((*yyvalp).ast_node); /*output($$, 1);*/ ;}
    break;

  case 3:

/* Line 936 of glr.c  */
#line 418 "sql.ypp"
    { printf("> \n");/* $$ = $1;*/ parsetreeroot = ((*yyvalp).ast_node); /*output($$, 1);*/ ;}
    break;

  case 4:

/* Line 936 of glr.c  */
#line 423 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); output(((*yyvalp).ast_node), 1); puts("This is a select statement"); ;}
    break;

  case 5:

/* Line 936 of glr.c  */
#line 428 "sql.ypp"
    {
		((*yyvalp).ast_node) = newQueryStmt(t_query_stmt, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL, NULL, NULL, NULL, NULL, NULL);
		puts("select_stmt1");
	;}
    break;

  case 6:

/* Line 936 of glr.c  */
#line 434 "sql.ypp"
    {
			((*yyvalp).ast_node) = newQueryStmt(t_query_stmt, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (11))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (11))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (11))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (11))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (11))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (11))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (11))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((10) - (11))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (11))].yystate.yysemantics.yysval.ast_node));
			puts("select_stmt2");
		;}
    break;

  case 7:

/* Line 936 of glr.c  */
#line 440 "sql.ypp"
    { ((*yyvalp).ast_node)= NULL; puts("opt_where is null"); ;}
    break;

  case 8:

/* Line 936 of glr.c  */
#line 441 "sql.ypp"
    { ((*yyvalp).ast_node) = newWhereList(t_where_list, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); puts("opt_where");;}
    break;

  case 9:

/* Line 936 of glr.c  */
#line 443 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; puts("opt_groupby is null"); ;}
    break;

  case 10:

/* Line 936 of glr.c  */
#line 445 "sql.ypp"
    {
     	((*yyvalp).ast_node) = newGroupbyList(t_groupby_list, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.intval));
      	puts("opt_groupby");
	;}
    break;

  case 11:

/* Line 936 of glr.c  */
#line 452 "sql.ypp"
    { 
		((*yyvalp).ast_node)=newGroupbyExpr(t_groupby_expr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval), NULL);
		puts("groupby_list1");
	;}
    break;

  case 12:

/* Line 936 of glr.c  */
#line 457 "sql.ypp"
    {
     	((*yyvalp).ast_node)=newGroupbyExpr(t_groupby_expr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node));
     	puts("groupby_list2");
    ;}
    break;

  case 13:

/* Line 936 of glr.c  */
#line 463 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 14:

/* Line 936 of glr.c  */
#line 464 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 15:

/* Line 936 of glr.c  */
#line 465 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 16:

/* Line 936 of glr.c  */
#line 468 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 17:

/* Line 936 of glr.c  */
#line 469 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 18:

/* Line 936 of glr.c  */
#line 472 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; puts("opt_having is null"); ;}
    break;

  case 19:

/* Line 936 of glr.c  */
#line 474 "sql.ypp"
    {
		((*yyvalp).ast_node)=newHavingList(t_having_list, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node));
		puts("opt_having2");
	;}
    break;

  case 20:

/* Line 936 of glr.c  */
#line 480 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; puts("opt_orederby is null"); ;}
    break;

  case 21:

/* Line 936 of glr.c  */
#line 482 "sql.ypp"
    {
		((*yyvalp).ast_node)=newOrderbyList(t_groupby_list, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node));
		puts("opt_orederby2");
	;}
    break;

  case 22:

/* Line 936 of glr.c  */
#line 488 "sql.ypp"
    {((*yyvalp).ast_node) = NULL; puts("opt_limit is null");;}
    break;

  case 23:

/* Line 936 of glr.c  */
#line 490 "sql.ypp"
    {
		((*yyvalp).ast_node)=newLimitExpr(t_limit_expr, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node));
		puts("opt_limit2");
	;}
    break;

  case 24:

/* Line 936 of glr.c  */
#line 495 "sql.ypp"
    {
  		Limit_expr *n=(Limit_expr *)malloc(sizeof(struct Limit_expr));
  		n->type=t_limit_expr;
  		n->offset=(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.ast_node);
  		n->row_count=(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node);
		((*yyvalp).ast_node)=(Node *)n;
	;}
    break;

  case 25:

/* Line 936 of glr.c  */
#line 504 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; puts("opt_into_list is null"); ;}
    break;

  case 26:

/* Line 936 of glr.c  */
#line 505 "sql.ypp"
    {  ;}
    break;

  case 27:

/* Line 936 of glr.c  */
#line 508 "sql.ypp"
    { ((*yyvalp).ast_node) = newColumn(t_column, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval), NULL, NULL); ;}
    break;

  case 28:

/* Line 936 of glr.c  */
#line 509 "sql.ypp"
    { ((*yyvalp).ast_node) = newColumn(t_column, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 29:

/* Line 936 of glr.c  */
#line 512 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 30:

/* Line 936 of glr.c  */
#line 513 "sql.ypp"
    { if(((*yyvalp).intval) & 1) yyerror("duplicate ALL option"); ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 1; ;}
    break;

  case 31:

/* Line 936 of glr.c  */
#line 514 "sql.ypp"
    { if(((*yyvalp).intval) & 2) yyerror("duplicate DISTINCT option"); ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 2; ;}
    break;

  case 32:

/* Line 936 of glr.c  */
#line 515 "sql.ypp"
    { if(((*yyvalp).intval) & 4) yyerror("duplicate DISTINCTROW option"); ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 4; ;}
    break;

  case 33:

/* Line 936 of glr.c  */
#line 516 "sql.ypp"
    { if(((*yyvalp).intval) & 8) yyerror("duplicate HIGH_PRIORITY option"); ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 8; ;}
    break;

  case 34:

/* Line 936 of glr.c  */
#line 517 "sql.ypp"
    { if(((*yyvalp).intval) & 16) yyerror("duplicate STRAIGHT_JOIN option"); ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 16; ;}
    break;

  case 35:

/* Line 936 of glr.c  */
#line 518 "sql.ypp"
    { if(((*yyvalp).intval) & 32) yyerror("duplicate SQL_SMALL_RESULT option"); ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 32; ;}
    break;

  case 36:

/* Line 936 of glr.c  */
#line 519 "sql.ypp"
    { if(((*yyvalp).intval) & 64) yyerror("duplicate SQL_BIG_RESULT option"); ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 64; ;}
    break;

  case 37:

/* Line 936 of glr.c  */
#line 520 "sql.ypp"
    { if(((*yyvalp).intval) & 128) yyerror("duplicate SQL_CALC_FOUND_ROWS option"); ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 128; ;}
    break;

  case 38:

/* Line 936 of glr.c  */
#line 523 "sql.ypp"
    { ((*yyvalp).ast_node) = newSelectList(t_select_list, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); puts("select_expr_list1"); ;}
    break;

  case 39:

/* Line 936 of glr.c  */
#line 524 "sql.ypp"
    { ((*yyvalp).ast_node) = newSelectList(t_select_list, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); puts("select_expr_list2"); ;}
    break;

  case 40:

/* Line 936 of glr.c  */
#line 525 "sql.ypp"
    { ((*yyvalp).ast_node) = newSelectList(t_select_list, 1, NULL, NULL); puts("select_expr_list3"); ;}
    break;

  case 41:

/* Line 936 of glr.c  */
#line 528 "sql.ypp"
    { ((*yyvalp).ast_node) = newSelectExpr(t_select_expr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node)); puts("select_expr"); ;}
    break;

  case 42:

/* Line 936 of glr.c  */
#line 531 "sql.ypp"
    { ((*yyvalp).ast_node)=newFromList(t_from_list, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL, NULL); puts("table_references1"); ;}
    break;

  case 43:

/* Line 936 of glr.c  */
#line 532 "sql.ypp"
    { ((*yyvalp).ast_node)=newFromList(t_from_list, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), NULL); puts("table_references2"); ;}
    break;

  case 44:

/* Line 936 of glr.c  */
#line 535 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);puts("table_referen1"); ;}
    break;

  case 45:

/* Line 936 of glr.c  */
#line 536 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);puts("table_referen2");;}
    break;

  case 46:

/* Line 936 of glr.c  */
#line 541 "sql.ypp"
    {
	    ((*yyvalp).ast_node)=newTable(t_table, NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval), 0, NULL, NULL);
	    puts("table_factor1");
    ;}
    break;

  case 47:

/* Line 936 of glr.c  */
#line 546 "sql.ypp"
    {
		((*yyvalp).ast_node)=newTable(t_table, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval), 0, NULL, NULL);
   		puts("table_factor2");;}
    break;

  case 48:

/* Line 936 of glr.c  */
#line 550 "sql.ypp"
    {
		((*yyvalp).ast_node)=newTable(t_table, NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval), 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), NULL);
		puts("table_factor3");
	;}
    break;

  case 49:

/* Line 936 of glr.c  */
#line 554 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); ;}
    break;

  case 52:

/* Line 936 of glr.c  */
#line 561 "sql.ypp"
    { ((*yyvalp).strval)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval); puts("opt_as_alias1");;}
    break;

  case 53:

/* Line 936 of glr.c  */
#line 562 "sql.ypp"
    { ((*yyvalp).strval)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval); puts("opt_as_alias2");;}
    break;

  case 54:

/* Line 936 of glr.c  */
#line 563 "sql.ypp"
    { ((*yyvalp).strval)=NULL; puts("opt_as_alias3");;}
    break;

  case 55:

/* Line 936 of glr.c  */
#line 579 "sql.ypp"
    {
		((*yyvalp).ast_node)=newJoin(t_join, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node));
	;}
    break;

  case 56:

/* Line 936 of glr.c  */
#line 583 "sql.ypp"
    {
		((*yyvalp).ast_node)=newJoin(t_join, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL);
	;}
    break;

  case 57:

/* Line 936 of glr.c  */
#line 587 "sql.ypp"
    {
		Node *m=newCondition(t_condition, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node));
		((*yyvalp).ast_node)=newJoin(t_join, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), m);
	;}
    break;

  case 58:

/* Line 936 of glr.c  */
#line 592 "sql.ypp"
    {
		((*yyvalp).ast_node)=newJoin(t_join, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.intval)+(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval.ast_node));
    ;}
    break;

  case 59:

/* Line 936 of glr.c  */
#line 596 "sql.ypp"
    {
		((*yyvalp).ast_node)=newJoin(t_join, 32 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), NULL);
	;}
    break;

  case 60:

/* Line 936 of glr.c  */
#line 601 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 61:

/* Line 936 of glr.c  */
#line 602 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 62:

/* Line 936 of glr.c  */
#line 603 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 63:

/* Line 936 of glr.c  */
#line 606 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 64:

/* Line 936 of glr.c  */
#line 607 "sql.ypp"
    {((*yyvalp).intval) = 4; ;}
    break;

  case 65:

/* Line 936 of glr.c  */
#line 610 "sql.ypp"
    { ((*yyvalp).intval) = 8; ;}
    break;

  case 66:

/* Line 936 of glr.c  */
#line 611 "sql.ypp"
    { ((*yyvalp).intval) = 16; ;}
    break;

  case 67:

/* Line 936 of glr.c  */
#line 614 "sql.ypp"
    { ((*yyvalp).intval) = 8 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval); ;}
    break;

  case 68:

/* Line 936 of glr.c  */
#line 615 "sql.ypp"
    { ((*yyvalp).intval) = 16 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval); ;}
    break;

  case 69:

/* Line 936 of glr.c  */
#line 616 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 71:

/* Line 936 of glr.c  */
#line 620 "sql.ypp"
    {((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);;}
    break;

  case 72:

/* Line 936 of glr.c  */
#line 628 "sql.ypp"
    {
    	((*yyvalp).ast_node)=newCondition(t_condition, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node));
    ;}
    break;

  case 73:

/* Line 936 of glr.c  */
#line 632 "sql.ypp"
    {
    	((*yyvalp).ast_node)=newCondition(t_condition, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node));
    ;}
    break;

  case 74:

/* Line 936 of glr.c  */
#line 651 "sql.ypp"
    { emit("INDEX %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval));  ;}
    break;

  case 75:

/* Line 936 of glr.c  */
#line 652 "sql.ypp"
    { emit("INDEX %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 76:

/* Line 936 of glr.c  */
#line 655 "sql.ypp"
    {  ;}
    break;

  case 77:

/* Line 936 of glr.c  */
#line 660 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 78:

/* Line 936 of glr.c  */
#line 665 "sql.ypp"
    { emit("DELETEONE %d %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)); free((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 79:

/* Line 936 of glr.c  */
#line 668 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node) + 01; ;}
    break;

  case 80:

/* Line 936 of glr.c  */
#line 669 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node) + 02; ;}
    break;

  case 81:

/* Line 936 of glr.c  */
#line 670 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node) + 04; ;}
    break;

  case 82:

/* Line 936 of glr.c  */
#line 671 "sql.ypp"
    { ((*yyvalp).ast_node) = 0; ;}
    break;

  case 83:

/* Line 936 of glr.c  */
#line 677 "sql.ypp"
    {  ;}
    break;

  case 84:

/* Line 936 of glr.c  */
#line 679 "sql.ypp"
    {  ;}
    break;

  case 85:

/* Line 936 of glr.c  */
#line 680 "sql.ypp"
    {  ;}
    break;

  case 88:

/* Line 936 of glr.c  */
#line 688 "sql.ypp"
    { emit("DELETEMULTI %d %d %d", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 89:

/* Line 936 of glr.c  */
#line 693 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 90:

/* Line 936 of glr.c  */
#line 699 "sql.ypp"
    { emit("INSERTVALS %d %d %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.strval)); free((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.strval)) ;}
    break;

  case 92:

/* Line 936 of glr.c  */
#line 703 "sql.ypp"
    { emit("DUPUPDATE %d", (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 93:

/* Line 936 of glr.c  */
#line 706 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 94:

/* Line 936 of glr.c  */
#line 707 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 01 ; ;}
    break;

  case 95:

/* Line 936 of glr.c  */
#line 708 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 02 ; ;}
    break;

  case 96:

/* Line 936 of glr.c  */
#line 709 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 04 ; ;}
    break;

  case 97:

/* Line 936 of glr.c  */
#line 710 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 010 ; ;}
    break;

  case 101:

/* Line 936 of glr.c  */
#line 717 "sql.ypp"
    {  ;}
    break;

  case 108:

/* Line 936 of glr.c  */
#line 733 "sql.ypp"
    { emit("INSERTASGN %d %d %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)); free((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)) ;}
    break;

  case 109:

/* Line 936 of glr.c  */
#line 738 "sql.ypp"
    { emit("INSERTSELECT %d %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)); free((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 114:

/* Line 936 of glr.c  */
#line 757 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 115:

/* Line 936 of glr.c  */
#line 763 "sql.ypp"
    { emit("REPLACEVALS %d %d %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.strval)); free((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.strval)) ;}
    break;

  case 116:

/* Line 936 of glr.c  */
#line 769 "sql.ypp"
    { emit("REPLACEASGN %d %d %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)); free((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)) ;}
    break;

  case 117:

/* Line 936 of glr.c  */
#line 774 "sql.ypp"
    { emit("REPLACESELECT %d %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)); free((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 118:

/* Line 936 of glr.c  */
#line 778 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 119:

/* Line 936 of glr.c  */
#line 785 "sql.ypp"
    { emit("UPDATE %d %d %d", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 123:

/* Line 936 of glr.c  */
#line 795 "sql.ypp"
    {
		/*
		if ($2 != 4 || $3->data.string_val == NULL) 
			yyerror("bad insert assignment to %s", $1);
	 	emit("ASSIGN %s", $1); 
	 	free($3); 
	 	$$ = $3->data.string_val;
	 	*/ 
	;}
    break;

  case 124:

/* Line 936 of glr.c  */
#line 805 "sql.ypp"
    { 
	/*
		if ($4 != 4) 
			yyerror("bad insert assignment to %s", $1); 
		emit("ASSIGN %s.%s", $1, $3);
		free($1); 
		free($3); 
		$$ = 1;
	*/
	;}
    break;

  case 127:

/* Line 936 of glr.c  */
#line 826 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); output(((*yyvalp).ast_node), 1); puts("This is a create_database statement"); ;}
    break;

  case 128:

/* Line 936 of glr.c  */
#line 831 "sql.ypp"
    { ((*yyvalp).ast_node) =  newCreateDatabaseStmt(t_create_database_stmt, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 129:

/* Line 936 of glr.c  */
#line 833 "sql.ypp"
    { ((*yyvalp).ast_node) =  newCreateDatabaseStmt(t_create_database_stmt, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 130:

/* Line 936 of glr.c  */
#line 836 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 131:

/* Line 936 of glr.c  */
#line 837 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 132:

/* Line 936 of glr.c  */
#line 842 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); output(((*yyvalp).ast_node), 1); puts("This is a create_table statement"); ;}
    break;

  case 133:

/* Line 936 of glr.c  */
#line 846 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateTableStmt(t_create_table_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.strval), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node), NULL); ;}
    break;

  case 134:

/* Line 936 of glr.c  */
#line 850 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateTableStmt(t_create_table_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (10))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (10))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (10))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (10))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (10))].yystate.yysemantics.yysval.ast_node), NULL); ;}
    break;

  case 135:

/* Line 936 of glr.c  */
#line 855 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateTableStmt(t_create_table_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (9))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (9))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval.strval), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 136:

/* Line 936 of glr.c  */
#line 859 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateTableStmt(t_create_table_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.strval), NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 137:

/* Line 936 of glr.c  */
#line 864 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateTableStmt(t_create_table_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (11))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (11))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (11))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (11))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (11))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (11))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 138:

/* Line 936 of glr.c  */
#line 869 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateTableStmt(t_create_table_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.strval), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (8))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 139:

/* Line 936 of glr.c  */
#line 874 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateSelectStmt(t_create_select_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.intval), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 140:

/* Line 936 of glr.c  */
#line 877 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 141:

/* Line 936 of glr.c  */
#line 878 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 142:

/* Line 936 of glr.c  */
#line 879 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 143:

/* Line 936 of glr.c  */
#line 882 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 144:

/* Line 936 of glr.c  */
#line 883 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 145:

/* Line 936 of glr.c  */
#line 886 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateColList(t_create_col_list, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); ;}
    break;

  case 146:

/* Line 936 of glr.c  */
#line 887 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateColList(t_create_col_list, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 147:

/* Line 936 of glr.c  */
#line 891 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateDef( t_create_def, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL); ;}
    break;

  case 148:

/* Line 936 of glr.c  */
#line 892 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateDef( t_create_def, 2, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 149:

/* Line 936 of glr.c  */
#line 893 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateDef( t_create_def, 3, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 150:

/* Line 936 of glr.c  */
#line 894 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateDef( t_create_def, 4, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 151:

/* Line 936 of glr.c  */
#line 895 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateDef( t_create_def, 5, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 152:

/* Line 936 of glr.c  */
#line 896 "sql.ypp"
    { ((*yyvalp).ast_node) = newCreateDef( t_create_def, 6, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 153:

/* Line 936 of glr.c  */
#line 899 "sql.ypp"
    { ((*yyvalp).ast_node) = newColumnAtts(t_column_atts, 0, 0, 0, NULL, NULL); ;}
    break;

  case 154:

/* Line 936 of glr.c  */
#line 900 "sql.ypp"
    { Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node);t->datatype += 01; ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 155:

/* Line 936 of glr.c  */
#line 901 "sql.ypp"
    { Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node);t->datatype += 02; ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 156:

/* Line 936 of glr.c  */
#line 902 "sql.ypp"
    {  Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node);t->datatype += 04; t->s = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval); ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 157:

/* Line 936 of glr.c  */
#line 903 "sql.ypp"
    {  Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node);t->datatype += 010; t->num1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval); ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 158:

/* Line 936 of glr.c  */
#line 904 "sql.ypp"
    {  Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node);t->datatype += 020; t->num2 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.floatval); ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 159:

/* Line 936 of glr.c  */
#line 905 "sql.ypp"
    {  Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node);t->datatype += 040; t->num1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval); ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 160:

/* Line 936 of glr.c  */
#line 906 "sql.ypp"
    {  Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node);t->datatype += 0100; ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 161:

/* Line 936 of glr.c  */
#line 907 "sql.ypp"
    {  Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node);t->datatype += 0200; ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 162:

/* Line 936 of glr.c  */
#line 908 "sql.ypp"
    {  Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node);t->datatype += 0400; ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 163:

/* Line 936 of glr.c  */
#line 909 "sql.ypp"
    {  Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node);t->datatype += 01000; ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 164:

/* Line 936 of glr.c  */
#line 910 "sql.ypp"
    {  Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node);t->datatype += 02000; ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 165:

/* Line 936 of glr.c  */
#line 911 "sql.ypp"
    {  Column_atts *t = (Column_atts *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node);t->datatype += 04000; t->col_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node); ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 166:

/* Line 936 of glr.c  */
#line 920 "sql.ypp"
    { ((*yyvalp).ast_node) = newDoStmt(t_do_stmt,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); puts("This is a do expr statement"); ;}
    break;

  case 167:

/* Line 936 of glr.c  */
#line 924 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); puts("This is a truncate_stmt statement"); ;}
    break;

  case 168:

/* Line 936 of glr.c  */
#line 927 "sql.ypp"
    { ((*yyvalp).ast_node) = newTruncateStmt(t_truncate_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 169:

/* Line 936 of glr.c  */
#line 928 "sql.ypp"
    { ((*yyvalp).ast_node) = newTruncateStmt(t_truncate_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 170:

/* Line 936 of glr.c  */
#line 932 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); output(((*yyvalp).ast_node), 1); puts("This is a alter_database statement"); ;}
    break;

  case 171:

/* Line 936 of glr.c  */
#line 936 "sql.ypp"
    { ((*yyvalp).ast_node) = newAlterDBStmt(t_alter_database_stmt, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 172:

/* Line 936 of glr.c  */
#line 937 "sql.ypp"
    { ((*yyvalp).ast_node) = newAlterDBStmt(t_alter_database_stmt, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 173:

/* Line 936 of glr.c  */
#line 941 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); output(((*yyvalp).ast_node), 1); puts("This is a alter_table statement"); ;}
    break;

  case 174:

/* Line 936 of glr.c  */
#line 946 "sql.ypp"
    { ((*yyvalp).ast_node) = newAlterTableStmt(t_alter_table_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 175:

/* Line 936 of glr.c  */
#line 947 "sql.ypp"
    { ((*yyvalp).ast_node) = newAlterTableStmt(t_alter_table_stmt, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 178:

/* Line 936 of glr.c  */
#line 956 "sql.ypp"
    {;}
    break;

  case 179:

/* Line 936 of glr.c  */
#line 957 "sql.ypp"
    {;}
    break;

  case 184:

/* Line 936 of glr.c  */
#line 964 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 185:

/* Line 936 of glr.c  */
#line 965 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 187:

/* Line 936 of glr.c  */
#line 969 "sql.ypp"
    {;}
    break;

  case 188:

/* Line 936 of glr.c  */
#line 970 "sql.ypp"
    {;}
    break;

  case 190:

/* Line 936 of glr.c  */
#line 974 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 191:

/* Line 936 of glr.c  */
#line 975 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 192:

/* Line 936 of glr.c  */
#line 979 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 194:

/* Line 936 of glr.c  */
#line 986 "sql.ypp"
    { ((*yyvalp).intval) = 0;;}
    break;

  case 195:

/* Line 936 of glr.c  */
#line 987 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 196:

/* Line 936 of glr.c  */
#line 988 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 197:

/* Line 936 of glr.c  */
#line 989 "sql.ypp"
    { ((*yyvalp).intval) = 3; ;}
    break;

  case 200:

/* Line 936 of glr.c  */
#line 996 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 201:

/* Line 936 of glr.c  */
#line 997 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 205:

/* Line 936 of glr.c  */
#line 1008 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 207:

/* Line 936 of glr.c  */
#line 1015 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 208:

/* Line 936 of glr.c  */
#line 1019 "sql.ypp"
    { emit("DROPDATABASE %d %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); free((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 209:

/* Line 936 of glr.c  */
#line 1020 "sql.ypp"
    { emit("DROPSCHEMA %d %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); free((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 210:

/* Line 936 of glr.c  */
#line 1023 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 211:

/* Line 936 of glr.c  */
#line 1024 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 212:

/* Line 936 of glr.c  */
#line 1028 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 213:

/* Line 936 of glr.c  */
#line 1031 "sql.ypp"
    { emit("DROP %d %d %d %d", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval.intval)); ;}
    break;

  case 214:

/* Line 936 of glr.c  */
#line 1034 "sql.ypp"
    { emit("TABLE %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval));;}
    break;

  case 215:

/* Line 936 of glr.c  */
#line 1035 "sql.ypp"
    { emit("TABLE %s.%s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 216:

/* Line 936 of glr.c  */
#line 1036 "sql.ypp"
    { emit("TABLE %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.intval));;}
    break;

  case 217:

/* Line 936 of glr.c  */
#line 1037 "sql.ypp"
    { emit("TABLE %s.%s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval)); ;}
    break;

  case 218:

/* Line 936 of glr.c  */
#line 1040 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 219:

/* Line 936 of glr.c  */
#line 1041 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 220:

/* Line 936 of glr.c  */
#line 1042 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 221:

/* Line 936 of glr.c  */
#line 1047 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 222:

/* Line 936 of glr.c  */
#line 1050 "sql.ypp"
    {;}
    break;

  case 224:

/* Line 936 of glr.c  */
#line 1054 "sql.ypp"
    {;}
    break;

  case 225:

/* Line 936 of glr.c  */
#line 1055 "sql.ypp"
    {;}
    break;

  case 226:

/* Line 936 of glr.c  */
#line 1056 "sql.ypp"
    {;}
    break;

  case 227:

/* Line 936 of glr.c  */
#line 1057 "sql.ypp"
    {;}
    break;

  case 228:

/* Line 936 of glr.c  */
#line 1061 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 229:

/* Line 936 of glr.c  */
#line 1064 "sql.ypp"
    {;}
    break;

  case 230:

/* Line 936 of glr.c  */
#line 1065 "sql.ypp"
    {;}
    break;

  case 231:

/* Line 936 of glr.c  */
#line 1069 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 232:

/* Line 936 of glr.c  */
#line 1072 "sql.ypp"
    {;}
    break;

  case 233:

/* Line 936 of glr.c  */
#line 1076 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 234:

/* Line 936 of glr.c  */
#line 1077 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 235:

/* Line 936 of glr.c  */
#line 1078 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 240:

/* Line 936 of glr.c  */
#line 1089 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 241:

/* Line 936 of glr.c  */
#line 1092 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 242:

/* Line 936 of glr.c  */
#line 1093 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 243:

/* Line 936 of glr.c  */
#line 1094 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 244:

/* Line 936 of glr.c  */
#line 1097 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 245:

/* Line 936 of glr.c  */
#line 1098 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 246:

/* Line 936 of glr.c  */
#line 1099 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 247:

/* Line 936 of glr.c  */
#line 1102 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 248:

/* Line 936 of glr.c  */
#line 1106 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 256:

/* Line 936 of glr.c  */
#line 1129 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 261:

/* Line 936 of glr.c  */
#line 1142 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 262:

/* Line 936 of glr.c  */
#line 1143 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 263:

/* Line 936 of glr.c  */
#line 1144 "sql.ypp"
    { ((*yyvalp).intval) = 3; ;}
    break;

  case 264:

/* Line 936 of glr.c  */
#line 1145 "sql.ypp"
    { ((*yyvalp).intval) = 4; ;}
    break;

  case 269:

/* Line 936 of glr.c  */
#line 1163 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 270:

/* Line 936 of glr.c  */
#line 1164 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 271:

/* Line 936 of glr.c  */
#line 1165 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 272:

/* Line 936 of glr.c  */
#line 1169 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 273:

/* Line 936 of glr.c  */
#line 1170 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 274:

/* Line 936 of glr.c  */
#line 1171 "sql.ypp"
    { ((*yyvalp).intval) = 3; ;}
    break;

  case 275:

/* Line 936 of glr.c  */
#line 1172 "sql.ypp"
    { ((*yyvalp).intval) = 4; ;}
    break;

  case 276:

/* Line 936 of glr.c  */
#line 1176 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 283:

/* Line 936 of glr.c  */
#line 1192 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 287:

/* Line 936 of glr.c  */
#line 1203 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 291:

/* Line 936 of glr.c  */
#line 1214 "sql.ypp"
    { ((*yyvalp).intval) = 01; ;}
    break;

  case 292:

/* Line 936 of glr.c  */
#line 1215 "sql.ypp"
    { ((*yyvalp).intval) = 02; ;}
    break;

  case 293:

/* Line 936 of glr.c  */
#line 1216 "sql.ypp"
    { ((*yyvalp).intval) = 04; ;}
    break;

  case 294:

/* Line 936 of glr.c  */
#line 1217 "sql.ypp"
    { ((*yyvalp).intval) = 010; ;}
    break;

  case 295:

/* Line 936 of glr.c  */
#line 1218 "sql.ypp"
    { ((*yyvalp).intval) = 020; ;}
    break;

  case 296:

/* Line 936 of glr.c  */
#line 1219 "sql.ypp"
    { ((*yyvalp).intval) = 040; ;}
    break;

  case 297:

/* Line 936 of glr.c  */
#line 1220 "sql.ypp"
    { ((*yyvalp).intval) = 0100; ;}
    break;

  case 298:

/* Line 936 of glr.c  */
#line 1221 "sql.ypp"
    { ((*yyvalp).intval) = 0200; ;}
    break;

  case 299:

/* Line 936 of glr.c  */
#line 1222 "sql.ypp"
    { ((*yyvalp).intval) = 0400; ;}
    break;

  case 300:

/* Line 936 of glr.c  */
#line 1223 "sql.ypp"
    { ((*yyvalp).intval) = 01000; ;}
    break;

  case 301:

/* Line 936 of glr.c  */
#line 1224 "sql.ypp"
    { ((*yyvalp).intval) = 02000; ;}
    break;

  case 302:

/* Line 936 of glr.c  */
#line 1225 "sql.ypp"
    { ((*yyvalp).intval) = 04000; ;}
    break;

  case 310:

/* Line 936 of glr.c  */
#line 1241 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 312:

/* Line 936 of glr.c  */
#line 1248 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 325:

/* Line 936 of glr.c  */
#line 1277 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 327:

/* Line 936 of glr.c  */
#line 1283 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 329:

/* Line 936 of glr.c  */
#line 1289 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 331:

/* Line 936 of glr.c  */
#line 1296 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 335:

/* Line 936 of glr.c  */
#line 1308 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 339:

/* Line 936 of glr.c  */
#line 1319 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 341:

/* Line 936 of glr.c  */
#line 1325 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 342:

/* Line 936 of glr.c  */
#line 1326 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 343:

/* Line 936 of glr.c  */
#line 1327 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 344:

/* Line 936 of glr.c  */
#line 1331 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 346:

/* Line 936 of glr.c  */
#line 1338 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 348:

/* Line 936 of glr.c  */
#line 1344 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 349:

/* Line 936 of glr.c  */
#line 1345 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 350:

/* Line 936 of glr.c  */
#line 1346 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 351:

/* Line 936 of glr.c  */
#line 1347 "sql.ypp"
    { ((*yyvalp).intval) = 3; ;}
    break;

  case 352:

/* Line 936 of glr.c  */
#line 1348 "sql.ypp"
    { ((*yyvalp).intval) = 4; ;}
    break;

  case 353:

/* Line 936 of glr.c  */
#line 1349 "sql.ypp"
    { ((*yyvalp).intval) = 5; ;}
    break;

  case 354:

/* Line 936 of glr.c  */
#line 1353 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 356:

/* Line 936 of glr.c  */
#line 1359 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 357:

/* Line 936 of glr.c  */
#line 1360 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 358:

/* Line 936 of glr.c  */
#line 1361 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 359:

/* Line 936 of glr.c  */
#line 1365 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 361:

/* Line 936 of glr.c  */
#line 1372 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 367:

/* Line 936 of glr.c  */
#line 1385 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 397:

/* Line 936 of glr.c  */
#line 1424 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 398:

/* Line 936 of glr.c  */
#line 1425 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 413:

/* Line 936 of glr.c  */
#line 1459 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 414:

/* Line 936 of glr.c  */
#line 1460 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 415:

/* Line 936 of glr.c  */
#line 1461 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 420:

/* Line 936 of glr.c  */
#line 1475 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 421:

/* Line 936 of glr.c  */
#line 1476 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 422:

/* Line 936 of glr.c  */
#line 1477 "sql.ypp"
    { ((*yyvalp).intval) = 04; ;}
    break;

  case 423:

/* Line 936 of glr.c  */
#line 1478 "sql.ypp"
    { ((*yyvalp).intval) = 010; ;}
    break;

  case 424:

/* Line 936 of glr.c  */
#line 1479 "sql.ypp"
    { ((*yyvalp).intval) = 020; ;}
    break;

  case 425:

/* Line 936 of glr.c  */
#line 1480 "sql.ypp"
    { ((*yyvalp).intval) = 040; ;}
    break;

  case 426:

/* Line 936 of glr.c  */
#line 1481 "sql.ypp"
    { ((*yyvalp).intval) = 0100; ;}
    break;

  case 427:

/* Line 936 of glr.c  */
#line 1482 "sql.ypp"
    { ((*yyvalp).intval) = 0200; ;}
    break;

  case 428:

/* Line 936 of glr.c  */
#line 1483 "sql.ypp"
    { ((*yyvalp).intval) = 0400; ;}
    break;

  case 429:

/* Line 936 of glr.c  */
#line 1484 "sql.ypp"
    { ((*yyvalp).intval) = 01000; ;}
    break;

  case 432:

/* Line 936 of glr.c  */
#line 1494 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 433:

/* Line 936 of glr.c  */
#line 1495 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 434:

/* Line 936 of glr.c  */
#line 1496 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 445:

/* Line 936 of glr.c  */
#line 1527 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 446:

/* Line 936 of glr.c  */
#line 1528 "sql.ypp"
    { ((*yyvalp).intval) = 2; ;}
    break;

  case 447:

/* Line 936 of glr.c  */
#line 1529 "sql.ypp"
    { ((*yyvalp).intval) = 3; ;}
    break;

  case 456:

/* Line 936 of glr.c  */
#line 1554 "sql.ypp"
    { emit("STMT"); ;}
    break;

  case 460:

/* Line 936 of glr.c  */
#line 1563 "sql.ypp"
    { if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.subtok) != 4) yyerror("bad set to @%s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval));
		emit("SET %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)); free((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval));
	;}
    break;

  case 461:

/* Line 936 of glr.c  */
#line 1567 "sql.ypp"
    {
    	emit("SET %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)); 
    	free((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)); 
    ;}
    break;

  case 462:

/* Line 936 of glr.c  */
#line 1574 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; ;}
    break;

  case 463:

/* Line 936 of glr.c  */
#line 1575 "sql.ypp"
    { ((*yyvalp).ast_node) = newLength (t_length, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), 0); ;}
    break;

  case 464:

/* Line 936 of glr.c  */
#line 1576 "sql.ypp"
    { ((*yyvalp).ast_node) = newLength (t_length, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.intval)); ;}
    break;

  case 465:

/* Line 936 of glr.c  */
#line 1579 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 466:

/* Line 936 of glr.c  */
#line 1580 "sql.ypp"
    { ((*yyvalp).intval) = 1; ;}
    break;

  case 467:

/* Line 936 of glr.c  */
#line 1583 "sql.ypp"
    { ((*yyvalp).intval) = 0; ;}
    break;

  case 468:

/* Line 936 of glr.c  */
#line 1584 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 01; ;}
    break;

  case 469:

/* Line 936 of glr.c  */
#line 1585 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 02; ;}
    break;

  case 470:

/* Line 936 of glr.c  */
#line 1588 "sql.ypp"
    { ((*yyvalp).ast_node) =newOptCsc(t_opt_csc, 0, NULL, NULL);;}
    break;

  case 471:

/* Line 936 of glr.c  */
#line 1590 "sql.ypp"
    { Opt_csc * t = (Opt_csc *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node); t->datatype = t->datatype | 01; t->s1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval); ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 472:

/* Line 936 of glr.c  */
#line 1592 "sql.ypp"
    { Opt_csc * t = (Opt_csc *)(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node); t->datatype = t->datatype | 02; t->s2 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval); ((*yyvalp).ast_node) = (Node *)t; ;}
    break;

  case 473:

/* Line 936 of glr.c  */
#line 1596 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 01, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node), 0, NULL, 0, NULL); ;}
    break;

  case 474:

/* Line 936 of glr.c  */
#line 1597 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 02, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); ;}
    break;

  case 475:

/* Line 936 of glr.c  */
#line 1598 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 04, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); ;}
    break;

  case 476:

/* Line 936 of glr.c  */
#line 1599 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 010, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); ;}
    break;

  case 477:

/* Line 936 of glr.c  */
#line 1600 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 020, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); ;}
    break;

  case 478:

/* Line 936 of glr.c  */
#line 1601 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 040, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); ;}
    break;

  case 479:

/* Line 936 of glr.c  */
#line 1602 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 0100, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); ;}
    break;

  case 480:

/* Line 936 of glr.c  */
#line 1603 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 0200, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); ;}
    break;

  case 481:

/* Line 936 of glr.c  */
#line 1604 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 0400, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); ;}
    break;

  case 482:

/* Line 936 of glr.c  */
#line 1605 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 01000, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); ;}
    break;

  case 483:

/* Line 936 of glr.c  */
#line 1606 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 02000, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); ;}
    break;

  case 484:

/* Line 936 of glr.c  */
#line 1607 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 04000, NULL, 0, NULL, 0, NULL); ;}
    break;

  case 485:

/* Line 936 of glr.c  */
#line 1608 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 010000, NULL, 0, NULL, 0, NULL); ;}
    break;

  case 486:

/* Line 936 of glr.c  */
#line 1609 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 020000, NULL, 0, NULL, 0, NULL); ;}
    break;

  case 487:

/* Line 936 of glr.c  */
#line 1610 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 040000, NULL, 0, NULL, 0, NULL); ;}
    break;

  case 488:

/* Line 936 of glr.c  */
#line 1611 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 0100000, NULL, 0, NULL, 0, NULL); ;}
    break;

  case 489:

/* Line 936 of glr.c  */
#line 1612 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 0200000, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), 0, NULL); ;}
    break;

  case 490:

/* Line 936 of glr.c  */
#line 1613 "sql.ypp"
    { Node * t = newLength(t_datatype, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.intval), NULL);
					((*yyvalp).ast_node) = newDatatype (t_datatype, 0400000, t, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), 0, NULL); ;}
    break;

  case 491:

/* Line 936 of glr.c  */
#line 1615 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 01000000, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node), 0, NULL, 0, NULL); ;}
    break;

  case 492:

/* Line 936 of glr.c  */
#line 1616 "sql.ypp"
    {  Node * t = newLength(t_datatype, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), NULL);
				((*yyvalp).ast_node) = newDatatype (t_datatype, 02000000, NULL, 0, NULL, 0, NULL); ;}
    break;

  case 493:

/* Line 936 of glr.c  */
#line 1618 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 04000000, NULL, 0, NULL, 0, NULL); ;}
    break;

  case 494:

/* Line 936 of glr.c  */
#line 1619 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 010000000, NULL, 0, NULL, 0, NULL); ;}
    break;

  case 495:

/* Line 936 of glr.c  */
#line 1620 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 020000000, NULL, 0, NULL, 0, NULL); ;}
    break;

  case 496:

/* Line 936 of glr.c  */
#line 1621 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 040000000, NULL, 0, NULL, 0, NULL); ;}
    break;

  case 497:

/* Line 936 of glr.c  */
#line 1622 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 0100000000, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); ;}
    break;

  case 498:

/* Line 936 of glr.c  */
#line 1623 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 0200000000, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); ;}
    break;

  case 499:

/* Line 936 of glr.c  */
#line 1624 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 0400000000, NULL,0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); ;}
    break;

  case 500:

/* Line 936 of glr.c  */
#line 1625 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 01000000000,NULL,0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); ;}
    break;

  case 501:

/* Line 936 of glr.c  */
#line 1626 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 02000000000, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 502:

/* Line 936 of glr.c  */
#line 1627 "sql.ypp"
    { ((*yyvalp).ast_node) = newDatatype (t_datatype, 04000000000, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 503:

/* Line 936 of glr.c  */
#line 1630 "sql.ypp"
    { ((*yyvalp).ast_node) = newEnumList( t_enum_list, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval), NULL); ;}
    break;

  case 504:

/* Line 936 of glr.c  */
#line 1631 "sql.ypp"
    { ((*yyvalp).ast_node) = newEnumList( t_enum_list, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 505:

/* Line 936 of glr.c  */
#line 1637 "sql.ypp"
    { dataval d; d.string_val = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval); ((*yyvalp).ast_node) = newExpr(t_name, d);  puts("expr1");;}
    break;

  case 506:

/* Line 936 of glr.c  */
#line 1638 "sql.ypp"
    { dataval d; d.string_val = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval); ((*yyvalp).ast_node) = newExpr(t_name, d); ;}
    break;

  case 507:

/* Line 936 of glr.c  */
#line 1639 "sql.ypp"
    { ((*yyvalp).ast_node) = newColumn(t_name_name, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval), NULL); puts("expr2");;}
    break;

  case 508:

/* Line 936 of glr.c  */
#line 1640 "sql.ypp"
    { dataval d; d.string_val = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval); ((*yyvalp).ast_node) = newExpr(t_stringval, d); puts("expr3");;}
    break;

  case 509:

/* Line 936 of glr.c  */
#line 1641 "sql.ypp"
    { dataval d; d.int_val=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.intval); ((*yyvalp).ast_node) = newExpr(t_intnum, d); puts("expr4");;}
    break;

  case 510:

/* Line 936 of glr.c  */
#line 1642 "sql.ypp"
    { dataval d; d.double_val = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.floatval); ((*yyvalp).ast_node) = newExpr(t_approxnum, d); ;}
    break;

  case 511:

/* Line 936 of glr.c  */
#line 1643 "sql.ypp"
    { dataval d; d.bool_val = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.intval); ((*yyvalp).ast_node) = newExpr(t_bool, d); ;}
    break;

  case 512:

/* Line 936 of glr.c  */
#line 1646 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "+", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 513:

/* Line 936 of glr.c  */
#line 1647 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "-", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 514:

/* Line 936 of glr.c  */
#line 1648 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "*", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 515:

/* Line 936 of glr.c  */
#line 1649 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "/", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 516:

/* Line 936 of glr.c  */
#line 1650 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "%", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 517:

/* Line 936 of glr.c  */
#line 1651 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "MOD", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 518:

/* Line 936 of glr.c  */
#line 1652 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "--", NULL, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 519:

/* Line 936 of glr.c  */
#line 1653 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "ANDOP", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 520:

/* Line 936 of glr.c  */
#line 1654 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "OR", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 521:

/* Line 936 of glr.c  */
#line 1655 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "XOR", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 522:

/* Line 936 of glr.c  */
#line 1656 "sql.ypp"
    { ((*yyvalp).ast_node) = newExprCal(t_expr_cal, "CMP", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node));/* puts("=");*/ ;}
    break;

  case 523:

/* Line 936 of glr.c  */
#line 1657 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "CMP", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 524:

/* Line 936 of glr.c  */
#line 1658 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "CMP", "ANY", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 525:

/* Line 936 of glr.c  */
#line 1659 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "CMP", "SOME", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 526:

/* Line 936 of glr.c  */
#line 1660 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "CMP", "ALL", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 527:

/* Line 936 of glr.c  */
#line 1661 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "|", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 528:

/* Line 936 of glr.c  */
#line 1662 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "&", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 529:

/* Line 936 of glr.c  */
#line 1663 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "^", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 530:

/* Line 936 of glr.c  */
#line 1664 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, (SHIFT==1?"LS":"RS"), NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 531:

/* Line 936 of glr.c  */
#line 1665 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "NOT", NULL, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 532:

/* Line 936 of glr.c  */
#line 1666 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "!", NULL, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 533:

/* Line 936 of glr.c  */
#line 1667 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; ;}
    break;

  case 534:

/* Line 936 of glr.c  */
#line 1668 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); ;}
    break;

  case 535:

/* Line 936 of glr.c  */
#line 1671 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "ISN", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL, NULL); ;}
    break;

  case 536:

/* Line 936 of glr.c  */
#line 1672 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "ISNN", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node), NULL, NULL, NULL); ;}
    break;

  case 537:

/* Line 936 of glr.c  */
#line 1673 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "ISB", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL, NULL); ;}
    break;

  case 538:

/* Line 936 of glr.c  */
#line 1674 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "ISNB", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node), NULL, NULL, NULL); ;}
    break;

  case 539:

/* Line 936 of glr.c  */
#line 1677 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "BA", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), NULL); ;}
    break;

  case 540:

/* Line 936 of glr.c  */
#line 1681 "sql.ypp"
    { ((*yyvalp).ast_node) = newExprList(t_expr_list, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); ;}
    break;

  case 541:

/* Line 936 of glr.c  */
#line 1682 "sql.ypp"
    { ((*yyvalp).ast_node) = newExprList(t_expr_list, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 543:

/* Line 936 of glr.c  */
#line 1686 "sql.ypp"
    {((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);;}
    break;

  case 544:

/* Line 936 of glr.c  */
#line 1689 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "INV", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 545:

/* Line 936 of glr.c  */
#line 1690 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "NIN", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 546:

/* Line 936 of glr.c  */
#line 1691 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "INS", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 547:

/* Line 936 of glr.c  */
#line 1692 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "NINS", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 548:

/* Line 936 of glr.c  */
#line 1693 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "EX", NULL, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 549:

/* Line 936 of glr.c  */
#line 1694 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "NINS", NULL, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 550:

/* Line 936 of glr.c  */
#line 1697 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "NAME", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.strval), 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 551:

/* Line 936 of glr.c  */
#line 1701 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "FCOUNTALL", NULL, NULL, NULL, NULL); ;}
    break;

  case 552:

/* Line 936 of glr.c  */
#line 1702 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "FCOUNT", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), NULL, NULL); ;}
    break;

  case 553:

/* Line 936 of glr.c  */
#line 1705 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "FSUBSTRING", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), NULL, NULL); ;}
    break;

  case 554:

/* Line 936 of glr.c  */
#line 1706 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "FSUBSTRING2", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), NULL);;}
    break;

  case 555:

/* Line 936 of glr.c  */
#line 1707 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "FSUBSTRING3", (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.ast_node), NULL); ;}
    break;

  case 556:

/* Line 936 of glr.c  */
#line 1708 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "FTRIM", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), NULL, NULL); ;}
    break;

  case 557:

/* Line 936 of glr.c  */
#line 1709 "sql.ypp"
    { ;}
    break;

  case 558:

/* Line 936 of glr.c  */
#line 1712 "sql.ypp"
    { emit("INT 1"); ;}
    break;

  case 559:

/* Line 936 of glr.c  */
#line 1713 "sql.ypp"
    { emit("INT 2"); ;}
    break;

  case 560:

/* Line 936 of glr.c  */
#line 1714 "sql.ypp"
    { emit("INT 3"); ;}
    break;

  case 563:

/* Line 936 of glr.c  */
#line 1721 "sql.ypp"
    { emit("NUMBER 1"); ;}
    break;

  case 564:

/* Line 936 of glr.c  */
#line 1722 "sql.ypp"
    { emit("NUMBER 2"); ;}
    break;

  case 565:

/* Line 936 of glr.c  */
#line 1723 "sql.ypp"
    { emit("NUMBER 3"); ;}
    break;

  case 566:

/* Line 936 of glr.c  */
#line 1724 "sql.ypp"
    { emit("NUMBER 4"); ;}
    break;

  case 567:

/* Line 936 of glr.c  */
#line 1725 "sql.ypp"
    { emit("NUMBER 5"); ;}
    break;

  case 568:

/* Line 936 of glr.c  */
#line 1726 "sql.ypp"
    { emit("NUMBER 6"); ;}
    break;

  case 569:

/* Line 936 of glr.c  */
#line 1727 "sql.ypp"
    { emit("NUMBER 7"); ;}
    break;

  case 570:

/* Line 936 of glr.c  */
#line 1728 "sql.ypp"
    { emit("NUMBER 8"); ;}
    break;

  case 571:

/* Line 936 of glr.c  */
#line 1729 "sql.ypp"
    { emit("NUMBER 9"); ;}
    break;

  case 572:

/* Line 936 of glr.c  */
#line 1732 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "CASE3", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), NULL, NULL); ;}
    break;

  case 573:

/* Line 936 of glr.c  */
#line 1733 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "CASE2", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), NULL); ;}
    break;

  case 574:

/* Line 936 of glr.c  */
#line 1734 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "CASE3", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL); ;}
    break;

  case 575:

/* Line 936 of glr.c  */
#line 1735 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "CASE4", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node), NULL); ;}
    break;

  case 576:

/* Line 936 of glr.c  */
#line 1738 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "WHEN1", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node), NULL); ;}
    break;

  case 577:

/* Line 936 of glr.c  */
#line 1739 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprFunc(t_expr_func, "WHEN2", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 578:

/* Line 936 of glr.c  */
#line 1742 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "LIKE", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 579:

/* Line 936 of glr.c  */
#line 1743 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "NLIKE", NULL, 0, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 580:

/* Line 936 of glr.c  */
#line 1746 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "REGEXP", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); ;}
    break;

  case 581:

/* Line 936 of glr.c  */
#line 1747 "sql.ypp"
    { ((*yyvalp).ast_node)=newExprCal(t_expr_cal, "NREGEXP", NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node)); ;}
    break;



/* Line 936 of glr.c  */
#line 5501 "sql.tab.cpp"
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


/*ARGSUSED*/ static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {
      
      default: break;
    }
}

			      /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
		&yys->yysemantics.yysval);
  else
    {
#if YYDEBUG
      if (yydebug)
	{
	  if (yys->yysemantics.yyfirstVal)
	    YYFPRINTF (stderr, "%s unresolved ", yymsg);
	  else
	    YYFPRINTF (stderr, "%s incomplete ", yymsg);
	  yy_symbol_print (stderr, yystos[yys->yylrState],
			   NULL);
	  YYFPRINTF (stderr, "\n");
	}
#endif

      if (yys->yysemantics.yyfirstVal)
	{
	  yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
	  yyGLRState *yyrh;
	  int yyn;
	  for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
	       yyn > 0;
	       yyrh = yyrh->yypred, yyn -= 1)
	    yydestroyGLRState (yymsg, yyrh);
	}
    }
}

/** Left-hand-side symbol for rule #RULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yyis_pact_ninf(yystate) \
  ((yystate) == YYPACT_NINF)

/** True iff LR state STATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yyis_pact_ninf (yypact[yystate]);
}

/** The default reduction for STATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yyis_table_ninf(yytable_value) \
  ((yytable_value) == YYTABLE_NINF)

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *CONFLICTS to a pointer into yyconfl to 0-terminated list of
 *  conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
		int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yyis_table_ninf (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
{
  int yyr;
  yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yylhs - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

				/* GLRStates */

/** Return a fresh GLRStackItem.  Callers should call
 * YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 * headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  RULENUM on the semantic values in RHS to the list of
 *  alternative actions for STATE.  Assumes that RHS comes from
 *  stack #K of *STACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
		     yyGLRState* rhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  yynewOption->yystate = rhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

				/* GLRStacks */

/** Initialize SET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = NULL;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize STACK to a single empty stack, with total maximum
 *  capacity for all stacks of SIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = NULL;
  yystackp->yylastDeleted = NULL;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If STACK is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yysize, yynewSize;
  size_t yyn;
  yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
	{
	  yyGLRState* yys0 = &yyp0->yystate;
	  yyGLRState* yys1 = &yyp1->yystate;
	  if (yys0->yypred != NULL)
	    yys1->yypred =
	      YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
	  if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != NULL)
	    yys1->yysemantics.yyfirstVal =
	      YYRELOC(yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
	}
      else
	{
	  yySemanticOption* yyv0 = &yyp0->yyoption;
	  yySemanticOption* yyv1 = &yyp1->yyoption;
	  if (yyv0->yystate != NULL)
	    yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
	  if (yyv0->yynext != NULL)
	    yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
	}
    }
  if (yystackp->yysplitPoint != NULL)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
				 yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != NULL)
      yystackp->yytops.yystates[yyn] =
	YYRELOC (yystackp->yyitems, yynewItems,
		 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that S is a GLRState somewhere on STACK, update the
 *  splitpoint of STACK, if needed, so that it is at least as deep as
 *  S.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != NULL && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #K in STACK.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != NULL)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = NULL;
}

/** Undelete the last stack that was marked as deleted.  Can only be
    done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == NULL || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = NULL;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == NULL)
	{
	  if (yyi == yyj)
	    {
	      YYDPRINTF ((stderr, "Removing dead stacks.\n"));
	    }
	  yystackp->yytops.yysize -= 1;
	}
      else
	{
	  yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
	  /* In the current implementation, it's unnecessary to copy
	     yystackp->yytops.yylookaheadNeeds[yyi] since, after
	     yyremoveDeletes returns, the parser immediately either enters
	     deterministic operation or shifts a token.  However, it doesn't
	     hurt, and the code might evolve to need it.  */
	  yystackp->yytops.yylookaheadNeeds[yyj] =
	    yystackp->yytops.yylookaheadNeeds[yyi];
	  if (yyj != yyi)
	    {
	      YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
			  (unsigned long int) yyi, (unsigned long int) yyj));
	    }
	  yyj += 1;
	}
      yyi += 1;
    }
}

/** Shift to a new state on stack #K of STACK, corresponding to LR state
 * LRSTATE, at input position POSN, with (resolved) semantic value SVAL.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
	    size_t yyposn,
	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #K of YYSTACK, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = NULL;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, rhs, yyrule);
}

/** Pop the symbols consumed by reduction #RULE from the top of stack
 *  #K of STACK, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *VALP to the resulting value,
 *  and *LOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == NULL)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* rhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, rhs,
			   yyvalp, yylocp, yystackp);
    }
  else
    {
      /* At present, doAction is never called in nondeterministic
       * mode, so this branch is never taken.  It is here in
       * anticipation of a future feature that will allow immediate
       * evaluation of selected actions in nondeterministic mode.  */
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
	= yystackp->yytops.yystates[yyk];
      for (yyi = 0; yyi < yynrhs; yyi += 1)
	{
	  yys = yys->yypred;
	  YYASSERT (yys);
	}
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
			   yyvalp, yylocp, yystackp);
    }
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)		\
do {					\
  if (yydebug)				\
    yy_reduce_print Args;		\
} while (YYID (0))

/*----------------------------------------------------------.
| Report that the RULE is going to be reduced on stack #K.  |
`----------------------------------------------------------*/

/*ARGSUSED*/ static inline void
yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
		 YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  int yynrhs = yyrhsLength (yyrule);
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == NULL);
  yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
  int yylow = 1;
  int yyi;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
	     (unsigned long int) yyk, yyrule - 1,
	     (unsigned long int) yyrline[yyrule]);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yysemantics.yysval)
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}
#endif

/** Pop items off stack #K of STACK according to grammar rule RULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with RULE and store its value with the
 *  newly pushed state, if FORCEEVAL or if STACK is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #K from
 *  the STACK.  In this case, the (necessarily deferred) semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
	     yybool yyforceEval)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == NULL)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YY_REDUCE_PRINT ((yystackp, yyk, yyrule, &yysval, &yyloc));
      YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval,
			 &yyloc));
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
		  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
				 yylhsNonterm (yyrule)),
		  yyposn, &yysval, &yyloc);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
	   0 < yyn; yyn -= 1)
	{
	  yys = yys->yypred;
	  YYASSERT (yys);
	}
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
		  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
	if (yyi != yyk && yystackp->yytops.yystates[yyi] != NULL)
	  {
	    yyGLRState* yyp, *yysplit = yystackp->yysplitPoint;
	    yyp = yystackp->yytops.yystates[yyi];
	    while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
	      {
		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
		  {
		    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
		    yymarkStackDeleted (yystackp, yyk);
		    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
				(unsigned long int) yyk,
				(unsigned long int) yyi));
		    return yyok;
		  }
		yyp = yyp->yypred;
	      }
	  }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == NULL)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = NULL;

      if (yystackp->yytops.yycapacity
	  > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
	(yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
				  (yystackp->yytops.yycapacity
				   * sizeof yynewStates[0]));
      if (yynewStates == NULL)
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
	(yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
			     (yystackp->yytops.yycapacity
			      * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == NULL)
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff Y0 and Y1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
	   yyn = yyrhsLength (yyy0->yyrule);
	   yyn > 0;
	   yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
	if (yys0->yyposn != yys1->yyposn)
	  return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (Y0,Y1), destructively merge the
 *  alternative semantic values for the RHS-symbols of Y1 and Y0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
	break;
      else if (yys0->yyresolved)
	{
	  yys1->yyresolved = yytrue;
	  yys1->yysemantics.yysval = yys0->yysemantics.yysval;
	}
      else if (yys1->yyresolved)
	{
	  yys0->yyresolved = yytrue;
	  yys0->yysemantics.yysval = yys1->yysemantics.yysval;
	}
      else
	{
	  yySemanticOption** yyz0p;
	  yySemanticOption* yyz1;
	  yyz0p = &yys0->yysemantics.yyfirstVal;
	  yyz1 = yys1->yysemantics.yyfirstVal;
	  while (YYID (yytrue))
	    {
	      if (yyz1 == *yyz0p || yyz1 == NULL)
		break;
	      else if (*yyz0p == NULL)
		{
		  *yyz0p = yyz1;
		  break;
		}
	      else if (*yyz0p < yyz1)
		{
		  yySemanticOption* yyz = *yyz0p;
		  *yyz0p = yyz1;
		  yyz1 = yyz1->yynext;
		  (*yyz0p)->yynext = yyz;
		}
	      yyz0p = &(*yyz0p)->yynext;
	    }
	  yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
	}
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
	return 0;
      else
	return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
				   yyGLRStack* yystackp);


/** Resolve the previous N states starting at and including state S.  If result
 *  != yyok, some states may have been left unresolved possibly with empty
 *  semantic option chains.  Regardless of whether result = yyok, each state
 *  has been left with consistent data so that yydestroyGLRState can be invoked
 *  if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
		 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
	YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of OPT, perform its user action, and return
 *  the semantic value and location.  Regardless of whether result = yyok, all
 *  RHS states have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
		 YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs;
  int yychar_current;
  YYSTYPE yylval_current;
  YYLTYPE yylloc_current;
  YYRESULTTAG yyflag;

  yynrhs = yyrhsLength (yyopt->yyrule);
  yyflag = yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
	yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  yychar_current = yychar;
  yylval_current = yylval;
  yylloc_current = yylloc;
  yychar = yyopt->yyrawchar;
  yylval = yyopt->yyval;
  yylloc = yyopt->yyloc;
  yyflag = yyuserAction (yyopt->yyrule, yynrhs,
			   yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
			   yyvalp, yylocp, yystackp);
  yychar = yychar_current;
  yylval = yylval_current;
  yylloc = yylloc_current;
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == NULL)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
	       yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
	       yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
	       (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
	{
	  if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
	    YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]));
	  else
	    YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
		       (unsigned long int) (yystates[yyi - 1]->yyposn + 1),
		       (unsigned long int) yystates[yyi]->yyposn);
	}
      else
	yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

/*ARGSUSED*/ static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
		   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Starting at and including state S1, resolve the location for each of the
 *  previous N1 states that is unresolved.  The first semantic option of a state
 *  is always chosen.  */
static void
yyresolveLocations (yyGLRState* yys1, int yyn1,
		    yyGLRStack *yystackp)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp);
      if (!yys1->yyresolved)
	{
	  yySemanticOption *yyoption;
	  yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
	  int yynrhs;
	  int yychar_current;
	  YYSTYPE yylval_current;
	  YYLTYPE yylloc_current;
	  yyoption = yys1->yysemantics.yyfirstVal;
	  YYASSERT (yyoption != NULL);
	  yynrhs = yyrhsLength (yyoption->yyrule);
	  if (yynrhs > 0)
	    {
	      yyGLRState *yys;
	      int yyn;
	      yyresolveLocations (yyoption->yystate, yynrhs,
				  yystackp);
	      for (yys = yyoption->yystate, yyn = yynrhs;
		   yyn > 0;
		   yys = yys->yypred, yyn -= 1)
		yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
	    }
	  else
	    {
	      /* Both yyresolveAction and yyresolveLocations traverse the GSS
		 in reverse rightmost order.  It is only necessary to invoke
		 yyresolveLocations on a subforest for which yyresolveAction
		 would have been invoked next had an ambiguity not been
		 detected.  Thus the location of the previous state (but not
		 necessarily the previous state itself) is guaranteed to be
		 resolved already.  */
	      yyGLRState *yyprevious = yyoption->yystate;
	      yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
	    }
	  yychar_current = yychar;
	  yylval_current = yylval;
	  yylloc_current = yylloc;
	  yychar = yyoption->yyrawchar;
	  yylval = yyoption->yyval;
	  yylloc = yyoption->yyloc;
	  YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
	  yychar = yychar_current;
	  yylval = yylval_current;
	  yylloc = yylloc_current;
	}
    }
}

/** Resolve the ambiguity represented in state S, perform the indicated
 *  actions, and set the semantic value of S.  If result != yyok, the chain of
 *  semantic options in S has been cleared instead or it has been left
 *  unmodified except that redundant options may have been removed.  Regardless
 *  of whether result = yyok, S has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest;
  yySemanticOption** yypp;
  yybool yymerge;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  yybest = yyoptionList;
  yymerge = yyfalse;
  for (yypp = &yyoptionList->yynext; *yypp != NULL; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
	{
	  yymergeOptionSets (yybest, yyp);
	  *yypp = yyp->yynext;
	}
      else
	{
	  switch (yypreference (yybest, yyp))
	    {
	    case 0:
	      yyresolveLocations (yys, 1, yystackp);
	      return yyreportAmbiguity (yybest, yyp);
	      break;
	    case 1:
	      yymerge = yytrue;
	      break;
	    case 2:
	      break;
	    case 3:
	      yybest = yyp;
	      yymerge = yyfalse;
	      break;
	    default:
	      /* This cannot happen so it is not worth a YYASSERT (yyfalse),
		 but some compilers complain if the default case is
		 omitted.  */
	      break;
	    }
	  yypp = &yyp->yynext;
	}
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval,
				yylocp);
      if (yyflag == yyok)
	for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
	  {
	    if (yyprec == yydprec[yyp->yyrule])
	      {
		YYSTYPE yysval_other;
		YYLTYPE yydummy;
		yyflag = yyresolveAction (yyp, yystackp, &yysval_other,
					  &yydummy);
		if (yyflag != yyok)
		  {
		    yydestruct ("Cleanup: discarding incompletely merged value for",
				yystos[yys->yylrState],
				&yysval);
		    break;
		  }
		yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
	      }
	  }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = NULL;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != NULL)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
	   yys != yystackp->yysplitPoint;
	   yys = yys->yypred, yyn += 1)
	continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
			     ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == NULL)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = NULL;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = NULL;
  yystackp->yylastDeleted = NULL;

  while (yyr != NULL)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
		   size_t yyposn)
{
  int yyaction;
  const short int* yyconflicts;
  yyRuleNum yyrule;

  while (yystackp->yytops.yystates[yyk] != NULL)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
		  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
	{
	  yyrule = yydefaultAction (yystate);
	  if (yyrule == 0)
	    {
	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
			  (unsigned long int) yyk));
	      yymarkStackDeleted (yystackp, yyk);
	      return yyok;
	    }
	  YYCHK (yyglrReduce (yystackp, yyk, yyrule, yyfalse));
	}
      else
	{
	  yySymbol yytoken;
	  yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
	  if (yychar == YYEMPTY)
	    {
	      YYDPRINTF ((stderr, "Reading a token: "));
	      yychar = YYLEX;
	    }

	  if (yychar <= YYEOF)
	    {
	      yychar = yytoken = YYEOF;
	      YYDPRINTF ((stderr, "Now at end of input.\n"));
	    }
	  else
	    {
	      yytoken = YYTRANSLATE (yychar);
	      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	    }

	  yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

	  while (*yyconflicts != 0)
	    {
	      size_t yynewStack = yysplitStack (yystackp, yyk);
	      YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
			  (unsigned long int) yynewStack,
			  (unsigned long int) yyk));
	      YYCHK (yyglrReduce (yystackp, yynewStack,
				  *yyconflicts, yyfalse));
	      YYCHK (yyprocessOneStack (yystackp, yynewStack,
					yyposn));
	      yyconflicts += 1;
	    }

	  if (yyisShiftAction (yyaction))
	    break;
	  else if (yyisErrorAction (yyaction))
	    {
	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
			  (unsigned long int) yyk));
	      yymarkStackDeleted (yystackp, yyk);
	      break;
	    }
	  else
	    YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
				yyfalse));
	}
    }
  return yyok;
}

/*ARGSUSED*/ static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 0)
    {
#if YYERROR_VERBOSE
      int yyn;
      yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      if (YYPACT_NINF < yyn && yyn <= YYLAST)
	{
	  yySymbol yytoken = YYTRANSLATE (yychar);
	  size_t yysize0 = yytnamerr (NULL, yytokenName (yytoken));
	  size_t yysize = yysize0;
	  size_t yysize1;
	  yybool yysize_overflow = yyfalse;
	  char* yymsg = NULL;
	  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn + 1;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytokenName (yytoken);
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytokenName (yyx);
		yysize1 = yysize + yytnamerr (NULL, yytokenName (yyx));
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + strlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow)
	    yymsg = (char *) YYMALLOC (yysize);

	  if (yymsg)
	    {
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYFREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      yyMemoryExhausted (yystackp);
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
      yynerrs += 1;
    }
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
/*ARGSUSED*/ static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (YYID (yytrue))
      {
	yySymbol yytoken;
	if (yychar == YYEOF)
	  yyFail (yystackp, NULL);
	if (yychar != YYEMPTY)
	  {
	    yytoken = YYTRANSLATE (yychar);
	    yydestruct ("Error: discarding",
			yytoken, &yylval);
	  }
	YYDPRINTF ((stderr, "Reading a token: "));
	yychar = YYLEX;
	if (yychar <= YYEOF)
	  {
	    yychar = yytoken = YYEOF;
	    YYDPRINTF ((stderr, "Now at end of input.\n"));
	  }
	else
	  {
	    yytoken = YYTRANSLATE (yychar);
	    YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	  }
	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
	if (yyis_pact_ninf (yyj))
	  return;
	yyj += yytoken;
	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
	  {
	    if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
	      return;
	  }
	else if (yytable[yyj] != 0 && ! yyis_table_ninf (yytable[yyj]))
	  return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != NULL)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, NULL);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != NULL)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yyis_pact_ninf (yyj))
	{
	  yyj += YYTERROR;
	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
	      && yyisShiftAction (yytable[yyj]))
	    {
	      /* Shift the error token having adjusted its location.  */
	      YYLTYPE yyerrloc;
	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
			       &yylval, &yyerrloc);
	      yyglrShift (yystackp, 0, yytable[yyj],
			  yys->yyposn, &yylval, &yyerrloc);
	      yys = yystackp->yytops.yystates[0];
	      break;
	    }
	}

      if (yys->yypred != NULL)
	yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == NULL)
    yyFail (yystackp, NULL);
}

#define YYCHK1(YYE)							     \
  do {									     \
    switch (YYE) {							     \
    case yyok:								     \
      break;								     \
    case yyabort:							     \
      goto yyabortlab;							     \
    case yyaccept:							     \
      goto yyacceptlab;							     \
    case yyerr:								     \
      goto yyuser_error;						     \
    default:								     \
      goto yybuglab;							     \
    }									     \
  } while (YYID (0))


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;


  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (YYID (yytrue))
    {
      /* For efficiency, we have two loops, the first of which is
	 specialized to deterministic operation (single stack, no
	 potential ambiguity).  */
      /* Standard mode */
      while (YYID (yytrue))
	{
	  yyRuleNum yyrule;
	  int yyaction;
	  const short int* yyconflicts;

	  yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
	  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
	  if (yystate == YYFINAL)
	    goto yyacceptlab;
	  if (yyisDefaultedState (yystate))
	    {
	      yyrule = yydefaultAction (yystate);
	      if (yyrule == 0)
		{

		  yyreportSyntaxError (&yystack);
		  goto yyuser_error;
		}
	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
	    }
	  else
	    {
	      yySymbol yytoken;
	      if (yychar == YYEMPTY)
		{
		  YYDPRINTF ((stderr, "Reading a token: "));
		  yychar = YYLEX;
		}

	      if (yychar <= YYEOF)
		{
		  yychar = yytoken = YYEOF;
		  YYDPRINTF ((stderr, "Now at end of input.\n"));
		}
	      else
		{
		  yytoken = YYTRANSLATE (yychar);
		  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
		}

	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
	      if (*yyconflicts != 0)
		break;
	      if (yyisShiftAction (yyaction))
		{
		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
		  yychar = YYEMPTY;
		  yyposn += 1;
		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
		  if (0 < yystack.yyerrState)
		    yystack.yyerrState -= 1;
		}
	      else if (yyisErrorAction (yyaction))
		{

		  yyreportSyntaxError (&yystack);
		  goto yyuser_error;
		}
	      else
		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
	    }
	}

      while (YYID (yytrue))
	{
	  yySymbol yytoken_to_shift;
	  size_t yys;

	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

	  /* yyprocessOneStack returns one of three things:

	      - An error flag.  If the caller is yyprocessOneStack, it
		immediately returns as well.  When the caller is finally
		yyparse, it jumps to an error label via YYCHK1.

	      - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
		(&yystack, yys), which sets the top state of yys to NULL.  Thus,
		yyparse's following invocation of yyremoveDeletes will remove
		the stack.

	      - yyok, when ready to shift a token.

	     Except in the first case, yyparse will invoke yyremoveDeletes and
	     then shift the next token onto all remaining stacks.  This
	     synchronization of the shift (that is, after all preceding
	     reductions on all stacks) helps prevent double destructor calls
	     on yylval in the event of memory exhaustion.  */

	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
	  yyremoveDeletes (&yystack);
	  if (yystack.yytops.yysize == 0)
	    {
	      yyundeleteLastStack (&yystack);
	      if (yystack.yytops.yysize == 0)
		yyFail (&yystack, YY_("syntax error"));
	      YYCHK1 (yyresolveStack (&yystack));
	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));

	      yyreportSyntaxError (&yystack);
	      goto yyuser_error;
	    }

	  /* If any yyglrShift call fails, it will fail after shifting.  Thus,
	     a copy of yylval will already be on stack 0 in the event of a
	     failure in the following loop.  Thus, yychar is set to YYEMPTY
	     before the loop to make sure the user destructor for yylval isn't
	     called twice.  */
	  yytoken_to_shift = YYTRANSLATE (yychar);
	  yychar = YYEMPTY;
	  yyposn += 1;
	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    {
	      int yyaction;
	      const short int* yyconflicts;
	      yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
	      yygetLRActions (yystate, yytoken_to_shift, &yyaction,
			      &yyconflicts);
	      /* Note that yyconflicts were handled by yyprocessOneStack.  */
	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
	      YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
	      yyglrShift (&yystack, yys, yyaction, yyposn,
			  &yylval, &yylloc);
	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
			  (unsigned long int) yys,
			  yystack.yytops.yystates[yys]->yylrState));
	    }

	  if (yystack.yytops.yysize == 1)
	    {
	      YYCHK1 (yyresolveStack (&yystack));
	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
	      yycompressStack (&yystack);
	      break;
	    }
	}
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
		YYTRANSLATE (yychar),
		&yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
	{
	  size_t yysize = yystack.yytops.yysize;
	  size_t yyk;
	  for (yyk = 0; yyk < yysize; yyk += 1)
	    if (yystates[yyk])
	      {
		while (yystates[yyk])
		  {
		    yyGLRState *yys = yystates[yyk];
		    if (yys->yypred != NULL)
		      yydestroyGLRState ("Cleanup: popping", yys);
		    yystates[yyk] = yys->yypred;
		    yystack.yynextFree -= 1;
		    yystack.yyspaceLeft += 1;
		  }
		break;
	      }
	}
      yyfreeGLRStack (&yystack);
    }

  /* Make sure YYID is used.  */
  return YYID (yyresult);
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void yypstack (yyGLRStack* yystackp, size_t yyk)
  __attribute__ ((__unused__));
static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));

static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == NULL)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)							     \
    ((YYX) == NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
	{
	  YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
		     yyp->yystate.yyresolved, yyp->yystate.yylrState,
		     (unsigned long int) yyp->yystate.yyposn,
		     (long int) YYINDEX (yyp->yystate.yypred));
	  if (! yyp->yystate.yyresolved)
	    YYFPRINTF (stderr, ", firstVal: %ld",
		       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
	}
      else
	{
	  YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
		     yyp->yyoption.yyrule - 1,
		     (long int) YYINDEX (yyp->yyoption.yystate),
		     (long int) YYINDEX (yyp->yyoption.yynext));
	}
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
	       (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif



/* Line 2634 of glr.c  */
#line 1758 "sql.ypp"


void
emit(char *s, ...)
{
  extern int yylineno;

  va_list ap;
  va_start(ap, s);

  printf("rpn: ");
  vfprintf(stdout, s, ap);
  printf("\n");
}

void
yyerror(const char *s, ...)
{
  extern int  yylineno;

  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

/*
int readInputForLexer( char *buffer, int *numBytesRead, int maxBytesToRead ) {
	int numBytesToRead = maxBytesToRead;
	int bytesRemaining = strlen(globalInputText)-globalReadOffset;
	int i;
	if ( numBytesToRead > bytesRemaining ) { numBytesToRead = bytesRemaining; }
	for ( i = 0; i < numBytesToRead; i++ ) {
		buffer[i] = globalInputText[globalReadOffset+i];
	}
	*numBytesRead = numBytesToRead;
	globalReadOffset += numBytesToRead;
	cout<<isfirst<<endl;
	if (!isfirst)
	{
		pthread_mutex_unlock(&mutex);
		isfirst = !isfirst;
	}
	return 0;
}*/

/*
main(int ac, char **av)
{
	char c;
	while(1)
	{
		int charnum=0;
	    	while(1)
	    	{
			char c=getchar();
			globalInputText[charnum++] = c;
			if(c==';')
			{
			    globalInputText[charnum++]='\0';
			    break;
			}
	  	}
	    	puts(globalInputText);
	
		numToRead = strlen(globalInputText);
	
		if(!yyparse())
		{
			printf("SQL parse worked\n");
		}		
		else
		{
			printf("SQL parse failed\n");
		}
		c = getchar();
		while(c != '\n')
		{
			c = getchar();
		}
		cout<<"q for quit, other for continue"<<endl;
		c = getchar();
		cout<<c<<endl;
		if(c == 'q') break;
	}
} *//* main */

