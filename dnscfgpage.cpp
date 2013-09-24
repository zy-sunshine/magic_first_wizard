#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QFile>
#include <QTextStream>

#include "dnscfgpage.h"

DNSCfgPage::DNSCfgPage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "DNSCfgPage" )) );
    //     setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );

    label = new QLabel( tr(gtr( "DNSCfgPage" )) );
    label->setWordWrap( true );
    layout->addWidget( label );

    // validate for ip address
    QRegExp exp( "^(((25[0-5])|(2[0-4][0-9])|([01]?[0-9]?[0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|([01]?[0-9]?[0-9]))$" );
    QRegExpValidator* ipvalidator = new QRegExpValidator( exp, this );

    primarybutton = new QCheckBox( tr(gtr( "Use Primary DNS" )) );
    primarybutton->setCheckState( Qt::Checked );
    layout->addWidget( primarybutton );

    labelprimary = new QLabel( tr(gtr( "Primary DNS IP Address:" )) );
    labelprimary->setWordWrap( true );
    labelprimary->setEnabled( true );
    layout->addWidget( labelprimary );

    primarydns = new QLineEdit;
    primarydns->setValidator( ipvalidator );
    primarydns->setEnabled( true );
    layout->addWidget( primarydns );

    secondarybutton = new QCheckBox( tr(gtr( "Use Secondary DNS" )) );
    secondarybutton->setCheckState( Qt::Unchecked );
    secondarybutton->setEnabled( true );
    layout->addWidget( secondarybutton );

    labelsecondary = new QLabel( tr(gtr( "Secondary DNS IP Address:" )) );
    labelsecondary->setWordWrap( true );
    labelsecondary->setEnabled( false );
    layout->addWidget( labelsecondary );

    secondarydns = new QLineEdit;
    secondarydns->setValidator( ipvalidator );
    secondarydns->setEnabled( false );
    layout->addWidget( secondarydns );

    connect( primarybutton, SIGNAL( toggled( bool ) ), labelprimary, SLOT( setEnabled( bool ) ) );
    connect( primarybutton, SIGNAL( toggled( bool ) ), primarydns, SLOT( setEnabled( bool ) ) );
    connect( primarybutton, SIGNAL( toggled( bool ) ), secondarybutton, SLOT( setEnabled( bool ) ) );
    connect( primarybutton, SIGNAL( toggled( bool ) ), secondarybutton, SLOT( setChecked( bool ) ) );
    connect( secondarybutton, SIGNAL( toggled( bool ) ), labelsecondary, SLOT( setEnabled( bool ) ) );
    connect( secondarybutton, SIGNAL( toggled( bool ) ), secondarydns, SLOT( setEnabled( bool ) ) );
/*
    registerField( "primarybutton", primarybutton );
    registerField( "primarydns", primarydns );
    registerField( "secondarybutton", secondarybutton );
    registerField( "secondarydns", secondarydns );
*/
}
bool DNSCfgPage::validatePage()
{
    QStringList lines;
    lines << "# Created by MagicLinux First Wizard";
    if(primarybutton->isChecked() == true){
        lines << "nameserver "+primarydns->text();
        if(secondarybutton->isChecked() == true){
            lines << "nameserver "+secondarydns->text();
        }
    }
    //qDebug() << lines.join("\n");

    QFile resolv("/etc/resolv.conf");
    if(!resolv.open(QIODevice::WriteOnly)){
        return false;
    }else{
        QTextStream stream( &resolv );
        stream << lines.join("\n");
        resolv.close();
    }
    return true;
}
