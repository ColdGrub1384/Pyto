/* Copyright (C) 1989, 2000 Aladdin Enterprises.  All rights reserved. */

/*$Id: ansi2knr.c,v 1.14 2003/09/06 05:36:56 eggert Exp $*/
/* Convert ANSI C function definitions to K&R ("traditional C") syntax */

/*
ansi2knr is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY.  No author or distributor accepts responsibility to anyone for the
consequences of using it or for whether it serves any particular purpose or
works at all, unless he says so in writing.  Refer to the GNU General Public
License (the "GPL") for full details.

Everyone is granted permission to copy, modify and redistribute ansi2knr,
but only under the conditions described in the GPL.  A copy of this license
is supposed to have been given to you along with ansi2knr so you can know
your rights and responsibilities.  It should be in a file named COPYLEFT,
or, if there is no file named COPYLEFT, a file named COPYING.  Among other
things, the copyright notice and this notice must be preserved on all
copies.

We explicitly state here what we believe is already implied by the GPL: if
the ansi2knr program is distributed as a separate set of sources and a
separate executable file which are aggregated on a storage medium together
with another program, this in itself does not bring the other program under
the GPL, nor does the mere fact that such a program or the procedures for
constructing it invoke the ansi2knr executable bring any other part of the
program under the GPL.
*/

/*
 * Usage:
	ansi2knr [--filename FILENAME] [INPUT_FILE [OUTPUT_FILE]]
 * --filename provides the file name for the #line directive in the output,
 * overriding input_file (if present).
 * If no input_file is supplied, input is read from stdin.
 * If no output_file is supplied, output goes to stdout.
 * There are no error messages.
 *
 * ansi2knr recognizes function definitions by seeing a non-keyword
 * identifier at the left margin, followed by a left parenthesis, with a
 * right parenthesis as the last character on the line, and with a left
 * brace as the first token on the following line (ignoring possible
 * intervening comments and/or preprocessor directives), except that a line
 * consisting of only
 *	identifier1(identifier2)
 * will not be considered a function definition unless identifier2 is
 * the word "void", and a line consisting of
 *	identifier1(identifier2, <<arbitrary>>)
 * will not be considered a function definition.
 * ansi2knr will recognize a multi-line header provided that no intervening
 * line ends with a left or right brace or a semicolon.  These algorithms
 * ignore whitespace, comments, and preprocessor directives, except that
 * the function name must be the first thing on the line.  The following
 * constructs will confuse it:
 *	- Any other construct that starts at the left margin and
 *	    follows the above syntax (such as a macro or function call).
 *	- Some macros that tinker with the syntax of function headers.
 */

