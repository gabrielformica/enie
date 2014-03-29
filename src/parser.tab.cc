// A Bison parser, made by GNU Bison 3.0.

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

#line 37 "parser.tab.cc" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "parser.tab.hh"

// User implementation prologue.

#line 51 "parser.tab.cc" // lalr1.cc:406
// Unqualified %code blocks.
#line 15 "parser.y" // lalr1.cc:407

    void yyerror(char const *);
    int yylex(void);
    using namespace std;

#line 59 "parser.tab.cc" // lalr1.cc:407


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
#line 145 "parser.tab.cc" // lalr1.cc:473

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
  parser::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
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
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

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
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* If YYLEN is nonzero, implement the default value of the action:
       '$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYLHS.VALUE to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
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

#line 552 "parser.tab.cc" // lalr1.cc:846
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
    yypush_ (YY_NULL, yylhs);
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
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
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


  const signed char parser::yypact_ninf_ = -71;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
       8,    19,    40,    29,     8,   -71,    33,   348,   -71,     8,
     -71,    33,    34,   -71,   -71,   -71,   -71,   -71,   375,   -71,
     -71,    18,   -71,    -2,    73,     8,    33,   109,    81,   375,
     375,   375,   -71,   -71,   -71,   -19,    61,    64,    65,    92,
     131,   -71,   -71,    96,   131,   131,   131,    44,   -71,   -71,
     -71,    99,   -71,   -71,   -71,   -71,   291,    71,   -71,   -71,
     -71,   -71,   -71,   -71,   100,   131,   131,   131,    82,   131,
     131,   360,    91,   -16,   291,    98,   171,   -71,   -71,    60,
      27,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   105,   -71,   122,   291,   -22,   291,   131,
     193,   215,    85,   360,   360,   -71,   -71,   -71,   131,    28,
      -8,    -8,    -8,    76,    76,   143,   143,   143,   143,   -26,
     307,    76,   -71,   -71,   -71,   131,   149,    33,    33,   131,
     -71,   -28,   -27,   291,   131,   291,   -71,   132,   -71,   275,
     -71,   360,   -71,   291,   110,   134,   131,   -71,   131,    33,
     -71,   237,   259,   -71,    33,    33,   -71,   -71
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     6,     8,     5,     0,     1,     0,
       7,     0,     0,     9,    34,    35,    36,    37,     0,    38,
      39,    13,    10,    12,     0,     3,     4,     0,     0,     0,
       0,     0,    16,    66,    67,    65,     0,     0,     0,     0,
      47,    68,    69,     0,     0,     0,     0,     0,    19,    21,
      23,     0,    24,    25,    26,    27,    22,    49,    33,    72,
      71,    17,    14,    11,     0,     0,     0,     0,    70,     0,
       0,     0,     0,    65,    48,     0,     0,    63,    62,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,    81,     0,    28,     0,
       0,     0,     0,     0,     0,    64,    20,    18,     0,    31,
      61,    51,    50,    52,    53,    57,    58,    59,    60,    56,
      55,    54,    82,    74,    79,     0,     0,     0,     0,     0,
      78,     0,     0,    30,     0,    80,    73,    42,    45,     0,
      76,     0,    75,    32,     0,    44,     0,    77,     0,     0,
      40,     0,     0,    43,     0,     0,    46,    41
  };

  const short int
  parser::yypgoto_[] =
  {
     -71,   -71,   -71,   136,     3,    58,   -71,   -71,   -71,   -11,
      67,   -71,   -70,    69,   -71,   -71,   -71,   -71,   -71,   -71,
     -40,   -71,    68,   -71,    43,   -71,   -71,   -71
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     5,    11,    22,    23,    47,    13,
      48,    49,    50,    51,    52,   145,   150,    53,    54,    55,
      56,    57,    68,    58,   131,    59,    97,    60
  };

  const unsigned char
  parser::yytable_[] =
  {
      74,   102,   140,   142,    76,    77,    78,    10,    65,    81,
     124,    65,    66,     1,    67,    66,    82,    83,    84,   125,
      85,    86,    87,    88,    89,    95,    96,    98,    10,   100,
     101,   141,   141,   130,   130,    92,    84,    30,    85,    31,
       8,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    92,    65,    99,     7,    29,     6,   126,
     108,   134,    12,    33,    34,    35,    36,    26,   133,    37,
      38,   147,    14,    15,    16,    17,    24,    19,    32,    39,
      40,    41,    42,    20,    43,   135,    61,    28,     9,   139,
     106,    44,    69,    27,   143,    70,    71,    72,    62,    63,
      64,    75,    45,    79,    80,    94,   151,    93,   152,    99,
     122,    46,    33,    34,    35,    36,   137,   138,    37,    38,
     103,    14,    15,    16,    17,   129,    19,   104,    39,    40,
      41,    42,    20,    43,    33,    34,    73,    92,   153,   144,
      44,   148,   149,   156,   157,    25,   107,   132,   109,     0,
     123,    45,    41,    42,     0,     0,     0,    81,     0,     0,
      46,     0,    44,     0,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    45,    90,    91,     0,   136,    81,     0,
       0,     0,    46,    92,    81,    82,    83,    84,     0,    85,
       0,    82,    83,    84,     0,    85,    86,    87,    88,    89,
       0,    90,    91,   105,    92,     0,    81,     0,     0,     0,
      92,     0,     0,    82,    83,    84,     0,    85,    86,    87,
      88,    89,     0,    90,    91,   127,     0,     0,    81,     0,
       0,     0,    92,     0,     0,    82,    83,    84,     0,    85,
      86,    87,    88,    89,     0,    90,    91,   128,     0,     0,
      81,     0,     0,     0,    92,     0,     0,    82,    83,    84,
       0,    85,    86,    87,    88,    89,     0,    90,    91,   154,
       0,     0,    81,     0,     0,     0,    92,     0,     0,    82,
      83,    84,     0,    85,    86,    87,    88,    89,     0,    90,
      91,   155,     0,     0,    81,     0,     0,     0,    92,     0,
       0,    82,    83,    84,     0,    85,    86,    87,    88,    89,
      81,    90,    91,     0,     0,   146,     0,    82,    83,    84,
      92,    85,    86,    87,    88,    89,    81,    90,    91,     0,
       0,     0,     0,    82,    83,    84,    92,    85,    86,    87,
      88,    89,    81,    90,    91,     0,     0,     0,     0,    82,
      83,    84,    92,    85,    86,    87,    88,    89,     0,    90,
      14,    15,    16,    17,    18,    19,     0,     0,    92,     0,
       0,    20,    14,    15,    16,    17,     0,    19,     0,    39,
       0,     0,     0,    20,    43,     0,    21,    14,    15,    16,
      17,     0,    19,     0,     0,     0,     0,     0,    20
  };

  const short int
  parser::yycheck_[] =
  {
      40,    71,    30,    30,    44,    45,    46,     4,    27,    35,
      32,    27,    31,     5,    33,    31,    42,    43,    44,    41,
      46,    47,    48,    49,    50,    65,    66,    67,    25,    69,
      70,    59,    59,   103,   104,    61,    44,    39,    46,    41,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    61,    27,    27,    37,    39,     0,    99,
      33,    33,    29,     3,     4,     5,     6,     9,   108,     9,
      10,   141,    12,    13,    14,    15,     7,    17,     5,    19,
      20,    21,    22,    23,    24,   125,     5,    18,    59,   129,
      30,    31,    31,    59,   134,    31,    31,     5,    29,    30,
      31,     5,    42,    59,     5,     5,   146,    36,   148,    27,
       5,    51,     3,     4,     5,     6,   127,   128,     9,    10,
      29,    12,    13,    14,    15,    40,    17,    29,    19,    20,
      21,    22,    23,    24,     3,     4,     5,    61,   149,     7,
      31,    31,     8,   154,   155,     9,    79,   104,    80,    -1,
      28,    42,    21,    22,    -1,    -1,    -1,    35,    -1,    -1,
      51,    -1,    31,    -1,    42,    43,    44,    -1,    46,    47,
      48,    49,    50,    42,    52,    53,    -1,    28,    35,    -1,
      -1,    -1,    51,    61,    35,    42,    43,    44,    -1,    46,
      -1,    42,    43,    44,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    32,    61,    -1,    35,    -1,    -1,    -1,
      61,    -1,    -1,    42,    43,    44,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    32,    -1,    -1,    35,    -1,
      -1,    -1,    61,    -1,    -1,    42,    43,    44,    -1,    46,
      47,    48,    49,    50,    -1,    52,    53,    32,    -1,    -1,
      35,    -1,    -1,    -1,    61,    -1,    -1,    42,    43,    44,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    32,
      -1,    -1,    35,    -1,    -1,    -1,    61,    -1,    -1,    42,
      43,    44,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    32,    -1,    -1,    35,    -1,    -1,    -1,    61,    -1,
      -1,    42,    43,    44,    -1,    46,    47,    48,    49,    50,
      35,    52,    53,    -1,    -1,    40,    -1,    42,    43,    44,
      61,    46,    47,    48,    49,    50,    35,    52,    53,    -1,
      -1,    -1,    -1,    42,    43,    44,    61,    46,    47,    48,
      49,    50,    35,    52,    53,    -1,    -1,    -1,    -1,    42,
      43,    44,    61,    46,    47,    48,    49,    50,    -1,    52,
      12,    13,    14,    15,    16,    17,    -1,    -1,    61,    -1,
      -1,    23,    12,    13,    14,    15,    -1,    17,    -1,    19,
      -1,    -1,    -1,    23,    24,    -1,    38,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,    64,    65,    66,    67,    68,    37,     0,    59,
      67,    68,    29,    72,    12,    13,    14,    15,    16,    17,
      23,    38,    69,    70,    76,    66,    68,    59,    76,    39,
      39,    41,     5,     3,     4,     5,     6,     9,    10,    19,
      20,    21,    22,    24,    31,    42,    51,    71,    73,    74,
      75,    76,    77,    80,    81,    82,    83,    84,    86,    88,
      90,     5,    76,    76,    76,    27,    31,    33,    85,    31,
      31,    31,     5,     5,    83,     5,    83,    83,    83,    59,
       5,    35,    42,    43,    44,    46,    47,    48,    49,    50,
      52,    53,    61,    36,     5,    83,    83,    89,    83,    27,
      83,    83,    75,    29,    29,    32,    30,    73,    33,    85,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,     5,    28,    32,    41,    83,    32,    32,    40,
      75,    87,    87,    83,    33,    83,    28,    72,    72,    83,
      30,    59,    30,    83,     7,    78,    40,    75,    31,     8,
      79,    83,    83,    72,    32,    32,    72,    72
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    63,    64,    65,    65,    65,    65,    66,    66,    67,
      68,    69,    69,    69,    69,    70,    70,    70,    71,    71,
      72,    73,    73,    73,    73,    73,    73,    73,    74,    75,
      75,    75,    75,    75,    76,    76,    76,    76,    76,    76,
      77,    78,    78,    79,    79,    80,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      89,    89,    90
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,     3,     1,     1,     2,     1,     2,
       3,     3,     1,     1,     3,     4,     2,     3,     3,     1,
       5,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       4,     3,     5,     1,     1,     1,     1,     1,     1,     1,
       7,     5,     0,     2,     0,     5,     9,     1,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     4,     3,     5,     5,     3,     1,     4,
       3,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "NUMENT", "NUMFLOT", "ID", "SI", "OSI",
  "SINO", "MIENTRAS", "PARA", "CASO", "ENT", "FLOT", "NADA", "BOOL", "VAR",
  "CAR", "CADENA", "REGISTRO", "RETORNA", "CIERTO", "FALSO", "ARREGLO",
  "UNION", "PROGRAMA", "LEER", "OBRACK", "CBRACK", "OBRACE", "CBRACE",
  "LPAR", "RPAR", "EQUAL", "EQUIV", "DOTDOT", "ONEDOT", "COLCOL", "TILDE",
  "ARROW", "SEMICOL", "COMMA", "MINUS", "PLUS", "MULT", "DIV", "MOD",
  "LTHAN", "GTHAN", "LETHAN", "GETHAN", "NEGATION", "AND", "OR", "QUOTA",
  "APOST", "BSLASH", "OCOMENT", "CCOMENT", "SEP", "INEQUIV", "POWER",
  "NEG", "$accept", "enie", "prog", "funcl", "func", "header", "signa",
  "arglist", "instlist", "instbl", "inst", "asign", "decl", "type",
  "selec", "oselect", "sinoselect", "indite", "detite", "return", "exp",
  "term", "arr", "declbox", "declist", "callfunc", "explist", "boxelem", YY_NULL
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,   102,   102,   105,   106,   107,   108,   111,   112,   115,
     119,   122,   123,   124,   125,   128,   129,   130,   133,   134,
     137,   140,   141,   142,   143,   144,   145,   146,   149,   153,
     154,   155,   156,   157,   161,   162,   163,   164,   165,   166,
     169,   172,   173,   176,   177,   180,   183,   186,   187,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   209,   210,   211,   212,   213,
     214,   215,   216,   219,   220,   223,   224,   227,   228,   231,
     234,   235,   238
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
      55,    56,    57,    58,    59,    60,    61,    62
    };
    const unsigned int user_token_number_max_ = 317;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1039 "parser.tab.cc" // lalr1.cc:1156
#line 240 "parser.y" // lalr1.cc:1157
 

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


