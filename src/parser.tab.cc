// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

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

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.tab.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hh"

// User implementation prologue.
#line 92 "parser.y" // lalr1.cc:407

extern int yylex(yy::parser::sematic_type *yylval,
                yy::parser::location_type *yyloc);

#line 55 "parser.tab.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 15 "parser.y" // lalr1.cc:408

    void yyerror(char const *);
    int yylex(void);
    using namespace std;

#line 63 "parser.tab.cc" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 149 "parser.tab.cc" // lalr1.cc:474

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 98 "parser.y" // lalr1.cc:725
{
    yyla.location.begin.filename = yyla.location.end.filename = new std::string("stdin");
}

#line 452 "parser.tab.cc" // lalr1.cc:725

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {

#line 564 "parser.tab.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -59;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
      -3,     2,    56,     9,    -3,   -59,    44,   290,   -59,    -3,
     -59,    44,    45,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,    -2,    69,    -3,    44,   -59,   -59,    -5,    47,    48,
      49,   137,   -59,   -59,   137,   137,   137,   118,   -26,   -59,
     -59,   -59,    73,   -59,   -59,   -59,   -59,   -29,   -59,   290,
     290,   -59,   137,   137,   137,   137,   290,    58,   -29,   150,
      -8,   -59,    30,   -59,   118,    54,   -59,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   -59,    80,
     134,   -29,   166,   182,    53,   -59,    90,   -59,    -8,    -8,
      33,    33,    31,    31,    31,    31,   246,   107,    33,   -59,
     -59,    44,    44,   137,   -59,    82,   -59,   230,    63,    84,
     137,   137,    44,   -59,   198,   214,   -59,    44,    44,   -59,
     -59
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     6,     8,     5,     0,     1,     0,
       7,     0,     0,     9,    29,    30,    31,    32,    33,    34,
      10,    12,     0,     3,     4,    60,    61,    59,     0,     0,
       0,    42,    62,    63,     0,     0,     0,     0,     0,    16,
      19,    21,     0,    22,    23,    24,    25,    20,    44,     0,
       0,    14,     0,     0,     0,     0,     0,    59,    43,     0,
      57,    56,     0,    18,     0,    27,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,    26,     0,     0,     0,    58,     0,    15,    46,    45,
      47,    48,    52,    53,    54,    55,    51,    50,    49,    13,
      64,     0,     0,     0,    17,    37,    40,     0,     0,    39,
       0,     0,     0,    35,     0,     0,    38,     0,     0,    41,
      36
  };

  const short int
  parser::yypgoto_[] =
  {
     -59,   -59,   -59,    88,    12,    20,   -59,   -59,    64,   179,
     -58,    65,    57,     3,   -59,   -59,   -59,   -59,   -59,   -59,
     -31,   -59
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     5,    11,    20,    21,    38,    13,
      39,    40,    41,    42,    43,   109,   113,    44,    45,    46,
      47,    48
  };

  const unsigned char
  parser::yytable_[] =
  {
      58,    63,     1,    59,    60,    61,    87,    67,    68,    69,
      22,    70,    71,    72,    73,    74,    10,    75,    76,    52,
       6,    80,    81,    82,    83,    53,    77,    64,    87,    24,
      69,    49,    70,    50,     7,    10,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    77,    25,    26,
      27,    28,    78,    79,    29,    30,     8,    14,    15,    16,
      17,    18,     9,    19,    31,    32,    33,    67,    68,    69,
      12,    70,   107,    34,    51,    54,    55,    56,    65,   114,
     115,    35,    52,    86,    53,    99,    77,   103,    77,   108,
      36,   111,   112,    25,    26,    27,    28,    23,    37,    29,
      30,    62,    14,    15,    16,    17,    18,    66,    19,    31,
      32,    33,     0,    84,     0,     0,     0,   104,    34,     0,
       0,    25,    26,    27,    28,     0,    35,    29,    30,     0,
      14,    15,    16,    17,    18,    36,    19,    31,    32,    33,
      25,    26,    57,    67,    68,    69,    34,    70,    71,    72,
      73,    74,     0,    75,    35,     0,     0,    32,    33,   100,
       0,     0,    77,    36,     0,    34,     0,     0,     0,     0,
      67,    68,    69,    35,    70,    71,    72,    73,    74,    85,
      75,    76,    36,     0,     0,     0,    67,    68,    69,    77,
      70,    71,    72,    73,    74,   101,    75,    76,     0,     0,
       0,     0,    67,    68,    69,    77,    70,    71,    72,    73,
      74,   102,    75,    76,     0,     0,     0,     0,    67,    68,
      69,    77,    70,    71,    72,    73,    74,   117,    75,    76,
       0,     0,     0,     0,    67,    68,    69,    77,    70,    71,
      72,    73,    74,   118,    75,    76,     0,     0,     0,     0,
      67,    68,    69,    77,    70,    71,    72,    73,    74,     0,
      75,    76,     0,     0,   110,     0,    67,    68,    69,    77,
      70,    71,    72,    73,    74,     0,    75,    76,     0,     0,
     105,   106,    67,    68,    69,    77,    70,    71,    72,    73,
      74,   116,     0,     0,     0,     0,   119,   120,     0,     0,
       0,    77,    14,    15,    16,    17,    18,     0,    19
  };

  const signed char
  parser::yycheck_[] =
  {
      31,    27,     5,    34,    35,    36,    64,    36,    37,    38,
       7,    40,    41,    42,    43,    44,     4,    46,    47,    24,
       0,    52,    53,    54,    55,    30,    55,    53,    86,     9,
      38,    33,    40,    35,    32,    23,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    55,     3,     4,
       5,     6,    49,    50,     9,    10,     0,    12,    13,    14,
      15,    16,    53,    18,    19,    20,    21,    36,    37,    38,
      26,    40,   103,    28,     5,    28,    28,    28,     5,   110,
     111,    36,    24,    53,    30,     5,    55,    34,    55,     7,
      45,    28,     8,     3,     4,     5,     6,     9,    53,     9,
      10,    37,    12,    13,    14,    15,    16,    42,    18,    19,
      20,    21,    -1,    56,    -1,    -1,    -1,    27,    28,    -1,
      -1,     3,     4,     5,     6,    -1,    36,     9,    10,    -1,
      12,    13,    14,    15,    16,    45,    18,    19,    20,    21,
       3,     4,     5,    36,    37,    38,    28,    40,    41,    42,
      43,    44,    -1,    46,    36,    -1,    -1,    20,    21,    25,
      -1,    -1,    55,    45,    -1,    28,    -1,    -1,    -1,    -1,
      36,    37,    38,    36,    40,    41,    42,    43,    44,    29,
      46,    47,    45,    -1,    -1,    -1,    36,    37,    38,    55,
      40,    41,    42,    43,    44,    29,    46,    47,    -1,    -1,
      -1,    -1,    36,    37,    38,    55,    40,    41,    42,    43,
      44,    29,    46,    47,    -1,    -1,    -1,    -1,    36,    37,
      38,    55,    40,    41,    42,    43,    44,    29,    46,    47,
      -1,    -1,    -1,    -1,    36,    37,    38,    55,    40,    41,
      42,    43,    44,    29,    46,    47,    -1,    -1,    -1,    -1,
      36,    37,    38,    55,    40,    41,    42,    43,    44,    -1,
      46,    47,    -1,    -1,    34,    -1,    36,    37,    38,    55,
      40,    41,    42,    43,    44,    -1,    46,    47,    -1,    -1,
     101,   102,    36,    37,    38,    55,    40,    41,    42,    43,
      44,   112,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
      -1,    55,    12,    13,    14,    15,    16,    -1,    18
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,    57,    58,    59,    60,    61,    32,     0,    53,
      60,    61,    26,    65,    12,    13,    14,    15,    16,    18,
      62,    63,    69,    59,    61,     3,     4,     5,     6,     9,
      10,    19,    20,    21,    28,    36,    45,    53,    64,    66,
      67,    68,    69,    70,    73,    74,    75,    76,    77,    33,
      35,     5,    24,    30,    28,    28,    28,     5,    76,    76,
      76,    76,    64,    27,    53,     5,    67,    36,    37,    38,
      40,    41,    42,    43,    44,    46,    47,    55,    69,    69,
      76,    76,    76,    76,    68,    29,    53,    66,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,     5,
      25,    29,    29,    34,    27,    65,    65,    76,     7,    71,
      34,    28,     8,    72,    76,    76,    65,    29,    29,    65,
      65
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    56,    57,    58,    58,    58,    58,    59,    59,    60,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    70,    71,    71,    72,    72,
      73,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    77,    77,    77,    77
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,     3,     1,     1,     2,     1,     2,
       3,     3,     1,     4,     2,     3,     1,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     7,     5,     0,     2,     0,
       5,     9,     1,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     1,
       1,     1,     1,     1,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "NUMENT", "NUMFLOT", "ID", "SI", "OSI",
  "SINO", "MIENTRAS", "PARA", "CASO", "ENT", "FLOT", "NADA", "BOOL", "CAR",
  "CADENA", "REGISTRO", "RETORNA", "CIERTO", "FALSO", "PROGRAMA", "LEER",
  "OBRACK", "CBRACK", "OBRACE", "CBRACE", "LPAR", "RPAR", "EQUAL", "EQUIV",
  "COLCOL", "ARROW", "SEMICOL", "COMMA", "MINUS", "PLUS", "MULT", "DIV",
  "MOD", "LTHAN", "GTHAN", "LETHAN", "GETHAN", "NEGATION", "AND", "OR",
  "QUOTA", "APOST", "BSLASH", "OCOMENT", "CCOMENT", "SEP", "INEQUIV",
  "POWER", "$accept", "enie", "prog", "funcl", "func", "header", "signa",
  "arglist", "instlist", "instbl", "inst", "asign", "decl", "type",
  "selec", "oselect", "sinoselect", "indite", "detite", "return", "exp",
  "term", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,   104,   104,   107,   108,   109,   110,   113,   114,   117,
     121,   124,   125,   128,   129,   132,   133,   136,   137,   140,
     141,   142,   143,   144,   145,   146,   151,   154,   155,   159,
     160,   161,   162,   163,   164,   168,   171,   172,   175,   176,
     179,   182,   185,   186,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   207,
     208,   209,   210,   211,   212
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
    };
    const unsigned int user_token_number_max_ = 310;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1018 "parser.tab.cc" // lalr1.cc:1155
#line 216 "parser.y" // lalr1.cc:1156
 

void yyerror (const char *s) {
    cerr << s;
} 

int main (int argc, char **argv) {
    if  (!(yyin = fopen(argv[1],"r"))) {
        cout << "Fallo en la apertura de archivo" << endl;
        exit;
    }
    yyparse();
}


