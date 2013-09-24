#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QVariant>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include "conclusionpage.h"
#include "wizard.h"

ConclusionPage::ConclusionPage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "ConclusionPage" )) );
//     setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );

    label = new QLabel;
    label->setWordWrap( true );
    layout->addWidget( label );
}

void ConclusionPage::initializePage()
{
    QString str;
    if( field("dhcpbutton"+QString::number(Wizard::currentNetcard)).toBool() == true){
        //dhcp option config

        str = QString( tr(gtr(
        "No. %1 card use dhcp mode\n"
        "Device: %2\n\n")) )
                .arg(QString::number(Wizard::currentNetcard+1))
                .arg(Wizard::netcardDeviceMap[Wizard::currentNetcard]);
    }
    if( field("manualbutton"+QString::number(Wizard::currentNetcard)).toBool() == true){
        //manual ip option config


        QString ip = field( "ip"+QString::number(Wizard::currentNetcard) ).toString();
        QString netmask = field( "netmask"+QString::number(Wizard::currentNetcard) ).toString();
        QString gateway = field( "gateway"+QString::number(Wizard::currentNetcard) ).toString();
        str = QString( tr(gtr(
        "No. %1 card use manual mode\n"
        "Device: %2\n\n"
        "IP      :%3\n"
        "Netmask :%4\n"
        "Gateway :%5\n")) )
                .arg(QString::number(Wizard::currentNetcard+1))
                .arg(Wizard::netcardDeviceMap[Wizard::currentNetcard])
                .arg(ip, netmask, gateway );
    }
    str += tr(gtr("Allow rootless: %1\n")).arg( field( "allowrootless"+QString::number(Wizard::currentNetcard) ).toString() );
    str += tr(gtr("Boot activate : %1\n")).arg( field( "bootactivate"+QString::number(Wizard::currentNetcard) ).toString() );
    label->setText( str );
}
bool ConclusionPage::validatePage()
{
    QStringList lines;
    lines << "# Created by MagicLinux First Wizard";
    lines << "DEVICE="+Wizard::netcardDeviceMap[Wizard::currentNetcard];

    if( field("dhcpbutton"+QString::number(Wizard::currentNetcard)).toBool() == true ){
        //dhcp option config

        lines << "BOOTPROTO=dhcp";
    }
    if( field("manualbutton"+QString::number(Wizard::currentNetcard)).toBool() == true ){
        //manual ip option config

        lines << "BOOTPROTO=static";
        //lines << "BROADCAST="+192.168.1.255";
        lines << "IPADDR="+field( "ip"+QString::number(Wizard::currentNetcard) ).toString();
        lines << "NETMASK="+field( "netmask"+QString::number(Wizard::currentNetcard) ).toString();
        lines << "GATEWAY="+field( "gateway"+QString::number(Wizard::currentNetcard) ).toString();

    }

    if( field( "allowrootless"+QString::number(Wizard::currentNetcard) ).toBool() == true ){
        lines << "USERCTL=yes";
    }else{
        lines << "USERCTL=no";
    }
    if( field( "bootactivate"+QString::number(Wizard::currentNetcard) ).toBool() == true ){
        lines << "ONBOOT=yes";
    }else{
        lines << "ONBOOT=no";
    }
    //qDebug() << lines.join("\n");
    QFile ifcfg("/etc/sysconfig/network-scripts/ifcfg-"+Wizard::netcardDeviceMap[Wizard::currentNetcard]);
    if(!ifcfg.open(QIODevice::WriteOnly)){
        return false;
    }else{
        QTextStream stream( &ifcfg );
        stream << lines.join("\n");
        ifcfg.close();
    }
    return true;
}
/*
DEVICE=eth0
BOOTPROTO=static(dhcp)
#BROADCAST=192.168.1.255
IPADDR=192.168.1.101
NETMASK=255.255.255.0
GATEWAY=192.168.1.1
#HWADDR=00:0C:29:69:76:CA
USERCTL=yes
ONBOOT=yes
#TYPE=Ethernet
*/
