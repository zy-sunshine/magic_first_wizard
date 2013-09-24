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
#include <QMap>
#include <QMessageBox>

#include "startcfgpage.h"
#include "wizard.h"


StartCfgPage::StartCfgPage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "StartCfgPage" )) );
    // setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );
/*
    // get netcard info
    QProcess *p = new QProcess( this );
    p->start( "dmesg" );
    p->waitForFinished( -1 );// never timeout
    QStringList netcards = QString( p->readAllStandardOutput() ).split( '\n', QString::SkipEmptyParts ).filter( "eth" );
    QMessageBox::information(this, tr(gtr("info")), tr(gtr("%1")).arg(netcards.join("\n")));
*/

    label = new QLabel( "Nothing" );
    label->setWordWrap( true );
    layout->addWidget( label );
    //setCommitPage ( true );
}
void StartCfgPage::initializePage()
{
    Wizard::currentNetcard++;

    QString str = QString( tr(gtr( "Start to configure %1." )) ).arg( *(Wizard::netcardDeviceMap.find(Wizard::currentNetcard)) );

    label->setText( str );

}
void StartCfgPage::cleanupPage()
{
    Wizard::currentNetcard--;
}
