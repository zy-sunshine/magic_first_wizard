#ifndef DEFAULTGATE_H
#define DEFAULTGATE_H

#include <QWizardPage>

class QWidget;
class QLabel;
class QCheckBox;
class QLineEdit;

class DefaultGatePage : public QWizardPage
{
    Q_OBJECT
    public:
        DefaultGatePage( QWidget* parent = 0 );
    private:
        QLabel* label;
        QLabel* label2;
        QCheckBox* check;
        QLineEdit* edit;
};

#endif // DEFAULTGATE_H
