for var in *.cpp; do ./replace.pl $var; done
for var in *.cpp; do ./replace2.pl $var;done
xgettext --keyword=gtr -o translation.po `ls *.cpp`
mkdir -pv language/zh_CN/LC_MESSAGES
msgfmt -o language/zh_CN/LC_MESSAGES/translation.mo translation.po
