#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QApplication>
#include <QTranslator>
#include <QTextCodec>
#include "wizard.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );

    QTextCodec::setCodecForTr( QTextCodec::codecForName("GBK") );
    //QTranslator translator;
    //translator.load("magic_first_wizard_zh_CN.qm");
    //app.installTranslator(&translator);
    ::setlocale(LC_ALL, "");
    ::textdomain("magic_first_wizard");
    ::bindtextdomain("magic_first_wizard", "/usr/share/locale");

    Wizard wizard;
    return wizard.exec();
}
