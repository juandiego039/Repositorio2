%% spie.cls - Version 2.6
%% LaTeX2e class file to format manuscript for SPIE Proceedings

% History
% Prepared by Rick Zaccone <zaccone@bucknell.edu> on 6/3/91.
% Modified by Adrian F Clark <alien@uk.ac.essex> 11-Jan-1992.
% Modified by Ken Hanson <kmh@lanl.gov>  April, 1995
% Modified by Ken Hanson <kmh@lanl.gov>  June 23, 1997
% Modified by Ken Hanson <kmh@lanl.gov>  Nov. 3, 1997
% Modified by Ken Hanson <kmh@lanl.gov>  Dec. 10, 1997
% Modified by Ken Hanson <kmh@lanl.gov>  Mar. 8, 1998
% Modified by Ken Hanson <kmh@lanl.gov>  July 18, 2001
% Modified by Guenter Milde <G.Milde@physik.tu-dresden.de>  August 1, 2001
%  convert to LaTex2e class and added option a4 paper
% Modified by Ken Hanson <kmh@lanl.gov>  August 29, 2001
%  update SPIE format, including reduced text field: 6.75 in by 8.75 in
%  citesort.sty embedded to facilitate concatenation of citations.
%  However, citesort may lead to problems when used with babel,
%  in which case it should be removed from this file.
%
% ADAPTADO PARA PLANTILLA DE LA REVISTA MOMENTO POR
% OMAR ORTIZ Y MARTA GUERRA
%Modificado por Monica Lopez. Nov 2012

% This style file does not automatically implement all the formatting
%  required for an SPIE manuscript.  The user must make a few adjustments
%  manually for proper formatting, such as:
% 1. Title and subsubsection should be in lower case
%    except for the first letter and proper nouns or acronyms
% 2. Subsection headings should be capitalized as for book titles
% 3. Format authors as follows
%    \author{author1\supit{a}, author2\supit{b}, and author3\supit{c} \skiplinehalf
%            \supit{a}affiliation1\\
%            \supit{b}affiliation2\\
%            \supit{c}affiliation3
%           }
%
%  Note: \skiplinehalf and \supit{} are defined in this class
% ------------------------------------------------------------
%% based on standard LaTeX article class --
%% need to define font Size Option inside spie.cls
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{momento}[2001/09/27 v2.61 SPIE proceedings class]

\LoadClassWithOptions{articulo}  % COSTRUIDO SOBRE LA CLASE articulo

\DeclareOption{mpaper}{%
   \AtEndOfClass{%
       \oddsidemargin 2.2cm
       \evensidemargin 2.2cm
       \typeout{mpaper used}
       }
   }
\DeclareOption{m4}{%
   \AtEndOfClass{%
       \oddsidemargin 2.2cm
       \evensidemargin 2.2cm
       \typeout{m4 used}
       }
   }
\ProcessOptions\relax      % se especifican margenes para mpaper

%% type out specified font size
\if0\@ptsize\typeout{ten-point font}\fi
\if1\@ptsize\typeout{eleven-point font}\fi
\if2\@ptsize\typeout{twelve-point font}\fi

%% TAMA� DE LA P�INA
\hoffset -1in
\voffset -1in
\topmargin 2.0 cm                 % = 1.2in
% the next two only hold for US-standard paper
\oddsidemargin .88in              % = 2.2cm
\evensidemargin .88in             % = 2.2cm
% and are overridden by the a4paper option
\textheight 19cm                  % = 8.75in
\textwidth 12cm                   % = 6.75in
\headheight 6mm \headsep 4mm      %
%%
%%  DEFINICI� DEL ESTILO DE P�INA Y ENCABEZADOS
%%
%%Packages for Bibliography
\usepackage[sort&compress,numbers]{natbib}
\usepackage{doi}
\usepackage{setspace}

\usepackage{fancyhdr}
\pagestyle{fancy}
\fancyhead{}
\fancyhead[RE]{\scriptsize\it\autor}
\fancyhead[LO]{\scriptsize\it\tema}
\fancyhead[LE,RO]{\thepage}
\fancyfoot{}
%\parskip 1ex plus 1ex minus 0.3ex % NO ESPACIO ENTRE PAR�RAFOS
%\date{}                           % avoid date


%%  space for floats - figures and tables
\floatsep 0.9ex plus 0.3ex minus 0.6ex
\textfloatsep 4ex plus 3ex minus 1.5ex
\renewcommand{\textfraction}{0.10}
\renewcommand{\floatpagefraction}{0.60}
\renewcommand{\topfraction}{0.90}
\renewcommand{\bottomfraction}{0.90}
\setcounter{totalnumber}{3}
\setcounter{topnumber}{2}
\setcounter{bottomnumber}{2}
\setlength{\bibsep}{2pt}

