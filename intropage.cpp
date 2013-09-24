#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>

#include "intropage.h"

IntroPage::IntroPage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "Introduction" )) );
//     setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );

    label = new QLabel( tr(gtr( "Welcome to Magic wideband configuration wizard!\n"
                                            "Press Next to start configuration.\n"
                                            "This software is licensed as GPLv2+\n"
                                            "(c)) 2004-2007, Magic Group\n"
                                            "Author: KDE <athena_star {at} 163 {dot} com>" ) ));
    label->setWordWrap( true );
    layout->addWidget( label );
}
