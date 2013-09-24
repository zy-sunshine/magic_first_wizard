#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>

#include "bootactivatepage.h"
#include "wizard.h"

BootActivatePage::BootActivatePage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "BootActivatePage" )) );
    //     setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );

    label = new QLabel( tr(gtr( "BootActivatePage" )) );
    label->setWordWrap( true );
    layout->addWidget( label );

    bootactivate = new QCheckBox( tr(gtr( "Activate netcard at boot" )) );
    bootactivate->setCheckState( Qt::Checked );
    layout->addWidget( bootactivate );
}
void BootActivatePage::initializePage()
{
    registerField( "bootactivate"+QString::number(Wizard::currentNetcard), bootactivate );
}