%%%% useful definitions %%%%
\def\skiplinehalf{\medskip\\}
\def\skipline{\\}
\def\exspace{\vspace{1ex}}
% SUPER�DICE EN rm,
% PARA REFERENCIAS DEL AUTOR
\def\suprm#1{\raisebox{0.8ex}{\scriptsize\rm #1}\hspace{0.05em}}


%%%%  define \ample font size %%%%
%% 10% larger than \normalsize for 10 pt,
%% but smaller than \large
\if0\@ptsize
   \def\ample{\@setsize\normalsize{12pt}\xipt\@xipt}
\else
   \def\ample{\normalsize}%% P. E. TAMA� DE LETRA DE SECCIONES
\fi
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%% definici� de aspectos del t�ulo %%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\def\titlefont{\normalsize\bf}  %% insurance
\if0\@ptsize
   \font\titlefont = cmbx12 at 16truept  %
\else
   \def\titlefont{\normalsize\bf}             % PARA EL T�ULO
\fi

\def\title#1{\gdef\@title{\titlefont #1}}

\def\authorinfo#1{\gdef\@authorinfo{\hspace{-0.7cm}#1}}
\authorinfo{}     %% vac� por defecto
%%%   DEFINICI� de maketitle

\def\maketitle{\par \thispagestyle{empty}
 \begingroup
   \def\thefootnote{\fnsymbol{footnote}}%
   \def\@makefnmark{\hbox
       to\z@{$\m@th^{\@thefnmark}$\hss}}%
   \if@twocolumn
     \twocolumn[\@maketitle]%
     \else \newpage
     \global\@topnum\z@
     \@maketitle \fi
     \@thanks
 \endgroup
 \let\maketitle\relax
 \let\@maketitle\relax
 \gdef\@thanks{}\gdef\@author{}\gdef\@title{}\let\thanks\relax

%%%%  define footnote attributes %%%%
%\renewcommand{\footnotesize}{\small}  % enlarge footnote font to small
\renewcommand{\thefootnote}{\fnsymbol{footnote}}
\ifx\@authorinfo\empty \else\footnotetext[0]{\@authorinfo}\fi
%% use zero to avoid footnote mark
\renewcommand{\thefootnote}{\arabic{footnote}}
%% use footnote symbols, not numbers
}

\def\@maketitle{\newpage
 \null
% move title to top of page
\if0\@ptsize\vspace{-10mm}\else\vspace{-12mm}\fi
\noindent{\sc herramientas computacionales}\hfill{\scriptsize Midterm Project, Agosto 30, 2016}\hfill\thepage\par
\vspace{-4mm}
\noindent\hrulefill
 \begin{center}%
 \vspace{0.5cm}
  {\setlength{\baselineskip}{4.3ex} \@title \par}
  \vskip 3.5mm
  {\small\bf       % AUTOR Y UNIVERSIDAD
   \@author}\\
   \vspace{5mm}
  {\scriptsize \afiliacion}%%%   Universidad
  %\vskip 1.5ex
  %{\large \@date}%
 \end{center}%
 \par
}


%%%% aspectos de la secci� %%%%
% en negrilla
% justificado a la izquierda, tama� normal
\def\sectfont{\noindent\ample\bf}
% sub- and subsubsection headings flush left
\def\subsectfont{\raggedright\ample\bf}
\def\subsubsectfont{\raggedright\normalsize\bf}
\def\append{0}
%% LO QUE SIGUE SE REEMPLAZ�POR LAS DEFINICIONES
%% DADAS EN 'articulo.cls', PUES PRODUCEN MEJORES RESULTADOS
%%
%%\def\section{\@startsection{section}{1}{\z@}
%%   {-2.5ex plus -1ex minus -0.5ex}{0.2ex plus 0.5ex minus 0ex}{\sectfont}}
%%\def\subsection{\@startsection{subsection}{2}{\z@}
%%   {-1.5ex plus -1ex minus -0.5ex}{0.1ex plus 0.1ex minus 0.1ex}{\subsectfont}}
%%\def\subsubsection{\@startsection{subsubsection}{3}{\z@}
 %%  {-1ex plus -1ex minus -0.5ex}{0.1ex plus 0.1ex}{\subsubsectfont}}

