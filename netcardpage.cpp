#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>
#include <QDir>
#include <QProcess>
#include <QString>
#include <QStringList>

#include "netcardpage.h"

NetCardPage::NetCardPage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "NetCardPage" )) );
    //     setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );

    // get netcard info
    QProcess *p = new QProcess( this );
    p->start( "lspci" );
    p->waitForFinished( -1 );// never timeout
    QStringList netcards = QString( p->readAllStandardOutput() ).split( '\n', QString::SkipEmptyParts ).filter( "Ethernet controller:" );
    QStringList loadedcards = QDir( "/sys/class/net" ).entryList( QStringList( "eth*" ) );

    QString str = QString( tr(gtr( "Detected %1 PCI netcards:\n"
                        "%2\n\n"
                        "Loaded %3 netcards:\n"
                        "%4" )) )
                        .arg( QString::number( netcards.count() ) )
                        .arg( netcards.join( "\n" ) )
                        .arg( QString::number( loadedcards.count() ) )
                        .arg( loadedcards.join( "\n" ) );
    label = new QLabel( str );
    label->setWordWrap( true );
    layout->addWidget( label );
}
