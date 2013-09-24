#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>

#include "rootlesspage.h"
#include "wizard.h"


RootlessPage::RootlessPage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "RootlessPage" )) );
    //     setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );

    label = new QLabel( tr(gtr( "RootlessPage" )) );
    label->setWordWrap( true );
    layout->addWidget( label );

    allowrootless = new QCheckBox( tr(gtr( "Allow non-root user operation" )) );
    allowrootless->setCheckState( Qt::Checked );
    layout->addWidget( allowrootless );
}
void RootlessPage::initializePage()
{
    registerField( "allowrootless"+QString::number(Wizard::currentNetcard), allowrootless );
}