%% from latex.sty
%% \@sect{NAME}{LEVEL}{INDENT}{BEFORESKIP}{AFTERSKIP}
%% {STYLE}[ARG1]{ARG2}
%%\def\@sect#1#2#3#4#5#6[#7]#8{\ifnum #2>\c@secnumdepth
%%     \let\@svsec\@empty\else
%%     \refstepcounter{#1}\edef\@svsec{\csname the#1\endcsname.\hskip 0.3em plus 0.3em}\fi
%%     \@tempskipa #5\relax
%%      \ifdim \@tempskipa>\z@
%%       \begingroup #6\relax
%%          \ifnum #2=1
%%(kmh) in appendix, add word appendix in front of section number
%%             \ifnum \append=1 {\interlinepenalty \@M
%%            APPENDIX \@svsec\uppercase{#8}\par}
%%         \else {\interlinepenalty \@M \@svsec\uppercase{#8}\par}
%%         \fi
%%      \else\ifnum #2=2
%%             \noindent{\interlinepenalty \@M \@svsec #8\par}
%%      \else
%%             \noindent{\interlinepenalty \@M \@svsec #8\par}
%%           \fi
%%      \fi
%%       \endgroup
%%       \csname #1mark\endcsname{#7}\addcontentsline
%%         {toc}{#1}{\ifnum #2>\c@secnumdepth \else
%%                      \protect\numberline{\csname the#1\endcsname}\fi
%%                    #7}\else
%%        \def\@svsechd{#6\hskip #3\relax  %% \relax added 2 May 90
%%                   \@svsec #8\csname #1mark\endcsname
%%                      {#7}\addcontentsline
%%                           {toc}{#1}{\ifnum #2>\c@secnumdepth \else
%%                             \protect\numberline{\csname the#1\endcsname}\fi
%%                       #7}}\fi
%%     \@xsect{#5}}

%%%%% Special sections %%%%%
%\def\abstract{\section*{ABSTRACT}}
%\def\endabstract{}

% PALABRAS CLAVES EN ESPAÑOL
\def\keywords#1{
\par\vspace{0.5ex}{\noindent\bf \small Palabras clave: }{\small #1}
\vspace{0.5ex}   %% provide extra space before first section
}
% PALABRAS CLAVES EN INGLES
\def\ikeywords#1{
\par\vspace{0.5ex}{\noindent\bf \small Keywords: }{\small #1}
\vspace{0.5ex}   %% provide extra space before first section
}

\def\acknowledgments{\section*{ACKNOWLEDGMENTS}}
\def\endacknowledgments{}
% Old spelling - acceptable, but not preferred
\def\acknowledgements{\section*{ACKNOWLEDGMENTS}}
\def\endacknowledgements{}

%%
%%   proporciona otro estilo de bibliografia
%%
%%   POR DEFECTO SE USARA EL ESTILO DE 'articulo.cls'
%%   LAS LINEAS QUE SIGUEN EST� COMO COMENTARIOS PARA QUE SE UTILIZE ESE ESTILO Y NO EL DE
%%   ESTE DOCUMENTO

%%\def\thebibliography#1{\section*{REFERENCIAS\@mkboth
%% {REFERENCIAS}{REFERENCIAS}}\list
%% {\arabic{enumi}.}
%% {\settowidth\labelwidth{[#1]}\leftmargin\labelwidth
%% \advance\leftmargin\labelsep \usecounter{enumi}}
%% \def\newblock{\hskip .11em plus .33em minus .07em}
%%  %% reduce vspace between items
%%  \parskip -0.7ex plus 0.5ex minus 0ex
%%\if0\@ptsize\else\small\fi      %% smaller fonts
%% \sloppy\clubpenalty4000\widowpenalty4000
%% \sfcode`\.=1000\relax}
%%\let\endthebibliography=\endlist



%%%% Add theorem, lemma, and definition environments %%%%
% kmh - noindent
\def\@begintheorem#1#2{
   \par\noindent\bgroup{\sc #1\ #2. }\it\ignorespaces}
\def\@opargbegintheorem#1#2#3{
   \par\bgroup{\sc #1\ #2\ (#3). }\it\ignorespaces}
\def\@endtheorem{\egroup}
%\def\proof{\par{\it Proof}. \ignorespaces}
%\def\endproof{{\ \vbox{\hrule\hbox{%
%  \vrule height1.3ex\hskip0.8ex\vrule}\hrule
 % }}\par}
%\newtheorem{theorem}{Theorem}[section]
%\newtheorem{lemma}[theorem]{Lemma}
%\newtheorem{definition}[theorem]{Definition}

%%%% Figure and table captions %%%
%\long\def\@makecaption#1#2{%     % from article.cls
%  \vskip\abovecaptionskip
%  \sbox\@tempboxa{{\footnotesize\bf #1}: {\footnotesize #2}}%
%  \ifdim \wd\@tempboxa >\hsize   % bold with period
%    {\footnotesize\bf #1.\ }{\footnotesize #2 \par}
%  \else
%    \global \@minipagefalse
%    \hb@xt@\hsize{\hfil\box\@tempboxa\hfil}%
%  \fi
%  \vskip\belowcaptionskip}

%%%% appendix aspects %%%%
% use \appendix to start an appendix
% use \section{} for each appendix section
\def\appendix{\def\append{1}
  \par
  \setcounter{section}{0}
  \setcounter{subsection}{0}
  \setcounter{subsubsection}{0}
  \def\thesection{\Alph{section}}
  \def\thesubsection{\Alph{section}.\arabic{subsection}}
\def\thesubsubsection{
\Alph{section}.\arabic{subsection}.\arabic{subsubsection}}
}
