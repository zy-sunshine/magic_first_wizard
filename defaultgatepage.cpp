#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QRegExpValidator>

#include "defaultgatepage.h"

extern int currentNetcard;

DefaultGatePage::DefaultGatePage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "DefaultGatePage" )) );
    //     setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );

    label = new QLabel( tr(gtr( "DefaultGatePage" )) );
    label->setWordWrap( true );
    layout->addWidget( label );

    check = new QCheckBox( tr(gtr( "Use Default Gate" )) );
    check->setCheckState( Qt::Checked );
    layout->addWidget( check );

    label2 = new QLabel( tr(gtr( "Default Gate IP Address:" )) );
    label2->setWordWrap( true );
    layout->addWidget( label2 );

    edit = new QLineEdit;
    // validate for ip address
    QRegExp exp( "^(((25[0-5])|(2[0-4][0-9])|([01]?[0-9]?[0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|([01]?[0-9]?[0-9]))$" );
    QRegExpValidator* ipvalidator = new QRegExpValidator( exp, this );
    edit->setValidator( ipvalidator );
    layout->addWidget( edit );

    connect( check, SIGNAL( toggled( bool ) ), label2, SLOT( setEnabled( bool ) ) );
    connect( check, SIGNAL( toggled( bool ) ), edit, SLOT( setEnabled( bool ) ) );

    registerField( "defaultgatecheck"+QString::number(currentNetcard), check );
    registerField( "defaultgateip"+QString::number(currentNetcard), edit );

}
