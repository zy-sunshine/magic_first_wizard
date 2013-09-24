#!/usr/bin/perl
use strict;

my $strAll = "#include <locale.h>\n#include <libintl.h>\n#define gtr(string) gettext(string)\n";
open(INFILE, "<$ARGV[0]");
while(<INFILE>){
    $strAll .= $_;
}
#print $strAll;
#$strAll =~ s/\btr\b\((.*?)\)/tr\(gtr\($1\)\)/mgs;
#print $strAll;
#open(OUTFILE, ">outfile");
#print OUTFILE ("Here is an output line.\n");
print $ARGV[1];
open(OUTFILE, ">$ARGV[0]");
print OUTFILE ($strAll);
