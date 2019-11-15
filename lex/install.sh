echo Generating Lexical Parser
lex palindrome.l
echo Done..
rm palindrome.c
mv lex.yy.c palindrome.c
echo Generating target File
g++ palindrome.c -o palindrome
echo Done..
