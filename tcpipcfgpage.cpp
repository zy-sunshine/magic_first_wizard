#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QString>
#include "tcpipcfgpage.h"
#include "wizard.h"

TCPIPCfgPage::TCPIPCfgPage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "TCPIPCfgPage" )) );
    //     setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );

    label = new QLabel( tr(gtr( "TCPIPCfgPage" )) );
    label->setWordWrap( true );
    layout->addWidget( label );

    dhcpbutton = new QRadioButton( tr(gtr( "Use DHCP" )) );
    dhcpbutton->setChecked( false );
    layout->addWidget( dhcpbutton );
    
    manualbutton = new QRadioButton( tr(gtr( "Manually" )) );
    manualbutton->setChecked( true );
    layout->addWidget( manualbutton );

    labelip = new QLabel( tr(gtr( "IP Address:" )) );
    labelip->setWordWrap( true );
    layout->addWidget( labelip );

    // validate for ip address
    QRegExp exp( "^(((25[0-5])|(2[0-4][0-9])|([01]?[0-9]?[0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|([01]?[0-9]?[0-9]))$" );
    QRegExpValidator* ipvalidator = new QRegExpValidator( exp, this );
    ip = new QLineEdit;
    ip->setValidator( ipvalidator );
    layout->addWidget( ip );

    labelnetmask = new QLabel( tr(gtr( "Net Mask Address:" )) );
    labelnetmask->setWordWrap( true );
    layout->addWidget( labelnetmask );

    netmask = new QLineEdit;
    netmask->setValidator( ipvalidator );
    layout->addWidget( netmask );

    labelGateway = new QLabel(tr(gtr("Default Gateway:")));
    labelGateway->setWordWrap(true);
    layout->addWidget(labelGateway);

    gateway = new QLineEdit;
    gateway->setValidator(ipvalidator);
    layout->addWidget(gateway);
    connect( manualbutton, SIGNAL( toggled( bool ) ), labelip, SLOT( setEnabled( bool ) ) );
    connect( manualbutton, SIGNAL( toggled( bool ) ), labelnetmask, SLOT( setEnabled( bool ) ) );
    connect( manualbutton, SIGNAL( toggled( bool ) ), labelGateway, SLOT( setEnabled( bool ) ) );
    connect( manualbutton, SIGNAL( toggled( bool ) ), ip, SLOT( setEnabled( bool ) ) );
    connect( manualbutton, SIGNAL( toggled( bool ) ), netmask, SLOT( setEnabled( bool ) ) );
    connect( manualbutton, SIGNAL( toggled( bool ) ), gateway, SLOT( setEnabled( bool ) ) );
}
void TCPIPCfgPage::initializePage()
{
    registerField( "dhcpbutton"+QString::number(Wizard::currentNetcard), dhcpbutton );
    registerField( "manualbutton"+QString::number(Wizard::currentNetcard), manualbutton );
    registerField( "ip"+QString::number(Wizard::currentNetcard), ip );
    registerField( "netmask"+QString::number(Wizard::currentNetcard), netmask );
    registerField( "gateway"+QString::number(Wizard::currentNetcard), gateway );

}
