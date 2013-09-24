#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>

#include "tcpipinfopage.h"

TCPIPInfoPage::TCPIPInfoPage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "TCPIPInfoPage" )) );
    //     setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );
    
    label = new QLabel( tr(gtr( "TCPIPInfoPage balh balh....." )) );
    label->setWordWrap( true );
    layout->addWidget( label );
}
