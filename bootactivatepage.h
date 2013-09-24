#ifndef BOOTACTIVATEPAGE_H
#define BOOTACTIVATEPAGE_H

#include <QWizardPage>

class QWidget;
class QLabel;
class QCheckBox;
class QLineEdit;

class BootActivatePage : public QWizardPage
{
    public:
        BootActivatePage( QWidget* parent = 0 );
    private:
        QLabel* label;
        QCheckBox* bootactivate;
    protected:
        void initializePage();
};

#endif // BOOTACTIVATEPAGE_H