/*
 * The original and principal author of ansi2knr is L. Peter Deutsch
 * <ghost@aladdin.com>.  Other authors are noted in the change history
 * that follows (in reverse chronological order):

	lpd 2000-04-12 backs out Eggert's changes because of bugs:
	- concatlits didn't declare the type of its bufend argument;
	- concatlits didn't recognize when it was inside a comment;
	- scanstring could scan backward past the beginning of the string; when
	- the check for \ + newline in scanstring was unnecessary.

	2000-03-05  Paul Eggert  <eggert@twinsun.com>

	Add support for concatenated string literals.
	* ansi2knr.c (concatlits): New decl.
	(main): Invoke concatlits to concatenate string literals.
	(scanstring): Handle backslash-newline correctly.  Work with
	character constants.  Fix bug when scanning backwards through
	backslash-quote.  Check for unterminated strings.
	(convert1): Parse character constants, too.
	(appendline, concatlits): New functions.
	* ansi2knr.1: Document this.

	lpd 1999-08-17 added code to allow preprocessor directives
		wherever comments are allowed
	lpd 1999-04-12 added minor fixes from Pavel Roskin
		<pavel_roskin@geocities.com> for clean compilation with
		gcc -W -Wall
	lpd 1999-03-22 added hack to recognize lines consisting of
		identifier1(identifier2, xxx) as *not* being procedures
	lpd 1999-02-03 made indentation of preprocessor commands consistent
	lpd 1999-01-28 fixed two bugs: a '/' in an argument list caused an
		endless loop; quoted strings within an argument list
		confused the parser
	lpd 1999-01-24 added a check for write errors on the output,
		suggested by Jim Meyering <meyering@ascend.com>
	lpd 1998-11-09 added further hack to recognize identifier(void)
		as being a procedure
	lpd 1998-10-23 added hack to recognize lines consisting of
		identifier1(identifier2) as *not* being procedures
	lpd 1997-12-08 made input_file optional; only closes input and/or
		output file if not stdin or stdout respectively; prints
		usage message on stderr rather than stdout; adds
		--filename switch (changes suggested by
		<ceder@lysator.liu.se>)
	lpd 1996-01-21 added code to cope with not HAVE_CONFIG_H and with
		compilers that don't understand void, as suggested by
		Tom Lane
	lpd 1996-01-15 changed to require that the first non-comment token
		on the line following a function header be a left brace,
		to reduce sensitivity to macros, as suggested by Tom Lane
		<tgl@sss.pgh.pa.us>
	lpd 1995-06-22 removed #ifndefs whose sole purpose was to define
		undefined preprocessor symbols as 0; changed all #ifdefs
		for configuration symbols to #ifs
	lpd 1995-04-05 changed copyright notice to make it clear that
		including ansi2knr in a program does not bring the entire
		program under the GPL
	lpd 1994-12-18 added conditionals for systems where ctype macros
		don't handle 8-bit characters properly, suggested by
		Francois Pinard <pinard@iro.umontreal.ca>;
		removed --varargs switch (this is now the default)
	lpd 1994-10-10 removed CONFIG_BROKETS conditional
	lpd 1994-07-16 added some conditionals to help GNU `configure',
		suggested by Francois Pinard <pinard@iro.umontreal.ca>;
		properly erase prototype args in function parameters,
		contributed by Jim Avera <jima@netcom.com>;
		correct error in writeblanks (it shouldn't erase EOLs)
	lpd 1989-xx-xx original version
 */

/* Most of the conditionals here are to make ansi2knr work with */
/* or without the GNU configure machinery. */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <ctype.h>

#if HAVE_CONFIG_H

/*
   For properly autoconfiguring ansi2knr, use AC_CONFIG_HEADER(config.h).
   This will define HAVE_CONFIG_H and so, activate the following lines.
 */

# if STDC_HEADERS || HAVE_STRING_H
#  include <string.h>
# else
#  include <strings.h>
# endif

#else /* not HAVE_CONFIG_H */

/* Otherwise do it the hard way */

# ifdef BSD
#  include <strings.h>
# else
#  ifdef VMS
    extern int strlen(), strncmp();
#  else
#   include <string.h>
#  endif
# endif

#endif /* not HAVE_CONFIG_H */

#if STDC_HEADERS
# include <stdlib.h>
#else
/*
   malloc and free should be declared in stdlib.h,
   but if you've got a K&R compiler, they probably aren't.
 */
# ifdef MSDOS
#  include <malloc.h>
# else
#  ifdef VMS
     extern char *malloc();
     extern void free();
#  else
     //extern char *malloc();
     //extern int free();
#  endif
# endif

#endif

/* Define NULL (for *very* old compilers). */
#ifndef NULL
# define NULL (0)
#endif

/*
 * The ctype macros don't always handle 8-bit characters correctly.
 * Compensate for this here.
 */
#ifdef isascii
# undef HAVE_ISASCII		/* just in case */
# define HAVE_ISASCII 1
#else
#endif
#if STDC_HEADERS || !HAVE_ISASCII
# define is_ascii(c) 1
#else
# define is_ascii(c) isascii(c)
#endif

#define is_space(c) (is_ascii(c) && isspace(c))
#define is_alpha(c) (is_ascii(c) && isalpha(c))
#define is_alnum(c) (is_ascii(c) && isalnum(c))

/* Scanning macros */
#define isidchar(ch) (is_alnum(ch) || (ch) == '_')
#define isidfirstchar(ch) (is_alpha(ch) || (ch) == '_')

/* Forward references */
char *ppdirforward();
char *ppdirbackward();
char *skipspace();
char *scanstring();
int writeblanks();
int test1();
int convert1();
